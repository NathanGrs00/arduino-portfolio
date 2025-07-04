// Tellertje
int teller = 1;
// Vaste led en knop pins.
const int ledPin1 = 11;
const int ledPin2 = 5;
const int knopPin = 8;

// Globale variabele om de laatste stand van de knop te bewaren.
int laatsteKnopStatus = HIGH;

// Deze functie wordt een keer uitgevoerd.
void setup(){
  // Zet de Led's als output en de button als input.
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(knopPin, INPUT);
  // Zorg ervoor dat in het begin pin 5 aan staat, niet pin 11.
  // Dit doen we door de veranderLeds functie 1 keer aan te roepen.
  veranderLeds();
}

// Deze functie wordt constant doorheen gelooped.
void loop() {
  // Lees de state van de knop af.
  // @author: https://docs.arduino.cc/built-in-examples/digital/Button/
  int knopStatus = digitalRead(knopPin);

  // Dit checkt of de knop is ingedrukt.
  // LOW is de ingedrukte staat, omdat hij naar GND drukt.
  // laatsteKnopStatus == HIGH zorgt ervoor dat de knop niet blijft knipperen bij indrukken
  if (knopStatus == LOW && laatsteKnopStatus == HIGH) {
    // Kleine delay.
    delay(50);
    // Voeg 1 toe bij het tellertje.
    teller++;
    // Zorg dat de LED's veranderd worden.
    veranderLeds();
  }

  // Sla de huidige stand op als laatste stand, voor de volgende iteratie.
  // Hiermee reageert de loop alleen bij een nieuwe knopindruk.
  laatsteKnopStatus = knopStatus;
}

// Functie om de LED's te updaten.
void veranderLeds() {
  // Als het tellertje / 2 geen getal achter de comma achter laat,
  // dan is het getal even en voer het volgende uit:
  if (teller % 2 == 0) {
    // Linkse led aan, rechtse uit.
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  } else {
    // Linkse led uit, rechtse aan.
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
  }
}