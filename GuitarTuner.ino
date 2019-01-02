#include "pitches.h" // to play notes on the active buzzer

byte A = B11101110; // Here I am defining the bit sequence that will display each letter on the 7 segment display
byte B = B11111110; // I will be using a shift register, with LSB first
byte C = B10011100;
byte D = B11111100;
byte E = B10011110;
byte HIGH_E = B10011111; // Since there are 2 E notes on a guitar, I am indicating the High E by illuminating the Decimal Point on the Display
byte F = B10001110;
byte G = B10111110;

#define BUZZER_PIN 6 // Defining which pin will will be connected to the Active Buzzer
#define E_BUTTON 13  // Defining which button will produce which note, and which pin each button is assigned to
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
int resetPin = 5; // To reset the shift register after each use
 
void setup() {
  // Set latchPin, clockPin, dataPin, BUZZER_PIN as output
  pinMode(latchPin, OUTPUT); 
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(E_BUTTON, INPUT_PULLUP); // setting the buttons as logical high
  pinMode(A_BUTTON, INPUT_PULLUP);
  pinMode(D_BUTTON, INPUT_PULLUP);
  pinMode(G_BUTTON, INPUT_PULLUP);
  pinMode(B_BUTTON, INPUT_PULLUP);
}
 
void loop() {       

//For E Button
  if (digitalRead(E_BUTTON) == LOW) // if the button is pressed, it will be connected to ground, hence making it a low
  
  {
    delay(500); // this is here because we want to know if the user wants a high E or a low E
                // To access a high E, the user must HOLD down the button. For the low E he simply must press the button
    
    if(digitalRead(E_BUTTON) == LOW){ // if the button was held down (High E)
      
      digitalWrite(resetPin, LOW);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, HIGH_E);  //Display 'E.'
      digitalWrite(latchPin, HIGH);

       for (int i = 0; i<3; i++) // this for loop is so that we will hear the sound of the not 3 times
      
      {
        tone(BUZZER_PIN, NOTE_E4, 1000); // play a High E
        delay(3000); // wait 3 seconds between each buzz
      }   
    }
    else{  // if the button wasn't held down, and the user wants a low E
      
    
    digitalWrite(resetPin, LOW);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, E);  // display 'E'
    digitalWrite(latchPin, HIGH);

    

    for (int i = 0; i<3; i++)
    
    {
      tone(BUZZER_PIN, NOTE_E2, 1000); // play a low E
      delay(3000);
    }
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(resetPin, LOW);
  }

    }

//For A Button
  if (digitalRead(A_BUTTON) == LOW) // if the A button is pressed
  
  {
    
    digitalWrite(resetPin, LOW);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, A);  //Display 'A'
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
