int pulPin = 7;
int dirPin = 6;
int enaPin = 5;

void setup() 
{
  Serial.begin(9600); 
  pinMode (pulPin, OUTPUT);
  pinMode (dirPin, OUTPUT);
  pinMode (enaPin, OUTPUT);
}

void loop() 
{
  int frequency = 60;
  int time = 10;
  int period = 1/frequency;
  int loopLength = time/(1000*period);

  digitalWrite(enaPin,HIGH);
  for (int i=0; i<loopLength; i++)
  {
    digitalWrite(pulPin,HIGH);
    delayMicroseconds(period*1000000 - 100);
    digitalWrite(pulPin,LOW);
    delayMicroseconds(100); 
  }
}
