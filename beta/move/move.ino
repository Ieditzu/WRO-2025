#include <Servo.h>

const int IN1 = 7;
const int IN2 = 8;
const int ENA = 9;

const int SERVO_PIN = 10;
Servo steeringServo;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  digitalWrite(ENA, HIGH);

  steeringServo.attach(SERVO_PIN);
  center();

  stop();
}

void loop() {
  left();
  delay(1000);

  digitalWrite(ENA, HIGH);

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
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, LOW);
}

void left() {
  steeringServo.write(60);
}

void right() {
  steeringServo.write(120);
}

void center() {
  steeringServo.write(90);
}