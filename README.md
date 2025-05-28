
WRO 2025 Future Engineers – Pikart Team Repository
📚 Table of Contents
👥 The Team

🎯 Challenge Overview

🤖 Our Robot

🚗 Mobility Management

🛠️ Power and Sense Management

📝 Obstacle Management

📽️ Performance Videos

💰 Cost Analysis

📂 Resources

📜 License

👥 The Team
Name	Age	School	Description	Photo
Popescu Curutchi Ciprian (Left Side)	14	Bogdan Petriceicu Hasdeu Middle School No. 12, Constanța	Hi! I’m Ciprian from Romania, passionate about robotics, electronics, algorithms, and tech. This is my second WRO season, first in Future Engineers.	
Eduard Perjoc (Right Side)	14	Ion Jalea Middle School No. 12, Constanța	Hi! I’m Eduard, with 3 WRO seasons, experienced in RoboMission, interested in tech and robotics.	
Alin (Right Side)	14	Decebal Theoretical School Middle School, Constanța	Hi! I’m Alin, 2nd WRO season, passionate about robotics and eager to learn and experiment.	

🎯 Challenge Overview
The WRO 2025 Future Engineers challenge pushes teams to develop a fully autonomous vehicle capable of navigating a dynamic and randomized racetrack using sensors, computer vision, and advanced control algorithms. The goal is to complete multiple laps while adapting to randomized obstacles, following strict driving rules, and executing a parallel parking maneuver.

Open Challenge: Complete 3 laps on a track with randomized inside walls.

Obstacle Challenge: Detect and respond to red and green traffic signs:

🟥 Red markers → stay right

🟩 Green markers → stay left

Parking: Locate and perform a precise parallel parking maneuver at the end.

Scoring balances accuracy, documentation, speed, adaptability, and innovation.

🤖 Our Robot
[Add a few photos of your robot from different angles: front, back, left, right, top, bottom]




🚗 Mobility Management
The robot’s mobility is controlled through a fully 3D-printed chassis and servo-based steering system, ensuring smooth, precise movement with optimized traction and power.

⚙️ Drivebase
Motor: 30:1 Micro Metal Pololu Gearmotor HPCB

Motor Driver: L298N Motor Driver

Steering: Parallelogram steering system with MG955 servo

[Add detailed images of drivebase, motor mounts, and steering mechanism]



🛠️ Power and Sense Management
Controller: Arduino Nano ESP32

Battery: 3S 450mAh Li-Po

Sensors: MPU-6050 IMU, Trust Camera (OpenMV H7), JS40F IR Distance Sensor

Power Regulation: L7805CV Voltage Regulator

[Add images of PCB, wiring, battery, sensors mounted on chassis]




📝 Obstacle Management
Line detection and color blob detection using OpenMV H7 camera with LAB color space processing.

Turn signals: Orange line → right turn, Blue line → left turn.

The robot uses a PID controller with gyro yaw data for stable movement.

python
Copy
Edit
# Sample code snippet for line detection (from camera processing)
red_blobs = img.find_blobs(red_threshold, roi=cubes_roi, pixels_threshold=min_cube_size, area_threshold=min_cube_size, merge=True)
green_blobs = img.find_blobs(green_threshold, roi=cubes_roi, pixels_threshold=min_cube_size, area_threshold=min_cube_size, merge=True)
blue_blobs = img.find_blobs(blue_threshold, roi=lines_roi, pixels_threshold=min_line_size, area_threshold=min_line_size, merge=True)
orange_blobs = img.find_blobs(orange_threshold, roi=lines_roi, pixels_threshold=min_line_size, area_threshold=min_line_size, merge=True)

if direction == 0:
    if orange_line and not is_invalid_orange(orange_line, red_blobs):
        direction = 2  # Right turn
    elif blue_line:
        direction = 1  # Left turn

uart.write(str(direction) + '\n')
📽️ Performance Videos
Watch our robot in action here:


💰 Cost Analysis
Motors, sensors, electronics, PCB, 3D printing, and other parts optimized for performance and cost-efficiency.

📂 Resources
3D Models: 3D Models/STL-models/

Electrical Schematics: electrical-schematics/

Source Code: src/

Media: media/


