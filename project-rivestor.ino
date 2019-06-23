#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // setup color sensor
  setupTCS3200();
}

void loop() {
  // put your main code here, to run repeatedly:

}
