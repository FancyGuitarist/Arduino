int PlayerShot = 1

void setup() {
  Serial.begin(115200);
  pinMode(5,INPUT);

}

void loop() {
  int sensorValue = digitalRead(5);
  if ((sensorValue == 0) && (PlayerShot == 1)){
    Serial.println("Oh no! I'm Shot")
    delay(1200);
  }
  Serial.println(sensorValue);
  delay(1);
}
