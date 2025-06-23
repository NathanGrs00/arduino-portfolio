// Voeg de servo library toe.
#include <Servo.h>

// Maak een Servo object aan. Dit object wordt gebruikt om de servo motor aan te sturen.
Servo MijnServo;
// Definieer de pinnen voor de knoppen.
int knopPin1 = 11;
int knopPin2 = 10;

// Definieer de duur voor de servo bewegingen in seconden.
float tijd1 = 3.0;
float tijd2 = 0.5;

// Deze functie wordt één keer uitgevoerd bij het opstarten van de Arduino.
void setup() {
  // Koppel de servo motor aan pin 3.
  MijnServo.attach(3);
  // Zet de knoppen als INPUT.
  pinMode(knopPin1, INPUT);
  pinMode(knopPin2, INPUT);
}

// Deze functie wordt continu uitgevoerd na de setup.
void loop() {
  // boolean variabelen om de status van de knoppen te controleren.
  // De knoppen zijn LOW wanneer ze ingedrukt zijn.
  bool knop1Ingedrukt = digitalRead(knopPin1) == LOW;
  bool knop2Ingedrukt = digitalRead(knopPin2) == LOW;

  //Als beide knoppen zijn ingedrukt, ga dan 3s heen en 0.5s terug.
  if (knop1Ingedrukt && knop2Ingedrukt) {
    actieKnopIngedrukt(tijd1, tijd2, true);
    // Als alleen de eerste knop is ingedrukt, ga dan 3s heen en 3s terug.
  } else if (knop1Ingedrukt) {
    actieKnopIngedrukt(tijd1, tijd1, false);
    // Als alleen de tweede knop is ingedrukt, ga dan 0.5s heen en 0.5s terug.
  } else if (knop2Ingedrukt) {
    actieKnopIngedrukt(tijd2, tijd2, false);
  }

  // Een korte delay om te voorkomen dat de loop te snel draait.
  delay(50);
}

// Een functie die de servo motor laat bewegen op basis van het aantal seconden.
void actieKnopIngedrukt(float heenwegTijd, float terugwegTijd, bool beideKnoppen) {
  // Zet de servo motor in de beginpositie.
  MijnServo.write(0);
  // Maak een boolean variabele om te controleren of de knoppen nog steeds ingedrukt zijn.
  bool knopIngedrukt;
  // Beweeg de servo motor van 0 naar 120 graden in stappen van 1 graad.
  for (int pos = 0; pos <= 120; pos++) {
    // Beweeg de servo motor naar de huidige positie van de iteratie.
    MijnServo.write(pos);
    // Wacht een tijd na elke beweging.
    // De tijd is * 1000 gedaan om naar milliseconden om te rekenen,
    // dan delen door 120 omdat de opdracht vraagt om een max graad van 120,
    delay((heenwegTijd * 1000.0) / 120);

    // Controleer elke iteratie of de knoppen nog steeds ingedrukt zijn.
    knopIngedrukt = digitalRead(knopPin1) == LOW || digitalRead(knopPin2) == LOW;
    // Als geen van de knoppen meer ingedrukt is, stop dan met bewegen.
    if (!knopIngedrukt) {
      // Break eindigt de loop.
      break;
    }

    // Als beide knoppen zijn ingedrukt en de positie 120 graden is,
    if (beideKnoppen && pos == 120) {
      // Pauseer de beweging voor 5 seconden.
      delay(5000);
    }
  }

  // For loop om de servo terug te bewegen vanaf de huidige positie naar 0 graden.
  for (int pos = MijnServo.read(); pos >= 0; pos--) {
    // Beweeg de servo motor naar de huidige positie van de iteratie.
    MijnServo.write(pos);
    // Zelfde formule, maar dan voor de terug duratie.
    delay((terugwegTijd * 1000.0) / 120);
  }
}
