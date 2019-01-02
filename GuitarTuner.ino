#include "pitches.h"

byte A = B11101110;
byte B = B11111110;
byte C = B10011100;
byte D = B11111100;
byte E = B10011110;
byte HIGH_E = B10011111;
byte F = B10001110;
byte G = B10111110;

#define BUZZER_PIN 6
#define E_BUTTON 13
#define A_BUTTON 12
#define D_BUTTON 11
#define G_BUTTON 9
#define B_BUTTON 10

// connect to the ST_CP of 74HC595 (pin 3,latch pin)
int latchPin = 3;
// connect to the SH_CP of 74HC595 (pin 4, clock pin)
int clockPin = 4;
// connect to the DS of 74HC595 (pin 2)
int dataPin = 2;
int resetPin = 5;
 
void setup() {
  // Set latchPin, clockPin, dataPin as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(E_BUTTON, INPUT_PULLUP);
  pinMode(A_BUTTON, INPUT_PULLUP);
  pinMode(D_BUTTON, INPUT_PULLUP);
  pinMode(G_BUTTON, INPUT_PULLUP);
  pinMode(B_BUTTON, INPUT_PULLUP);
}
 
void loop() {       

//For E Button
  if (digitalRead(E_BUTTON) == LOW)
  
  {
    delay(500);

    
    if(digitalRead(E_BUTTON) == LOW){
      
      digitalWrite(resetPin, LOW);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, HIGH_E);  //A
      digitalWrite(latchPin, HIGH);

       for (int i = 0; i<3; i++)
      
      {
        tone(BUZZER_PIN, NOTE_E4, 1000);
        delay(3000);
      }   
    }
    else{
      
    
    digitalWrite(resetPin, LOW);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, E);  //A
    digitalWrite(latchPin, HIGH);

    

    for (int i = 0; i<3; i++)
    
    {
      tone(BUZZER_PIN, NOTE_E2, 1000);
      delay(3000);
    }
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(resetPin, LOW);
  }

    }

//For A Button
  if (digitalRead(A_BUTTON) == LOW)
  
  {
    
    digitalWrite(resetPin, LOW);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, A);  //A
    digitalWrite(latchPin, HIGH);

    for (int i = 0; i<3; i++)
    
    {
      tone(BUZZER_PIN, NOTE_A2, 1000);
      delay(3000);
    }
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(resetPin, LOW);
  }


//For D Button
  if (digitalRead(D_BUTTON) == LOW)
  
  {
    
    digitalWrite(resetPin, LOW);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, D);  //A
    digitalWrite(latchPin, HIGH);

    for (int i = 0; i<3; i++)
    
    {
      tone(BUZZER_PIN, NOTE_D3, 1000);
      delay(3000);
    }
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(resetPin, LOW);
  }


  

//For G Button
  if (digitalRead(G_BUTTON) == LOW)
  
  {
    
    digitalWrite(resetPin, LOW);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, G);  //A
    digitalWrite(latchPin, HIGH);

    for (int i = 0; i<3; i++)
    
    {
      tone(BUZZER_PIN, NOTE_G3, 1000);
      delay(3000);
    }
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(resetPin, LOW);
  }



//For B Button
  if (digitalRead(B_BUTTON) == LOW)
  
  {
    
    digitalWrite(resetPin, LOW);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B);  //A
    digitalWrite(latchPin, HIGH);

    for (int i = 0; i<3; i++)
    
    {
      tone(BUZZER_PIN, NOTE_B3, 1000);
      delay(3000);
    }
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(resetPin, LOW);
  }


  
}
