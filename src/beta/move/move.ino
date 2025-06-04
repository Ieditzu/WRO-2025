#include <Servo.h>

// Motor driver pins (L298N)
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

  Serial.begin(9600);

  // Servo setup
  steeringServo.attach(SERVO_PIN);
  center();

  stop();
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    switch (command) {
      case 'g':
        forward();
        break;
      case 'r':
        ocolireDreapta(); // când primește 'r', face ocolirea
        break;
      default:
        forward();  
    }
  }

  delay(100);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 250);  // Ajustează viteza
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 250);
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

void ocolireDreapta() {
  right();
  forward();
  delay(800);

  left();
  delay(300);

  forward();
  delay(800);

  center();
  stop();
}

void ocolireStanga() {
  left();
  forward();
  delay(800);

  right();
  delay(300);

  forward();
  delay(800);

  center();
  stop();
}
