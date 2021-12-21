
#include <Servo.h>  //servo library
Servo myservo;      // create servo object to control servo

int Echo = A4;
int Trig = A5;

int Echo2 = 10;
int Trig2 = 9;


//Ultrasonic distance measurement Sub function
//how to det distanceMesurment from Ultrasonic
int getDistance( int Trigs, int Echos) {
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    return (int)pulseIn(Echo, HIGH) / 58;
}

void setup() {
  myservo.attach(3);  // attach servo on pin 3 to servo object
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo2, INPUT);
  pinMode(Trig2, OUTPUT);
}

void scan(){
  int i = 0;
  // gets average distance measurement in a 20 degree arc for the whole cirile
  for(i =0;i<10;i++){
    myservo.write(20*i);
    delay(500);// allows servo to stablize
    int checkdistance1=getDistance(Trig,Echo);
    delay(100);

    int checkdistance2=getDistance(Trig,Echo);
    delay(100);

    int checkdistance3=getDistance(Trig,Echo);
    delay(100);

    int distance = (checkdistance1+checkdistance2+checkdistance3)/3;

    Serial.print(20*i);
    Serial.print(";");
    Serial.print(distance);
    Serial.print(";");
// same thing for the other ultrasonic 
    checkdistance1=getDistance(Trig2,Echo2);
    delay(100);
    checkdistance2=getDistance(Trig2,Echo2);
    delay(100);
    checkdistance3=getDistance(Trig2,Echo2);
    delay(100);

    distance = (checkdistance1+checkdistance2+checkdistance3)/3;
    Serial.print(-20*i);
    Serial.print(";");
    Serial.println(distance);
    }
}

void loop() {
    scan();
    delay(2000);
}
