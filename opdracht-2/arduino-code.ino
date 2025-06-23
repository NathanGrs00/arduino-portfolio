// Array met de pinnen die gebruikt worden.
int pinLijst[] = {13, 11, 10, 8, 7, 5, 3, 0};
// Hier hebben we de totaal aantal elementen in de array nodig.
// Maar sizeof(pinLijst) geeft het aantal bytes terug, niet het aantal elementen.
// Om het aantal elementen te berekenen, delen we de totale grootte van de array
// door de grootte van een enkel element in de array.
int aantalPins = sizeof(pinLijst) / sizeof(pinLijst[0]);
// De delay tussen de pulsen in milliseconden.
int vertragingMs = 50;

// Setup functie wordt één keer uitgevoerd bij het opstarten van de Arduino.
void setup(){
  // for loop om alle pinnen in de pinLijst te initialiseren.
  for (int x = 0; x < aantalPins; x++) {
    // Roep de pinSetup functie aan voor elke pin in de array.
    pinSetup(pinLijst[x]);
  }
}

// Loop functie wordt continu uitgevoerd na de setup.
void loop(){
  // Voer de functie van links naar rechts en daarna van rechts naar links.
  linksNaarRechts();
  rechtsNaarLinks();
}

// Functies om de LED's van links naar rechts te laten knipperen.
void linksNaarRechts() {
  // Loop door alle pinnen in de pinLijst.
  for (int x = 0; x < aantalPins; x++){
    // Roep de pulse functie aan voor elke pin in de array.
  	pulse(pinLijst[x]);
  }
}

// Functie om de LED's van rechts naar links te laten knipperen.
void rechtsNaarLinks() {
    // Loop door de pinnen in de pinLijst, maar in omgekeerde volgorde.
  for (int x = aantalPins -1; x >= 0; x--) {
    // Roep de pulse functie aan voor elke pin in de array.
    pulse(pinLijst[x]);
  }
}

// Functie om een pin in te stellen als output.
void pinSetup(int pin) {
  pinMode(pin, OUTPUT);
}

// Functie om een puls te geven op een pin.
void pulse(int pin){
  // HIGH betekent dat de pin aan staat.
  digitalWrite(pin, HIGH);
    // Wacht voor de opgegeven delay in milliseconden.
  delay(vertragingMs);
    // LOW betekent dat de pin uit staat.
  digitalWrite(pin, LOW);
    // Wacht opnieuw voor de opgegeven delay in milliseconden.
  delay(vertragingMs);
}