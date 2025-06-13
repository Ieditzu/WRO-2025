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

![image](https://github.com/user-attachments/assets/ae65ed7d-a220-4b51-ac3c-c2f960def2b0) ![image](https://github.com/user-attachments/assets/6c25630d-5f6e-42e1-8558-7109089544ba) ![image](https://github.com/user-attachments/assets/055c4b82-7657-4c5f-8424-1b6494587704) ![image](https://github.com/user-attachments/assets/2fc4e58d-7893-4054-a242-433f2e4746f8) ![image](https://github.com/user-attachments/assets/9bdd0f77-bbfa-4852-8850-e6d1a5ece047) ![image](https://github.com/user-attachments/assets/1d437515-d427-4683-847c-d658b3240dd1)


 





---

---

## 🧠 Sensing and Perception

Our robot uses an HUSKYLENS camera connected to the ARDUINO MEGA 2560 for real-time image processing. Through all the libraries, the system identifies key visual cues on the racetrack, including color-coded lines and markers. Each color corresponds to a different behavior:

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

- HUSKYLENS Camera

(![image](https://github.com/user-attachments/assets/704d36e5-30b8-4164-8c7b-d786da3f6dbf)
)


- Servo Motor MG996

(![image](https://github.com/user-attachments/assets/a44398ef-df68-40bc-88f1-a2da52490220))


  
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
- Steering Servo – MG996  
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
- Battery: GH 18650 9900mAh 3.7v x3
- Camera: HUSKYLENS Camera
- Motor driver: L298N

---

## ⚡ Power Consumption Summary
| Component                | Voltage | Avg Current | Peak Current |
|--------------------------|---------|-------------|--------------|
| Arduino MEGA             | 5V      | 100 mA	     | 200 mA       |
| Motor Driver L298N       | 5V/12V  | 240mA       | 3.2A         |
| Steering Servo MG955     | 5V      | 500mA       | 2.5 A        |
| HUSKYLENS Camera         | 5V      | 500mA       | 600mA        |
| DC Metal Motor           | 2.5V→6V | 200 mA      | 600 mA       |
| Total Robot Usage Power  |         | 2.5-3A      | 7 A          |
---
## 💰 Cost Analysis
| Component                  | Qty | Unit Price | Total    |
|----------------------------|-----|------------|----------|
| Arduino MEGA               | 1   | $30        | $30      |
| Steering Servo (MG955)     | 1   | $5         | $5       |
| HUSKYLENS Camera           | 1   | $80.00     | $80.00   |
| GH 18650 9900mAh 3.7v x3   | 1   | $2         | $6       |
| DC Metal Motor             | 1   | $1.99      | $1.99    |
| L298N  Motor Driver        | 1   | $10        | $10      |
| **Total Components**       |     |            | $132.99  |
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
| **Grand Total**            |     |            | $151.99  |

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



## ⚡ Final Round

Our robot will use all the knowledge from the other rounds and will succesfully pass through it

---

## 🅿️ Starting from Parking

- Goes straight forward and then wait for serial communication betwen arduino and raspberry for it to turn

---

## 🅿️ Parking

The robot detects the nearby colors and adjusts itself so he could fit properly into the parking slot

---



**Camera Processing (Sample Code):**
```c++
#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

HUSKYLENS huskylens;
SoftwareSerial mySerial(10, 11); // RX, TX (Arduino <-> HuskyLens)

void setup() {
  Serial.begin(9600);       // Start serial monitor
  mySerial.begin(9600);     // Start serial communication with HuskyLens

  // Try connecting to HuskyLens until successful
  while (!huskylens.begin(mySerial)) {
    Serial.println(F("Failed to connect to HuskyLens. Check connections!"));
    delay(1000);
  }

  Serial.println(F("HuskyLens is connected!"));
}

void loop() {
  // Request data from HuskyLens
  if (!huskylens.request()) {
    Serial.println(F("Error requesting data"));
  } 
  // No object (color) detected
  else if (!huskylens.available()) {
    Serial.println(F("No color detected"));
  } 
  else {
    // Read detected result
    HUSKYLENSResult result = huskylens.read();

    if (result.command == COMMAND_RETURN_BLOCK) {
      int id = result.ID;
      String colorName;

      // Assign color name based on ID trained in HuskyLens
      switch(id) {
        case 1:
          colorName = "Red";
          break;
        case 2:
          colorName = "Yellow";
          break;
        case 3:
          colorName = "Green";
          break;
        case 4:
          colorName = "Blue";
          break;
        default:
          colorName = "Unknown color (ID " + String(id) + ")";
      }

      Serial.println("Detected color: " + colorName);
    }
  }

  delay(300); // Small delay to avoid flooding serial output
}

```
The full Arduino sketch enables color object detection using the HuskyLens AI camera and processes the results over serial communication.
It listens for objects recognized by the HuskyLens (in Color Recognition Mode) and identifies their IDs (each linked to a specific trained color: red, yellow, green, blue). 
Then it outputs those detections via the serial monitor.

