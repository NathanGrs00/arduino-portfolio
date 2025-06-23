// Analoge pin voor de potmeter.
const int potPin = A5;
// Waarde van de potmeter.
int potWaarde = 0;
// Array met de pin nummers van de Ledlampjes.
int pinLijst[] = {13, 12, 11, 10, 9, 8};
// Bereken de hoeveelheid ledjes we hebben.
// sizeof geeft totale bytes terug, niet de elementen.
// Daarom delen we de totale bytes door de hoeveelheid bytes van 1 element.
const int pinAantal = sizeof(pinLijst) / sizeof(pinLijst[0]);

// Deze code wordt 1 keer uitgevoerd na opstarten.
void setup() {
  // For loop om door het aantal LED lampjes te gaan.
  for (int x = 0; x < pinAantal; x++){
    // Voor elk lampje, roep stelLedsIn() aan. Geef de huidige led mee.
    stelLedsIn(x);
  }
}

// Blijft constant deze code loopen tijdens dat de arduino aan is.
void loop(){
  // Waarde van de potmeter lezen.
  potWaarde = analogRead(potPin);
  // Roep deze functie aan om mogelijk de leds te veranderen en geef de potWaarde mee.
  veranderLeds(potWaarde);
}

/* Functie om de lampjes te initialiseren.

@param1 positie = De positie van de lamp in de pinLijst array.
*/
void stelLedsIn(int positie){
  // Zorgt dat de pins een output worden bij elk lampje.
  pinMode(pinLijst[positie], OUTPUT);
}

/*
Functie om lampjes te veranderen.

@param1 potmeterWaarde = De waarde van de potmeter die we uitlezen.
@author: https://www.arduino.cc/en/Tutorial/BuiltInExamples/BarGraph/
*/
void veranderLeds(int potmeterWaarde){
  // Verdeel eerst de maximale waarde van de potmeter over het aantal lampjes.
  // Dan word de huidige waarde van de potmeter gedeeld door de waarde van elk vlak.
  // Het resultaat is het aantal ledjes dat uitgezet moet worden.
  int aantalLedsUit = potmeterWaarde / (1024 / pinAantal);

  // For loop om door de hoeveelheid pins te gaan.
  for (int x = 0; x < pinAantal; x++) {
    // Voor elke LED, kijk of de indexwaarde van de LED
    // kleiner is dan de hoeveelheid LED's om uit te zetten.
    if (x < aantalLedsUit) {
      // Als dit zo is, betekent dat deze LED uit moet.
      digitalWrite(pinLijst[x], LOW);
    } else {
      // Zo niet, dan blijft hij aan, of gaat hij dus weer terug aan.
      digitalWrite(pinLijst[x], HIGH);
    }
  }
}