#defineBLYNK_PRINTSerial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h> 
#defineBD0//definingtheBasbuttonconnectedonpinnoD0 
intval=0; //definingavariableinttostorethevalue

charauth[]="MmLGdyarNDgtkLFkVsbKheZocXO3kH-l"; 
charssid[]="Blynk"; 
charpass[]="12345678"; 

Stringlatitude; //definingstringtostorethevalueoflatitude 
Stringlongitude;//definingstringtostorethevalueoflongitude

voidsetup()
{ 
  Serial.begin(9600);
  pinMode(D1,INPUT); 
  pinMode(D2,INPUT); 
  pinMode(D3,INPUT); 
  PinMode(B,INPUT);
  Blynk.begin(auth,ssid,pass); 
  }
  BLYNK_WRITE(V6) //connectionofGPSwidgetonvirtualpinnoV6
  {

GpsParamgps(param); //initialisingtheGPS
Blynk.virtualWrite(V6, param[0].asString()); // Making a pointer [0] to store data on s ame pin V6 of GPS
Blynk.virtualWrite(V6, param[1].asString()); // Making a pointer [1] to store data on s ame pin V6 of GPS
latitude=param[0].asString(); //storethevalueofpointer[0]invariable
longitude=param[1].asString();//storethevalueofpointer[1]invariable 
//Print6decimalplacesforLat,Lon
Serial.print("Lat:");//serialprintallthedataonserialmonitor
Serial.println(gps.getLat(),7);
Serial.print("Lon:");
Serial.println(gps.getLon(),7);
}
voidloop() 
{
  Blynk.run();
  If(B==HIGH)//ifconditionistruethenentertheloop 
  {
    if(digitalRead(D1)==HIGH&&digitalRead(D2)==LOW) //ifD1andD2ishighthenenter theloop
    {
      Serial.write(1);//serialwriting1valuefornanocontrollerfortexttospeechconversion 
      Serial.println("WalkAhead");//printdataonserialmonitor 
      delay(100);
      }
      elseif(digitalRead(D2)==HIGH&&digitalRead(D1)==LOW)//ifconditionistruethenenter theloop
    }
  }
}
{
  Serial.write(2);//serialwriting2valuefornanocontrollerfortexttospeechconversion 
  Serial.println("TurnLeft"); //printdataonserialmonitor
  delay(100); 
  } 
  elseif(digitalRead(D3)==HIGH)//ifconditionistruethenentertheloop
}
{
  Serial.write(3);//serialwriting3valuefornanocontrollerfortexttospeechconversion 
  Serial.println("SlopeAhead"); //printdataonserialmonitor
  delay(100);
  }
  elseif((digitalRead(D1)==HIGH&&digitalRead(D2)==HIGH)||(digitalRead(D2)==HIGH&& digitalRead(D1)==HIGH)) //ifconditionistruethenentertheloop
{
  Serial.write(4);//serialwriting4valuefornanocontrollerfortexttospeechconversion
  Serial.println("Stop");//printdataonserialmonitor
  delay(100); } else//ifnoneoftheaboveconditionistruethenentertheloop
  {
Serial.write(5);//serialwriting5valuefornanocontrollerfortexttospeechconversion 
Serial.println("Allok"); //printdataonserialmonitor 
delay(100); 
} 
}
else { Serial.print("Help"); //printdataonserialmonitor 
StringtoSend; //definingstringtostorethevalue
toSend+="HELP!!!!!"; toSend+=".ViewlocationonMaps:";
toSend+="http://maps.google.com/?q=";
toSend+=latitude; toSend+=",";
toSend+=longitude; //writingthevaluesinthestring 
Blynk.email("kamblimitali9@gmail.com","Subject:SmartShoe",toSend); //sendmail command
}
}
