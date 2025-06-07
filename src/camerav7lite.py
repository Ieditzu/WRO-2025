import cv2
import numpy as np
import os
import time
import serial

# Serial setup (adjust the port!)
ser = serial.Serial('/dev/ttyUSB0', 9600)
time.sleep(2)

# Resize terminal
os.system("printf '\033[8;50;120t'")

ASCII_CHARS = "@%#*+=-:. "
WIDTH = 120
HEIGHT = 40

# Only Red and Green ranges
color_ranges = {
    "Red": [(np.array([0, 120, 70]), np.array([10, 255, 255])),
            (np.array([170, 120, 70]), np.array([180, 255, 255]))],
    "Green": [(np.array([35, 50, 70]), np.array([85, 255, 255]))]
}

color_codes = {"Red": b'R', "Green": b'G', "None": b'N'}
prev_color = None

def rgb_to_ansi(r, g, b):
    return f"\033[38;2;{r};{g};{b}m"

def frame_to_colored_ascii(frame):
    resized = cv2.resize(frame, (WIDTH, HEIGHT))
    hsv = cv2.cvtColor(resized, cv2.COLOR_BGR2HSV)
    ascii_img = ""

    for y in range(resized.shape[0]):
        for x in range(resized.shape[1]):
            b, g, r = resized[y, x]
            h, s, v = hsv[y, x]
            gray = int(0.2989 * r + 0.5870 * g + 0.1140 * b)
            char = ASCII_CHARS[gray * len(ASCII_CHARS) // 256]

            color = "Unknown"
            for name, ranges in color_ranges.items():
                for lower, upper in ranges:
                    if cv2.inRange(np.uint8([[hsv[y, x]]]), lower, upper)[0][0] > 0:
                        color = name
                        break
                if color != "Unknown":
                    break

            if color in color_codes:
                ansi = rgb_to_ansi(r, g, b)
            else:
                ansi = "\033[38;2;255;255;255m"  # white for unknown

            ascii_img += ansi + char
        ascii_img += "\n"

    return ascii_img + "\033[0m"

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

        if detected_color != prev_color:
            ser.write(color_codes[detected_color])
            prev_color = detected_color

        ascii_frame = frame_to_colored_ascii(frame)
        os.system("clear")
        print(ascii_frame)
        print(f"\033[1mDetected Color:\033[0m {detected_color}")

except KeyboardInterrupt:
    pass
finally:
    cap.release()
    ser.close()
    os.system("clear")

