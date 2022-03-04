#defineBLYNK_PRINTSerial // initializationofblynkserialcommunication 
#include<BlynkSimpleEsp8266.h>//initializationofcontrollernodemcuwithblynk 
#include<Blynk.h> //initializationofblynkapplication 
#definetrig1D1 //definingultrasonic1trigpinisconectedtoD1ofnodemcu 
#defineecho1D0 //definingultrasonic1echopinisconectedtoD0ofnodemcu 
#definetrig2D2 //definingultrasonic2trigpinisconectedtoD2ofnodemcu 
#defineecho2D3 //definingultrasonic2echopinisconectedtoD3ofnodemcu 
#definetrig3D5 //definingultrasonic3trigpinisconectedtoD5ofnodemcu
#defineecho3D4 //definingultrasonic3echopinisconectedtoD4ofnodemcu 
floattim1=0; //denotingavariabletostorethevalueoftimeandmakingit0
floatdistance1=0; //denotingavariabletostorethevalueofdistanceandmakingit0 
floattim2=0; //denotingavariabletostorethevalueoftimeandmakingit0
floatdistance2=0; //denotingavariabletostorethevalueofdistanceandmakingit0
floattim3=0; //denotingavariabletostorethevalueoftimeandmakingit0 
floatdistance3=0; //denotingavariabletostorethevalueofdistanceandmakingit0

charauth[]="1swyZkxQfhM2AE6iU9jz5x0vU8_gA7ha";//Authtokenforconnectionofthe controllertotheblynkapp 
charssid[]="Blynk"; //SSIDnamefortheconnectionofthecontrollertowifi 
charpass[]="12345678"; //passofssidfortheconnectionofthecontrollertowifi

WidgetBridgebridge1(V2); //connectingwidgetbridgetovirtualpinnoV2 
BlynkTimertimer; //initializationofblynktimer 
BLYNK_CONNECTED() //commandforstartingtheconnectionofbridge 
{
  bridge1.setAuthToken("MmLGdyarNDgtkLFkVsbKheZocXO3kH-l");//tokenofdevicewhich istobeconnected }
}
/*voidblynkAnotherDevice() 
 * { 
 * if(distance1>=10&&distance2<=10) 
 * { 
 * bridge1.digitalWrite(D1,HIGH); delay(100); 
 * } 
 * else { bridge1.digitalWrite(D1,LOW); 
 * delay(100); 
 * } 
 * if(distance2>=10&&distance1<=10) 
 * { 
 * bridge1.digitalWrite(D2,HIGH); 
 * delay(100); 
 * } 
 * else 
 * {
bridge1.digitalWrite(D2,LOW);
delay(100);
}
if(distance1<=10&&distance2<=10) 
{
bridge1.digitalWrite(D1,HIGH);
bridge1.digitalWrite(D2,HIGH);
delay(100);
}
else
{
bridge1.digitalWrite(D1,LOW);
bridge1.digitalWrite(D2,LOW); 
delay(100); 
}
if(distance3<=40) 
{ 
bridge1.digitalWrite(D3,HIGH); 
delay(100);
}
else
{
bridge1.digitalWrite(D3,LOW);
delay(100);
} 
} */ [wholeiscommentfrom/*to*/]
voidblynkAnotherDevice() //makingavoidfunction
{ 
  if(distance2<=20) //measuringthedistancevalueofultrasonicfordetection ofobstacle
  {
    bridge1.digitalWrite(D1,HIGH); //ifobstacledetectedthenmakingvalueofother controllerhighonpinD1
    delay(100); //waitfor100millisecond
    } 
    elseif(distance1<=20) //measuringthedistancevalueofultrasonicfordetectionof obstacle 
    { bridge1.digitalWrite(D2,HIGH);//ifobstacledetectedthenmakingvalueofothercontroller highonpinD2 
    delay(100); //waitfor100millisecond 
    }
    elseif(distance1<=10&&distance2<=10) //measuringthedistancevalueofultrasonicfor detectionofobstacle
    {
      bridge1.digitalWrite(D1,HIGH); // if obstacle detected then making value of other con troller high on pin D1 and D2 
      bridge1.digitalWrite(D2,HIGH); 
      delay(100); //Waitfor100millisecond 
      }
  }
}
elseif(distance3>=60) //measuringthedistancevalueofultrasonicfordetectionof obstacle
{
  bridge1.digitalWrite(D3,HIGH); // if obstacle detected then making value of other co ntroller high on pin D1 and D2 
  delay(100);//Waitfor100millisecond 
  }
  else //ifnoneoftheaboveconditionsaretruethenmakingthevalueofD1,D2,D3 lowoftheothercontroller
  {
    bridge1.digitalWrite(D1,LOW);
    bridge1.digitalWrite(D2,LOW);
    bridge1.digitalWrite(D3,LOW);
    delay(100); 
    }
    }
voidsetup()//voidsetupfordefiningthemodeoftheconnectedpins 
{
  pinMode(trig1,OUTPUT); //definingtriggerpinsasoutputpinsofultrasonicsensor
pinMode(echo1,INPUT); //definingechopinsasinputpinsofultrasonicsensors
pinMode(trig2,OUTPUT);
pinMode(echo2,INPUT); 
pinMode(trig3,OUTPUT);
pinMode(echo3,INPUT); 
Serial.begin(9600); //definingbaudratespeedforserialcommunicationas9600bits/sec
Blynk.begin(auth,ssid,pass); //starttheconnectionoftheblynkusingcredentials mentionedabove
timer.setInterval(1000L,blynkAnotherDevice); //startthetimeroftheblynk }
voidloop() //voidloopforrunningtheprogramagainandagain
{ 
  Blynk.run(); //Starttheblynkprocess
  ultra1(); //callingultrasoniccodesforexecutingfrombelow 
  ultra2(); 
  ultra3(); 
  timer.run(); //timerstarted 
  }
voidultra1() //codeforultrasonicsensor
{ 
  digitalWrite(trig1,LOW); //makingtriggerpinlow 
  delayMicroseconds(2); //wait2us 
  digitalWrite(trig1,HIGH); //makingtriggerpinhigh 
  delayMicroseconds(10); //wait2us 
  digitalWrite(trig1,LOW); //makingtriggerpinlow 
  delayMicroseconds(2); //wait2usthisgeneratesthepulsesonthetriggerpin
  tim1=pulseIn(echo1,HIGH); //countingthepulseandstoringinvariable
  distance1=tim1*0.0340/2; //calculatingthedistancebyformulaandstoringit
  }
voidultra2()// same asultra1
{
  digitalWrite(trig2,LOW);
  delayMicroseconds(2); 
  digitalWrite(trig2,HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig2,LOW); 
  delayMicroseconds(2);
  tim2=pulseIn(echo2,HIGH);
  distance2=tim2*0.0340/2; 
  }
  voidultra3()//sameasultra1
  {
    digitalWrite(trig3,LOW);
    delayMicroseconds(2);
    digitalWrite(trig3,HIGH);
    delayMicroseconds(10); 
    digitalWrite(trig3,LOW);
    delayMicroseconds(2); 
    tim3=pulseIn(echo3,HIGH);
    distance3=tim3*0.0340/2;
    }
