const int BTN_1_PIN = 9;
const int BTN_2_PIN = 6;
const int LED_1_PIN = 10;
const int LED_2_PIN = 16;
const int LED_3_PIN = 14;

int btn1 = 0;
int btn2 = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("Museum Peephole by kevinc...");
  
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  
  pinMode(BTN_1_PIN, INPUT);
  pinMode(BTN_2_PIN, INPUT);
}

void loop() {
  btn1 = digitalRead(BTN_1_PIN);
  btn2 = digitalRead(BTN_2_PIN);

  if (btn1 == HIGH && btn2 == LOW) {
    Serial.println("1 - ON");
    digitalWrite(LED_1_PIN, HIGH);
  } else {
    digitalWrite(LED_1_PIN, LOW);
  }

  if (btn1 == HIGH && btn2 == HIGH) {
    Serial.println("2 - ON");
    digitalWrite(LED_2_PIN, HIGH);
  } else {
    digitalWrite(LED_2_PIN, LOW);
  }

  if (btn2 == HIGH && btn1 == LOW) {
//    Serial.println("3 - ON");
    digitalWrite(LED_3_PIN, HIGH);
  } else {
    digitalWrite(LED_3_PIN, LOW);
  }
}
