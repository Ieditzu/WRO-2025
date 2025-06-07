import cv2
import numpy as np
import time

# Start video capture (0 = USB webcam or Pi camera)
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        continue

    # Resize for faster processing
    frame = cv2.resize(frame, (320, 240))

    # Convert to HSV color space
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Color ranges in HSV
    color_ranges = {
        "Red": [
            (np.array([0, 120, 70]), np.array([10, 255, 255])),
            (np.array([170, 120, 70]), np.array([180, 255, 255]))
        ],
        "Green": [
            (np.array([36, 100, 100]), np.array([86, 255, 255]))
        ],
        "Blue": [
            (np.array([94, 80, 2]), np.array([126, 255, 255]))
        ]
    }

    detected_colors = []

    for color, ranges in color_ranges.items():
        # Combine all masks for each color
        mask = None
        for lower, upper in ranges:
            if mask is None:
                mask = cv2.inRange(hsv, lower, upper)
            else:
                mask |= cv2.inRange(hsv, lower, upper)

        # Find contours for the color
        contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        for cnt in contours:
            area = cv2.contourArea(cnt)
            if area > 500:
                detected_colors.append(color)
                break  # Only detect one object per color per frame

    # Output result
    if detected_colors:
        print("Detected:", ", ".join(detected_colors))
    else:
        print("No color detected")

    time.sleep(0.1)  # Slight delay to avoid high CPU usage

