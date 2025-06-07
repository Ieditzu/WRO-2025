#include <Servo.h>

// ---------------------------
// Configurare pini & constante
// ---------------------------

// Pini pentru driverul motor (L298N)
const int MOTOR_IN1 = 7;       // Pin pentru direcție
const int MOTOR_IN2 = 8;       // Pin pentru direcție
const int MOTOR_ENA = 9;       // Pin PWM pentru controlul vitezei

// Pini pentru servo
const int SERVO_PIN = 10;      // Pinul pe care este conectat servo motorul
Servo steeringServo;           // Obiectul servo

// Poziții calibrate pentru servo (în grade)
const int SERVO_LEFT   = 85;   // Poziție pentru viraj stânga
const int SERVO_CENTER = 93;   // Poziție centrală (dreapta înainte)
const int SERVO_RIGHT  = 100;  // Poziție pentru viraj dreapta

// Viteză pentru motor (valori între 0 și 255)
const int MOTOR_SPEED = 250;   

// ---------------------------
// Prototipuri de funcții
// ---------------------------
void motorForward();
void motorStop();
void servoLeft();
void servoRight();
void servoCenter();
void performBypassRight();
void performBypassLeft();

// ---------------------------
// Funcția de set-up
// ---------------------------
void setup() {
  // Configurează pinii motorului ca ieșiri
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_ENA, OUTPUT);
  
  // Inițializează comunicarea serială pentru recepționarea comenzilor
  Serial.begin(9600);
  
  // Atașează servo și setează poziția inițială
  steeringServo.attach(SERVO_PIN);
  servoCenter();  // Setați servo la poziția centrală
  motorStop();    // Oprește motorul

  Serial.println("Setup complet. Aștept comenzi de la cameră...");
}

// ---------------------------
// Funcția loop
// ---------------------------
void loop() {
  // Verifică dacă sunt date seriale disponibile
  if (Serial.available() > 0) {
    char command = Serial.read();  // Citește un caracter de pe serial
    Serial.print("Comandă primită: ");
    Serial.println(command);
    
    // Interpretează comanda primită
    switch (command) {
      case 'c':  // Avans înainte cu servo centrat TODO
        motorForward();
        servoCenter();
        break;
        
      case 's':  // Oprește motorul TODO
        motorStop();
        break;
        
      case 'l':  // Virare stânga: motor înainte + servo la stânga TODO
        motorForward();
        servoLeft();
        break;
        
      case 'd':  // Virare dreapta: motor înainte + servo la dreapta TODO
        motorForward();
        servoRight();
        break;
        
      case 'r':  // Manevră de ocolire spre dreapta
        performBypassRight();
        break;
        
      case 'g':  // Manevră de ocolire spre stânga
        performBypassLeft();
        break;
        
      default:
        motorForward();
        break;
    }
  }
  // Fără delay pentru a păstra codul reactiv
}

// ---------------------------
// Funcții pentru controlul motorului
// ---------------------------

// Pornește motorul înainte la viteza definită
void motorForward() {
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENA, MOTOR_SPEED);
}

// Oprește motorul
void motorStop() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENA, 0);
}

// ---------------------------
// Funcții pentru controlul servo motorului
// ---------------------------

// Mută servo în poziția de virare stânga
void servoLeft() {
  steeringServo.write(SERVO_LEFT);
}

// Mută servo în poziția de virare dreapta
void servoRight() {
  steeringServo.write(SERVO_RIGHT);
}

// Centrează servo-ul
void servoCenter() {
  steeringServo.write(SERVO_CENTER);
}

// ---------------------------
// Funcții pentru manevre complexe (ocoliri)
// ---------------------------

// Manevră de ocolire spre dreapta
void performBypassRight() {
  servoRight();
  motorForward();
  delay(800);  // Păstrează schimbarea direcției pentru 800ms
  
  servoLeft();
  delay(300);  // Ajustează virajul prin simpla mișcare a servo-ului
  
  motorForward();
  delay(800);  // Continuă înainte pentru 800ms
  
  servoCenter();
  motorStop();
}

// Manevră de ocolire spre stânga
void performBypassLeft() {
  servoLeft();
  motorForward();
  delay(800);  // Menține virajul spre stânga pentru 800ms
  
  servoRight();
  delay(300);  // Ajustează virajul prin schimbarea poziției servo
  
  motorForward();
  delay(800);  // Continuă mișcarea înainte pentru 800ms
  
  servoCenter();
  motorStop();
}

