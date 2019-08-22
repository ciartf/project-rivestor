#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define LED 9

int frequency = 0;
const int dataSize = 60;
const int dataLength = 3;
const int classLength = 2;
// default data to test "yes" class
//int dataTest[dataLength] = {244, 234, 28};
// default data to test "no" class
int dataTest[dataLength] = {209, 248, 175};
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
  {155,216,16},
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
  {248,205,29},
  {245,201,30},
  {238,200,25},
  {243,206,20},
  {247,203,26},
  {250,206,32},
  {241, 209, 31},
  {244,201,28},
  {245,207,27},
  {236, 209, 19},
  {240,202,25},
  {250,204,31},
  {243,195,27},
  {230,197,18},
  {248,193,25},
  {245,208,23},
  {242,201,18},
  {245,203,19},
  {248,206,19},
  {252,209,23}
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
  setupLED();
}

void loop() {
  // put your main code here, to run repeatedly:

  sense();
  process();
}

void process() {
  // determine class of data Test
  String result = calculateKNN(7);
  if (result == "yes") {
    ledON();
  } else {
    ledOFF();
  }
  Serial.print("Final result= ");
  Serial.println(result);
}

void sense() {
  // read color in RGB format
  runTCS3200();
  delay(500);
}
