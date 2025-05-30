import cv2
import numpy as np
import serial
import time

color_thresholds = {
    'red':    [(0, 120, 70), (10, 255, 255), (170, 120, 70), (180, 255, 255)],
    'green':  [(36, 50, 50), (89, 255, 255)],
    'blue':   [(90, 50, 50), (140, 255, 255)],
    'yellow': [(20, 100, 100), (30, 255, 255)]
}

def find_largest_contour(mask):
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if contours:
        return max(contours, key=cv2.contourArea)
    return None

# Serial communication setup
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)  # Adjust port as needed
time.sleep(2)  # Wait for Arduino to reset and be ready

# Keep track of sent signals
color_sent = {color: False for color in color_thresholds}

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    for color_name, thresholds in color_thresholds.items():
        if len(thresholds) == 4:
            lower1 = np.array(thresholds[0])
            upper1 = np.array(thresholds[1])
            lower2 = np.array(thresholds[2])
            upper2 = np.array(thresholds[3])
            mask1 = cv2.inRange(hsv, lower1, upper1)
            mask2 = cv2.inRange(hsv, lower2, upper2)
            mask = cv2.bitwise_or(mask1, mask2)
        else:
            lower = np.array(thresholds[0])
            upper = np.array(thresholds[1])
            mask = cv2.inRange(hsv, lower, upper)

        largest_contour = find_largest_contour(mask)

        if largest_contour is not None and cv2.contourArea(largest_contour) > 800:
            x, y, w, h = cv2.boundingRect(largest_contour)
            color_bgr = {
                'red': (0,0,255),
                'green': (0,255,0),
                'blue': (255,0,0),
                'yellow': (0,255,255)
            }[color_name]
            cv2.rectangle(frame, (x,y), (x+w,y+h), color_bgr, 2)
            cv2.putText(frame, color_name.upper(), (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, color_bgr, 2)

            if not color_sent[color_name]:
                code = {
                    'red': 'r',
                    'green': 'g',
                    'blue': 'b',
                    'yellow': 'y'
                }[color_name]
                ser.write(code.encode())
                print(f"Detected: {color_name.upper()} — Sent: '{code}' to serial")
                color_sent[color_name] = True
        else:
            color_sent[color_name] = False

    cv2.imshow('Webcam', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
ser.close()

