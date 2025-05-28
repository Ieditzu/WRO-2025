# WRO2025 Future Engineers – Pikart

Repository of the Pikart team competing in the World Robot Olympiad (WRO) 2025, Future Engineers category.

---

## 📚 Table of Contents

- The Team
- Challenge Overview
- Our Robot
- Mobility Management
- Drivebase
- Motor & Motor Driver
- Steering & Servo
- Chassis & Component Mounting
- Assembly Process
- Power and Sense Management
- Obstacle Management
- Cost Analysis
- Resources
- Folder Structure
- License

---

## 👥 The Team

**Curutchi Ciprian**  
*Age*: 14  
*School*: Bogdan Petriceicu Hasdeu Middle School No. 12, Constanța  
Hi! I’m Ciprian from Romania, and this is my second WRO season. This is my first season in Future Engineers, previously competing in Future Innovators.I am passionate about robotics, electronics, algorithms, and technology.My interests also include volleyball, programming, and gaming .

![csm-constagasnta-grup](https://github.com/user-attachments/assets/d1d51696-4f31-47f5-995c-56bd7958575c)

---

**Eduard Perjoc**  
*Age*: 14  
*School*: Ion Jalea Middle School No. 12, Constanța  
Hi! I’m Eduard from Romania, and this is my third WRO season with Ciprian and Alin. I have participated in RoboMission multiple times, gaining valuable experience in robotics and problem-solving.

---

**Alin Parvu**  
*Age*: 14  
*School*: Decebal Theoretical School, Constanța  
Hi! I’m Alin from Romania, and this is my second WRO season with Ciprian and Eduard. I am passionate about technology, robotics, and hands-on experimentation.

## 📦 Folder Structure

```
WRO-2025
├── 3D Models/         # 3D design files (STL format)
├── electrical-schematics/ # Circuit diagrams and wiring
├── media/
│   ├── robot-photos/  # Robot photos
│   ├── team-photos/   # Team photos
│   └── video/         # Recorded testing
├── other/             # Miscellaneous files
├── src/               # Main robot source code
└── README.md          # Main documentation
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
- 🟥 Red marker: Stay on the right side.
- 🟩 Green marker: Stay on the left side.

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

## 🚗 Mobility Management

- Fully 3D-printed chassis
- Servo-based steering system for smooth, precise movement

---

## ⚙️ Drivebase

- Motor – 30:1 Micro Metal Pololu Gearmotor HPCB
- Voltage: 12V  
- No-load Speed: 1000 RPM  
- Stall Torque: ~0.4 kg·cm  
- Motor Driver – L298N  
- Model: TB6612FNG  
- Operating Voltage: 2.5V–13.5V  
- PWM Frequency: Up to 100 kHz  

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
- Cable Management: Integrated PCB routing, hot glue for wire security.  

---

## 🔧 Assembly Process

1. Mount drive motor using bracket.
2. Secure steering servo in slot with screws.
3. Place battery in center compartment.
4. Use hot glue for cable management.

---

## 🛠️ Power and Sense Management

- Controller: Arduino Nano ESP32  
- Battery: Li-Po 3S 450mAh (11.1V)  
- IMU: BMI088 for motion and stability  
- Camera: OpenMV H7 for real-time vision processing  
- Distance Sensor: JS40F IR for obstacle detection  
- Voltage Regulator: L7805CV for stable 5V output  

---

## ⚡ Power Consumption Summary

| Component                | Voltage | Avg Current | Peak Current |
|--------------------------|---------|-------------|--------------|
| Arduino Nano ESP32       | 5V      | 200mA       | 500mA        |
| Drive Motor (x2)         | 12V     | 240mA       | 3.2A         |
| Steering Servo MG90S     | 5V      | 120mA       | 500mA        |
| OpenMV H7 Camera         | 3.3V/5V | 300mA       | 400mA        |
| IMU Sensor BMI088        | 3.3V    | 3.2mA       | 4mA          |
| JS40F Distance Sensor    | 5V      | 15mA        | 20mA         |
| TB6612FNG Motor Driver   | 5V      | 50mA        | 100mA        |
| Voltage Regulator        | 7.4V→5V | -           | -            |

---
## 💰 Cost Analysis

| Component                  | Qty | Unit Price | Total    |
|----------------------------|-----|------------|----------|
| Arduino MEGA               | 1   | $21.42     | $21.42   |
| Raspberry Pi 5             | 1   | $22.45     | $22.45   |
| Steering Servo (MG955)     | 1   | $4.05      | $4.05    |
| TRUST Camera               | 1   | $80.00     | $80.00   |
| LiPo Battery (3S 450mAh)   | 1   | $8.99      | $8.99    |
| L298N  Motor Driver        | 1   | $1.50      | $1.50    |
| **Total Components**       |     |            | $169.97  |
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
| **Grand Total**            |     |            | $194.47  |

*Prices are approximate, based on current market rates.*

## 📝 Obstacle Management

### 🏁 Open Round

- Straight trajectory using PID controller (gyro yaw)  
- Camera detects Orange (right turn) and Blue (left turn) lines

  ---

## 📽️ Performance Videos

Watch our robot in action on YouTube!

---

## ⚡ Final Round

_To be completed – How the robot handles the final round challenges._

---

## 🅿️ Starting from Parking

_To be completed – How the robot starts from the parking slot._

---

## 🅿️ Parking

_To be completed – How the robot executes parallel parking._

---

**Camera Processing (Sample Code):**
```python
# Detect Blobs
red_blobs = img.find_blobs(red_threshold, ...)
green_blobs = img.find_blobs(green_threshold, ...)
blue_blobs = img.find_blobs(blue_threshold, ...)
orange_blobs = img.find_blobs(orange_threshold, ...)
# Determine Direction
if direction == 0:
    if orange_line and not is_invalid_orange(orange_line, red_blobs):
        direction = 2  # Orange line → right turn
    elif blue_line:
        direction = 1  # Blue line → left turn
# Send Direction Command
uart.write(str(direction) + '\n')
