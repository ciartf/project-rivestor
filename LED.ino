void setupLED() {
  pinMode(LED, OUTPUT);
}

void ledON() {
  digitalWrite(LED, HIGH);
}

void ledOFF() {
  digitalWrite(LED, LOW);
}
