#include <esp_now.h>
#include <WiFi.h>
int Player;

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    int b;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.println();
  Player = myData.b;
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  pinMode(5,INPUT);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {
  int sensorValue = digitalRead(5);
    if ((sensorValue == 0) && (Player == 42)){
    Serial.println("Oh no! I'm Shot");
    delay(1200);
  }
  Serial.println(sensorValue);
  Serial.print("Player # ");
  Serial.println(Player);
  delay(1);
}