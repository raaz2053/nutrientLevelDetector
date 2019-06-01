#include <HCSR04.h>

UltraSonicDistanceSensor US(12, 13); // Initialize sensor that uses digital pins trig and echo.
float x = 24;
int LED1 = 10;
int LED2 = 9;
int LED3 = 8;
int LED4 = 7;
int LED5 = 6;
int LED6 = 5;  //Buzzer pin

void setup()
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  delay(500);
}

void loop()
{
  us();
}

void us(){
  float distance = US.measureDistanceCm();
  if (distance > 0.86 * x)
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    Serial.println("Empty tank");
    delay(100);
  }

  else if (distance > .76 * x && distance < .85 * x)
  {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    Serial.println("5th led balyo");
    delay(100);
  }

  else if (distance < .75 * x && distance > .5 * x)
  {
    Serial.println("4th led balyo");
    digitalWrite(5, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(100);
  }


  else if (distance < .5 * x && distance > .26 * x)
  {
    Serial.println("3rd led balyo");
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(10, LOW);
    delay(100);
  }


  else if (distance < .25 * x && distance > .1 * x)
  {
    Serial.println("alikai ghatyo");
    digitalWrite(5, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    delay(100);
  }

  else if (distance <= .1 * x) // check if water is full
  {
    digitalWrite(5, LOW);
    digitalWrite(10, HIGH);
    Serial.println("full tank");
    delay(100);
  }
  delay(100);
}

