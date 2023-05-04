const int pinSortiePWM = 5; // Numéro de la broche PWM pour l'émetteur IR
int freq = 69000;
int LEDChannel = 0;
int resolution = 8;

void setup() {
  ledcSetup(LEDChannel, freq, resolution);
  ledcAttachPin(5,LEDChannel);
  Serial.begin(115200);
  pinMode(pinSortiePWM, OUTPUT);
}

void loop() {
  digitalWrite(pinSortiePWM, HIGH);
  delay(2000);
  digitalWrite(pinSortiePWM, LOW);
  delay(2000);
}