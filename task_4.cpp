#include <Arduino.h>

#define Red 9
// SW1
#define Brightness_Up 2
// SW2
#define Yellow 10
#define Brightness_Down 3
// SW3
#define Green 11
#define Switch_Color 4

/*
Max is 255
Min is 0
*/
int brightness_red = 255;
int brightness_yellow = 255;
int brightness_green = 255;

/*
Red is 1
Yellow is 2
Green is 3
*/
int current_color = 1;

/*
SW1 is 1
SW2 is 2
SW3 is 3
When 0 waiting for user to start
*/
int current_button = 0;

int buttonPressed_Up = 0;
int buttonPressed_Down = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(Brightness_Up, 0);
  digitalWrite(Brightness_Up, 1);

  pinMode(Red, 1);

  pinMode(Brightness_Down, 0);
  digitalWrite(Brightness_Down, 1);

  pinMode(Yellow, 1);

  pinMode(Switch_Color, 0);
  digitalWrite(Switch_Color, 1);

  pinMode(Green, 1);
}


void max_brightness()
{
  if (brightness_red > 255)
  {
    brightness_red = 255;
  }
  if (brightness_yellow > 255)
  {
    brightness_yellow = 255;
  }
  if (brightness_green > 255)
  {
    brightness_green = 255;
  }
}

void min_brightness()
{
  if (brightness_red < 0)
  {
    brightness_red = 0;
  }
  if (brightness_yellow < 0)
  {
    brightness_yellow = 0;
  }
  if (brightness_green < 0)
  {
    brightness_green = 0;
  }
}

void dispaly_colors()
{
  max_brightness();
  min_brightness();

  
  analogWrite(Red, brightness_red);
  analogWrite(Yellow, brightness_yellow);
  analogWrite(Green, brightness_green);
}
void determenButtonPressed()
{
  if (digitalRead(Brightness_Up) == 0)
  {
    current_button = Brightness_Up;
  }
  else if (digitalRead(Brightness_Down) == 0)
  {
    current_button = Brightness_Down;
  }
  else if (digitalRead(Switch_Color) == 0)
  {
    current_button = Switch_Color;
  }
}
void blink(int LED)
{
  analogWrite(LED, 255);
  delay(100);
  analogWrite(LED, 0);
}

int thirdButtonPressed = 0;

void whichButtonPressed(int Button, int LED)
{
  switch (Button)
  {

  case Brightness_Up:
    if (digitalRead(Brightness_Up) == 0)
    {
      buttonPressed_Up = 1;
    }
    else
    {
      buttonPressed_Up = 0;
    }
    while (digitalRead(Brightness_Up) == 0 && buttonPressed_Up)
    {

      if (LED == 1)
      {
        brightness_red = brightness_red + 10;
        max_brightness();
        Serial.println("Brightness red");
        Serial.println(brightness_red);
        buttonPressed_Up = 1;
        buttonPressed_Down = 0;
      }
      else if (LED == 2)
      {
        brightness_yellow = brightness_yellow + 10;
        max_brightness();

        Serial.println("Brightness yellow");
        Serial.println(brightness_yellow);
        buttonPressed_Up = 1;
        buttonPressed_Down = 0;
      }
      else if (LED == 3)
      {
        brightness_green = brightness_green + 10;
        max_brightness();
        Serial.println("Brightness green");
        Serial.println(brightness_green);
        buttonPressed_Up = 1;
        buttonPressed_Down = 0;
      }
      dispaly_colors();
    }
    break;

  case Brightness_Down:
    if (digitalRead(Brightness_Down) == 0)
    {
      buttonPressed_Down = 1;
    }
    else
    {
      buttonPressed_Down = 0;
    }
    while (digitalRead(Brightness_Down) == 0 && buttonPressed_Down)
    {
      if (LED == 1)
      {
        brightness_red = brightness_red - 10;
        min_brightness();
        Serial.println("Brightness red");
        Serial.println(brightness_red);
      }
      else if (LED == 2)
      {
        brightness_yellow = brightness_yellow - 10;
        min_brightness();
        Serial.println("Brightness yellow");
        Serial.println(brightness_yellow);
      }
      else if (LED == 3)
      {
        brightness_green = brightness_green - 10;
        min_brightness();
        Serial.println("Brightness green");
        Serial.println(brightness_green);
      }
      dispaly_colors();

    }
    break;

  case Switch_Color:
    if (digitalRead(Switch_Color) == 0)
    {
      thirdButtonPressed = 1;

      if (current_color == 3)
      {
        current_color = 1;
        if (LED == 3)
        {
          blink(Red);
          analogWrite(Red, brightness_red);
        }
        else if (LED == 1)
        {
          blink(Yellow);
          analogWrite(Yellow, brightness_yellow);
        }
        else if (LED == 2)
        {
          blink(Green);
          analogWrite(Green, brightness_green);
        }
      }
      else
      {
        current_color++;
        if (LED == 3)
        {
          blink(Red);
          analogWrite(Red, brightness_red);
        }
        else if (LED == 1)
        {
          blink(Yellow);
          analogWrite(Yellow, brightness_yellow);
        }
        else if (LED == 2)
        {
          blink(Green);
          analogWrite(Green, brightness_green);
        }
      }
    }
    else
    {
      thirdButtonPressed = 0;
    }

    while (digitalRead(Switch_Color) == 0 && thirdButtonPressed)
    {
      /* code */
    }

    break;
  }
}

void loop()
{
  determenButtonPressed();
  whichButtonPressed(current_button, current_color);
  Serial.println("Curent button");
  Serial.println(current_button);
  Serial.println("Curent color");
  Serial.println(current_color);

  dispaly_colors();
  delay(100);
}