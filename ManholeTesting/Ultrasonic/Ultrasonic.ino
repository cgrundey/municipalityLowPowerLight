const int trigPin = 9;
const int echoPin = 10;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (isOpen()) {
    //Connect and intialize modem
    //Send Text Message
    do {
      ESP.deepSleep(10 *1000000);
    } while(isOpen());
  }
  else
    ESP.deepSleep(10 * 1000000);
}

//returns the distance detected in cm
float getDistance() {
  long duration;
  float distance;
  //make sure trigger is low
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //write trigger high for 10us
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //read from sensor
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2.0;
}

//returns true if detects a certain distance
bool isOpen() {
  return getDistance() > 100;
}

