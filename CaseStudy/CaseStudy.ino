#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

const int flameSensorPin = 2;
const int buzzerPin = 3;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;

int currentState = 1;
int lastState = 1;

void setup() {
  pinMode(flameSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Fire detection");
  delay(1000);
}

void loop() {
  // No flame input is 1.
  currentState = digitalRead(flameSensorPin);

  if (currentState != lastState) {
    if(currentState == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire!");

      tone(buzzerPin, 440);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
    } else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Safe");

      noTone(buzzerPin);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
    }

    delay(50);
  }

  lastState = currentState;
}