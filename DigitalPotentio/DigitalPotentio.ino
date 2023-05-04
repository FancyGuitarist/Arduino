#include <SPI.h>


const int mcpSS = 5; // The SS pin of the MCP41100


void setup() {
  Serial.begin(115200);
  SPI.begin(18, 19, 23);
  pinMode(mcpSS, OUTPUT);
  digitalWrite(mcpSS, HIGH);
}

void setPotValue(int value) {
  digitalWrite(mcpSS, LOW);
  SPI.transfer(0x11); // Command byte to set wiper position
  SPI.transfer(value); // Data byte to set value
  digitalWrite(mcpSS, HIGH);
}

void loop() {
  for (int i=0; i<=255; i++) {
      Serial.print("i is : ");
      Serial.println(i);
      setPotValue(i);
      delay(10);
   }
  for (int i=255; i>=0; i--) {
      Serial.print("i is : ");
      Serial.println(i);
      setPotValue(i);
      delay(10);
   }
}