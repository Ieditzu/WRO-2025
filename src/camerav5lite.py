import cv2
import serial
import numpy as np
import time

# Open serial connection to Arduino
arduino = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
time.sleep(2)  # wait for Arduino to reset

# Start video capture (0 = default USB webcam; adjust if needed)
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        continue

    # Resize frame for faster processing
    frame = cv2.resize(frame, (320, 240))

    # Convert to HSV and filter for red color
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Define red color range (adjust if needed)
    lower_red = np.array([0, 120, 70])
    upper_red = np.array([10, 255, 255])
    mask1 = cv2.inRange(hsv, lower_red, upper_red)

    lower_red = np.array([170, 120, 70])
    upper_red = np.array([180, 255, 255])
    mask2 = cv2.inRange(hsv, lower_red, upper_red)

    mask = mask1 + mask2

    # Find contours
    contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # Send signal to Arduino if red object is detected
    if contours:
        largest = max(contours, key=cv2.contourArea)
        area = cv2.contourArea(largest)

        if area > 500:
            arduino.write(b'1')  # Send '1' to Arduino
            print("Red object detected - sent 1")
        else:
            arduino.write(b'0')
            print("No large red object - sent 0")
    else:
        arduino.write(b'0')
        print("No red detected - sent 0")

    time.sleep(0.1)  # Delay to avoid overloading the serial buffer

