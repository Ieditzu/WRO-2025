#include <Servo.h>

// Motor driver pins
const int IN1 = 7;
const int IN2 = 8;
const int ENA = 9;  // Enable pin (PWM capable)

// Servo pin
const int SERVO_PIN = 10;
Servo steeringServo;

// Steering angles
#define STEERING_LEFT 60
#define STEERING_CENTER 90
#define STEERING_RIGHT 120

void setup() {
  // Motor setup
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Servo setup
  steeringServo.attach(SERVO_PIN);
  center();

  // Initially stop
  stop();
}

void loop() {
  // Demo movement pattern
  left();
  delay(1000);

  forward();
  delay(2000);

  right();
  delay(1000);

  stop();
  center();
  delay(2000);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 150);  // Adjust speed (0-255)
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 150);  // Adjust speed (0-255)
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}

void left() {
  steeringServo.write(STEERING_LEFT);
}

void right() {
  steeringServo.write(STEERING_RIGHT);
}

void center() {
  steeringServo.write(STEERING_CENTER);
}
