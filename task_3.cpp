#include <Arduino.h>

#define Piezo 8

void setup()
{
  pinMode(Piezo, OUTPUT);

  Serial.begin(9600);
}

void playTone(String input_tone)
{

  // Got note tones from internet and tone documentation
  if (input_tone == "C"){
    tone(Piezo, 261.63, 1000);
  }
  else if (input_tone == "D"){
    tone(Piezo, 293.66, 1000);
  }
  else if (input_tone == "E"){
    tone(Piezo, 329.63, 1000);
  }
  else if (input_tone == "F"){
    tone(Piezo, 349.23, 1000);
  }
  else if (input_tone == "G"){
    tone(Piezo, 392.00, 1000);
  }
  else if (input_tone == "A"){
    tone(Piezo, 440.00, 1000);
  }
  else if (input_tone == "B"){
    tone(Piezo, 493.88, 1000);
  }
  else{
    Serial.println("Gracefully you entered an invalid tone");
  }
}

void loop()
{

  if (Serial.available() > 0)
  {
    // Read the incoming string until user presses enter:
    String input = Serial.readStringUntil('\n');

    // Display which note is to be played:
    Serial.print("Note played is: ");
    Serial.println(input);

    playTone(input);

  }
}