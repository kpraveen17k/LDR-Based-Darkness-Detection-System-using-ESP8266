#define LDR_PIN A0
#define LED_PIN D2
#define BUZZER_PIN D5

int ldrValue = 0;
int threshold = 500;   // adjust based on your light and dark values

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("LDR Dark Detection System Started...");
}

void loop() {
  ldrValue = analogRead(LDR_PIN);

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Reverse logic fix for your setup
  if (ldrValue > threshold) {
    // DARK CONDITION
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("DARK -> LED ON, BUZZER ON");
  } 
  else {
    // LIGHT CONDITION
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("LIGHT -> LED OFF, BUZZER OFF");
  }

  delay(500);
}