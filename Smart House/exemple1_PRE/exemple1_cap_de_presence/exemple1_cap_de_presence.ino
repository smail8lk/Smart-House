

int Pin_LED_CH1= 13;  
const int Pin_PRE1 = A0;    


void setup() {
 

}


void loop() {
    
 // input 
 pinMode(Pin_PRE1, INPUT);

//output  
pinMode(Pin_LED_CH1, OUTPUT);  
   

  
 int Etat_Bouton_Pre1 =analogRead(Pin_PRE1);

 
 if( Etat_Bouton_Pre1 == 0)
{
     digitalWrite(Pin_LED_CH1, LOW);   // LED CH1 OFF
   
     
}
else {
   digitalWrite(Pin_LED_CH1, HIGH);   // LED CH1 ON
    

}

 
 }
