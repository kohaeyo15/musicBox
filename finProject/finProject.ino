int pulPin1 = 7;
int dirPin1 = 6;
int enaPin1 = 5;
int pulPin2;
int dirPin2;
int enaPin2;

void setup() 
{
  pinMode (pulPin1, OUTPUT);
  pinMode (dirPin1, OUTPUT);
  pinMode (enaPin1, OUTPUT);
  pinMode (pulPin2, OUTPUT);
  pinMode (dirPin2, OUTPUT);
  pinMode (enaPin2, OUTPUT);  
}

void playTune(double frequency1, double frequency2, long time)
{
  time*= 1000;
  time*= 5;
  long period1 = 1000000/frequency1;
  long period2 = 1000000/frequency2;

  if(frequency1 == 9999)
  {
    digitalWrite(enaPin1,LOW);
  }
  else
  {
    digitalWrite(enaPin1,HIGH);
  }
  if(frequency2 == 9999)
  {
    digitalWrite(enaPin2,LOW);
  }
  else
  {
    digitalWrite(enaPin2,HIGH);
  }
  
  digitalWrite(pulPin1,HIGH);
  digitalWrite(pulPin1,LOW);

  digitalWrite(pulPin2,HIGH);
  digitalWrite(pulPin2,LOW);

  long elapsedTime = 0;
  long smallerTime = 0;
  long n1 = 1, n2 = 1;
  
  while (elapsedTime <= time)
  {
    delayMicroseconds(min(n1*period1,n2*period2) - elapsedTime);
    if (n1*period1 == n2*period2)
    {
      digitalWrite(pulPin1,HIGH);
      digitalWrite(pulPin1,LOW);
      digitalWrite(pulPin2,HIGH);
      digitalWrite(pulPin2,LOW);
      elapsedTime += min(period1,period2);
      n1++;
      n2++;
    }
    else if (n1*period1 < n2*period2)
    {
      digitalWrite(pulPin1,HIGH);
      digitalWrite(pulPin1,LOW);
      elapsedTime += period1;
      n1++;
    }
    else if (n1*period1 > n2*period2)
    {
      digitalWrite(pulPin1,HIGH);
      digitalWrite(pulPin1,LOW);
      elapsedTime += period2;
      n2++;
    }
  }
}

void noTune(long time)
{
  time*=1000;
  time*=5;
  digitalWrite(enaPin1,LOW);
  digitalWrite(enaPin2,LOW);
  delayMicroseconds(time);
}

void loop()
{
  playTune(659, 370, 16);
  noTune(8);
  playTune(659, 370, 16);
  noTune(32);
  playTune(659, 370, 16);
  noTune(32);
  playTune(523, 370, 16);
  noTune(8);
  playTune(659, 370, 16);
  noTune(32);
  playTune(784, 494, 16);
  noTune(80);
  playTune(0, 392, 16);
  noTune(80);
}
