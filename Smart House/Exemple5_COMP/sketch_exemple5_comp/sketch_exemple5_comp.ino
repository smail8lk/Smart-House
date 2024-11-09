// déclarer la bibliothéque LiquidCrystal
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// L’arduino pin il est connecté à différents entrées et sorties

int Pin_LED_CH1= 13;  
int Pin_LED_CHAUFFA= 12; 
int Pin_ALARME= 11;  
int Pin_STORE1= 10;  
int Pin_STORE2= 9;  

    
const int Pin_PRE1= A0;    
const int Pin_TEM= A1;    
const int Pin_GAZ = A2; 

void setup() {
  lcd.begin(16, 2);

lcd.setCursor(4,0);

lcd.print("EST MEKNES ");
delay(2000);
 
lcd.setCursor(1,1);
lcd.print(" PFE : SMART HOME");

 // Faites défiler 120 position vers la gauche
for (int positionCounter = 0; positionCounter < 120; positionCounter++) {
// Faites défiler une position gauche
lcd.scrollDisplayLeft();
// attendez un peu de temps
delay(150);
}
//// Effacer l’écran
lcd.clear();
lcd.setCursor(1,0);
lcd.print("realiser par :");
delay(2000);
lcd.setCursor(0,1);
lcd.print("NOM Prenom 1 & NOM Prenom 2 & NOM Prenom 3");
//
// Faites défiler 120 position vers la gauche
for (int positionCounter = 0; positionCounter < 120; positionCounter++) {
lcd.scrollDisplayLeft();
delay(100);
}
//
//// Effacer l’écran
lcd.clear();
lcd.setCursor(1,0);
lcd.print("Encadrer par :");
//
lcd.setCursor(0,1);
lcd.print("Pr. MED FATTAH");
delay(4000);
// Faites défiler 120 position vers la gauche
for (int positionCounter = 0; positionCounter < 120; positionCounter++) {
lcd.scrollDisplayLeft();
delay(100);
}

}

void loop() {
  //lcd.begin(16, 2);
  // Effacer l’écran
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("NIVEAU GAZ= ");
  lcd.setCursor(15, 0);
  lcd.print("%");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("TEMP= ");
  lcd.setCursor(15, 1);
  lcd.print("C");
 delay(1000);

  
 pinMode(Pin_GAZ, INPUT);   
 pinMode(Pin_PRE1, INPUT);
 pinMode(Pin_TEM, INPUT);   
 
  
  
  pinMode(Pin_LED_CH1, OUTPUT);  
  pinMode(Pin_LED_CHAUFFA, OUTPUT);  
  pinMode(Pin_ALARME, OUTPUT);   
  pinMode(Pin_STORE1, OUTPUT);   
  pinMode(Pin_STORE2, OUTPUT);   

  

 
  int Vin_GAZ = analogRead(Pin_GAZ);
  int Vout_GAZ = Vin_GAZ * 5.0 / 1023 * 20;
  
  lcd.setCursor(12, 0);
  lcd.print(Vout_GAZ);

  int Vin_TEM = analogRead(Pin_TEM);
  int Vout_TEM = ( Vin_TEM * 5.0 / 1023 * 1000 )/ 10;
 
 
  lcd.setCursor(12, 1);
  lcd.print(Vout_TEM);

delay(2000);
 Vin_GAZ = analogRead(Pin_GAZ);
 Vout_GAZ = Vin_GAZ * 5.0 / 1023 * 20;
 
 Vin_TEM = analogRead(Pin_TEM);
 Vout_TEM = ( Vin_TEM * 5.0 / 1023 * 1000 )/ 10;

 

 int Etat_Bouton_Pre1 =analogRead(Pin_PRE1);
 if( Etat_Bouton_Pre1 == 0)
{
     digitalWrite(Pin_LED_CH1, LOW);   // LED CH1 OFF
   
     
}
else {
   digitalWrite(Pin_LED_CH1, HIGH);   // LED CH1 ON
    
      lcd.clear();
      lcd.setCursor(0,1); 
      lcd.print("ECLAIRAGE AUTO");
      lcd.setCursor(1,0);
      lcd.print("CHAMBRE 1 ");
}



  delay(2000);
 Vin_GAZ = analogRead(Pin_GAZ);
 Vout_GAZ = Vin_GAZ * 5.0 / 1023 * 20;
 
if(Vout_GAZ >= 10){
 // Presence de GAZ
       tone(Pin_ALARME,10); // BUZZER ON
       digitalWrite(Pin_ALARME, HIGH);   // BUZZER ON
      digitalWrite(Pin_STORE1,HIGH);
      digitalWrite(Pin_STORE2,HIGH);
       lcd.clear();
      lcd.setCursor(0,1); 
      lcd.print("STORE(GAZ)-->MARCHE");
      lcd.setCursor(1,0);
      lcd.print("GAZ ");
      lcd.print(Vout_GAZ);
      lcd.print(" %");
   
    }
     else {
      noTone(Pin_ALARME); // BUZZER OFF
     digitalWrite(Pin_STORE1,LOW);
      digitalWrite(Pin_STORE2,LOW);
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("PAS DE GAZ ");
        lcd.setCursor(1,0);
        lcd.print("GAZ ");
        lcd.print(Vout_GAZ);
        lcd.print(" %");
       
    }
    
 delay(2000);
  Vin_TEM = analogRead(Pin_TEM);
 Vout_TEM = ( Vin_TEM * 5.0 / 1023 * 1000 )/ 10;
 
if(Vout_TEM <=14){
 // CHauffage automatique
       
      digitalWrite(Pin_LED_CHAUFFA,HIGH);
     lcd.clear();
      lcd.setCursor(0,1); 
      lcd.print("CHAUFFAGE--> ON");
      lcd.setCursor(1,0);
      lcd.print("TEMPERATURE ");
      lcd.print(Vout_TEM);
      lcd.print(" C");
   
    }
     else {
   
      digitalWrite(Pin_LED_CHAUFFA,LOW);
      lcd.clear();
      lcd.setCursor(0,1); 
      lcd.print("CHAUFFAGE --> OFF");
      lcd.setCursor(1,0);
      lcd.print("TEMPERATURE ");
      lcd.print(Vout_TEM);
      lcd.print(" C");
       
    }

 
 }
