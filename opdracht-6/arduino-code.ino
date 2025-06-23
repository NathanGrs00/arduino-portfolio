// Het toevoegen van de Servo library.
#include <Servo.h>
// Het aanmaken van een Servo object.
Servo MijnServo;
// Dit zijn de variabelen voor de trigger en echo pin. Beide worden gebruikt door de ultrasoon sensor.
const int trigPin = 9;
const int echoPin = 10;

void setup(){
  // Koppel de servomotor aan pin 5.
  MijnServo.attach(5);
  // Zet de motor in de beginpositie.
  MijnServo.write(0);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Dit wordt constant uitgevoerd.
void loop(){
  // Roep pingSensor functie aan en sla de waarde op in afstand.
  float afstand = pingSensor();
  // Stuur deze waarde naar de turnServo functie.
  draaiServo(afstand);
}

// Ping sensor geeft een float terug.
float pingSensor() {
  // Maak een variabele voor de duur en cm.
  long tijdMs, cm;
  // Zet hem eerst op LOW, zodat de ping sensor klaar is voor een nieuwe ping.
  digitalWrite(trigPin, LOW);
  // Wacht even om zeker te zijn dat de ping sensor klaar is.
  delayMicroseconds(2);
  // Zet de ping sensor op HIGH, dit is het moment dat de ping wordt verstuurd.
  digitalWrite(trigPin, HIGH);
  // Wacht 5 microseconden om de ping te versturen.
  delayMicroseconds(5);
  // Zet de ping sensor weer op LOW, zodat hij klaar is voor het meten van de echo.
  digitalWrite(trigPin, LOW);

  // pulseIn wacht tot de ping sensor een HIGH signaal ontvangt en meet de tijd dat dit signaal aan staat.
  tijdMs = pulseIn(echoPin, HIGH);
  // Zet de tijd om naar centimeters met een berekenfunctie.
  cm = msToCm(tijdMs);
  // Geef de waarde van cm terug.
  return cm;
}

// Functie om microseconden om te zetten naar centimeters.
long msToCm(long microsecs) {
  // Geef de waarde terug in centimeters.
  // De berekening is gebaseerd op de snelheid van geluid,
  // die ongeveer 343 meter per seconde is, of 29 microseconden per centimeter.
  // Delen door 2 om de heen- en terugreis van de ping te compenseren.
  return microsecs / 29 / 2;
}

// Functie om de servo te draaien op basis van de afstand in centimeters.
void draaiServo(float cm) {
  // Controleer of de afstand binnen het bereik van 4 tot 10 cm ligt.
  if (cm >= 4 && cm <= 10) {
    // Map de afstand naar een hoek tussen 0 en 180 graden.
    int hoek = map(cm, 10, 4, 0, 180);
    // Zet de servo naar de berekende hoek.
    MijnServo.write(hoek);
  }
  // Als de afstand kleiner is dan 4 cm, draai de servo naar 180 graden.
  else if (cm < 4) {
  	MijnServo.write(180);
  }
  // Als de afstand groter is dan 10 cm, draai de servo naar 0 graden.
  else {
    MijnServo.write(0);
  }
}