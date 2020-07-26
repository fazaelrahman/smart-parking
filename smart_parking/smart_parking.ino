#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "650f94ZZKGrfMUfDTtcq9Dw1AF2h7ygb";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "NUSA TITAN LTE";
char pass[] = "Nusa7173";

WidgetLED led1(V1);
WidgetLED led2(V2);

int sensor1 = D1;
int sensor2 = D2;

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(sensor2,INPUT);
  pinMode(sensor1,INPUT);

  while (Blynk.connect() == false) {
  }
}

void loop() {
  int sensorval1 = digitalRead(sensor1);
  int sensorval2 = digitalRead(sensor2);
  Serial.println(sensorval1);
  Serial.println(sensorval2);
  delay(1000);
  
    if (sensorval1 == 1)
    {
  led1.on();
  }
    if (sensorval2 == 1)
    {
  led2.on();
  }

    if (sensorval1 == 0)
    {
  led1.off();
  }
    if (sensorval2 == 0)
    {
  led2.off();
  }

  Blynk.run();
}
