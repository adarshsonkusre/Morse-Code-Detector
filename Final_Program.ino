
#include "src/Button2.h"
#include "src/LiquidCrystal_PCF8574.h"

#ifndef IS_TRAINING
  #include "model.h"
#endif


const byte inputPin = 16;

const byte buzzerPin = 5;

const byte ledPin = 2;

const byte patternLength = 4;

const int intraCharacterPause = 500;

Button2 button;

float pattern[patternLength];

unsigned long lastReleaseTime;

uint8_t counter;

uint8_t charsReceived;

#ifndef IS_TRAINING
 
  Eloquent::ML::Port::RandomForest classifier;
#endif
LiquidCrystal_PCF8574 lcd(0x27);  //LCD address is 0x27 for PCF8574 and 0x3F for PCF8574A

void setup() {
  
  Serial.begin(115200);
  Serial.println(__FILE__ __DATE__);


  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);


  Wire.begin();
  lcd.begin(16, 2);
  lcd.setBacklight(200);
  lcd.print("Morse Decoder");
  delay(1000);
  lcd.clear();

 
  button.setDebounceTime(30);
  button.setPressedHandler(onButtonPress);
  button.setReleasedHandler(onButtonRelease);
  button.begin(inputPin);
}


void onCharacterReceive() {
    charsReceived++;    
    if(charsReceived % 16 == 0) {
      lcd.setCursor(0, 1);
    }
    if(charsReceived % 32 == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
    }

    #ifdef IS_TRAINING
     
      for(int i=0; i<patternLength; i++) {
        Serial.print(pattern[i]);
        Serial.print(i==patternLength-1 ? '\n' : ',');
      }
   
    #else
     
      char* result = (char*)classifier.predictLabel(pattern);
         Serial.println(classifier.predictLabel(pattern));
    
      lcd.print(result);
    #endif

   
    counter = 0;
    memset(pattern, 0, sizeof(pattern));

    digitalWrite(ledPin, LOW);
}

void onButtonPress(Button2& btn) {
 
  digitalWrite(ledPin, HIGH);

  digitalWrite(buzzerPin, HIGH);  
}

void onButtonRelease(Button2& btn) {
   
    unsigned int duration = btn.wasPressedFor();
   
    pattern[counter] = duration;
   
    lastReleaseTime = millis();
    
    counter++;

    if(counter == patternLength) {
      onCharacterReceive();
    }
  
    digitalWrite(buzzerPin, LOW);
}

void loop() {

  button.loop();


  if(!button.isPressed() && counter > 0 && millis() - lastReleaseTime > intraCharacterPause) {    
   
    onCharacterReceive();
  }
}
