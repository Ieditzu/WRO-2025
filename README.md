WRO2025 Future Engineers – Pikart Repository of Pikart team competing in the World Robot Olympiad (WRO) 2025, Future Engineers category.

📚 Table of Contents 👥 The Team 🎯 Challenge Overview 🤖 Our Robot ⚙️ Mobility Management 🚗 Drivebase 🔧 Drivetrain ⚙️ Motor 🔄 Steering 🔄 Steering Servo Motor 🏎️ Chassis & Component Mounting ✨ Key Features & Advantages 🔧 Assembly Process 🛠️ Power and Sense Management 🔋 Li-Po Battery 🖥️ Arduino Mega 📷 Trust Camera ⚙️ Drive Motor ⚙️ Motor Driver L298N 🔄 Steering Servo MG955 🛠️ PCB Design ⚡ Power Consumption 📝 Obstacle Management 🏁 Open Round ⚡ Final Round 🅿️ Start from Parking 🅿️ Parking 📽️ Performance Videos 🔌 PCB Manufacturing Cost 🔩 Other Materials (Screws, Nuts, Miscellaneous) 📂 Resources 📜 License 📂 Folder Structure This repository is organized as follows:

📦 WRO-2025 
├── 📁 3D Models # Contains 3D design files for the robot's components
│ └── 📁 STL-models # 3D models in STL format 
├── 📁 electrical-schematics # Circuit diagrams and wiring
├── 📁 media # Images and videos │ 
│ └── 📁 robot-photos # Photos of the robot │ 
│ └── 📁 team-photos # Pictures of team members and teamwork 
│ └── 📁 video # Recorded testing 
├── 📁 other # Contains files that do not fit into other categories 
    ├── 📁 src # Main source code for the robot 
     └── 📄 README.md # Main documentation for the project
     👥 The Team

Popescu Curutchi Ciprian (Left Side) Age: 14

Middle School : Bogdan Petriceicu Hasdeu Middle School No. 12, Constanța

Description: Hi! I’m Ciprian from Romania, and this is my second WRO season. This is my first season in Future Engineers, as before I competed in Future Inovators category. I am passionate about robotics especially electronics and latest algorithms and tech. Over the years, I have worked on multiple robotics projects, mostly being line followers. Apart from robotics, I also enjoy volleyball,programming and chess.


Eduard Perjoc (Right Side) Age: 14 Middle School : Ion Jalea Middle School No. 12, Constanța


Description: Hi! I’m Eduard from Romania, and this is my third WRO season competing alongside Ciprian and Alin. I have participated in RoboMission multiple times, gaining valuable experience in solving various problems that may arise while building a robot. I have a strong interest in technology and robotics and am always eager to learn and experiment with new ideas.


Alin (Right Side) Age: 14 Middle School : Middle School division of Decebal Theoretical School, Constanța


Description: Hi! I’m Alin from Romania, and this is my second WRO season competing alongside Ciprian and Eduard. I have participated in RoboMission multiple times, gaining valuable experience in solving various problems that may arise while building a robot. I have a strong interest in technology and robotics and am always eager to learn and experiment with new ideas.


🎯 Challenge Overview The WRO 2025 Future Engineers challenge pushes teams to develop a fully autonomous vehicle capable of navigating a dynamic and randomized racetrack using sensors, computer vision, and advanced control algorithms. The goal is to complete multiple laps while adapting to randomized obstacles, following strict driving rules, and successfully executing a parallel parking maneuver at the end of the course.



📌 Competition Format 🏁 Open Challenge: The vehicle must complete three (3) laps on a track with randomly placed inside walls.


🚦 Obstacle Challenge: The vehicle must complete three (3) laps while detecting and responding to randomly placed red and green traffic signs:


🟥 Red markers → The vehicle must stay on the right side of the lane. 🟩 Green markers → The vehicle must stay on the left side of the lane. After completing the three laps, the vehicle must locate the designated parking zone and perform a precise parallel parking maneuver within a limited space, adding an extra layer of difficulty.


📑 Documentation: Each team must maintain a public GitHub repository showcasing their engineering process, vehicle design, and source code.


🏆 Scoring & Evaluation Scoring is based on accuracy, technical documentation and speed, rewarding teams that balance efficiency, adaptability, and innovation. This challenge not only tests robotics and programming skills but also promotes problem-solving, teamwork, and engineering creativity.


🔗 Find out more about the challenge here. 🚀


🤖 Our Robot


Top


Bottom


Left


Right


Front


Back


🚗 Mobility Management The robot's mobility is controlled through a fully 3D-printed chassis, a servo-based steering system. These components work together to ensure smooth, precise movement with optimized traction, stability, and efficient power management.


⚙️ Drivebase

⚙️ Motor – 30:1 Micro Metal Pololu Gearmotor HPCB Following past testing, we selected a high-power 30:1 Micro Metal Gearmotor (12V) for the drive system. This motor provides an optimal balance of speed and torque, allowing the robot to maintain stability while navigating turns.


Specifications
Model: 30:1 HPCB Voltage: 12V No-load Speed: 1000 RPM No-load Current: 120mA Stall Torque: ~0.4 kg·cm Stall Current: 1.6A 🔗 Buy Here Function: Drives the robot Why We Chose This Motor?


Gear ratio provides sufficient torque without sacrificing efficiency.
Compact and lightweight design, allowing integration into a lightweight robot.
🔌 Motor Driver – L298N To control the motor's speed and direction, we integrated a L298N motor driver into the PCB. This dual motor driver enables precise adjustments for acceleration, braking, and turning through PWM control.


Specifications
Model: TB6612FNG Operating Voltage: 2.5V – 13.5V PWM Frequency: Up to 100 kHz Max Continuous Current: 1.2A 🔗 Buy Here Function: Controls the drive motor 🔄 Steering The steering system is a critical part of the robot, ensuring precise maneuverability and smooth turns. Our design is based on a parallelogram steering mechanism, where both front wheels turn at the same angle through a single servo-controlled linkage. This setup provides predictable and stable steering, making it easy to use for an autonomous vehicle. Instead of using an Ackermann steering system, which requires more complex calculations and linkages, we opted for a simpler and more lightweight solution that offers consistent control. Our steering system allows for a maximum turning angle of 50 degrees in both the left and right directions. This range provides precise maneuverability, enabling the robot to navigate sharp turns efficiently while maintaining stability.


Our steering arm is directly connected to the servo, which moves the two front wheels simultaneously. This ensures that the turning response is immediate and proportional to the servo's motion. The wheels are mounted on special mounts, allowing for smooth and precise movement without excessive friction. To ensure structural integrity and long-term reliability, the steering system is assembled using 2mm carbon fiber bars that are glued at the ends to the chassis.

⚙️ Design Considerations and Improvements. While the parallelogram steering system is effective, some potential enhancements could improve its performance. Additionally, optimizing the motor mounts could reduce mechanical play, making the system more precise. In future iterations, we may experiment with Ackermann geometry and suspension to better distribute wheel angles during turns, further improving efficiency and reducing tire slippage.

🔄 Steering Servo – MG955 To control the steering system, we use an MG955 servo, known for its high torque and fast response. This servo enables quick and precise adjustments while maintaining a compact and lightweight design. Featuring metal gears, it ensures durability and reliability over extended use. The servo is securely mounted onto the chassis with two screws, and the steering arm is directly attached to its output shaft, providing smooth and efficient motion transfer for accurate steering.

Specifications
Model: MG955 Voltage: 5V Torque: 2.2kg/cm Signal Type: PWM Current Draw (Avg): 120mA Peak Current: 500mA Weight: ~13.4g Gears: Plastic 🔗 Buy Here Function: Controls steering 🏎️ Chassis & Component Mounting The chassis is the main structure of the robot, providing a stable and lightweight base for all components. Since this is our first year competing, we decided to skip Lego-based designs and go straight for a fully 3D-printed chassis. This allowed us to create a more compact, lightweight, and optimized structure.

The robot is driven by a single high-performance motor, which is connected to a Lego 5 gears differential. This setup allows reducing complexity while maintaining precise control over movement.

Key Features & Advantages

➜ Lightweight & Durable – The 3D-printed chassis ensures a strong lightweight structure, optimizing performance. ➜ Balanced Design – The battery is centrally placed, ensuring even weight distribution and stability. ➜ Easy Component Mounting – Pre-designed slots for motor, PCB, steering servo, and camera make assembly quick and efficient. ➜ Secure PCB Mounting – The PCB is attached using 4 screws, keeping it firmly in place. ➜ Organized Wiring & Cable Management 🔹 Integrated PCB routing eliminates unnecessary wiring, ensuring a cleaner and more reliable setup. 🔹 Hot glue secures servo and camera wires, preventing loose cables from interfering with movement.

🔧 Assembly Process

1️⃣ Attach the drive motor using its dedicated mounting bracket. 2️⃣ Secure the steering servo in its designated slot and secure it using to screws. 3️⃣ Place the battery in the center compartment to keep weight evenly distributed. 4️⃣ Use hot glue for cable management, keeping servo and camera wires in place.

			
🛠️ Power and Sense Management The robot's power and sensing system is designed for efficiency, precision, and adaptability. It consists of an Arduino MEGA, a Li-Po battery, MPU-6050 IMU, TRUST Camera, motors, all working together to ensure stable operation and accurate navigation.	
	
Each component has been carefully selected to provide optimal performance, minimize power consumption, and ensure reliability in competition environments.

🔋 Li-Po Battery – 3S 450mAh The Li-Po battery provides a compact, lightweight, and high-discharge power source, making it ideal for our robot. The 11.1V output is suitable for running our motors and voltage regulator, ensuring stable power delivery.

Specifications
Model: 3S Li-Po Capacity: 450mAh Voltage: 11.1V Discharge Rate: 25C Weight: 38g Size: 56.5 × 31 × 9mm Output Current: Varies by load Connector Type: JST 🔗 Buy Here Function: Powers the entire robot 🖥️ Arduino MEGA – Main Controller The Arduino Nano ESP32 provides high-speed processing, built-in Wi-Fi and Bluetooth, and extensive GPIO capabilities in a compact form factor. This allows it to handle sensor data, motor control, and vision processing efficiently.

Specifications
Microcontroller: ESP32 Flash Memory: 4MB SRAM: 520KB Frequency: 240MHz Pins: 22 Input Voltage: 5V Current Draw (Avg): 200mA Peak Current: 500mA 🔗 Buy Here Function: Controls all robot components 🧭 IMU Sensor – BMI088 The BMI088 IMU is used to measure the robot's angular velocity and acceleration, helping it maintain stability and precise movement control. It is essential for calculating turns and avoiding drift.

Specifications
Gyroscope Range: ±2000°/s Accelerometer Range: ±24g Interface: I2C / SPI Supply Voltage: 3.0V – 3.6V Current Draw: ~3.2mA Weight: ~1g 🔗 Buy Here Function: Tracks orientation & motion 📷 OpenMV H7 Camera – Vision Processing The OpenMV H7 Camera processes traffic signs, lane detection, and other visual cues in real-time. Unlike traditional cameras, it has a built-in microcontroller, reducing the processing load on the Arduino and allowing it to focus on movement control.

Specifications
Microcontroller: STM32H7 Flash Memory: 32MB RAM: 512KB Frequency: 480MHz Resolution: 640x480 Frame Rate: 60fps Current Draw (Avg): 300mA Peak Current: 400mA 🔗 Buy Here Function: Detects traffic signs & lanes ⚙️ Drive Motor – 30:1 Micro Metal Gearmotor HPCB 12V w/ Encoder The drive motor is responsible for propelling the robot forward. The 30:1 gearbox provides an excellent balance of speed and torque, while the built-in encoder allows for precise speed control.

Specifications
Type: Micro Metal Gearmotor Gear Ratio: 30:1 Voltage: 12V Encoder: Yes Current Draw (Avg): 120mA Peak Current: 1.6A Weight: ~10g Shaft Diameter: 3mm 🔗 Buy Here Function: Drives the robot ⚙️ Dual Motor Driver – TB6612FNG The TB6612FNG motor driver is used to control the robot’s two drive motors efficiently. It supports precise speed and direction control using PWM signals, making it ideal for differential drive robots. The TB6612FNG is directly integrated into our PCB, enabling smooth communication with the Arduino Nano ESP32.

Specifications
Model: TB6612FNG Operating Voltage: 2.5V – 13.5V Logic Voltage: 2.7V – 5.5V PWM Frequency: Up to 100 kHz Max Continuous Current: 1.2A per channel Max Peak Current: 3.2A per channel Number of Channels: 2 (Dual Motor Control) Built-in Protections: Thermal & Overcurrent 🔗 Buy Here Function: Controls drive motors 🔄 Steering Servo – MG955 The MG955 servo is used for precise steering control, enabling the robot to navigate turns with accuracy. It provides high torque output in a compact size.

Specifications
Model: MG955 Voltage: 5V Torque: 2.2kg/cm Signal Type: PWM Current Draw (Avg): 120mA Peak Current: 500mA Weight: ~13.4g Gears: Plastic 🔗 Buy Here Function: Controls steering 📏 Distance Sensor – JS40F IR Digital Sensor The JS40F Digital Infrared Sensor is used to detect obstacles or walls in front of the robot and is especially helpful at the start of the match for determining the lap direction when exiting the parking zone. Its fast digital response and reliable detection of black objects make it ideal for this task.

Specifications
Detection Range: 40–80 cm (depends on surface) Type: Reflective IR Digital Output Voltage Supply: 3.3V – 5V Current Draw: ~15mA Signal Type: Digital (0 = no object, 1 = object detected) Reverse Polarity Protection: Yes Dimensions: 17.7mm × 11.5mm × 12.6mm Weight: 4g (with cable) 🔗 Buy Here Use Case: Detects lap direction when starting from parking 🔌 L7805CV Voltage Regulator – Power Management The L7805CV regulates the 11.1V Li-Po battery output to a stable 5V, ensuring safe power delivery to the Arduino, sensors, and camera. It prevents overvoltage damage and includes thermal & short-circuit protection for reliability.

Specifications
Model: L7805CV Input Voltage: 7V – 35V Output Voltage: 5V Output Current: 1.5A Efficiency: Linear Regulator Dropout Voltage: ~2V Protection: Short-circuit & thermal shutdown Mounting Type: TO-220 Package 🔗 Buy Here Function: Converts battery voltage to 5V 🛠️ PCB Design Electrical Schematics PCB Design

⚡ Power Consumption Summary Component Voltage Avg Current Draw Peak Current Arduino Nano ESP32 5V 200mA 500mA Drive Motor (x2) 12V 240mA (120mA each) 3.2A (1.6A each) Steering Servo MG90S 5V 120mA 500mA OpenMV H7 Camera 3.3V/5V 300mA 400mA IMU Sensor BMI088 3.3V 3.2mA 4mA JS40F Distance Sensor 5V 15mA 20mA TB6612FNG Motor Driver 5V 50mA 100mA Voltage Regulator L7805CV 7.4V → 5V Power Management - Total Robot Power Usage Mixed ~1.4A (Avg) ~3.9A (Peak) 📝 Obstacle Management 🏁 Open Round During the Open Round, our robot follows a straight trajectory using a PID controller based on gyro yaw, ensuring stable movement. To determine turns, the camera detects Orange and Blue lines on the track:

Orange Line → Right Turn Blue Line → Left Turn The turn is executed when the robot reaches an approximativ distance from the front black wall. Camera Processing for Line Detection The camera captures frames in RGB565 format and processes color blobs using LAB thresholds to detect relevant track elements. Below is a snippet of the camera’s core logic that identifies track lines and determines turning direction:

Detect Blobs
red_blobs = img.find_blobs(red_threshold, roi=cubes_roi, pixels_threshold=min_cube_size, area_threshold=min_cube_size, merge=True) green_blobs = img.find_blobs(green_threshold, roi=cubes_roi, pixels_threshold=min_cube_size, area_threshold=min_cube_size, merge=True) blue_blobs = img.find_blobs(blue_threshold, roi=lines_roi, pixels_threshold=min_line_size, area_threshold=min_line_size, merge=True) orange_blobs = img.find_blobs(orange_threshold, roi=lines_roi, pixels_threshold=min_line_size, area_threshold=min_line_size, merge=True)

...

Determine Direction
if direction == 0: if orange_line and not is_invalid_orange(orange_line, red_blobs): direction = 2 # Orange line first → turn right elif blue_line: direction = 1 # Blue line first → turn left

Send Direction Command
uart.write(str(direction) + '\n')

⚡ Final Round To be completed – Overview of how the robot handles the final round challenges, including obstacle adaptation and speed adjustments.

🅿️ Starting from Parking To be completed – Explanation of how the robot starts from the parking slot.

🅿️ Parking To be completed – Explanation of how the robot identifies and executes the parallel parking maneuver at the end of the course.

📽️ Performance Videos 🔗 Click here to watch the video on YouTube

💰 Cost Analysis We have optimized our robot for performance vs. cost efficiency. The total cost includes motors, sensors, electronics, PCB, 3D printing and custom parts.

📦 Components Costs Component Quantity Unit Price (
)
T
o
t
a
l
(
) Arduino Nano ESP32 1 21.42 21.42 Drive Motor (30:1 HPCB) 1 22.45 22.45 Steering Servo (MG90S) 1 4.05 4.05 OpenMV H7 Camera 1 80.00 80.00 Gyroscope (BMI088) 1 8.50 8.50 JS40F Distance Sensor 1 12.50 12.50 LiPo Battery (3S 450mAh) 1 8.99 8.99 L7805CV Voltage Regulator 1 1.50 1.50 Lego Spike Wheels 4 1.64 6.56 Lego Differential 1 4.00 4.00 Experimental Parts -.-- -.-- TOTAL COMPONENT COST - - 169.97 Experimental Parts:

MPU6050 (*to be detailed) 🔌 PCB Cost (Manufactured via JLCPCB) PCB Component Quantity Unit Price (
)
T
o
t
a
l
(
) PCB Manufacturing (JLCPCB) 5 0.40 2.00 Connectors & Soldering - 3.50 3.50 TOTAL PCB COST - - 5.50 🖨️ 3D Printing Cost Breakdown 3D Printed Parts Quantity Unit Price (
)
T
o
t
a
l
(
) 1000g filament (PLA from Aliexpress) 1 10.00 10.00 TOTAL 3D PRINTING COST - - 10.00 🔩 Other Materials (Screws, Nuts, and Miscellaneous) Material Quantity Unit Price (
)
T
o
t
a
l
(
) M3 Screws & Nuts Set - 4.00 4.00 Wiring & Connectors - 5.00 5.00 TOTAL OTHER MATERIALS COST - - 9.00 💵 TOTAL Category Total Cost ($) Components 169.97 PCB (JLCPCB + Components) 5.50 3D Printing 10.00 Other Materials 9.00 TOTAL PROJECT COST 194.47 *Prices are approximate, based on current market prices.

📂 Resources Below is a list of external images used in this repository.

Arduino MEGA
TRUST Camera
Raspberry Pi 5
L298N Motor driver
MG955 Steering Servo 3S
450mAh Li-Po Battery

