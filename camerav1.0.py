import cv2
import numpy as np
import serial
import time

try:
    ser = serial.Serial('/dev/tty.usbmodem101', 9600, timeout=1)
    time.sleep(2)
    print("✅ Serial connected.")
except Exception as e:
    print(f"❌ Serial error: {e}")
    ser = None

cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("❌ No camera found.")
    exit()

last_sent = None

while True:
    ret, frame = cap.read()
    if not ret:
        print("❌ Frame error.")
        break

    frame = cv2.resize(frame, (640, 480))  # Optional resize
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lower_red1 = np.array([0, 120, 120])
    upper_red1 = np.array([8, 255, 255])
    lower_red2 = np.array([170, 120, 120])
    upper_red2 = np.array([179, 255, 255])
    lower_green = np.array([45, 100, 100])
    upper_green = np.array([75, 255, 255])

    mask_red = cv2.inRange(hsv, lower_red1, upper_red1) | cv2.inRange(hsv, lower_red2, upper_red2)
    mask_green = cv2.inRange(hsv, lower_green, upper_green)

    mask_red = cv2.bitwise_and(mask_red, mask_red, mask=cv2.inRange(hsv, np.array([0, 100, 50]), np.array([179, 255, 255])))

    contours_red, _ = cv2.findContours(mask_red, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contours_green, _ = cv2.findContours(mask_green, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    largest_red = max([cv2.contourArea(c) for c in contours_red], default=0)
    largest_green = max([cv2.contourArea(c) for c in contours_green], default=0)

    label = ""
    MIN_AREA = 600

    if largest_green > MIN_AREA and largest_green > largest_red:
        label = "L"
        if ser and last_sent != "l":
            ser.write(b"l")
            last_sent = "l"
    elif largest_red > MIN_AREA:
        label = "R"
        if ser and last_sent != "r":
            ser.write(b"r")
            last_sent = "r"
    else:
        last_sent = None

    if label:
        cv2.putText(frame, label, (10, 40),
                    cv2.FONT_HERSHEY_SIMPLEX, 1.2, (0, 255, 0), 3)

    cv2.putText(frame, "Press 'q' to quit", (10, frame.shape[0] - 10),
                cv2.FONT_HERSHEY_SIMPLEX, 0.6, (200, 200, 200), 1)

    cv2.imshow("Full Frame Color Detection", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
if ser:
    ser.close()
cv2.destroyAllWindows()

