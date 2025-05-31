import cv2
import numpy as np

color_thresholds = {
    'yellow': [(20, 100, 100), (30, 255, 255)],
    'red':    [(0, 120, 70), (10, 255, 255), (170, 120, 70), (180, 255, 255)],
    'green':  [(36, 50, 50), (89, 255, 255)],
    'blue':   [(90, 50, 50), (140, 255, 255)]
}

REAL_WIDTH_CM = 3.0
FOCAL_LENGTH = 1000  # Set this using calibration
DISTANCE_THRESHOLD_CM = 45

cap = cv2.VideoCapture(0)
sent_turn_signal = False

def find_largest_contour(mask):
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if contours:
        return max(contours, key=cv2.contourArea)
    return None

while True:
    ret, frame = cap.read()
    if not ret:
        break

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(hsv, np.array(color_thresholds['yellow'][0]), np.array(color_thresholds['yellow'][1]))

    largest_contour = find_largest_contour(mask)

    if largest_contour is not None and cv2.contourArea(largest_contour) > 800:
        x, y, w, h = cv2.boundingRect(largest_contour)
        distance_cm = (REAL_WIDTH_CM * FOCAL_LENGTH) / w
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 255), 2)
        cv2.putText(frame, f"YELLOW {distance_cm:.1f}cm", (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 255), 2)

        if distance_cm < DISTANCE_THRESHOLD_CM and not sent_turn_signal:
            print("TURN RIGHT")
            sent_turn_signal = True
        elif distance_cm >= DISTANCE_THRESHOLD_CM:
            sent_turn_signal = False

    cv2.imshow('Webcam', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()