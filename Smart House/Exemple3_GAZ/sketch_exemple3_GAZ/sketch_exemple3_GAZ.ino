


int Pin_ALARME= 11;  
int Pin_STORE1= 10;  
int Pin_STORE2= 9;  

const int Pin_GAZ = A2;    



void setup() {
  

}



void loop() {
 
 pinMode(Pin_GAZ, INPUT);   
  
 
 pinMode(Pin_ALARME, OUTPUT);   
 pinMode(Pin_STORE1, OUTPUT);   
 pinMode(Pin_STORE2, OUTPUT);   

  

 
  int Vin_GAZ = analogRead(Pin_GAZ);
  int Vout_GAZ = Vin_GAZ * 5.0 / 1023 * 20;
  


 
if(Vout_GAZ >= 10){
 // Presence de GAZ
       tone(Pin_ALARME,10); // BUZZER ON
       digitalWrite(Pin_ALARME, HIGH);   // BUZZER ON
       digitalWrite(Pin_STORE1,HIGH);
       digitalWrite(Pin_STORE2,HIGH);

   
    }
     else {
      noTone(Pin_ALARME); // BUZZER OFF
      digitalWrite(Pin_STORE1,LOW);
      digitalWrite(Pin_STORE2,LOW);
      
       
    }
    


 
 }
