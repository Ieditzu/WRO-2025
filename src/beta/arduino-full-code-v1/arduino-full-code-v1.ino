#include <HUSKYLENS.h>         // Include HuskyLens library
#include <SoftwareSerial.h>    // For software-based serial communication
#include <Servo.h>             // For steering control via servo motor

// Create HuskyLens object
HUSKYLENS huskylens;
// Use digital pins 2 and 3 for SoftwareSerial communication
SoftwareSerial mySerial(2, 3); // RX = 2, TX = 3

// Create servo object for steering
Servo steeringServo;

// Motor control pins (adjust based on your wiring)
const int MOTOR_IN1 = 7;
const int MOTOR_IN2 = 8;
const int MOTOR_ENA = 9;      // PWM for speed control
const int SERVO_PIN = 10;      // Steering servo pin

// Define servo angles for steering
const int SERVO_LEFT   = 85;  // Turn left
const int SERVO_CENTER = 93;  // Go straight
const int SERVO_RIGHT  = 100; // Turn right

// Define motor speed (0–255)
const int MOTOR_SPEED = 255;

// Cooldown mechanism to avoid double detections
unsigned long lastTurnTime = 0;
const unsigned long cooldown = 4000; // milliseconds to ignore new detections

// Moves robot forward
void motorForward() {
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENA, MOTOR_SPEED);
}

// Stops the robot
void motorStop() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENA, 0);
}

// Steering helper functions
void servoLeft() {
  steeringServo.write(SERVO_LEFT);
}

void servoRight() {
  steeringServo.write(SERVO_RIGHT);
}

void servoCenter() {
  steeringServo.write(SERVO_CENTER);
}

// Sequence for bypassing obstacle to the RIGHT (for red color)
void performBypassRight() {
  servoRight();
  motorForward();
  delay(800);         // Move right
  servoLeft();
  delay(400);         // Curve left
  motorForward();
  delay(800);         // Return to path
  servoCenter();
  motorStop();
}

// Sequence for bypassing obstacle to the LEFT (for green color)
void performBypassLeft() {
  servoLeft();
  motorForward();
  delay(800);         // Move left
  servoRight();
  delay(400);         // Curve right
  motorForward();
  delay(800);         // Return to path
  servoCenter();
  motorStop();
}

void setup() {
  // Configure motor control pins as outputs
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_ENA, OUTPUT);

  // Attach servo to its pin
  steeringServo.attach(SERVO_PIN);
  servoCenter();    // Default position
  motorStop();      // Stop at startup

  // Start serial communication
  Serial.begin(9600);      // Debug port (USB)
  mySerial.begin(9600);    // HuskyLens communication

  // Start communication with HuskyLens
  huskylens.begin(mySerial);

  // Check if HuskyLens responds
  if (!huskylens.requestKnock()) {
    Serial.println("HuskyLens not detected!");
  } else {
    Serial.println("HuskyLens connected!");
  }
}

void loop() {
  // Skip color detection if in cooldown period
  if (millis() - lastTurnTime < cooldown) {
    return;
  }

  // Ask HuskyLens for data
  if (!huskylens.request()) return;

  // Read detection result
  HUSKYLENSResult result = huskylens.read();

  // If something was detected
  if (result.command == COMMAND_RETURN_BLOCK) {
    int colorID = result.ID; // HuskyLens assigns unique ID to each color

    // Execute command based on color ID
    switch (colorID) {
      case 1: // Blue detected: right turn
        servoRight();
        motorForward();
        delay(600);       // Move slightly right
        servoCenter();
        motorStop();
        lastTurnTime = millis(); // Start cooldown
        break;

      case 2: // Yellow detected: left turn
        servoLeft();
        motorForward();
        delay(600);       // Move slightly left
        servoCenter();
        motorStop();
        lastTurnTime = millis(); // Start cooldown
        break;

      case 3: // Red detected: obstacle – bypass to right
        performBypassRight();
        lastTurnTime = millis(); // Start cooldown
        break;

      case 4: // Green detected: obstacle – bypass to left
        performBypassLeft();
        lastTurnTime = millis(); // Start cooldown
        break;
    }
  }
}
