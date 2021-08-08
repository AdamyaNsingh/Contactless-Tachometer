float REV = 0;
int RPM_VALUE;
int PREVIOUS = 0;
int TIME;

void INTERRUPT()
{
  REV++;
}

void setup()
{
  Serial.begin(9600);
  attachInterrupt(1, INTERRUPT, RISING);
}

void loop()
{
  delay(1000);
  detachInterrupt(0);                   
  TIME = millis() - PREVIOUS;          
  RPM_VALUE = (REV/TIME) * 60000;       
  PREVIOUS = millis();                  
  REV = 0;
  Serial.println("RPM valaue is");
  Serial.println(RPM_VALUE);
  attachInterrupt(1, INTERRUPT, RISING);
  if (RPM_VALUE>=20000)
   {Serial.println("HIGH SPEED");
   digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);}
    else if (RPM_VALUE>=5000)
   {Serial.println("MEDIUM SPEED");
   digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);}
     else if (RPM_VALUE>=1)
   {Serial.println("LOW SPEED");
   digitalWrite(8,LOW);
    digitalWrite(9,LOW);
     digitalWrite(10,HIGH);
     digitalWrite(11,LOW);}
      else if (RPM_VALUE==0)
   {Serial.println("STEADY");
   digitalWrite(8,LOW);
    digitalWrite(9,LOW);
     digitalWrite(10,LOW);
     digitalWrite(11,HIGH);}
}
