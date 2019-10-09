const int photo=0;
const int spdt=2;
int spdtVal;
const int button=3;
int led[]={8,9,10,11,12,13};
int lightCal;
int lightVal;

void setup()
{
  pinMode (photo,INPUT);
  pinMode(spdt,INPUT);
  pinMode(button,INPUT);
  int index;
  for(index=0;index<=6;index++)  //for loop
  {
    pinMode(led[index],OUTPUT);
  }
  lightCal=analogRead(photo);
  

}


void loop()
{
spdtPart1();
}

void spdtPart1()
{
  spdtVal; //stores the state of the spdt switch
  spdtVal= digitalRead(spdt);
  if(spdtVal==HIGH){
    digitalWrite(led[3],HIGH);
    buttonPart2();
  } else { 
    digitalWrite(led[3],LOW);
    photoPart3();
  }
}

void buttonPart2()
{
  int timer=1000;
  int buttonState;
  int index;
  buttonState=digitalRead(button);
  if(buttonState==LOW)
  { 
    digitalWrite(led[3],LOW);
       for(index=2;index>=1;index--)  //for loop
      {
       digitalWrite(led[index],HIGH);
        if(index==1)
       {
        timer=3000;
       }
       delay(timer);
       digitalWrite(led[index],LOW);
      }
  }
  
}

void photoPart3(){
int photo;
int delaytime=500;
int index;
lightVal=analogRead(photo);
if(lightVal < lightCal - 50){
  for(index=5;index<=0;index--){
    digitalWrite(led[index],HIGH);
    digitalWrite(led[index+1],HIGH);
    delay(delaytime);
  }
  for(index=0;index<=5;index++)
  {
    digitalWrite(led[index],LOW);
    delay(delaytime);
  }
}
}
 


