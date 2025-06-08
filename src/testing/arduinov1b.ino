void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char received = Serial.read();
    Serial.println(received);
  }
}

