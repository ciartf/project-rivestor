void setupTCS3200() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void runTCS3200() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  frequency = map(frequency, 30, 325, 255, 0) - 185;
  frequency = map(frequency, 0, 75, 0, 255);
  if (frequency > 255) {
    frequency = 255;
  } else if (frequency <= 0) {
    frequency = 0;
  }
  dataTest[0] = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(dataTest[0]);//printing RED color frequency
  Serial.print("  ");
  delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  frequency = map(frequency, 25, 275, 255, 0) - 185;
  frequency = map(frequency, 0, 50, 0, 255);
  if (frequency > 255) {
    frequency = 255;
  } else if (frequency <= 0) {
    frequency = 0;
  }
  dataTest[1] = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(dataTest[1]);//printing RED color frequency
  Serial.print("  ");
  delay(100);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  frequency = map(frequency, 15, 185, 255, 0) - 185;
  frequency = map(frequency, 0, 60, 0, 255);
  if (frequency > 255) {
    frequency = 255;
  } else if (frequency <= 0) {
    frequency = 0;
  }
  dataTest[2] = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(dataTest[2]);//printing RED color frequency
  Serial.println("  ");
  delay(100);
}
