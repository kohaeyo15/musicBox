int enPin1 = 5;
int dirPin1 = 6;
int stepPin1 = 7;
int enPin2 = 3;
int dirPin2 = 9;
int stepPin2 = 4;

/*int enPin1 = 3;
int dirPin1 = 9;
int stepPin1 = 4;
int enPin2 = 5;
int dirPin2 = 6;
int stepPin2 = 7;*/

void setup() 
{
  //Serial.begin(9600); 
  pinMode (enPin1, OUTPUT);
  pinMode (dirPin1, OUTPUT);
  pinMode (stepPin1, OUTPUT);
  pinMode (enPin2, OUTPUT);
  pinMode (dirPin2, OUTPUT);
  pinMode (stepPin2, OUTPUT);
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
    digitalWrite(stepPin1,LOW);
    digitalWrite(stepPin1,HIGH);
    digitalWrite(stepPin2,LOW);
    digitalWrite(stepPin2,HIGH);
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
  delay(timeMilli);
  //Serial.print(timeMilli);
  //Serial.print("\n");
}

void loop() 
{
  playTune(659, 659, 16);

  noTune(8);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(784, 784, 16);
  
  noTune(80);
  
  playTune(0, 0, 16);
  
  noTune(80);
  
  playTune(523, 523, 16);
  
  noTune(56);
  
  playTune(392, 392, 16);
  
  noTune(56);
  
  playTune(330, 330, 16);
  
  noTune(56);
  
  playTune(440, 440, 16);
  
  noTune(32);
  
  playTune(494, 494, 16);
  
  noTune(32);
  
  playTune(466, 466, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(32);
  
  playTune(392, 392, 16);
  
  noTune(16);
  
  playTune(659, 659, 16);
  
  noTune(16);
  
  playTune(784, 784, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(784, 784, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(8);
  
  playTune(494, 494, 16);
  
  noTune(56);
  
  playTune(523, 523, 16);
  
  noTune(56);
  
  playTune(392, 392, 16);
  
  noTune(56);
  
  playTune(330, 330, 16);
  
  noTune(56);
  
  playTune(440, 440, 16);
  
  noTune(32);
  
  playTune(494, 494, 16);
  
  noTune(32);
  
  playTune(466, 466, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(32);
  
  playTune(392, 392, 16);
  
  noTune(16);
  
  playTune(659, 659, 16);
  
  noTune(16);
  
  playTune(784, 784, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(784, 784, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(8);
  
  playTune(494, 494, 16);
  
  noTune(104);
  
  playTune(784, 784, 16);
  
  noTune(8);
  
  playTune(740, 740, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(622, 622, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(415, 415, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(56);
  
  playTune(784, 784, 16);
  
  noTune(8);
  
  playTune(740, 740, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(622, 622, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(1047, 1047, 16);
  
  noTune(32);
  
  playTune(1047, 1047, 16);
  
  noTune(8);
  
  playTune(1047, 1047, 16);
  
  noTune(128);
  
  playTune(784, 784, 16);
  
  noTune(8);
  
  playTune(740, 740, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(622, 622, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(415, 415, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(56);
  
  playTune(622, 622, 16);
  
  noTune(56);
  
  playTune(587, 587, 16);
  
  noTune(56);
  
  playTune(523, 523, 16);
  
  noTune(224);
  
  playTune(784, 784, 16);
  
  noTune(8);
  
  playTune(740, 740, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(622, 622, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(415, 415, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(56);
  
  playTune(784, 784, 16);
  
  noTune(8);
  
  playTune(740, 740, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(622, 622, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(1047, 1047, 16);
  
  noTune(32);
  
  playTune(1047, 1047, 16);
  
  noTune(8);
  
  playTune(1047, 1047, 16);
  
  noTune(128);
  
  playTune(784, 784, 16);
  
  noTune(8);
  
  playTune(740, 740, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(622, 622, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(415, 415, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(56);
  
  playTune(622, 622, 16);
  
  noTune(56);
  
  playTune(587, 587, 16);
  
  noTune(56);
  
  playTune(523, 523, 16);
  
  noTune(176);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(392, 392, 16);
  
  noTune(80);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(8);
  
  playTune(659, 659, 16);
  
  noTune(200);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(392, 392, 16);
  
  noTune(80);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(784, 784, 16);
  
  noTune(80);
  
  playTune(0, 0, 16);
  
  noTune(80);
  
  playTune(523, 523, 16);
  
  noTune(56);
  
  playTune(392, 392, 16);
  
  noTune(56);
  
  playTune(330, 330, 16);
  
  noTune(56);
  
  playTune(440, 440, 16);
  
  noTune(32);
  
  playTune(494, 494, 16);
  
  noTune(32);
  
  playTune(466, 466, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(32);
  
  playTune(392, 392, 16);
  
  noTune(16);
  
  playTune(659, 659, 16);
  
  noTune(16);
  
  playTune(784, 784, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(784, 784, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(8);
  
  playTune(494, 494, 16);
  
  noTune(56);
  
  playTune(523, 523, 16);
  
  noTune(56);
  
  playTune(392, 392, 16);
  
  noTune(56);
  
  playTune(330, 330, 16);
  
  noTune(56);
  
  playTune(440, 440, 16);
  
  noTune(32);
  
  playTune(494, 494, 16);
  
  noTune(32);
  
  playTune(466, 466, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(32);
  
  playTune(392, 392, 16);
  
  noTune(16);
  
  playTune(659, 659, 16);
  
  noTune(16);
  
  playTune(784, 784, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(784, 784, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(8);
  
  playTune(494, 494, 16);
  
  noTune(56);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(392, 392, 16);
  
  noTune(56);
  
  playTune(415, 415, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(80);
  
  playTune(494, 494, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(16);
  
  playTune(784, 784, 16);
  
  noTune(16);
  
  playTune(698, 698, 16);
  
  noTune(16);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(392, 392, 16);
  
  noTune(80);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(392, 392, 16);
  
  noTune(56);
  
  playTune(415, 415, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(80);
  
  playTune(494, 494, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(16);
  
  playTune(659, 659, 16);
  
  noTune(16);
  
  playTune(587, 587, 16);
  
  noTune(16);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(0, 0, 16);
  
  noTune(32);
  
  playTune(0, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 16);
  
  noTune(80);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(392, 392, 16);
  
  noTune(56);
  
  playTune(415, 415, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(80);
  
  playTune(494, 494, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(16);
  
  playTune(784, 784, 16);
  
  noTune(16);
  
  playTune(698, 698, 16);
  
  noTune(16);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(392, 392, 16);
  
  noTune(80);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(392, 392, 16);
  
  noTune(56);
  
  playTune(415, 415, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(80);
  
  playTune(494, 494, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(16);
  
  playTune(659, 659, 16);
  
  noTune(16);
  
  playTune(587, 587, 16);
  
  noTune(16);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(0, 0, 16);
  
  noTune(32);
  
  playTune(0, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 16);
  
  noTune(80);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(392, 392, 16);
  
  noTune(80);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(8);
  
  playTune(659, 659, 16);
  
  noTune(200);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(587, 587, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(392, 392, 16);
  
  noTune(80);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(659, 659, 16);
  
  noTune(32);
  
  playTune(784, 784, 16);
  
  noTune(80);
  
  playTune(0, 0, 16);
  
  noTune(80);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(392, 392, 16);
  
  noTune(56);
  
  playTune(415, 415, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(80);
  
  playTune(494, 494, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(16);
  
  playTune(880, 880, 16);
  
  noTune(16);
  
  playTune(784, 784, 16);
  
  noTune(16);
  
  playTune(698, 698, 16);
  
  noTune(16);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(392, 392, 16);
  
  noTune(80);
  
  playTune(659, 659, 16);
  
  noTune(8);
  
  playTune(523, 523, 16);
  
  noTune(32);
  
  playTune(392, 392, 16);
  
  noTune(56);
  
  playTune(415, 415, 16);
  
  noTune(32);
  
  playTune(440, 440, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(440, 440, 16);
  
  noTune(80);
  
  playTune(494, 494, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(32);
  
  playTune(698, 698, 16);
  
  noTune(8);
  
  playTune(698, 698, 16);
  
  noTune(16);
  
  playTune(659, 659, 16);
  
  noTune(16);
  
  playTune(587, 587, 16);
  
  noTune(16);
  
  playTune(523, 523, 16);
  
  noTune(8);
  
  playTune(0, 0, 16);
  
  noTune(32);
  
  playTune(0, 0, 16);
  
  noTune(8);
  
  playTune(0, 0, 16);

  noTune(200);
}

