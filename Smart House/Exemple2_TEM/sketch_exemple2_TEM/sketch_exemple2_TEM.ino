

  
int Pin_LED_CHAUFFA= 12; 


    
const int Pin_TEM= A1;    


void setup() {
 

}

void loop() {
 

  

 pinMode(Pin_TEM, INPUT);   
  
 pinMode(Pin_LED_CHAUFFA, OUTPUT);  
 

  

 
  int Vin_TEM = analogRead(Pin_TEM);
  int Vout_TEM = ( Vin_TEM * 5.0 / 1023 * 1000 )/ 10;
 
 

 
if(Vout_TEM <=14){
 // CHauffage automatique
       
      digitalWrite(Pin_LED_CHAUFFA,HIGH);

   
    }
     else {
   
      digitalWrite(Pin_LED_CHAUFFA,LOW);

       
    }

 
 }
