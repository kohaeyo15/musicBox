int enPin = 5;
int dirPin = 6;
int stepPin = 7;

void setup() 
{
  pinMode (enPin, OUTPUT);
  pinMode (dirPin, OUTPUT);
  pinMode (stepPin, OUTPUT);
}

void loop() 
{
  digitalWrite(enPin, HIGH);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(1000);
}

