/*
 * measure time for activate two independent pushbutton (masurare timp apasare 2 butoane)
 * program adapt by Nicu FLORICA (niq_ro) - http://nicuflorica.blogspot.com/
 * original ideea from Andy DOZ's blog - https://andydoz.blogspot.com
 *
 */

#define buton1 2  // buton 1 fara retine la masa
#define buton2 3  // buton 2 fara retine la masa
#define led 7    // led + rezistenta 220..470 ohmi la masa

int apasarebuton1 = 0; // stare buton (apasat/neapasat)
int duratamare1 = 3000; // valoare timp apaaare lunga, in ms
int durataapasare1 = 0; // durata apasare buton
int tpaparare1 = 0;// memorare timp apasare
int tpeliberare1 = 0;// memorare timp eliberare
int durata1 = 0;  // durata apasare, in timp real
boolean stare1 = false; // stare de cronometrare

int apasarebuton2 = 0; // stare buton (apasat/neapasat)
int duratamare2 = 4000; // valoare timp apaaare lunga, in ms
int durataapasare2 = 0; // durata apasare buton
int tpaparare2 = 0;// memorare timp apasare
int tpeliberare2 = 0;// memorare timp eliberare
int durata2 = 0;  // durata apasare, in timp real
boolean stare2 = false; // stare de cronometrare

void setup() {
  Serial.begin(9600);
  pinMode(buton1,INPUT);//
  digitalWrite(buton1,HIGH); // pull-up activ
  pinMode(buton2,INPUT);//
  digitalWrite(buton2,HIGH); // pull-up activ
  pinMode(led,OUTPUT);//
  digitalWrite(led, LOW);  // led stins
}

void loop() { 
    durataapasare1 = aflareduratapasare1();
    durataapasare2 = aflareduratapasare2();
    delay (10);      
} // sfarsit program


int aflareduratapasare1() {
apasarebuton1 = digitalRead(buton1);    // citiree stare buton 1
 if(apasarebuton1 == LOW && stare1 == false) {   // daca butonul 1 e apasat, dar nu mai fusese apasat
   tpaparare1 = millis();
   stare1 = true;
   };
          
 if (apasarebuton1 == HIGH && stare1 == true) {  // daca butonul 1 este neapasat si tocmai a fost eliberat
    tpeliberare1 = millis ();
    durataapasare1 = tpeliberare1 - tpaparare1;
    Serial.println("---------------");
    Serial.print("Timp apasare totsla buton 1 = ");
    Serial.print(durataapasare1);
    Serial.println("ms");
    Serial.println("---------------");
    stare1 = false;
    digitalWrite(led, LOW);  // sting led
    };

 if(apasarebuton1 == LOW && stare1 == true) {  // daca butonul 1 este inca apasat
   durata1 = millis() - tpaparare1;
   Serial.print("Timp apasare buton 1 = ");
   Serial.print(durata1);
   if (durata1 > durataapasare1) Serial.print(" < ");
     else Serial.print(" > ");  
   Serial.print(duratamare1);
   Serial.println("ms");
   if (durata1 > duratamare1) {   // aprinde led daca s-a depasit timpul minim
      digitalWrite(led, HIGH);
      }
  }       
   return durataapasare1;  // iesire din subrutina si memorare timp
}

int aflareduratapasare2() {
apasarebuton2 = digitalRead(buton2);    // citiree stare buton 1
 if(apasarebuton2 == LOW && stare2 == false) {   // daca butonul 1 e apasat, dar nu mai fusese apasat
   tpaparare2 = millis();
   stare2 = true;
   };
          
 if (apasarebuton2 == HIGH && stare2 == true) {  // daca butonul 1 este neapasat si tocmai a fost eliberat
    tpeliberare2 = millis ();
    durataapasare2 = tpeliberare2 - tpaparare2;
    Serial.println("---------------");
    Serial.print("Timp apasare totsla buton 2 = ");
    Serial.print(durataapasare2);
    Serial.println("ms");
    Serial.println("---------------");
    stare2 = false;
    digitalWrite(led, LOW);  // sting led
    };

 if(apasarebuton2 == LOW && stare2 == true) {  // daca butonul 2 este inca apasat
   durata2 = millis() - tpaparare2;
   Serial.print("Timp apasare buton 2 = ");
   Serial.print(durata2);
   if (duratamare2 > durata2) Serial.print(" < ");
      else Serial.print(" > ");  
   Serial.print(duratamare2);
   Serial.println("ms");
   if (durata2 > duratamare2) {   // aprinde led daca s-a depasit timpul minim
      digitalWrite(led, HIGH);
      }
  }       
   return durataapasare2;  // iesire din subrutina si memorare timp
}
