import cv2
import numpy as np
import os
import time

# Resize terminal (macOS/Linux)
os.system("printf '\033[8;50;120t'")

ASCII_CHARS = "@%#*+=-:. "
WIDTH = 120
HEIGHT = 40

def rgb_to_ansi(r, g, b):
    return f"\033[38;2;{r};{g};{b}m"

def frame_to_colored_ascii(frame):
    frame = cv2.resize(frame, (WIDTH, HEIGHT))
    ascii_img = ""
    for row in frame:
        for b, g, r in row:
            gray = int(0.2989 * r + 0.5870 * g + 0.1140 * b)
            char = ASCII_CHARS[gray * len(ASCII_CHARS) // 256]
            ascii_img += rgb_to_ansi(r, g, b) + char
        ascii_img += "\n"
    return ascii_img + "\033[0m"

color_ranges = {
    "Red": [(np.array([0, 120, 70]), np.array([10, 255, 255])),
            (np.array([170, 120, 70]), np.array([180, 255, 255]))],
    "Green": [(np.array([35, 50, 70]), np.array([85, 255, 255]))],
    "Blue": [(np.array([90, 60, 70]), np.array([130, 255, 255]))]
}

def detect_color(hsv_frame):
    for color, ranges in color_ranges.items():
        mask = np.zeros(hsv_frame.shape[:2], dtype=np.uint8)
        for lower, upper in ranges:
            mask |= cv2.inRange(hsv_frame, lower, upper)
        contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        if any(cv2.contourArea(c) > 1000 for c in contours):
            return color
    return "None"

cap = cv2.VideoCapture(0)

try:
    while True:
        ret, frame = cap.read()
        if not ret:
            continue

        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        detected_color = detect_color(hsv)

        ascii_frame = frame_to_colored_ascii(frame)
        os.system("clear")
        print(ascii_frame)
        print(f"\033[1mDetected Color:\033[0m {detected_color}")
        time.sleep(0.05)

except KeyboardInterrupt:
    pass
finally:
    cap.release()
    os.system("clear")

