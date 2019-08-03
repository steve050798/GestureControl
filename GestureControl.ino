/*  Date: 16/01/2018
 *  ANARC - Robotics Club of NIT Agartala
 *  Project: Gesture controlled RC car 
 *  Author: Steve Suresh
 *  Status: Working
 */
/* Intialising the position of x,y,z pins */ 
const int x_pin=A1;
const int y_pin=A2;
const int z_pin=A3;

/* Variables for storing values */
int x,y,z;
int st=0; 

/* Initialization of motor pins (HT12E switches)*/
int lm1=11,lm2=10,rm1=9,rm2=8;


void setup() 
{
  /* External power for the circuit */
  pinMode(2,OUTPUT);  
  pinMode(3,OUTPUT);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  pinMode(A0,OUTPUT);
  pinMode(A4,OUTPUT);
  digitalWrite(A0,HIGH);
  digitalWrite(A4,LOW);
  
  /* Setting up motor pins */
  pinMode(lm1,OUTPUT);  
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);

  /*Starting Serial Monitor */
  Serial.begin(9600);
}
void loop() 
{
  x=0;
  y=0;
  z=0;
  int i;

  /* Reading multiple values to filter out spikes */
  for(i=0;i<50;++i)
  {
    x+=analogRead(x_pin); 
    y+=analogRead(y_pin);
    z+=analogRead(z_pin);
  }
  x/=50;
  y/=50;
  z/=50;

  
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
  delay(100);

  /* Application of previously calculated ranges into control statements */
  if((x>330&&x<380)&&(y>330&&y<380)&&(z>400&&z<450))//&&st!=0)
    off();
  else if((x>330&&x<380)&&(y>380&&y<430)&&(z>390&&z<440))//&&st!=1)
    forward();
  else if((x>340&&x<390)&&(y>300&&y<350)&&(z>400&&z<450))//&&st!=2)
    backward();
  else if((x>290&&x<340)&&(y>330&&y<3801)&&(z>400&&z<450))//&&st!=3)
    left();
  else if((x>380&&x<430)&&(y>330&&y<380)&&(z>400&&z<450))//&&st!=4)
    right();
}

/* Movement Functions */
void off()
{
  st=0;
  Serial.println("Breaking");
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,HIGH);
}

void forward()
{
  st=1;
  Serial.println("Forward");
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}
void backward()
{
  st=2;
  Serial.println("Backward");
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}
void right()
{
  st=3;
  Serial.println("Turning right");
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}
void left()
{
  st=4;
  Serial.println("Turning left");
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,HIGH);
}


