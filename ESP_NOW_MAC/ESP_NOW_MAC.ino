#include "WiFi.h"
/*
 * MAC RED: 0C:B8:15:74:13:DC
 * MAC BLACK: EC:62:60:1D:A0:C8
 */
void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
  Serial.println(WiFi.macAddress());
}
 
void loop(){

}
