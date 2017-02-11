//------Sonars--------
#define trigPin 8
#define echoPin 9
float distance;
long duration;
float sonarVal; // reading from sonar that is printed
static unsigned long timestamp = 0;

//------Motors-------
#define leftMotor  12
#define rightMotor  13
#define leftSpeed  3
#define rightSpeed  11


//------LED----------
//leds present for troubleshooting
#define ledPin1 2
#define ledPin2 4


void setup() {
  Serial.begin(9600);
  Serial.println("Start");

  //-----Setting up sonar---------
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //-----Setting up motors---------
  //Direction A & B
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  // Speed A & B
  pinMode(leftSpeed, OUTPUT);
  pinMode(rightSpeed, OUTPUT);

  analogWrite(leftSpeed, 255);
  analogWrite(rightSpeed, 255);

  //----Setting up led------------
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  

}

void loop() {
  beatAandB(150, 255);
  beatA(300,255);
  beatB(300,255);
  beatA(250,255);
  
  for(int i = 300; i> 150; i = i -30){
      beatA(i,255);
      beatB(i,255); 
  }

  beatAandB(150, 255);
  beatAandB(150, 255);
  beatAandB(150, 255);
  
  beatA(150,255);
  beatB(150,255); 
  beatA(150,255);
  beatB(150,255); 
  beatA(150,255);
  beatB(150,255); 

  for(int i = 150; i< 300; i = i + 30){
      beatA(i,255);
      beatB(i,255); 
  }


}



float sonar(){//sonar data distance function
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  return distance;
}


void beatA(int dly, int power) {
  analogWrite(3, power);
  digitalWrite(12, HIGH);
  digitalWrite(ledPin1, HIGH);
  delay(dly);
  digitalWrite(12, LOW);
  digitalWrite(ledPin1, LOW);
  delay(dly);
}

void beatB(int dly, int power) {
  analogWrite(11, power);
  digitalWrite(13, HIGH);
  digitalWrite(ledPin2, HIGH);
  delay(dly);
  digitalWrite(13, LOW);
  digitalWrite(ledPin2, LOW);
  delay(dly);
}

void beatAandB(int dly, int power) {
  analogWrite(3, power);
  analogWrite(11, power);
  digitalWrite(12, HIGH);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(13, HIGH);
  delay(dly);
  digitalWrite(12, LOW);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(13, LOW);
  delay(dly);
}
