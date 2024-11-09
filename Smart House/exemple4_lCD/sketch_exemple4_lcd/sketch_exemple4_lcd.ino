

// déclarer la bibliothéque LiquidCrystal
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);



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
 lcd.clear();
}

}

void loop() {
  //lcd.begin(16, 2);
  // Effacer l’écran
//  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("NIVEAU HUM= ");
  lcd.setCursor(15, 0);
  lcd.print("%");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("TEMP= ");
  lcd.setCursor(15, 1);
  lcd.print("C");
 delay(1000);

 
   
 }
