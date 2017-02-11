//Basic Code framework for intereacting with drum kit
//------Sonars--------
#define trigPin1 8
#define echoPin1 9

#define trigPin2 6
#define echoPin2 7

float distance1;
float distance2;

long duration1;
long duration2;

float sonarVal1; // reading from sonar that is printed
float sonarVal2; // reading from sonar that is printed

static unsigned long timestamp1 = 0;

//------Motors-------
#define LEFT_DIR = 12
#define RIGHT_DIR = 13
#define LEFT_SPEED = 3
#define RIGHT_SPEED = 11


//------LED----------
#define ledPin1 2
#define ledPin2 4


void setup() {
  Serial.println("Start");
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  //Direction A & B
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  // Speed A & B
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  beatA(150, 255);
  beatB(150, 255);
}


float sonar1(){
  // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1= duration1*0.034/2;
  return distance1;
}

float sonar2(){
  // Clears the trigPin
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= duration2*0.034/2;
  return distance2;
}


void beatA(int dly, int power) {
  analogWrite(3, power);
  digitalWrite(12, HIGH);
  delay(dly);
  digitalWrite(12, LOW);
  delay(dly);
}

void beatB(int dly, int power) {
  analogWrite(11, power);
  digitalWrite(13, HIGH);
  delay(dly);
  digitalWrite(13, LOW);
  delay(dly);
}

void beatAandB(int dly, int power) {
  analogWrite(3, power);
  analogWrite(11, power);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  delay(dly);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delay(dly);
}
