// defining a function which calculates euclidean distance between two data points
double euclideanDistance(int index) {
  Serial.println("Euclidean result");
  double distance = 0.0;
  for (int x = 0; x < dataLength; x++) {
    distance += pow((dataTest[x] - dataTrain[index][x]), 2);
    Serial.println(pow((dataTest[x] - dataTrain[index][x]), 2));
  }
  Serial.print(distance);
  Serial.print(" ");
  Serial.println(sqrt(distance));
  return sqrt(distance);
}

// defining our KNN model
String calculateKNN(int k) {
  // start of STEP 3
  // calculating euclidean distance between each row of training data and test data
  // index 0 represent original row order
  // index 1 represent calculated distance
  double distances[dataSize][2];
  for (int x = 0; x < dataSize; x++) {

    // start of STEP 3.1
    double dist = euclideanDistance(x);

    distances[x][0] = x;
    distances[x][1] = dist;
    // end of STEP 3.1
  }

  Serial.println("Step 1 result");
  for (int i = 0; i < dataSize; i++) {
    for (int j = 0; j < 2; j++) {
      Serial.print(distances[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }

  // start of STEP 3.2
  // sorting them on the basis of distance
  for (int x = 0; x < dataSize; x++) {
    int y = x;
    while (y > 0 && distances[y][1] < distances[y - 1][1]) {
      double temp[2];
      temp[0] = distances[y][0];
      temp[1] = distances[y][1];
      distances[y][0] = distances[y - 1][0];
      distances[y][1] = distances[y - 1][1];
      distances[y - 1][0] = temp[0];
      distances[y - 1][1] = temp[1];
      y--;
    }
  }
  // end of STEP 3.2

  Serial.println("Step 2 result");
  for (int i = 0; i < dataSize; i++) {
    for (int j = 0; j < 2; j++) {
      Serial.print(distances[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }

  // start of STEP 3.3
  // extracting top k neighbors
  double neighbors[k][2];
  for (int x = 0; x < k; x++) {
    neighbors[x][0] = distances[x][0];
    neighbors[x][1] = distances[x][1];
  }
  // end of STEP 3.3

  Serial.println("Step 3 result");
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 2; j++) {
      Serial.print(neighbors[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }

  // start of STEP 3.4
  // calculating the most freq class in the neighbors
  // index 0 represent "yes"
  // index 1 represent "no"
  int classVotes[classLength] = {0, 0};
  for (int x = 0; x < k; x++) {
    String currClass = dataClass[int(neighbors[x][0])];

    if (currClass == "yes") {
      classVotes[0] += 1;
    } else {
      classVotes[1] += 1;
    }
  }
  // end of STEP 3.4

  Serial.println("Step 4 result");
  for (int i = 0; i < k; i++) {
    Serial.println(classVotes[i]);
  }

  // start of STEP 3.5
  if (classVotes[0] > classVotes[1]) {
    return "yes";
  } else {
    return "no";
  }
  // end of STEP 3.5
}
