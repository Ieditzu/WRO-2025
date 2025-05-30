# WRO2025 Future Engineers – Pikart

Repository of the Pikart team competing in the World Robot Olympiad (WRO) 2025, Future Engineers category.

This document describes the engineering process, components, sensing system, and control logic behind our autonomous vehicle for WRO 2025 Future Engineers. It includes technical specs, power usage, software architecture, and deployment instructions.

---

## 📚 Table of Contents

- The Team
- Challenge Overview
- Our Robot
- Mobility Management
- Components
- Motor & Motor Driver
- Steering & Servo
- Chassis & Component Mounting
- Assembly Process
- Power and Sense Management
- Obstacle Management
- Cost Analysis
- Folder Structure


---

## 👥 The Team

**Curutchi Ciprian**  
*Age*: 14  
*School*: Bogdan Petriceicu Hasdeu Middle School No. 12, Constanța  
Hi! I’m Ciprian from Romania, and this is my second WRO season. This is my first season in Future Engineers, previously competing in Future Innovators.I am passionate about robotics, electronics, algorithms, and technology.My interests also include volleyball, programming, and gaming .


![csm-constanta-minivolei-turneu-tulcea-2024-49 (1) (1)](https://github.com/user-attachments/assets/bfb10549-500d-4ea1-ae3e-566cc2811c6b)


---

**Perjoc Eduard**  
*Age*: 14  
*School*: Ion Jalea Middle School No. 24, Constanța  
Hi! I’m Eduard from Romania, and this is my second WRO season with Ciprian and Alin. I have participated in Future Innovators multiple times, gaining valuable experience in robotics and problem-solving.

![WhatsApp Image 2025-05-28 at 21 54 13 (2)](https://github.com/user-attachments/assets/a2e389d9-ec24-4b05-b2e2-f3c3344d13e9)


---

**Pârvu Alin**  
*Age*: 14  
*School*: Decebal Theoretical School, Constanța  
Hi! I’m Alin from Romania, and this is my second WRO season with Ciprian and Eduard. I am passionate about technology, robotics, and hands-on experimentation.

![image](https://github.com/user-attachments/assets/c554b07e-b1a7-4924-b182-03efca5e6113)

## 📦 Folder Structure

```
WRO-2025
├── 3D                     # 3D design files (STL format)
├── electrical-schematics/ # Circuit diagrams and wiring
├── media/
│   ├── robot-photos/      # Robot photos
│   ├── team-photos/       # Team photos
│   └── video/             # Recorded testing
├── other/                 # Miscellaneous files
├── src/                   # Main robot source code
└── README.md              # Main documentation
```
---

## 🎯 Challenge Overview

The WRO 2025 Future Engineers challenge tasks teams with developing a fully autonomous vehicle capable of navigating a dynamic, randomized racetrack using sensors, computer vision, and advanced control algorithms.

**Key objectives:**
- Complete multiple laps while adapting to randomized obstacles and following driving rules.
- Successfully execute a parallel parking maneuver at the end.

---

### 📌 Competition Format

**🏁 Open Challenge:**  
Complete 3 laps on a track with randomly placed inside walls.

**🚦 Obstacle Challenge:**  

Detect and respond to red and green traffic signs while completing 3 laps:  
- 🟥 Red traffic sign: Stay on the right side.
- 🟩 Green traffic sign: Stay on the left side.
- Using color detection to read the traffic signs
- The steering logic adjust to the lane based on the detected color
- This process is performed in real-time using the camera and Raspberry Pi
  
**🅿️ Parking:**
Locate and perform a precise parallel parking maneuver after laps.

---

### 📑 Documentation Requirement

Maintain a public GitHub repository showcasing engineering process, vehicle design, and code.

---

### 🏆 Scoring & Evaluation

Based on accuracy, technical documentation, speed, innovation, and teamwork.

---

## 🤖 Our Robot

---

---

## 🧠 Sensing and Perception

Our robot uses a TRUST USB camera connected to the Raspberry Pi 5 for real-time image processing. Through all the libraries, the system identifies key visual cues on the racetrack, including color-coded lines and markers. Each color corresponds to a different behavior:

- 🟦 Blue line: Indicates a left turn
- 🟧 Orange line: Indicates a right turn
- 🟥 Red sign: Indicates "stay on the right"
- 🟩 Green sign: Indicates "stay on the left"

The largest contour of the detected color is extracted and analyzed to determine the robot’s steering direction. This visual input is processed continuously while the robot is in motion, allowing for real-time decision-making and adaptive path planning.

---

## 🚗 Mobility Management

- Fully 3D-printed chassis
- Servo-based steering system for smooth, precise movement

---

## ⚙️ Components

- TRUST Camera

 ![image](https://github.com/user-attachments/assets/0d6c8091-42e9-4095-aba0-a974adb96e93)


- Servo Motor MG955

 ![image](https://github.com/user-attachments/assets/11d42a7f-64f2-4038-b62e-221c5efcb710)

  
- Arduino MEGA 2560

 ![image](https://github.com/user-attachments/assets/7280ac78-b58e-419f-834f-f0dbf24b9b35)
  
- Raspberry Pi 5
 
 ![image](https://github.com/user-attachments/assets/30ba5574-37bf-44aa-8b50-c0e504fc640a)
 
- Motor Driver – L298N
  
 ![image](https://github.com/user-attachments/assets/153e4217-f7d3-4cfc-8475-6489bd2b2e20)

- DC Metal Motor Without Gearbox

 ![image](https://github.com/user-attachments/assets/5748d149-668b-471b-8bea-d9ee378fbbc4)


- Operating Voltage: 5V-12V


---

## 🔄 Steering & Servo

- Parallelogram Steering Mechanism  
- Both front wheels turn at the same angle for stability and precision.  
- Direct servo linkage for immediate response.  
- Steering Servo – MG955  
- Voltage: 5V  
- Torque: 2.2 kg/cm  
- Gears: Metal  

---

## 🏎️ Chassis & Component Mounting

- 3D-Printed Chassis: Lightweight, strong, and optimized design.  
- Component Placement: Pre-designed slots for motors, PCB, servo, and camera.  
- Balanced Design: Central battery placement for stability.  
- Cable Management: Hot glue for wire security.  

---

## 🔧 Assembly Process

1. Mount drive motor using bracket.
2. Secure steering servo in slot with screws.
3. Place battery in center compartment.
4. Use hot glue for cable management.

---

## 🛠️ Power and Sense Management

- Controller: Arduino MEGA
- Battery: Li-Po 3S 450mAh (11.1V)  
- Camera: TRUST Camera
- 2nd Controller: Raspberry Pi 5
- Motor driver: L298N

---

## ⚡ Power Consumption Summary
| Component                | Voltage | Avg Current | Peak Current |
|--------------------------|---------|-------------|--------------|
| Arduino MEGA             | 5V      | 100 mA	   | 200 mA       |
| Motor Driver L298N       | 5V/12V  | 240mA       | 3.2A         |
| Steering Servo MG955     | 5V      | 500mA       | 2.5 A        |
| TRUST Camera             | 5V      | 300mA       | 400mA        |
| Raspberry Pi 5           | 5V      | 2.5–3A      | 5A           |
| DC Metal Motor           | 2.5V→6V | 200 mA      | 600 mA       |
| Total Robot Usage Power  |         | 4.5–5 A     | 9 A          |
---
## 💰 Cost Analysis
| Component                  | Qty | Unit Price | Total    |
|----------------------------|-----|------------|----------|
| Arduino MEGA               | 1   | $30        | $30      |
| Raspberry Pi 5             | 1   | $80        | $80      |
| Steering Servo (MG955)     | 1   | $5         | $5       |
| TRUST Camera               | 1   | $10.00     | $10.00   |
| LiPo Battery (3S 450mAh)   | 1   | $8.99      | $8.99    |
| DC Metal Motor             | 1   | $1.99      | $1.99    |
| L298N  Motor Driver        | 1   | $10        | $10      |
| **Total Components**       |     |            | $145.98  |
|                            |     |            |          |
| **3D Printing Cost**       |     |            |          |
| Filament (1000g, PLA)      |     |            | $10.00   |
| **Total 3D Printing Cost** |     |            | $10.00   |
|                            |     |            |          |
| **Other Materials**        |     |            |          |
| M3 Screws & Nuts Set       |     |            | $4.00    |
| Wiring & Connectors        |     |            | $5.00    |
| **Total Other Materials**  |     |            | $9.00    |
|                            |     |            |          |
| **Grand Total**            |     |            | $164.98  |

*Prices are approximate, based on current market rates.*

---

## 📝 Obstacle Management

Obstacle Challenge Handling

In the Obstacle Challenge round, the robot uses the same camera vision system to interpret traffic signs placed along the track. These signs are randomly positioned and determine lane behavior:

- **Red traffic marker** (🟥): Robot must keep to the **right** side of the lane.
- **Green traffic marker** (🟩): Robot must keep to the **left** side of the lane.

Upon detecting one of these signs using HSV color thresholds, the robot shifts its path accordingly using a PID steering controller. The logic is implemented entirely onboard using the Raspberry Pi 5, ensuring responsive behavior without delay.

### 🏁 Open Round

- Straight trajectory using PID controller (gyro yaw)  
- Camera detects Orange (right turn) and Blue (left turn) lines

  ---

## 📽️ Performance Videos

Watch our robot in action on YouTube!

---


## 🛠️ Code Deployment Instructions

### ✅ Uploading Arduino Code
1. Open the Arduino IDE.
2. Connect the Arduino MEGA via USB.
3. Open the `.ino` file located in `src/move/`.
4. Select **Board**: Arduino Mega 2560.
5. Select the correct **COM port**.
6. Click **Upload**.

### ✅ Running Raspberry Pi Code
1. Power the Raspberry Pi 5 and ensure the camera is connected.
2. Open a terminal.
3. Run the main Python vision script:

```bash
python3 camerav4.py
TODO
```

### ✅ Python Requirements for Raspberry Pi

Make sure your Pi has Python 3 and pip installed. Then run:

```bash
sudo apt update
sudo apt install python3-pip -y
pip3 install pyserial opencv-python
```

This installs:

- `opencv-python` → for camera and image processing
- `pyserial` → for communication with the Arduino

---

## ⚡ Final Round

_To be completed – How the robot handles the final round challenges._

---

## 🅿️ Starting from Parking

- Goes straight forward and then wait for serial communication betwen arduino and raspberry for it to turn

---

## 🅿️ Parking

_To be completed – How the robot executes parallel parking._

---



**Camera Processing (Sample Code):**
```python
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

```
The full part of the code uses computer vision to detect colored objects in a video stream and sends corresponding signals to an Arduino via serial communication. 
It defines color thresholds, sets up serial, and processes each frame to detect and label objects, sending codes to the Arduino for new detections.
The script imports libraries, sets up serial, and enters a loop to process frames. It converts to HSV, creates masks, finds contours, and draws rectangles around large enough objects, sending codes to the Arduino.


