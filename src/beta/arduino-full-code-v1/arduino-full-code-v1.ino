#include <Servo.h>

// ----------- SENZOR TCS3200 -------------

const int S0 = 2;
const int S1 = 3;
const int S2 = 4;
const int S3 = 5;
const int sensorOut = 48;

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

void setupColorSensor() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

// Măsoară frecvența pentru o culoare dată
int readColorComponent(int s2Val, int s3Val) {
  digitalWrite(S2, s2Val);
  digitalWrite(S3, s3Val);
  delay(50);
  return pulseIn(sensorOut, LOW);
}

void readColors() {
  redFrequency = readColorComponent(LOW, LOW);
  greenFrequency = readColorComponent(HIGH, HIGH);
  blueFrequency = readColorComponent(LOW, HIGH);
}

void detectAndSendColor() {
  readColors();

  // Condiții ajustabile în funcție de calibrare
  if (blueFrequency < 180 && redFrequency > 300 && greenFrequency > 250) {
    Serial.println('a');  // Albastru → viraj dreapta
  }
  else if (redFrequency < 180 && greenFrequency < 180 && blueFrequency > 300) {
    Serial.println('g');  // Galben → viraj stânga
  }
}

// ----------- CONTROL ROBOT -------------

const int MOTOR_IN1 = 7;
const int MOTOR_IN2 = 8;
const int MOTOR_ENA = 9;

const int SERVO_PIN = 10;
Servo steeringServo;

const int SERVO_LEFT   = 85;
const int SERVO_CENTER = 93;
const int SERVO_RIGHT  = 100;

const int MOTOR_SPEED = 250;

void motorForward() {
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENA, MOTOR_SPEED);
}

void motorStop() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENA, 0);
}

void servoLeft() {
  steeringServo.write(SERVO_LEFT);
}

void servoRight() {
  steeringServo.write(SERVO_RIGHT);
}

void servoCenter() {
  steeringServo.write(SERVO_CENTER);
}

void performBypassRight() {
  servoRight();
  motorForward();
  delay(800);
  servoLeft();
  delay(300);
  motorForward();
  delay(800);
  servoCenter();
  motorStop();
}

void performBypassLeft() {
  servoLeft();
  motorForward();
  delay(800);
  servoRight();
  delay(300);
  motorForward();
  delay(800);
  servoCenter();
  motorStop();
}

// ------------- SETUP & LOOP --------------

void setup() {
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_ENA, OUTPUT);

  Serial.begin(9600);
  steeringServo.attach(SERVO_PIN);
  servoCenter();
  motorStop();

  setupColorSensor();

  Serial.println("Setup complet.");
}

void loop() {
  detectAndSendColor();  // Senzor trimite comenzi seriale

  if (Serial.available()) {
    char command = Serial.read();
    switch (command) {
      case 'a':  // Albastru → ocolire dreapta
        performBypassRight();
        break;
      case 'g':  // Galben → ocolire stânga
        performBypassLeft();
        break;
      case 'c':  // Centru și înainte
        motorForward();
        servoCenter();
        break;
      case 'l':  // Stânga
        motorForward();
        servoLeft();
        break;
      case 'd':  // Dreapta
        motorForward();
        servoRight();
        break;
      case 's':  // Stop
        motorStop();
        break;
    }
  }
}
