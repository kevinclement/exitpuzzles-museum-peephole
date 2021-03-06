#include <Arduino.h>

const int BTN_1_PIN = 9;
const int BTN_2_PIN = 8;

const int LED_BTN_1_PIN = 7;
const int LED_BTN_2_PIN = 6;

// TODO: Remove these, don't think they are used
// TODO: confirm
const int LED_FRNT_1_PIN = 21;
const int LED_FRNT_2_PIN = 20;
const int LED_FRNT_3_PIN = 19;

const int LED_1_PIN = 12;
const int LED_2_PIN = 11;
const int LED_3_PIN = 10;

int btn1 = 0;
int btn2 = 0;

void(* resetFunc) (void) = 0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  Serial.println("READY");
  Serial.println("Museum Peephole by kevinc...");

  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);

  pinMode(LED_BTN_1_PIN, OUTPUT);
  pinMode(LED_BTN_2_PIN, OUTPUT);

  pinMode(LED_FRNT_1_PIN, OUTPUT);
  pinMode(LED_FRNT_2_PIN, OUTPUT);
  pinMode(LED_FRNT_3_PIN, OUTPUT);

  pinMode(BTN_1_PIN, INPUT);
  pinMode(BTN_2_PIN, INPUT);
}

void loop() {
  btn1 = digitalRead(BTN_1_PIN);
  btn2 = digitalRead(BTN_2_PIN);

  // map led above button to state of button
  digitalWrite(LED_BTN_1_PIN, btn1);
  digitalWrite(LED_BTN_2_PIN, btn2);

  digitalWrite(LED_FRNT_1_PIN, HIGH);
  digitalWrite(LED_FRNT_2_PIN, HIGH);
  digitalWrite(LED_FRNT_3_PIN, HIGH);

  if (btn1 == HIGH && btn2 == LOW) {
    digitalWrite(LED_1_PIN, HIGH);
  } else {
    digitalWrite(LED_1_PIN, LOW);
  }

  if (btn1 == HIGH && btn2 == HIGH) {
    digitalWrite(LED_2_PIN, HIGH);
  } else {
    digitalWrite(LED_2_PIN, LOW);
  }

  if (btn2 == HIGH && btn1 == LOW) {
    digitalWrite(LED_3_PIN, HIGH);
  } else {
    digitalWrite(LED_3_PIN, LOW);
  }
}
