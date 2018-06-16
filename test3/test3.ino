int enPin1 = 5;
int dirPin1 = 6;
int stepPin1 = 7;
int enPin2 = 3;
int dirPin2 = 9;
int stepPin2 = 4;

void setup() 
{
  Serial.begin(9600); 
  pinMode (enPin1, OUTPUT);
  pinMode (dirPin1, OUTPUT);
  pinMode (stepPin1, OUTPUT);
  pinMode (enPin2, OUTPUT);
  pinMode (dirPin2, OUTPUT);
  pinMode (stepPin2, OUTPUT);
}

void playTune(double frequency, long timeMilli)
{
  long timeMicro = (timeMilli) * 1000;
  timeMicro*=5;
  double period = 1/frequency;
  long periodMicro = 1000000*period;
  long loopLength = timeMicro/(periodMicro);
  Serial.print(timeMicro);
  Serial.print("\n");

  long elapsedTime = 0;
  digitalWrite(enPin1,HIGH);
  digitalWrite(enPin2,HIGH);
  while(elapsedTime <= timeMicro)
  {
    digitalWrite(stepPin1,LOW);
    digitalWrite(stepPin2,LOW);
    digitalWrite(stepPin1,HIGH);
    digitalWrite(stepPin2,HIGH);
    delayMicroseconds(periodMicro);
    elapsedTime += periodMicro;
    Serial.print(micros());
    //Serial.print("\n");
  }
}

void noTune(long timeMilli)
{
  timeMilli*=5;
  digitalWrite(enPin1,LOW);
  digitalWrite(enPin2,LOW);
  delay(timeMilli);
  Serial.print(timeMilli);
  Serial.print("\n");
}

void loop() 
{
    playTune(659, 16);

  noTune(8);

  playTune(659, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(659, 16);

  noTune(32);

  playTune(784, 16);

  noTune(176);

  playTune(523, 16);

  noTune(56);

  playTune(392, 16);

  noTune(56);

  playTune(330, 16);

  noTune(56);

  playTune(440, 16);

  noTune(32);

  playTune(494, 16);

  noTune(32);

  playTune(466, 16);

  noTune(8);

  playTune(440, 16);

  noTune(32);

  playTune(392, 16);

  noTune(16);

  playTune(659, 16);

  noTune(16);

  playTune(784, 16);

  noTune(16);

  playTune(880, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(784, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(8);

  playTune(494, 16);

  noTune(56);

  playTune(523, 16);

  noTune(56);

  playTune(392, 16);

  noTune(56);

  playTune(330, 16);

  noTune(56);

  playTune(440, 16);

  noTune(32);

  playTune(494, 16);

  noTune(32);

  playTune(466, 16);

  noTune(8);

  playTune(440, 16);

  noTune(32);

  playTune(392, 16);

  noTune(16);

  playTune(659, 16);

  noTune(16);

  playTune(784, 16);

  noTune(16);

  playTune(880, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(784, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(8);

  playTune(494, 16);

  noTune(104);

  playTune(784, 16);

  noTune(8);

  playTune(740, 16);

  noTune(8);

  playTune(698, 16);

  noTune(8);

  playTune(622, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(415, 16);

  noTune(8);

  playTune(440, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(56);

  playTune(784, 16);

  noTune(8);

  playTune(740, 16);

  noTune(8);

  playTune(698, 16);

  noTune(8);

  playTune(622, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(1047, 16);

  noTune(32);

  playTune(1047, 16);

  noTune(8);

  playTune(1047, 16);

  noTune(128);

  playTune(784, 16);

  noTune(8);

  playTune(740, 16);

  noTune(8);

  playTune(698, 16);

  noTune(8);

  playTune(622, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(415, 16);

  noTune(8);

  playTune(440, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(56);

  playTune(622, 16);

  noTune(56);

  playTune(587, 16);

  noTune(56);

  playTune(523, 16);

  noTune(224);

  playTune(784, 16);

  noTune(8);

  playTune(740, 16);

  noTune(8);

  playTune(698, 16);

  noTune(8);

  playTune(622, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(415, 16);

  noTune(8);

  playTune(440, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(56);

  playTune(784, 16);

  noTune(8);

  playTune(740, 16);

  noTune(8);

  playTune(698, 16);

  noTune(8);

  playTune(622, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(1047, 16);

  noTune(32);

  playTune(1047, 16);

  noTune(8);

  playTune(1047, 16);

  noTune(128);

  playTune(784, 16);

  noTune(8);

  playTune(740, 16);

  noTune(8);

  playTune(698, 16);

  noTune(8);

  playTune(622, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(415, 16);

  noTune(8);

  playTune(440, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(56);

  playTune(622, 16);

  noTune(56);

  playTune(587, 16);

  noTune(56);

  playTune(523, 16);

  noTune(176);

  playTune(523, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(32);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(392, 16);

  noTune(80);

  playTune(523, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(8);

  playTune(659, 16);

  noTune(200);

  playTune(523, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(32);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(392, 16);

  noTune(80);

  playTune(659, 16);

  noTune(8);

  playTune(659, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(659, 16);

  noTune(32);

  playTune(784, 16);

  noTune(176);

  playTune(523, 16);

  noTune(56);

  playTune(392, 16);

  noTune(56);

  playTune(330, 16);

  noTune(56);

  playTune(440, 16);

  noTune(32);

  playTune(494, 16);

  noTune(32);

  playTune(466, 16);

  noTune(8);

  playTune(440, 16);

  noTune(32);

  playTune(392, 16);

  noTune(16);

  playTune(659, 16);

  noTune(16);

  playTune(784, 16);

  noTune(16);

  playTune(880, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(784, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(8);

  playTune(494, 16);

  noTune(56);

  playTune(523, 16);

  noTune(56);

  playTune(392, 16);

  noTune(56);

  playTune(330, 16);

  noTune(56);

  playTune(440, 16);

  noTune(32);

  playTune(494, 16);

  noTune(32);

  playTune(466, 16);

  noTune(8);

  playTune(440, 16);

  noTune(32);

  playTune(392, 16);

  noTune(16);

  playTune(659, 16);

  noTune(16);

  playTune(784, 16);

  noTune(16);

  playTune(880, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(784, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(8);

  playTune(494, 16);

  noTune(56);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(392, 16);

  noTune(56);

  playTune(415, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(698, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(440, 16);

  noTune(80);

  playTune(494, 16);

  noTune(16);

  playTune(880, 16);

  noTune(16);

  playTune(880, 16);

  noTune(16);

  playTune(880, 16);

  noTune(16);

  playTune(784, 16);

  noTune(16);

  playTune(698, 16);

  noTune(16);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(392, 16);

  noTune(80);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(392, 16);

  noTune(56);

  playTune(415, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(698, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(440, 16);

  noTune(80);

  playTune(494, 16);

  noTune(8);

  playTune(698, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(698, 16);

  noTune(16);

  playTune(659, 16);

  noTune(16);

  playTune(587, 16);

  noTune(16);

  playTune(523, 16);

  noTune(176);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(392, 16);

  noTune(56);

  playTune(415, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(698, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(440, 16);

  noTune(80);

  playTune(494, 16);

  noTune(16);

  playTune(880, 16);

  noTune(16);

  playTune(880, 16);

  noTune(16);

  playTune(880, 16);

  noTune(16);

  playTune(784, 16);

  noTune(16);

  playTune(698, 16);

  noTune(16);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(392, 16);

  noTune(80);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(392, 16);

  noTune(56);

  playTune(415, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(698, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(440, 16);

  noTune(80);

  playTune(494, 16);

  noTune(8);

  playTune(698, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(698, 16);

  noTune(16);

  playTune(659, 16);

  noTune(16);

  playTune(587, 16);

  noTune(16);

  playTune(523, 16);

  noTune(176);

  playTune(523, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(32);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(392, 16);

  noTune(80);

  playTune(523, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(8);

  playTune(659, 16);

  noTune(200);

  playTune(523, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(587, 16);

  noTune(32);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(392, 16);

  noTune(80);

  playTune(659, 16);

  noTune(8);

  playTune(659, 16);

  noTune(32);

  playTune(659, 16);

  noTune(32);

  playTune(523, 16);

  noTune(8);

  playTune(659, 16);

  noTune(32);

  playTune(784, 16);

  noTune(176);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(392, 16);

  noTune(56);

  playTune(415, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(698, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(440, 16);

  noTune(80);

  playTune(494, 16);

  noTune(16);

  playTune(880, 16);

  noTune(16);

  playTune(880, 16);

  noTune(16);

  playTune(880, 16);

  noTune(16);

  playTune(784, 16);

  noTune(16);

  playTune(698, 16);

  noTune(16);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(392, 16);

  noTune(80);

  playTune(659, 16);

  noTune(8);

  playTune(523, 16);

  noTune(32);

  playTune(392, 16);

  noTune(56);

  playTune(415, 16);

  noTune(32);

  playTune(440, 16);

  noTune(8);

  playTune(698, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(440, 16);

  noTune(80);

  playTune(494, 16);

  noTune(8);

  playTune(698, 16);

  noTune(32);

  playTune(698, 16);

  noTune(8);

  playTune(698, 16);

  noTune(16);

  playTune(659, 16);

  noTune(16);

  playTune(587, 16);

  noTune(16);

  playTune(523, 16);

  noTune(100);
}

