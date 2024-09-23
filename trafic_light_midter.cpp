#include <Arduino.h>

#define Red 8
#define Yellow 9
#define Green 10

void setup()
{
  pinMode(Red, 1);
  pinMode(Yellow, 1);
  pinMode(Green, 1);
}

void loop()
{

  digitalWrite(Green, 1);
  delay(5000);
  digitalWrite(Green, 0);

  digitalWrite(Yellow, 1);
  delay(2000);
  digitalWrite(Yellow, 0);
  digitalWrite(Red, 1);

  delay(5000);
  digitalWrite(Red, 0);

}