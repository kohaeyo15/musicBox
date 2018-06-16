int enPin1 = 5;
int dirPin1 = 6;
int stepPin1 = 7;
int enPin2 = 3;
int dirPin2 = 9;
int stepPin2 = 4;
int enPin3 = 10;
int dirPin3 = 11;
int stepPin3 = 12;

void setup() 
{
  //Serial.begin(9600); 
  pinMode (enPin1, OUTPUT);
  pinMode (dirPin1, OUTPUT);
  pinMode (stepPin1, OUTPUT);
  pinMode (enPin2, OUTPUT);
  pinMode (dirPin2, OUTPUT);
  pinMode (stepPin2, OUTPUT);
  pinMode (enPin3, OUTPUT);
  pinMode (dirPin3, OUTPUT);
  pinMode (stepPin3, OUTPUT);
}

void playTune(double frequency1, double frequency2, double frequency3, long timeMilli)
{
  long timeMicro = (timeMilli) * 1000;
  timeMicro*=5;
 
  if(frequency1 != 0 && frequency2 != 0 && frequency3 != 0)
  {
    double period1 = 1/frequency1;
    double period2 = 1/frequency2;
    double period3 = 1/frequency3;
    long periodMicro1 = 1000000*period1;
    long periodMicro2 = 1000000*period2;
    long periodMicro3 = 1000000*period3;

    long startingTime = micros();
    long n1 = 1, n2 = 1, n3 = 1;
    
    digitalWrite(enPin1,HIGH);
    digitalWrite(enPin2,HIGH);
    digitalWrite(enPin3,HIGH);
    digitalWrite(stepPin1,LOW);
    digitalWrite(stepPin1,HIGH);
    digitalWrite(stepPin2,LOW);
    digitalWrite(stepPin2,HIGH);
    digitalWrite(stepPin3,LOW);
    digitalWrite(stepPin3,HIGH);
    
    while (micros() <= (startingTime + timeMicro))
    {
      long minimumValue = min(min(n1*periodMicro1,n2*periodMicro2),n3*periodMicro3);
      long elapsedTime = micros()-startingTime;
      long delayFromPrevious = minimumValue - elapsedTime;
      delayMicroseconds(delayFromPrevious);
      //delayMicroseconds(min(min(n1*periodMicro1,n2*periodMicro2),n3*periodMicro3)-micros());
      
      if (n1*periodMicro1 < n2*periodMicro2)
      {
        if (n1*periodMicro1 < n3*periodMicro3)
        {
          digitalWrite(stepPin1,LOW);
          digitalWrite(stepPin1,HIGH);
          n1++;
        }
        else if (n1*periodMicro1 == n3*periodMicro3)
        {
          digitalWrite(stepPin1,LOW);
          digitalWrite(stepPin1,HIGH);
          digitalWrite(stepPin3,LOW);
          digitalWrite(stepPin3,HIGH);
          n1++;
          n3++;
        }
      }
      else if (n2*periodMicro2 < n1*periodMicro1)
      {
        if (n2*periodMicro2 < n3*periodMicro3)
        {
          digitalWrite(stepPin2,LOW);
          digitalWrite(stepPin2,HIGH);
          n2++;
        }
        else if (n2*periodMicro2 == n3*periodMicro3)
        {
          digitalWrite(stepPin2,LOW);
          digitalWrite(stepPin2,HIGH);
          digitalWrite(stepPin3,LOW);
          digitalWrite(stepPin3,HIGH);
          n2++;
          n3++;
        }
      }
      else if (n3*periodMicro3 < n1*periodMicro1)
      {
        if (n3*periodMicro3 < n2*periodMicro2)
        {
          digitalWrite(stepPin3,LOW);
          digitalWrite(stepPin3,HIGH);
          n3++;
        }
      }
      else if (n1*periodMicro1 < n3*periodMicro3)
      {
        if (n1*periodMicro1 == n2*periodMicro2)
        {
          digitalWrite(stepPin1,LOW);
          digitalWrite(stepPin1,HIGH);
          digitalWrite(stepPin2,LOW);
          digitalWrite(stepPin2,HIGH);
          n1++;
          n2++;
        }
      }
      else
      {
        digitalWrite(stepPin1,LOW);
        digitalWrite(stepPin1,HIGH);
        digitalWrite(stepPin2,LOW);
        digitalWrite(stepPin2,HIGH);
        digitalWrite(stepPin3,LOW);
        digitalWrite(stepPin3,HIGH);
        n1++;
        n1++;
        n3++;
      }
    }
  }
  else if(frequency1 == 0 && frequency2 == 0 && frequency3 == 0)
  {
    noTune(timeMilli);
  }
  else if(frequency2 == 0 && frequency3 == 0)
  {
    double period1 = 1/frequency1;
    long periodMicro1 = 1000000*period1;
    long startingTime = micros();
    
    digitalWrite(enPin1,HIGH);

    while(micros() <= (startingTime + timeMicro))
    {
      digitalWrite(stepPin1,LOW);
      digitalWrite(stepPin1,HIGH);
      delayMicroseconds(periodMicro1);
    }
  }
  else if(frequency1 == 0 && frequency3 == 0)
  {
    double period2 = 1/frequency2;
    long periodMicro2 = 1000000*period2;
    long startingTime = micros();
    
    digitalWrite(enPin2,HIGH);

    while(micros() <= (startingTime + timeMicro))
    {
      digitalWrite(stepPin2,LOW);
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(periodMicro2);
    }
  }
  else if(frequency1 == 0 && frequency2 == 0)
  {
    double period3 = 1/frequency3;
    long periodMicro3 = 1000000*period3;
    long startingTime = micros();
    
    digitalWrite(enPin3,HIGH);

    while(micros() <= (startingTime + timeMicro))
    {
      digitalWrite(stepPin3,LOW);
      digitalWrite(stepPin3,HIGH);
      delayMicroseconds(periodMicro3);
    }
  }
  else if(frequency3 == 0)
  {
    double period1 = 1/frequency1;
    double period2 = 1/frequency2;
    long periodMicro1 = 1000000*period1;
    long periodMicro2 = 1000000*period2;
    long startingTime = micros();
    long n1 = 1, n2 = 1;
    
    digitalWrite(enPin1,HIGH);
    digitalWrite(enPin2,HIGH);
    digitalWrite(stepPin1,LOW);
    digitalWrite(stepPin1,HIGH);
    digitalWrite(stepPin2,LOW);
    digitalWrite(stepPin2,HIGH);
    while (micros() <= (startingTime + timeMicro))
    {
      long minimumValue = min(n1*periodMicro1,n2*periodMicro2);
      long elapsedTime = micros()-startingTime;
      long delayFromPrevious = minimumValue - elapsedTime;
      delayMicroseconds(delayFromPrevious);
      //delayMicroseconds(min(n1*periodMicro1,n2*periodMicro2)-micros());
      if (n1*periodMicro1 == n2*periodMicro2)
      {
        digitalWrite(stepPin1,LOW);
        digitalWrite(stepPin1,HIGH);
        digitalWrite(stepPin2,LOW);
        digitalWrite(stepPin2,HIGH);
        //elapsedTime += min(periodMicro1,periodMicro2);
        n1++;
        n2++;
      }
      else if ((n1*periodMicro1) < (n2*periodMicro2))
      {
        digitalWrite(stepPin1,LOW);
        digitalWrite(stepPin1,HIGH);
        n1++;
      }
      else if ((n1*periodMicro1) > (n2*periodMicro2))
      {
        digitalWrite(stepPin2,LOW);
        digitalWrite(stepPin2,HIGH);
        n2++;
      } 
    }
  }
  else if(frequency2 == 0)
  {
    double period1 = 1/frequency1;
    double period3 = 1/frequency3;
    long periodMicro1 = 1000000*period1;
    long periodMicro3 = 1000000*period3;
    long startingTime = micros();
    long n1 = 1, n3 = 1;
    
    digitalWrite(enPin1,HIGH);
    digitalWrite(enPin3,HIGH);
    digitalWrite(stepPin1,LOW);
    digitalWrite(stepPin1,HIGH);
    digitalWrite(stepPin3,LOW);
    digitalWrite(stepPin3,HIGH);
    while (micros() <= (startingTime + timeMicro))
    {
      long minimumValue = min(n1*periodMicro1,n3*periodMicro3);
      long elapsedTime = micros()-startingTime;
      long delayFromPrevious = minimumValue - elapsedTime;
      delayMicroseconds(delayFromPrevious);
      //delayMicroseconds(min(n1*periodMicro1,n3*periodMicro3)-micros());
      if (n1*periodMicro1 == n3*periodMicro3)
      {
        digitalWrite(stepPin1,LOW);
        digitalWrite(stepPin1,HIGH);
        digitalWrite(stepPin3,LOW);
        digitalWrite(stepPin3,HIGH);
        //elapsedTime += min(periodMicro1,periodMicro2);
        n1++;
        n3++;
      }
      else if ((n1*periodMicro1) < (n3*periodMicro3))
      {
        digitalWrite(stepPin1,LOW);
        digitalWrite(stepPin1,HIGH);
        n1++;
      }
      else if ((n1*periodMicro1) > (n3*periodMicro3))
      {
        digitalWrite(stepPin3,LOW);
        digitalWrite(stepPin3,HIGH);
        n3++;
      } 
    }
  }
  else if(frequency1 == 0)
  {
    double period2 = 1/frequency2;
    double period3 = 1/frequency3;
    long periodMicro2 = 1000000*period2;
    long periodMicro3 = 1000000*period3;
    long startingTime = micros();
    long n2 = 1, n3 = 1;
    
    digitalWrite(enPin2,HIGH);
    digitalWrite(enPin3,HIGH);
    digitalWrite(stepPin2,LOW);
    digitalWrite(stepPin2,HIGH);
    digitalWrite(stepPin3,LOW);
    digitalWrite(stepPin3,HIGH);
    while (micros() <= (startingTime + timeMicro))
    {
      long minimumValue = min(n2*periodMicro2,n3*periodMicro3);
      long elapsedTime = micros()-startingTime;
      long delayFromPrevious = minimumValue - elapsedTime;
      delayMicroseconds(delayFromPrevious);
      //delayMicroseconds(min(n2*periodMicro2,n3*periodMicro3)-micros());
      if (n2*periodMicro2 == n3*periodMicro3)
      {
        digitalWrite(stepPin2,LOW);
        digitalWrite(stepPin2,HIGH);
        digitalWrite(stepPin3,LOW);
        digitalWrite(stepPin3,HIGH);
        //elapsedTime += min(periodMicro1,periodMicro2);
        n2++;
        n3++;
      }
      else if ((n2*periodMicro2) < (n3*periodMicro3))
      {
        digitalWrite(stepPin2,LOW);
        digitalWrite(stepPin2,HIGH);
        n2++;
      }
      else if ((n2*periodMicro2) > (n3*periodMicro3))
      {
        digitalWrite(stepPin3,LOW);
        digitalWrite(stepPin3,HIGH);
        n3++;
      } 
    }
  }
}

void noTune(long timeMilli)
{
  timeMilli*=5;
  digitalWrite(enPin1,LOW);
  digitalWrite(enPin2,LOW);
  delay(timeMilli);
  //Serial.print(timeMilli)
  //Serial.print("\n");
}

void loop() 
{
  playTune(659, 370, 147, 16);

  noTune(8);
  
  playTune(659, 370, 147, 16);
  
  noTune(32);
  
  playTune(659, 370, 147, 16);
  
  noTune(32);
  
  playTune(523, 370, 147, 16);
  
  noTune(8);
  
  playTune(659, 370, 147, 16);
  
  noTune(32);
  
  playTune(784, 494, 392, 16);
  
  noTune(80);
  
  playTune(0, 392, 196, 16);
  
  noTune(80);
  
  playTune(523, 330, 196, 16);
  
  noTune(56);
  
  playTune(392, 262, 165, 16);
  
  noTune(56);
  
  playTune(330, 196, 131, 16);
  
  noTune(56);
  
  playTune(440, 262, 175, 16);
  
  noTune(32);
  
  playTune(494, 294, 196, 16);
  
  noTune(32);
  
  playTune(466, 277, 185, 16);
  
  noTune(8);
  
  playTune(440, 262, 175, 16);
  
  noTune(32);
  
  playTune(392, 262, 165, 16);
  
  noTune(16);
  
  playTune(659, 392, 262, 16);
  
  noTune(16);
  
  playTune(784, 494, 330, 16);
  
  noTune(16);
  
  playTune(880, 523, 349, 16);
  
  noTune(32);
  
  playTune(698, 440, 294, 16);
  
  noTune(8);
  
  playTune(784, 494, 330, 16);
  
  noTune(32);
  
  playTune(659, 440, 262, 16);
  
  noTune(32);
  
  playTune(523, 330, 220, 16);
  
  noTune(8);
  
  playTune(587, 349, 247, 16);
  
  noTune(8);
  
  playTune(494, 294, 196, 16);
  
  noTune(56);
  
  playTune(523, 330, 196, 16);
  
  noTune(56);
  
  playTune(392, 262, 165, 16);
  
  noTune(56);
  
  playTune(330, 196, 131, 16);
  
  noTune(56);
  
  playTune(440, 262, 175, 16);
  
  noTune(32);
  
  playTune(494, 294, 196, 16);
  
  noTune(32);
  
  playTune(466, 277, 185, 16);
  
  noTune(8);
  
  playTune(440, 262, 175, 16);
  
  noTune(32);
  
  playTune(392, 262, 165, 16);
  
  noTune(16);
  
  playTune(659, 392, 262, 16);
  
  noTune(16);
  
  playTune(784, 494, 330, 16);
  
  noTune(16);
  
  playTune(880, 523, 349, 16);
  
  noTune(32);
  
  playTune(698, 440, 294, 16);
  
  noTune(8);
  
  playTune(784, 494, 330, 16);
  
  noTune(32);
  
  playTune(659, 440, 262, 16);
  
  noTune(32);
  
  playTune(523, 330, 220, 16);
  
  noTune(8);
  
  playTune(587, 349, 247, 16);
  
  noTune(8);
  
  playTune(494, 294, 196, 16);
  
  noTune(56);
  
  playTune(0, 0, 131, 16);
  
  noTune(32);
  
  playTune(784, 659, 0, 16);
  
  noTune(8);
  
  playTune(740, 622, 196, 16);
  
  noTune(8);
  
  playTune(698, 587, 0, 16);
  
  noTune(8);
  
  playTune(622, 494, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(659, 523, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(8);
  
  playTune(415, 330, 0, 16);
  
  noTune(8);
  
  playTune(440, 349, 0, 16);
  
  noTune(8);
  
  playTune(523, 392, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(440, 262, 0, 16);
  
  noTune(8);
  
  playTune(523, 330, 175, 16);
  
  noTune(8);
  
  playTune(587, 349, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 131, 16);
  
  noTune(32);
  
  playTune(784, 659, 0, 16);
  
  noTune(8);
  
  playTune(740, 622, 165, 16);
  
  noTune(8);
  
  playTune(698, 587, 0, 16);
  
  noTune(8);
  
  playTune(622, 494, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(8);
  
  playTune(659, 523, 262, 16);
  
  noTune(32);
  
  playTune(1047, 698, 784, 16);
  
  noTune(32);
  
  playTune(1047, 698, 784, 16);
  
  noTune(8);
  
  playTune(1047, 698, 784, 16);
  
  noTune(32);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(0, 0, 131, 16);
  
  noTune(32);
  
  playTune(784, 659, 0, 16);
  
  noTune(8);
  
  playTune(740, 622, 196, 16);
  
  noTune(8);
  
  playTune(698, 587, 0, 16);
  
  noTune(8);
  
  playTune(622, 494, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(659, 523, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(8);
  
  playTune(415, 330, 0, 16);
  
  noTune(8);
  
  playTune(440, 349, 0, 16);
  
  noTune(8);
  
  playTune(523, 392, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(440, 262, 0, 16);
  
  noTune(8);
  
  playTune(523, 330, 175, 16);
  
  noTune(8);
  
  playTune(587, 349, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 131, 16);
  
  noTune(32);
  
  playTune(622, 415, 208, 16);
  
  noTune(56);
  
  playTune(587, 349, 233, 16);
  
  noTune(56);
  
  playTune(523, 330, 262, 16);
  
  noTune(56);
  
  playTune(0, 0, 196, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(0, 0, 131, 16);
  
  noTune(32);
  
  playTune(0, 0, 131, 16);
  
  noTune(32);
  
  playTune(784, 659, 0, 16);
  
  noTune(8);
  
  playTune(740, 622, 196, 16);
  
  noTune(8);
  
  playTune(698, 587, 0, 16);
  
  noTune(8);
  
  playTune(622, 494, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(659, 523, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(8);
  
  playTune(415, 330, 0, 16);
  
  noTune(8);
  
  playTune(440, 349, 0, 16);
  
  noTune(8);
  
  playTune(523, 392, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(440, 262, 0, 16);
  
  noTune(8);
  
  playTune(523, 330, 175, 16);
  
  noTune(8);
  
  playTune(587, 349, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 131, 16);
  
  noTune(32);
  
  playTune(784, 659, 0, 16);
  
  noTune(8);
  
  playTune(740, 622, 165, 16);
  
  noTune(8);
  
  playTune(698, 587, 0, 16);
  
  noTune(8);
  
  playTune(622, 494, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(8);
  
  playTune(659, 523, 262, 16);
  
  noTune(32);
  
  playTune(1047, 698, 784, 16);
  
  noTune(32);
  
  playTune(1047, 698, 784, 16);
  
  noTune(8);
  
  playTune(1047, 698, 784, 16);
  
  noTune(32);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(0, 0, 131, 16);
  
  noTune(32);
  
  playTune(784, 659, 0, 16);
  
  noTune(8);
  
  playTune(740, 622, 196, 16);
  
  noTune(8);
  
  playTune(698, 587, 0, 16);
  
  noTune(8);
  
  playTune(622, 494, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(659, 523, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(8);
  
  playTune(415, 330, 0, 16);
  
  noTune(8);
  
  playTune(440, 349, 0, 16);
  
  noTune(8);
  
  playTune(523, 392, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(440, 262, 0, 16);
  
  noTune(8);
  
  playTune(523, 330, 175, 16);
  
  noTune(8);
  
  playTune(587, 349, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 131, 16);
  
  noTune(32);
  
  playTune(622, 415, 208, 16);
  
  noTune(56);
  
  playTune(587, 349, 233, 16);
  
  noTune(56);
  
  playTune(523, 330, 262, 16);
  
  noTune(56);
  
  playTune(0, 0, 196, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(0, 0, 131, 16);
  
  noTune(32);
  
  playTune(523, 415, 104, 16);
  
  noTune(8);
  
  playTune(523, 415, 0, 16);
  
  noTune(32);
  
  playTune(523, 415, 156, 16);
  
  noTune(32);
  
  playTune(523, 415, 0, 16);
  
  noTune(8);
  
  playTune(587, 466, 208, 16);
  
  noTune(32);
  
  playTune(659, 392, 196, 16);
  
  noTune(8);
  
  playTune(523, 330, 0, 16);
  
  noTune(32);
  
  playTune(440, 330, 131, 16);
  
  noTune(8);
  
  playTune(392, 262, 0, 16);
  
  noTune(32);
  
  playTune(0, 0, 98, 16);
  
  noTune(32);
  
  playTune(523, 415, 104, 16);
  
  noTune(8);
  
  playTune(523, 415, 0, 16);
  
  noTune(32);
  
  playTune(523, 415, 156, 16);
  
  noTune(32);
  
  playTune(523, 415, 0, 16);
  
  noTune(8);
  
  playTune(587, 466, 208, 16);
  
  noTune(8);
  
  playTune(659, 392, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(56);
  
  playTune(0, 0, 131, 16);
  
  noTune(56);
  
  playTune(0, 0, 98, 16);
  
  noTune(32);
  
  playTune(523, 415, 104, 16);
  
  noTune(8);
  
  playTune(523, 415, 0, 16);
  
  noTune(32);
  
  playTune(523, 415, 156, 16);
  
  noTune(32);
  
  playTune(523, 415, 0, 16);
  
  noTune(8);
  
  playTune(587, 466, 208, 16);
  
  noTune(32);
  
  playTune(659, 392, 196, 16);
  
  noTune(8);
  
  playTune(523, 330, 0, 16);
  
  noTune(32);
  
  playTune(440, 330, 131, 16);
  
  noTune(8);
  
  playTune(392, 262, 0, 16);
  
  noTune(32);
  
  playTune(0, 0, 98, 16);
  
  noTune(32);
  
  playTune(659, 370, 147, 16);
  
  noTune(8);
  
  playTune(659, 370, 147, 16);
  
  noTune(32);
  
  playTune(659, 370, 147, 16);
  
  noTune(32);
  
  playTune(523, 370, 147, 16);
  
  noTune(8);
  
  playTune(659, 370, 147, 16);
  
  noTune(32);
  
  playTune(784, 494, 392, 16);
  
  noTune(80);
  
  playTune(0, 392, 196, 16);
  
  noTune(80);
  
  playTune(523, 330, 196, 16);
  
  noTune(56);
  
  playTune(392, 262, 165, 16);
  
  noTune(56);
  
  playTune(330, 196, 131, 16);
  
  noTune(56);
  
  playTune(440, 262, 175, 16);
  
  noTune(32);
  
  playTune(494, 294, 196, 16);
  
  noTune(32);
  
  playTune(466, 277, 185, 16);
  
  noTune(8);
  
  playTune(440, 262, 175, 16);
  
  noTune(32);
  
  playTune(392, 262, 165, 16);
  
  noTune(16);
  
  playTune(659, 392, 262, 16);
  
  noTune(16);
  
  playTune(784, 494, 330, 16);
  
  noTune(16);
  
  playTune(880, 523, 349, 16);
  
  noTune(32);
  
  playTune(698, 440, 294, 16);
  
  noTune(8);
  
  playTune(784, 494, 330, 16);
  
  noTune(32);
  
  playTune(659, 440, 262, 16);
  
  noTune(32);
  
  playTune(523, 330, 220, 16);
  
  noTune(8);
  
  playTune(587, 349, 247, 16);
  
  noTune(8);
  
  playTune(494, 294, 196, 16);
  
  noTune(56);
  
  playTune(523, 330, 196, 16);
  
  noTune(56);
  
  playTune(392, 262, 165, 16);
  
  noTune(56);
  
  playTune(330, 196, 131, 16);
  
  noTune(56);
  
  playTune(440, 262, 175, 16);
  
  noTune(32);
  
  playTune(494, 294, 196, 16);
  
  noTune(32);
  
  playTune(466, 277, 185, 16);
  
  noTune(8);
  
  playTune(440, 262, 175, 16);
  
  noTune(32);
  
  playTune(392, 262, 165, 16);
  
  noTune(16);
  
  playTune(659, 392, 262, 16);
  
  noTune(16);
  
  playTune(784, 494, 330, 16);
  
  noTune(16);
  
  playTune(880, 523, 349, 16);
  
  noTune(32);
  
  playTune(698, 440, 294, 16);
  
  noTune(8);
  
  playTune(784, 494, 330, 16);
  
  noTune(32);
  
  playTune(659, 440, 262, 16);
  
  noTune(32);
  
  playTune(523, 330, 220, 16);
  
  noTune(8);
  
  playTune(587, 349, 247, 16);
  
  noTune(8);
  
  playTune(494, 294, 196, 16);
  
  noTune(56);
  
  playTune(659, 523, 131, 16);
  
  noTune(8);
  
  playTune(523, 440, 0, 16);
  
  noTune(32);
  
  playTune(392, 330, 185, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(415, 330, 262, 16);
  
  noTune(32);
  
  playTune(440, 349, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(440, 349, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(32);
  
  playTune(494, 392, 147, 16);
  
  noTune(16);
  
  playTune(880, 698, 0, 16);
  
  noTune(16);
  
  playTune(880, 698, 0, 8);
  
  playTune(0, 0, 175, 8);
  
  noTune(8);
  
  noTune(8);
  
  playTune(880, 698, 196, 16);
  
  noTune(16);
  
  playTune(784, 659, 0, 16);
  
  playTune(0, 0, 247, 16);
  
  playTune(698, 587, 0, 16);
  
  noTune(16);
  
  playTune(659, 523, 196, 16);
  
  noTune(8);
  
  playTune(523, 440, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(8);
  
  playTune(440, 349, 0, 16);
  
  noTune(8);
  
  playTune(392, 330, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(659, 523, 131, 16);
  
  noTune(8);
  
  playTune(523, 440, 0, 16);
  
  noTune(32);
  
  playTune(392, 330, 185, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(415, 330, 262, 16);
  
  noTune(32);
  
  playTune(440, 349, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(440, 349, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(32);
  
  playTune(494, 392, 196, 16);
  
  noTune(8);
  
  playTune(698, 587, 196, 16);
  
  noTune(32);
  
  playTune(698, 587, 196, 16);
  
  noTune(8);
  
  playTune(698, 587, 196, 16);
  
  noTune(16);
  
  playTune(659, 523, 220, 16);
  
  noTune(16);
  
  playTune(587, 494, 247, 16);
  
  noTune(16);
  
  playTune(523, 392, 262, 16);
  
  noTune(8);
  
  playTune(0, 330, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(8);
  
  playTune(0, 330, 0, 16);
  
  noTune(8);
  
  playTune(0, 262, 131, 16);
  
  noTune(80);
  
  playTune(659, 523, 131, 16);
  
  noTune(8);
  
  playTune(523, 440, 0, 16);
  
  noTune(32);
  
  playTune(392, 330, 185, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(415, 330, 262, 16);
  
  noTune(32);
  
  playTune(440, 349, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(440, 349, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(32);
  
  playTune(494, 392, 147, 16);
  
  noTune(16);
  
  playTune(880, 698, 0, 16);
  
  noTune(16);
  
  playTune(880, 698, 0, 8);
  
  playTune(0, 0, 175, 8);
  
  noTune(8);
  
  noTune(8);
  
  playTune(880, 698, 196, 16);
  
  noTune(16);
  
  playTune(784, 659, 0, 16);
  
  playTune(0, 0, 247, 16);
  
  playTune(698, 587, 0, 16);
  
  noTune(16);
  
  playTune(659, 523, 196, 16);
  
  noTune(8);
  
  playTune(523, 440, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(8);
  
  playTune(440, 349, 0, 16);
  
  noTune(8);
  
  playTune(392, 330, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(659, 523, 131, 16);
  
  noTune(8);
  
  playTune(523, 440, 0, 16);
  
  noTune(32);
  
  playTune(392, 330, 185, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(415, 330, 262, 16);
  
  noTune(32);
  
  playTune(440, 349, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(440, 349, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(32);
  
  playTune(494, 392, 196, 16);
  
  noTune(8);
  
  playTune(698, 587, 196, 16);
  
  noTune(32);
  
  playTune(698, 587, 196, 16);
  
  noTune(8);
  
  playTune(698, 587, 196, 16);
  
  noTune(16);
  
  playTune(659, 523, 220, 16);
  
  noTune(16);
  
  playTune(587, 494, 247, 16);
  
  noTune(16);
  
  playTune(523, 392, 262, 16);
  
  noTune(8);
  
  playTune(0, 330, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(8);
  
  playTune(0, 330, 0, 16);
  
  noTune(8);
  
  playTune(0, 262, 131, 16);
  
  noTune(80);
  
  playTune(523, 415, 104, 16);
  
  noTune(8);
  
  playTune(523, 415, 0, 16);
  
  noTune(32);
  
  playTune(523, 415, 156, 16);
  
  noTune(32);
  
  playTune(523, 415, 0, 16);
  
  noTune(8);
  
  playTune(587, 466, 208, 16);
  
  noTune(32);
  
  playTune(659, 392, 196, 16);
  
  noTune(8);
  
  playTune(523, 330, 0, 16);
  
  noTune(32);
  
  playTune(440, 330, 131, 16);
  
  noTune(8);
  
  playTune(392, 262, 0, 16);
  
  noTune(32);
  
  playTune(0, 0, 98, 16);
  
  noTune(32);
  
  playTune(523, 415, 104, 16);
  
  noTune(8);
  
  playTune(523, 415, 0, 16);
  
  noTune(32);
  
  playTune(523, 415, 156, 16);
  
  noTune(32);
  
  playTune(523, 415, 0, 16);
  
  noTune(8);
  
  playTune(587, 466, 208, 16);
  
  noTune(8);
  
  playTune(659, 392, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(56);
  
  playTune(0, 0, 131, 16);
  
  noTune(56);
  
  playTune(0, 0, 98, 16);
  
  noTune(32);
  
  playTune(523, 415, 104, 16);
  
  noTune(8);
  
  playTune(523, 415, 0, 16);
  
  noTune(32);
  
  playTune(523, 415, 156, 16);
  
  noTune(32);
  
  playTune(523, 415, 0, 16);
  
  noTune(8);
  
  playTune(587, 466, 208, 16);
  
  noTune(32);
  
  playTune(659, 392, 196, 16);
  
  noTune(8);
  
  playTune(523, 330, 0, 16);
  
  noTune(32);
  
  playTune(440, 330, 131, 16);
  
  noTune(8);
  
  playTune(392, 262, 0, 16);
  
  noTune(32);
  
  playTune(0, 0, 98, 16);
  
  noTune(32);
  
  playTune(659, 370, 147, 16);
  
  noTune(8);
  
  playTune(659, 370, 147, 16);
  
  noTune(32);
  
  playTune(659, 370, 147, 16);
  
  noTune(32);
  
  playTune(523, 370, 147, 16);
  
  noTune(8);
  
  playTune(659, 370, 147, 16);
  
  noTune(32);
  
  playTune(784, 494, 392, 16);
  
  noTune(80);
  
  playTune(0, 392, 196, 16);
  
  noTune(80);
  
  playTune(659, 523, 131, 16);
  
  noTune(8);
  
  playTune(523, 440, 0, 16);
  
  noTune(32);
  
  playTune(392, 330, 185, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(415, 330, 262, 16);
  
  noTune(32);
  
  playTune(440, 349, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(440, 349, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(32);
  
  playTune(494, 392, 147, 16);
  
  noTune(16);
  
  playTune(880, 698, 0, 16);
  
  noTune(16);
  
  playTune(880, 698, 0, 8);
  
  playTune(0, 0, 175, 8);
  
  noTune(8);
  
  noTune(8);
  
  playTune(880, 698, 196, 16);
  
  noTune(16);
  
  playTune(784, 659, 0, 16);
  
  playTune(0, 0, 247, 16);
  
  playTune(698, 587, 0, 16);
  
  noTune(16);
  
  playTune(659, 523, 196, 16);
  
  noTune(8);
  
  playTune(523, 440, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(8);
  
  playTune(440, 349, 0, 16);
  
  noTune(8);
  
  playTune(392, 330, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(659, 523, 131, 16);
  
  noTune(8);
  
  playTune(523, 440, 0, 16);
  
  noTune(32);
  
  playTune(392, 330, 185, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(32);
  
  playTune(415, 330, 262, 16);
  
  noTune(32);
  
  playTune(440, 349, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(8);
  
  playTune(698, 523, 0, 16);
  
  noTune(8);
  
  playTune(440, 349, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 262, 16);
  
  noTune(8);
  
  playTune(0, 0, 175, 16);
  
  noTune(32);
  
  playTune(494, 392, 196, 16);
  
  noTune(8);
  
  playTune(698, 587, 196, 16);
  
  noTune(32);
  
  playTune(698, 587, 196, 16);
  
  noTune(8);
  
  playTune(698, 587, 196, 16);
  
  noTune(16);
  
  playTune(659, 523, 220, 16);
  
  noTune(16);
  
  playTune(587, 494, 247, 16);
  
  noTune(16);
  
  playTune(523, 392, 262, 16);
  
  noTune(8);
  
  playTune(0, 330, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 196, 16);
  
  noTune(8);
  
  playTune(0, 330, 0, 16);
  
  noTune(8);
  
  playTune(0, 262, 131, 16);
  
  noTune(16);
}

