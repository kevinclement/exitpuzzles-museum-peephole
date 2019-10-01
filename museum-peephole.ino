const int BTN_1_PIN = 9;
const int BTN_2_PIN = 6;

const int LED_BTN_1_PIN = 7;
const int LED_BTN_2_PIN = 8;

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

  pinMode(LED_BTN_1_PIN, OUTPUT);
  pinMode(LED_BTN_2_PIN, OUTPUT);

  pinMode(BTN_1_PIN, INPUT);
  pinMode(BTN_2_PIN, INPUT);
}

void loop() {
  btn1 = digitalRead(BTN_1_PIN);
  btn2 = digitalRead(BTN_2_PIN);

  // map led above button to state of button
  digitalWrite(LED_BTN_1_PIN, btn1);
  digitalWrite(LED_BTN_2_PIN, btn2);

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
