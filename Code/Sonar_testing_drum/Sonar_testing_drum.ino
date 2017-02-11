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
  
  sonarVal = (sonar()+sonar()+sonar())/3;//filtering and smoothening sonar value

  timestamp = millis();//millis and timestamps are used throughout the program to ensure that the sonar read time is compensated for
  while(sonarVal>50 ){
    sonarVal = (sonar()+sonar()+sonar())/3;
    Serial.println("wait");
  }
  Serial.println(sonarVal);
  if(50*sonarVal-(millis()-timestamp)>0 &&  sonarVal <= 50 ){// statement insuring that the delay read is within the desired range
    delay(20*sonarVal-(millis()-timestamp));
  }
  
  delay(150);
  digitalWrite(rightMotor, HIGH);
  digitalWrite(leftMotor, LOW);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  
  timestamp = millis();
  sonarVal = (sonar()+sonar()+sonar())/3;
  
  if (50*sonarVal -(millis()-timestamp)> 0 &&  sonarVal <= 50 ){ 
    Serial.println(20*sonarVal - (millis()-timestamp));
    delay(20*sonarVal - (millis()-timestamp));
  }
  delay(150);
  digitalWrite(rightMotor, LOW);
  digitalWrite(leftMotor, HIGH);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
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
