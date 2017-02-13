#include <Servo.h>
#include "FastLED.h"

#define NUM_LEDS 29
#define DATA_PIN 3

#define POS_VERTICALE 129   //posizione del servo quando il piatto si trova su
#define POS_ORIZZONTALE 0   //posizione del servo quando appoggia il piatto sulla scarpa
#define VEL_SERVO 30        //velocità di salita e di discesa del piatto: 30 MEDIA // 15 VELOCE // 45 LENTA

CRGB leds[NUM_LEDS];  //inizializzo i led

Servo myservo;        //inizializzo il servo

void setup() {
  myservo.attach(9);  
  myservo.write(POS_VERTICALE); //sposta il servo in posizione verticale

  pinMode(12, OUTPUT);        
  digitalWrite(12, LOW);        //relay spento

  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);

  giro_bianco();

}

void loop() {

  digitalWrite(9,LOW);    //servo spento in posizione verticale

  digitalWrite(12, HIGH); //accendo pompa

  delay(5000);            //aspetto 5 sec

  digitalWrite(12, LOW);  //spengo pompa

  delay(15000);           //aspetto 15 sec

  scendi();               //scende piatto

  delay(5000);            //aspetto 5 sec
  
  sali();                 //salgo col piatto
}

void giro_bianco() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
    FastLED.show();
    delay(100);
  }
}

void scendi() {
  for (int pos = POS_VERTICALE; pos >= POS_ORIZZONTALE; pos -= 1) { 
    myservo.write(pos);              
    delay(VEL_SERVO);                       
  }
}

void sali() {
  for (int pos = POS_ORIZZONTALE; pos <= POS_VERTICALE; pos += 1) {
    myservo.write(pos);              
    delay(VEL_SERVO);                      
  }
}