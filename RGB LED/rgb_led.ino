// https://www.tinkercad.com/things/iGM1CaRDt4o-rgb-led?sharecode=WKI6L-sd5uDz8B-9uwmE7gXV_15mbjMR-o9gIjDLp8Q

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

const int redPotan = A2;
const int greenPotan = A1;
const int bluePotan = A0;


int redValue;
int greenValue;
int blueValue;


void setup()
{
  pinMode(redPotan, INPUT);
  pinMode(greenPotan, INPUT);
  pinMode(bluePotan, INPUT);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{

  redValue = (int) (analogRead(redPotan) / 4);
  greenValue = (int) (analogRead(greenPotan) / 4);
  blueValue = (int) (analogRead(bluePotan) / 4);
  
  Serial.print(redValue);
  Serial.print(", ");
  Serial.print(greenValue);
  Serial.print(", ");
  Serial.println(blueValue);

  
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
  
}