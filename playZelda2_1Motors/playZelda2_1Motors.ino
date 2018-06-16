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

void playTune(double frequency1, double frequency2, long timeMilli)
{
  long timeMicro = (timeMilli) * 1000;
  //timeMicro*=5;
 
  if(frequency1 != 0 && frequency2 != 0)
  {
    double period1 = 1/frequency1;
    double period2 = 1/frequency2;
    long periodMicro1 = 1000000*period1;
    long periodMicro2 = 1000000*period2;
    long startingTime = micros();
    long n1 = 1, n2 = 1;    
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
      long minimumValue = min(n1*periodMicro1,n2*periodMicro2);
      long elapsedTime = micros()-startingTime;
      long delayFromPrevious = minimumValue - elapsedTime;

      /*Serial.print("minimumValue = ");
      Serial.print(minimumValue);
      Serial.print("\n");
      Serial.print("elapsedTime = ");
      Serial.print(elapsedTime);
      Serial.print("\n");
      Serial.print("delayFromPrevious = ");
      Serial.print(delayFromPrevious);
      Serial.print("\n");
      Serial.print("\n");*/
      
      delayMicroseconds(delayFromPrevious);
      
      /*Serial.print("delayFromPrevious = ");
      Serial.print(delayFromPrevious);
      Serial.print("\n");*/
      
      if (n1*periodMicro1 == n2*periodMicro2)
      {
        digitalWrite(stepPin1,LOW);
        digitalWrite(stepPin1,HIGH);
        digitalWrite(stepPin2,LOW);
        digitalWrite(stepPin2,HIGH);
        digitalWrite(stepPin3,LOW);
        digitalWrite(stepPin3,HIGH);
        //elapsedTime += min(periodMicro1,periodMicro2);
        n1++;
        n2++;
      }
      else if ((n1*periodMicro1) < (n2*periodMicro2))
      {
        digitalWrite(stepPin1,LOW);
        digitalWrite(stepPin1,HIGH);
        digitalWrite(stepPin3,LOW);
        digitalWrite(stepPin3,HIGH);
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
  else if(frequency1 == 0 && frequency2 == 0)
  {
    noTune(timeMilli);
  }
  else if(frequency2 == 0)
  {
    double period1 = 1/frequency1;
    long periodMicro1 = 1000000*period1;

    long startingTime = micros();
    
    digitalWrite(enPin1,HIGH);

    while(micros() <= (startingTime + timeMicro))
    {
      digitalWrite(stepPin1,LOW);
      digitalWrite(stepPin1,HIGH);
      digitalWrite(stepPin3,LOW);
      digitalWrite(stepPin3,HIGH);
      delayMicroseconds(periodMicro1);
    }
  }
  else if(frequency1 == 0)
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
}

void noTune(long timeMilli)
{
  //timeMilli*=5;
  digitalWrite(enPin1,LOW);
  digitalWrite(enPin2,LOW);
  digitalWrite(enPin3,LOW);
  delay(timeMilli);
  //Serial.print(timeMilli);
  //Serial.print("\n");
}

void loop() 
{
  playTune(466, 294, 768);
  
  noTune(256);
  
  playTune(466, 294, 84);
  
  noTune(44);
  
  playTune(466, 294, 84);
  
  noTune(44);
  
  playTune(466, 294, 84);
  
  noTune(44);
  
  playTune(466, 294, 84);
  
  noTune(44);
  
  playTune(466, 262, 124);
  
  noTune(132);
  
  playTune(415, 262, 84);
  
  noTune(44);
  
  playTune(466, 262, 512);
  
  noTune(128);
  
  playTune(466, 0 , 84);
  
  noTune(44);
  
  playTune(466, 262, 84);
  
  noTune(44);
  
  playTune(466, 262, 84);
  
  noTune(44);
  
  playTune(466, 262, 84);
  
  noTune(44);
  
  playTune(466, 277, 124);
  
  noTune(132);
  
  playTune(415, 277, 84);
  
  noTune(44);
  
  playTune(466, 277, 572);
  
  noTune(68);
  
  playTune(466, 277, 84);
  
  noTune(44);
  
  playTune(466, 277, 84);
  
  noTune(44);
  
  playTune(466, 277, 84);
  
  noTune(44);
  
  playTune(466, 277, 84);
  
  noTune(44);
  
  playTune(466, 277, 128);
  
  noTune(60);
  
  noTune(4);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 128);
  
  noTune(64);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 128);
  
  noTune(64);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 128);
  
  noTune(64);
  
  playTune(349, 220, 128);
  
  noTune(64);
  
  playTune(466, 294, 256);
  
  noTune(128);
  
  playTune(349, 294, 124);
  
  noTune(4);
  
  playTune(0, 294, 124);
  
  noTune(4);
  
  playTune(0, 262, 124);
  
  noTune(4);
  
  playTune(0, 294, 188);
  
  noTune(100);
  
  playTune(466, 294, 92);
  
  noTune(4);
  
  playTune(466, 294, 92);
  
  noTune(4);
  
  playTune(523, 311, 92);
  
  noTune(4);
  
  playTune(587, 349, 92);
  
  noTune(4);
  
  playTune(622, 392, 92);
  
  noTune(4);
  
  playTune(698, 415, 284);
  
  noTune(4);
  
  playTune(0, 466, 92);
  
  noTune(4);
  
  playTune(0, 466, 92);
  
  noTune(4);
  
  playTune(0, 523, 92);
  
  noTune(4);
  
  playTune(0, 587, 92);
  
  noTune(4);
  
  playTune(0, 622, 92);
  
  noTune(4);
  
  playTune(0, 698, 188);
  
  noTune(4);
  
  playTune(698, 698, 128);
  
  noTune(60);
  
  noTune(4);
  
  playTune(698, 415, 124);
  
  noTune(4);
  
  playTune(740, 466, 124);
  
  noTune(4);
  
  playTune(831, 523, 124);
  
  noTune(4);
  
  playTune(932, 554, 284);
  
  noTune(4);
  
  playTune(0, 370, 92);
  
  noTune(4);
  
  playTune(0, 370, 92);
  
  noTune(4);
  
  playTune(0, 415, 92);
  
  noTune(4);
  
  playTune(0, 466, 92);
  
  noTune(4);
  
  playTune(0, 523, 92);
  
  noTune(4);
  
  playTune(0, 554, 124);
  
  noTune(4);
  
  playTune(932, 0 , 60);
  
  noTune(4);
  
  playTune(0, 554, 60);
  
  noTune(4);
  
  playTune(932, 0 , 124);
  
  noTune(4);
  
  playTune(932, 554, 124);
  
  noTune(4);
  
  playTune(831, 523, 124);
  
  noTune(4);
  
  playTune(740, 466, 124);
  
  noTune(4);
  
  playTune(831, 554, 124);
  
  noTune(132);
  
  playTune(740, 415, 124);
  
  noTune(4);
  
  playTune(698, 415, 124);
  
  noTune(4);
  
  playTune(0, 415, 124);
  
  noTune(4);
  
  playTune(0, 370, 124);
  
  noTune(4);
  
  playTune(0, 415, 124);
  
  noTune(132);
  
  playTune(0, 415, 124);
  
  noTune(4);
  
  playTune(698, 415, 124);
  
  noTune(4);
  
  playTune(0, 370, 124);
  
  noTune(4);
  
  playTune(0, 415, 124);
  
  noTune(4);
  
  playTune(622, 370, 188);
  
  noTune(4);
  
  playTune(622, 0 , 44);
  
  noTune(20);
  
  playTune(0, 370, 28);
  
  noTune(4);
  
  playTune(698, 0 , 28);
  
  noTune(4);
  
  playTune(0, 349, 60);
  
  noTune(4);
  
  playTune(740, 370, 256);
  
  playTune(0, 370, 28);
  
  noTune(32);
  
  noTune(4);
  
  playTune(0, 415, 60);
  
  noTune(4);
  
  playTune(0, 466, 380);
  
  noTune(4);
  
  playTune(698, 415, 188);
  
  noTune(4);
  
  playTune(622, 370, 188);
  
  noTune(4);
  
  playTune(554, 349, 188);
  
  noTune(4);
  
  playTune(554, 0 , 64);
  
  playTune(0, 349, 28);
  
  noTune(4);
  
  playTune(622, 0 , 28);
  
  noTune(4);
  
  playTune(0, 311, 60);
  
  noTune(4);
  
  playTune(698, 349, 256);
  
  playTune(0, 349, 28);
  
  noTune(32);
  
  noTune(4);
  
  playTune(0, 370, 60);
  
  noTune(4);
  
  playTune(0, 415, 380);
  
  noTune(4);
  
  playTune(622, 370, 188);
  
  noTune(4);
  
  playTune(554, 349, 188);
  
  noTune(4);
  
  playTune(523, 330, 188);
  
  noTune(4);
  
  playTune(523, 0 , 92);
  
  noTune(4);
  
  playTune(587, 0 , 92);
  
  noTune(4);
  
  playTune(659, 330, 284);
  
  noTune(4);
  
  playTune(0, 349, 92);
  
  noTune(4);
  
  playTune(0, 392, 256);
  
  playTune(0, 392, 28);
  
  noTune(32);
  
  noTune(4);
  
  playTune(0, 440, 60);
  
  noTune(4);
  
  playTune(784, 466, 188);
  
  noTune(4);
  
  playTune(0, 523, 188);
  
  noTune(4);
  
  playTune(698, 440, 128);
  
  noTune(64);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 128);
  
  noTune(64);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 128);
  
  noTune(64);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 128);
  
  noTune(64);
  
  playTune(349, 220, 128);
  
  noTune(64);
  
  playTune(466, 294, 256);
  
  noTune(128);
  
  playTune(349, 294, 124);
  
  noTune(4);
  
  playTune(0, 294, 124);
  
  noTune(4);
  
  playTune(0, 262, 124);
  
  noTune(4);
  
  playTune(0, 294, 188);
  
  noTune(100);
  
  playTune(466, 294, 92);
  
  noTune(4);
  
  playTune(466, 294, 92);
  
  noTune(4);
  
  playTune(523, 311, 92);
  
  noTune(4);
  
  playTune(587, 349, 92);
  
  noTune(4);
  
  playTune(622, 392, 92);
  
  noTune(4);
  
  playTune(698, 415, 284);
  
  noTune(4);
  
  playTune(0, 466, 92);
  
  noTune(4);
  
  playTune(0, 466, 92);
  
  noTune(4);
  
  playTune(0, 523, 92);
  
  noTune(4);
  
  playTune(0, 587, 92);
  
  noTune(4);
  
  playTune(0, 622, 92);
  
  noTune(4);
  
  playTune(0, 698, 188);
  
  noTune(4);
  
  playTune(698, 698, 128);
  
  noTune(60);
  
  noTune(4);
  
  playTune(698, 415, 124);
  
  noTune(4);
  
  playTune(740, 466, 124);
  
  noTune(4);
  
  playTune(831, 523, 124);
  
  noTune(4);
  
  playTune(932, 554, 1148);
  
  noTune(4);
  
  playTune(1109, 659, 380);
  
  noTune(4);
  
  playTune(1047, 622, 192);
  
  noTune(192);
  
  playTune(880, 523, 640);
  
  noTune(128);
  
  playTune(698, 440, 380);
  
  noTune(4);
  
  playTune(740, 494, 832);
  
  noTune(320);
  
  playTune(932, 554, 380);
  
  noTune(4);
  
  playTune(880, 523, 188);
  
  noTune(4);
  
  noTune(192);
  
  playTune(698, 440, 640);
  
  noTune(128);
  
  playTune(698, 440, 380);
  
  noTune(4);
  
  playTune(740, 494, 764);
  
  noTune(388);
  
  playTune(932, 554, 380);
  
  noTune(4);
  
  playTune(880, 523, 188);
  
  noTune(196);
  
  playTune(698, 440, 764);
  
  noTune(4);
  
  playTune(587, 440, 380);
  
  noTune(4);
  
  playTune(622, 370, 764);
  
  noTune(388);
  
  playTune(740, 494, 380);
  
  noTune(4);
  
  playTune(698, 466, 188);
  
  noTune(196);
  
  playTune(554, 349, 764);
  
  noTune(4);
  
  playTune(466, 277, 380);
  
  noTune(4);
  
  playTune(523, 330, 188);
  
  noTune(4);
  
  playTune(523, 0 , 92);
  
  noTune(4);
  
  playTune(587, 0 , 92);
  
  noTune(4);
  
  playTune(659, 330, 284);
  
  noTune(4);
  
  playTune(0, 349, 92);
  
  noTune(4);
  
  playTune(0, 392, 256);
  
  playTune(0, 392, 28);
  
  noTune(32);
  
  noTune(4);
  
  playTune(0, 440, 60);
  
  noTune(4);
  
  playTune(784, 466, 188);
  
  noTune(4);
  
  playTune(0, 523, 188);
  
  noTune(4);
  
  playTune(698, 440, 128);
  
  noTune(64);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 128);
  
  noTune(64);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 128);
  
  noTune(64);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 64);
  
  noTune(32);
  
  playTune(349, 220, 128);
  
  noTune(64);
  
  playTune(349, 220, 128);
  
  noTune(200);
}

