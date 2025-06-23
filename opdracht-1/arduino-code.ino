// Globale variabelen voor de pinnen.
// Hierbij is opgezocht hoe je een variabele in C++ kan declareren.
// @author: https://docs.arduino.cc/language-reference/en/variables/variable-scope-qualifiers/const/
const int pin1 = 10;
const int pin2 = 13;

// Functie om één keer code uit te voeren. 
// Hier wordt het gebruikt om twee pins op de Arduino als OUTPUT aan te geven.
void setup() {
  // Pin 10 en 13 worden gebruikt als OUTPUT.
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}

// Functie die in een loop wordt uitgevoerd.
void loop() {
  // Roep functie aan om te loopen.
  knipper(pin1, pin2, 2000);
}

/*
Functie om te knipperen

@param1 pin1 = Integer voor de eerste pin op de Arduino kit.
@param2 pin2 = Integer voor de tweede pin op de Arduino kit.
@paramm3 vertragingMs = Vertraging in milliseconde.
*/
void knipper(int pin1, int pin2, int vertragingMs) {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  delay(vertragingMs);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  delay(vertragingMs);
}
