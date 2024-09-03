// https://www.tinkercad.com/things/2rbG0GkJsT1-traffic-light?sharecode=HMQWEww0c4ylC0U-EYOQa7zacmYDgyBh2pA2EO-01oE

const int redLightPin = 13;
const int yellowLightPin = 12;
const int greenLightPin = 11;

const int redLightInterval = 5000;
const int yellowLightInterval = 1000;
const int greenLightInterval = 3000;

int spendTime = 0;
char turn = 'r';

void setup()
{
  Serial.begin(9600);
  
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  
  digitalWrite(redLightPin, 1);
}

void loop()
{
  int timer = millis();

  if ( turn == 'r' && timer - spendTime > redLightInterval) {
    spendTime = timer;
    turn = 'g';
    digitalWrite(redLightPin, 0);
    digitalWrite(greenLightPin, 1);
  } else if ( turn == 'g' && timer - spendTime > greenLightInterval) {
    spendTime = timer;
    turn = 'y';
    digitalWrite(greenLightPin, 0);
    digitalWrite(yellowLightPin, 1);
  }
   else if ( turn == 'y' && timer - spendTime > yellowLightInterval) {
    spendTime = timer;
    turn = 'r';
    digitalWrite(yellowLightPin, 0);
    digitalWrite(redLightPin, 1);
  }

}