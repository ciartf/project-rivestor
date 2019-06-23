#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int frequency = 0;
const int dataSize = 60;
const int dataLength = 3;
const int classLength = 2;
int dataTest[dataLength] = {0, 0, 0};
int dataTrain[dataSize][dataLength] = {
  {172, 242, 1},
  {155, 232, 1},
  {122, 222, 20},
  {141, 236, 47},
  {148, 237, 58},
  {168, 240, 96},
  {168, 240, 100},
  {177, 242, 119},
  {194, 244, 149},
  {115, 219, 21},
  {107, 204, 19},
  {120, 228, 22},
  {209, 248, 175},
  {209, 248, 177},
  {219, 250, 177},
  {172, 242, 1},
  {123, 212, 20},
  {171, 216, 16},
  {176, 226, 5},
  {94, 226, 5},
  {111, 220, 12},
  {116, 197, 35},
  {56, 223, 99},
  {168, 240, 99},
  {104, 243, 97},
  {122, 239, 101},
  {155, 232, 5},
  {177, 242, 119},
  {78, 233, 50},
  {109, 242, 21},
  {155, 232, 1},
  {165, 247, 111},
  {158, 247, 100},
  {152, 245, 90},
  {173, 243, 44},
  {179, 243, 29},
  {96, 252, 20},
  {100, 240, 32},
  {121, 236, 36},
  {188, 240, 32},
  {248, 232, 29},
  {219, 245, 31},
  {221, 249, 28},
  {243, 216, 20},
  {202, 247, 26},
  {240, 235, 32},
  {241, 209, 31},
  {244, 234, 28},
  {245, 230, 27},
  {236, 209, 19},
  {240, 235, 15},
  {184, 224, 31},
  {188, 228, 27},
  {200, 224, 31},
  {181, 223, 32},
  {233, 238, 17},
  {237, 226, 18},
  {236, 203, 19},
  {236, 231, 19},
  {232, 226, 23}
};
String dataClass[dataSize] = {
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "no",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes",
  "yes"
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // setup color sensor
  setupTCS3200();
}

void loop() {
  // put your main code here, to run repeatedly:

  // read color in RGB format
  runTCS3200();
  Serial.print("RGB= ");
  Serial.print(dataTest[0]);
  Serial.print(",");
  Serial.print(dataTest[1]);
  Serial.print(",");
  Serial.println(dataTest[2]);

  // determine class of data Test
  Serial.print("Final result= ");
  Serial.println(calculateKNN(3));
}
