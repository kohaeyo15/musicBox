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
  timeMicro*=5;
 
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
  timeMilli*=5;
  digitalWrite(enPin1,LOW);
  digitalWrite(enPin2,LOW);
  digitalWrite(enPin3,LOW);
  delay(timeMilli);
  //Serial.print(timeMilli);
  //Serial.print("\n");
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
  
  playTune(523, 330, 16);
  
  noTune(56);
  
  playTune(392, 262, 16);
  
  noTune(56);
  
  playTune(330, 196, 16);
  
  noTune(56);
  
  playTune(440, 262, 16);
  
  noTune(32);
  
  playTune(494, 294, 16);
  
  noTune(32);
  
  playTune(466, 277, 16);
  
  noTune(8);
  
  playTune(440, 262, 16);
  
  noTune(32);
  
  playTune(392, 262, 16);
  
  noTune(16);
  
  playTune(659, 392, 16);
  
  noTune(16);
  
  playTune(784, 494, 16);
  
  noTune(16);
  
  playTune(880, 523, 16);
  
  noTune(32);
  
  playTune(698, 440, 16);
  
  noTune(8);
  
  playTune(784, 494, 16);
  
  noTune(32);
  
  playTune(659, 440, 16);
  
  noTune(32);
  
  playTune(523, 330, 16);
  
  noTune(8);
  
  playTune(587, 349, 16);
  
  noTune(8);
  
  playTune(494, 294, 16);
  
  noTune(56);
  
  playTune(523, 330, 16);
  
  noTune(56);
  
  playTune(392, 262, 16);
  
  noTune(56);
  
  playTune(330, 196, 16);
  
  noTune(56);
  
  playTune(440, 262, 16);
  
  noTune(32);
  
  playTune(494, 294, 16);
  
  noTune(32);
  
  playTune(466, 277, 16);
  
  noTune(8);
  
  playTune(440, 262, 16);
  
  noTune(32);
  
  playTune(392, 262, 16);
  
  noTune(16);
  
  playTune(659, 392, 16);
  
  noTune(16);
  
  playTune(784, 494, 16);
  
  noTune(16);
  
  playTune(880, 523, 16);
  
  noTune(32);
  
  playTune(698, 440, 16);
  
  noTune(8);
  
  playTune(784, 494, 16);
  
  noTune(32);
  
  playTune(659, 440, 16);
  
  noTune(32);
  
  playTune(523, 330, 16);
  
  noTune(8);
  
  playTune(587, 349, 16);
  
  noTune(8);
  
  playTune(494, 294, 16);
  
  noTune(104);
  
  playTune(784, 659, 16);
  
  noTune(8);
  
  playTune(740, 622, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(8);
  
  playTune(622, 494, 16);
  
  noTune(32);
  
  playTune(659, 523, 16);
  
  noTune(32);
  
  playTune(415, 330, 16);
  
  noTune(8);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(523, 392, 16);
  
  noTune(32);
  
  playTune(440, 262, 16);
  
  noTune(8);
  
  playTune(523, 330, 16);
  
  noTune(8);
  
  playTune(587, 349, 16);
  
  noTune(56);
  
  playTune(784, 659, 16);
  
  noTune(8);
  
  playTune(740, 622, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(8);
  
  playTune(622, 494, 16);
  
  noTune(32);
  
  playTune(659, 523, 16);
  
  noTune(32);
  
  playTune(1047, 698, 16);
  
  noTune(32);
  
  playTune(1047, 698, 16);
  
  noTune(8);
  
  playTune(1047, 698, 16);
  
  noTune(128);
  
  playTune(784, 659, 16);
  
  noTune(8);
  
  playTune(740, 622, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(8);
  
  playTune(622, 494, 16);
  
  noTune(32);
  
  playTune(659, 523, 16);
  
  noTune(32);
  
  playTune(415, 330, 16);
  
  noTune(8);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(523, 392, 16);
  
  noTune(32);
  
  playTune(440, 262, 16);
  
  noTune(8);
  
  playTune(523, 330, 16);
  
  noTune(8);
  
  playTune(587, 349, 16);
  
  noTune(56);
  
  playTune(622, 415, 16);
  
  noTune(56);
  
  playTune(587, 349, 16);
  
  noTune(56);
  
  playTune(523, 330, 16);
  
  noTune(224);
  
  playTune(784, 659, 16);
  
  noTune(8);
  
  playTune(740, 622, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(8);
  
  playTune(622, 494, 16);
  
  noTune(32);
  
  playTune(659, 523, 16);
  
  noTune(32);
  
  playTune(415, 330, 16);
  
  noTune(8);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(523, 392, 16);
  
  noTune(32);
  
  playTune(440, 262, 16);
  
  noTune(8);
  
  playTune(523, 330, 16);
  
  noTune(8);
  
  playTune(587, 349, 16);
  
  noTune(56);
  
  playTune(784, 659, 16);
  
  noTune(8);
  
  playTune(740, 622, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(8);
  
  playTune(622, 494, 16);
  
  noTune(32);
  
  playTune(659, 523, 16);
  
  noTune(32);
  
  playTune(1047, 698, 16);
  
  noTune(32);
  
  playTune(1047, 698, 16);
  
  noTune(8);
  
  playTune(1047, 698, 16);
  
  noTune(128);
  
  playTune(784, 659, 16);
  
  noTune(8);
  
  playTune(740, 622, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(8);
  
  playTune(622, 494, 16);
  
  noTune(32);
  
  playTune(659, 523, 16);
  
  noTune(32);
  
  playTune(415, 330, 16);
  
  noTune(8);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(523, 392, 16);
  
  noTune(32);
  
  playTune(440, 262, 16);
  
  noTune(8);
  
  playTune(523, 330, 16);
  
  noTune(8);
  
  playTune(587, 349, 16);
  
  noTune(56);
  
  playTune(622, 415, 16);
  
  noTune(56);
  
  playTune(587, 349, 16);
  
  noTune(56);
  
  playTune(523, 330, 16);
  
  noTune(176);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(587, 466, 16);
  
  noTune(32);
  
  playTune(659, 392, 16);
  
  noTune(8);
  
  playTune(523, 330, 16);
  
  noTune(32);
  
  playTune(440, 330, 16);
  
  noTune(8);
  
  playTune(392, 262, 16);
  
  noTune(80);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(587, 466, 16);
  
  noTune(8);
  
  playTune(659, 392, 16);
  
  noTune(200);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(587, 466, 16);
  
  noTune(32);
  
  playTune(659, 392, 16);
  
  noTune(8);
  
  playTune(523, 330, 16);
  
  noTune(32);
  
  playTune(440, 330, 16);
  
  noTune(8);
  
  playTune(392, 262, 16);
  
  noTune(80);
  
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
  
  playTune(523, 330, 16);
  
  noTune(56);
  
  playTune(392, 262, 16);
  
  noTune(56);
  
  playTune(330, 196, 16);
  
  noTune(56);
  
  playTune(440, 262, 16);
  
  noTune(32);
  
  playTune(494, 294, 16);
  
  noTune(32);
  
  playTune(466, 277, 16);
  
  noTune(8);
  
  playTune(440, 262, 16);
  
  noTune(32);
  
  playTune(392, 262, 16);
  
  noTune(16);
  
  playTune(659, 392, 16);
  
  noTune(16);
  
  playTune(784, 494, 16);
  
  noTune(16);
  
  playTune(880, 523, 16);
  
  noTune(32);
  
  playTune(698, 440, 16);
  
  noTune(8);
  
  playTune(784, 494, 16);
  
  noTune(32);
  
  playTune(659, 440, 16);
  
  noTune(32);
  
  playTune(523, 330, 16);
  
  noTune(8);
  
  playTune(587, 349, 16);
  
  noTune(8);
  
  playTune(494, 294, 16);
  
  noTune(56);
  
  playTune(523, 330, 16);
  
  noTune(56);
  
  playTune(392, 262, 16);
  
  noTune(56);
  
  playTune(330, 196, 16);
  
  noTune(56);
  
  playTune(440, 262, 16);
  
  noTune(32);
  
  playTune(494, 294, 16);
  
  noTune(32);
  
  playTune(466, 277, 16);
  
  noTune(8);
  
  playTune(440, 262, 16);
  
  noTune(32);
  
  playTune(392, 262, 16);
  
  noTune(16);
  
  playTune(659, 392, 16);
  
  noTune(16);
  
  playTune(784, 494, 16);
  
  noTune(16);
  
  playTune(880, 523, 16);
  
  noTune(32);
  
  playTune(698, 440, 16);
  
  noTune(8);
  
  playTune(784, 494, 16);
  
  noTune(32);
  
  playTune(659, 440, 16);
  
  noTune(32);
  
  playTune(523, 330, 16);
  
  noTune(8);
  
  playTune(587, 349, 16);
  
  noTune(8);
  
  playTune(494, 294, 16);
  
  noTune(56);
  
  playTune(659, 523, 16);
  
  noTune(8);
  
  playTune(523, 440, 16);
  
  noTune(32);
  
  playTune(392, 330, 16);
  
  noTune(56);
  
  playTune(415, 330, 16);
  
  noTune(32);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(698, 523, 16);
  
  noTune(32);
  
  playTune(698, 523, 16);
  
  noTune(8);
  
  playTune(440, 349, 16);
  
  noTune(80);
  
  playTune(494, 392, 16);
  
  noTune(16);
  
  playTune(880, 698, 16);
  
  noTune(16);
  
  playTune(880, 698, 16);
  
  noTune(16);
  
  playTune(880, 698, 16);
  
  noTune(16);
  
  playTune(784, 659, 16);
  
  noTune(16);
  
  playTune(698, 587, 16);
  
  noTune(16);
  
  playTune(659, 523, 16);
  
  noTune(8);
  
  playTune(523, 440, 16);
  
  noTune(32);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(392, 330, 16);
  
  noTune(80);
  
  playTune(659, 523, 16);
  
  noTune(8);
  
  playTune(523, 440, 16);
  
  noTune(32);
  
  playTune(392, 330, 16);
  
  noTune(56);
  
  playTune(415, 330, 16);
  
  noTune(32);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(698, 523, 16);
  
  noTune(32);
  
  playTune(698, 523, 16);
  
  noTune(8);
  
  playTune(440, 349, 16);
  
  noTune(80);
  
  playTune(494, 392, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(32);
  
  playTune(698, 587, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(16);
  
  playTune(659, 523, 16);
  
  noTune(16);
  
  playTune(587, 494, 16);
  
  noTune(16);
  
  playTune(523, 392, 16);
  
  noTune(8);
  
  playTune(0, 330, 16);
  
  noTune(32);
  
  playTune(0, 330, 16);
  
  noTune(8);
  
  playTune(0, 262, 16);
  
  noTune(80);
  
  playTune(659, 523, 16);
  
  noTune(8);
  
  playTune(523, 440, 16);
  
  noTune(32);
  
  playTune(392, 330, 16);
  
  noTune(56);
  
  playTune(415, 330, 16);
  
  noTune(32);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(698, 523, 16);
  
  noTune(32);
  
  playTune(698, 523, 16);
  
  noTune(8);
  
  playTune(440, 349, 16);
  
  noTune(80);
  
  playTune(494, 392, 16);
  
  noTune(16);
  
  playTune(880, 698, 16);
  
  noTune(16);
  
  playTune(880, 698, 16);
  
  noTune(16);
  
  playTune(880, 698, 16);
  
  noTune(16);
  
  playTune(784, 659, 16);
  
  noTune(16);
  
  playTune(698, 587, 16);
  
  noTune(16);
  
  playTune(659, 523, 16);
  
  noTune(8);
  
  playTune(523, 440, 16);
  
  noTune(32);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(392, 330, 16);
  
  noTune(80);
  
  playTune(659, 523, 16);
  
  noTune(8);
  
  playTune(523, 440, 16);
  
  noTune(32);
  
  playTune(392, 330, 16);
  
  noTune(56);
  
  playTune(415, 330, 16);
  
  noTune(32);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(698, 523, 16);
  
  noTune(32);
  
  playTune(698, 523, 16);
  
  noTune(8);
  
  playTune(440, 349, 16);
  
  noTune(80);
  
  playTune(494, 392, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(32);
  
  playTune(698, 587, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(16);
  
  playTune(659, 523, 16);
  
  noTune(16);
  
  playTune(587, 494, 16);
  
  noTune(16);
  
  playTune(523, 392, 16);
  
  noTune(8);
  
  playTune(0, 330, 16);
  
  noTune(32);
  
  playTune(0, 330, 16);
  
  noTune(8);
  
  playTune(0, 262, 16);
  
  noTune(80);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(587, 466, 16);
  
  noTune(32);
  
  playTune(659, 392, 16);
  
  noTune(8);
  
  playTune(523, 330, 16);
  
  noTune(32);
  
  playTune(440, 330, 16);
  
  noTune(8);
  
  playTune(392, 262, 16);
  
  noTune(80);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(587, 466, 16);
  
  noTune(8);
  
  playTune(659, 392, 16);
  
  noTune(200);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(32);
  
  playTune(523, 415, 16);
  
  noTune(8);
  
  playTune(587, 466, 16);
  
  noTune(32);
  
  playTune(659, 392, 16);
  
  noTune(8);
  
  playTune(523, 330, 16);
  
  noTune(32);
  
  playTune(440, 330, 16);
  
  noTune(8);
  
  playTune(392, 262, 16);
  
  noTune(80);
  
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
  
  playTune(659, 523, 16);
  
  noTune(8);
  
  playTune(523, 440, 16);
  
  noTune(32);
  
  playTune(392, 330, 16);
  
  noTune(56);
  
  playTune(415, 330, 16);
  
  noTune(32);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(698, 523, 16);
  
  noTune(32);
  
  playTune(698, 523, 16);
  
  noTune(8);
  
  playTune(440, 349, 16);
  
  noTune(80);
  
  playTune(494, 392, 16);
  
  noTune(16);
  
  playTune(880, 698, 16);
  
  noTune(16);
  
  playTune(880, 698, 16);
  
  noTune(16);
  
  playTune(880, 698, 16);
  
  noTune(16);
  
  playTune(784, 659, 16);
  
  noTune(16);
  
  playTune(698, 587, 16);
  
  noTune(16);
  
  playTune(659, 523, 16);
  
  noTune(8);
  
  playTune(523, 440, 16);
  
  noTune(32);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(392, 330, 16);
  
  noTune(80);
  
  playTune(659, 523, 16);
  
  noTune(8);
  
  playTune(523, 440, 16);
  
  noTune(32);
  
  playTune(392, 330, 16);
  
  noTune(56);
  
  playTune(415, 330, 16);
  
  noTune(32);
  
  playTune(440, 349, 16);
  
  noTune(8);
  
  playTune(698, 523, 16);
  
  noTune(32);
  
  playTune(698, 523, 16);
  
  noTune(8);
  
  playTune(440, 349, 16);
  
  noTune(80);
  
  playTune(494, 392, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(32);
  
  playTune(698, 587, 16);
  
  noTune(8);
  
  playTune(698, 587, 16);
  
  noTune(16);
  
  playTune(659, 523, 16);
  
  noTune(16);
  
  playTune(587, 494, 16);
  
  noTune(16);
  
  playTune(523, 392, 16);
  
  noTune(8);
  
  playTune(0, 330, 16);
  
  noTune(32);
  
  playTune(0, 330, 16);
  
  noTune(8);
  
  playTune(0, 262, 16);

  noTune(200);
}

