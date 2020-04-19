/*
 * measure time for activate pushbutton (masurare timp apasare buton)
 * program adapt by Nicu FLORICA (niq_ro) - http://nicuflorica.blogspot.com/
 * original ideea from Andy DOZ's blog - https://andydoz.blogspot.com
 *
 */

#define buton 2  // buton fara retine la masa
#define led 7    // led + rezistenta 220..470 ohmi la masa
#define led2 6   // led + rezistenta 220..470 ohmi la masa

int apasarebuton = 0; // stare buton (apasat/neapasat)
int duratamare = 3000; // valoare timp apaaare lunga, in ms
int durataapasare = 0; // durata apasare buton
int tpaparare = 0;// memorare timp apasare
int tpeliberare = 0;// memorare timp eliberare
int durata1 = 0;  // durata apasare, in timp real
boolean stare = false; // stare de cronometrare

void setup() {
  Serial.begin(9600);
  pinMode(buton,INPUT);//
  digitalWrite(buton,HIGH); // pull-up activ
  pinMode(led,OUTPUT);//
  digitalWrite(led, LOW);  // led stins
  pinMode(led2,OUTPUT);//
  digitalWrite(led2, LOW);  // led stins 
}

void loop() {
    durataapasare = aflareduratapasare();
    delay (10);      
} // sfarsit program


int aflareduratapasare () {
apasarebuton = digitalRead(buton);    // citiree stare buton
 if(apasarebuton == LOW && stare == false) {   // daca butonul e apasat, dar nu mai fusese apasat
   tpaparare = millis();
   stare = true;
   };
          
 if (apasarebuton == HIGH && stare == true) {  // daca butonul este neapasat si tocmai a fost eliberat
    tpeliberare = millis ();
    durataapasare = tpeliberare - tpaparare;
    Serial.println("---------------");
    Serial.print("Timp apasare totsla buton = ");
    Serial.print(durataapasare);
    Serial.println("ms");
    Serial.println("---------------");
    stare = false;
    digitalWrite(led, LOW);  // sting led
    digitalWrite(led2, LOW);  // sting led   
    };

 if(apasarebuton == LOW && stare == true) {  // daca butonul este inca apasat
   durata1 = millis() - tpaparare;
   Serial.print("Timp apasare buton = ");
   Serial.print(durata1);
   Serial.print("ms");
   digitalWrite(led2, HIGH);  // aprinde led cat timp e butonul apasat
   Serial.println("---------------");
   if (durata1 > duratamare) {   // aprinde led daca s-a depasit timpul minim
      digitalWrite(led, HIGH);
      }
   digitalWrite(led2, LOW);  // sting led cat timp e butonul apasat (efect clipire)
  }       
   return durataapasare;  // iesire din subrutina si memorare timp
}
