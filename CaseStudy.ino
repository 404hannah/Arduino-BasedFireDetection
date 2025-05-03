#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

const int flameSensorPin = 2;
const int buzzerPin = 3;
const int ledPin = 4;

int currentState = 1;
int lastState = 1;

void setup() {
  pinMode(flameSensorPin, INPUT);
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  lcd.begin();
  lcd.backlight();
}

void loop() {
  // No flame input is 1.
  currentState = digitalRead(flameSensorPin);

  if (currentState != lastState) {
    if(currentState == 0) {
      lcd.setCursor(0, 0);
      lcd.print("Fire!");

      digitalWrite(buzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
    } else{
      lcd.clear();

      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);
    }

    delay(50);
  }

  lastState = currentState;
}
