#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

const int flamePinLft = 2;
const int flamePinRgt = 3;
const int buzzerPin = 4;
const int ledPin1 = 5;
const int ledPin2 = 6;

int currentStateLft = 1;
int lastStateLft = 1;

int currentStateRgt = 1;
int lastStateRgt = 1;

void setup() {
  pinMode(flamePinLft, INPUT);
  pinMode(flamePinRgt, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Fire detection");
  delay(1000);
}

void loop() {
  // No flame input is 1.
  currentStateLft = digitalRead(flamePinLft);
  currentStateRgt = digitalRead(flamePinRgt);
   
  if ((currentStateLft != lastStateLft) || (currentStateRgt != lastStateRgt)) {
    if(currentStateLft == 0 && currentStateRgt == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire on both!");
      delay(1000);

      tone(buzzerPin, 440);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);

    } else if(currentStateLft == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire on the lft!");
      delay(1000);

      tone(buzzerPin, 440);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);

    } else if(currentStateRgt == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire on the rgt!");
      delay(1000);

      tone(buzzerPin, 440);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
    } else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Safe");

      noTone(buzzerPin);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
    }

    delay(50);
  }

  lastStateLft = currentStateLft;
  lastStateRgt = currentStateRgt;
}