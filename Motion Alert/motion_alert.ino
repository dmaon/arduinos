// https://www.tinkercad.com/things/eMnQJ5scCdp-motion-alert?sharecode=1SYWGJN_wL03heTS6QF4G6_G7YrBKiHRXbuQ_gsJWAE

// buzzer notes
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880

const int blueLEDSPin = 13;
const int redLEDSPin = 12;
const int piezoPin = 11;
const int pirPin = 10;
const int pushBtnPin = 9;

int alertState = 0;

void setup()
{
  pinMode(blueLEDSPin, OUTPUT);
  pinMode(redLEDSPin, OUTPUT);
  pinMode(pirPin, INPUT);  
  pinMode(pushBtnPin, INPUT_PULLUP); 
  
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(pushBtnPin) == LOW)
    alertState = 0;
  
  
  int pirValue = digitalRead(pirPin);  // read input value
  Serial.println(pirValue);
  
  if (pirValue == HIGH || alertState) { 
    noTone(piezoPin);
    digitalWrite(blueLEDSPin, 1);
    digitalWrite(redLEDSPin, 0);
    tone(piezoPin, NOTE_F5, 400);
    delay(300*1.3);

    noTone(piezoPin);
    digitalWrite(redLEDSPin, 1);
    digitalWrite(blueLEDSPin, 0);
    tone(piezoPin, NOTE_D5, 400);
    delay(300*1.3);
  
    alertState = 1;
      
  } else { 
    noTone(piezoPin);
    digitalWrite(redLEDSPin, 0);
    digitalWrite(blueLEDSPin, 0);
  }

  delay(10);

}