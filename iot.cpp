#define BLYNK_TEMPLATE_ID "TMPLhEx5lMvU"
#define BLYNK_DEVICE_NAME "switch control"
#define BLYNK_AUTH_TOKEN "B73ghtHmxsEPaLnMbwP3RgGDUHFzthv2"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "GALAXY";  // type your wifi name
char pass[] =  "12345678";  // type your wifi password

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D0, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D0, HIGH);
     Serial.println("LED OFF");
  }
}
BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D2, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D2, HIGH);
     Serial.println("LED OFF");
  }
}
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT);
  digitalWrite(D0,HIGH);
  pinMode(D2,OUTPUT);
  digitalWrite(D2,HIGH);
}
void loop()
{
  Blynk.run();
}
