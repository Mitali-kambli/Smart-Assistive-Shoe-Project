
#include"Talkie.h"//HeaderfilefortexttospeechModule
#include"Vocab_US_Large.h"//HeaderfileforUSaccentspeech
#include"Vocab_Special.h" //Headerfileforttslibrary 
#include"Vocab_Soundbites.h" intvalue1=0; //definingthevalueofvariableinttostorevalue 
Talkievoice; //initialisingttsmodule 
voidsetup()
{ 
  Serial.begin(9600);
  }
  voidloop() 
  {
    if(Serial.available()>0)//ifserialdataisavailablethenentertheloop 
    {
      value1=Serial.read();//readtheincomingvalue
      if(value1==1)//ifconditionistruethenentertheloop 
      {
        //Serial.println("WalkAhead");
        voice.say(sp2_NORTH);//spellthewrittenword(sp2,sp3,sp4arethespeedofsayingword)
        }
        elseif(value1==2) //ifconditionistruethenentertheloop 
        {
          //Serial.println("TurnLeft"); 
          voice.say(sp2_LEFT);//spellthewrittenword
          } 
          elseif(value1==3) //ifconditionistruethenentertheloop 
          {
      }
    }
}
//Serial.println("SlopeAhead");
voice.say(sp2_ALERT); //spellthewrittenword
}
elseif(value1==4)//ifconditionistruethenentertheloop
{
  //Serial.println("Stop"); 
  voice.say(sp2_STOP);//spellthewrittenword 
  } 
  elseif(value1==5)//ifconditionistruethenentertheloop
  { 
    //Serial.println("Allok"); 
    voice.say(sp2_GO);//spellthewrittenword 
    }
    }
    }
