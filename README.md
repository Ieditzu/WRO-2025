# WRO2025 Future Engineers – Pikart

Repository of the Pikart team competing in the World Robot Olympiad (WRO) 2025, Future Engineers category.

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

![WhatsApp Image 2025-05-28 at 21 54 13 (2)](https://github.com/user-attachments/assets/a2e389d9-ec24-4b05-b2e2-f3c3344d13e9)


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

## ⚙️ Components

- TRUST Camera

 ![image](https://github.com/user-attachments/assets/0d6c8091-42e9-4095-aba0-a974adb96e93)


- Servo Motor MG955

 ![image](https://github.com/user-attachments/assets/11d42a7f-64f2-4038-b62e-221c5efcb710)

  
- Arduino MEGA

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
- Cable Management: Integrated PCB routing, hot glue for wire security.  

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
| Arduino MEGA             | 5V      | 100 mA	     | 200 mA       |
| Motor Driver L298N       | 5V/12V  | 240mA       | 3.2A         |
| Steering Servo MG955     | 5V      | 500mA       | 2.5 A        |
| TRUST Camera             | 5V      | 300mA       | 400mA        |
| Raspberry Pi 5           | 5V      | 1.5–3A      | 5A           |
| DC Metal Motor           | 2.5V→6V | 200 mA      | 600 mA       |

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
