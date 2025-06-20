# Opdracht 5
## Opdrachtomschrijving
Op de arduino zijn 2 drukknoppen aangesloten.  
Zolang op drukknop 1 wordt gedrukt, draait een servomotor van 0 graden naar 120 graden in 3 seconden.  
Dit betekent dus dat de servo niet volledig zal draaien, want de servo kan 180 graden draaien.
Als de servomotor zijn uiterste stand heeft bereikt, dan moet hij terugdraaien naar 0 graden in 3 seconden.  
Het is hierbij dus niet bekend of de gebruiker de knop nog steeds ingedrukt houdt...  
Ik ga hierbij ervanuit dat de gebruiker de knop heeft losgelaten.  
Zolang op de tweede drukknop wordt gedrukt, moet de servo van 0 graden naar 120 graden draaien in 0,5 seconden.  
Als de servo zijn uiterste stand heeft bereikt, dan moet hij terugdraaien naar 0 graden in 0,5 seconden.  
Als beide knoppen tegelijkertijd worden ingedrukt, dan moet de servo van 0 graden naar 120 graden draaien in 3 seconden.  
5 seconden blijven staan en dan terugdraaien naar 0 graden in 0,5 seconden.  
De beweging van de motor moet in 1 functie of methode worden gemaakt.  
(Er zal dus gewerkt moeten worden met parameters voor de tijden of snelheden)  
Ingangen en uitgangen zijn zelf te kiezen.

## Eigen onderzoek
Om code te schrijven voor deze opdracht, is het belangrijk om te weten hoe een servomotor werkt.  
Een servomotor kan draaien van 0 tot 180 graden, maar de snelheid en de tijd die het kost om te draaien, kunnen worden aangepast.  
De Arduino IDE heeft een ingebouwde bibliotheek voor servomotoren, genaamd "Servo.h".  
Dit importeer je met '#include <Servo.h>'.
Verder heeft een servomotor 3 aansluitingen. 1 voor de voeding, 1 voor de ground en 1 voor het signaal.

## Verzameling
- Ik heb een Arduino Uno kit nodig.
- Ik heb een BreadBoard nodig.
- Ik heb 1 servomotor nodig.
- Ik heb 2 drukknoppen nodig.
- Ik heb 2 resistors nodig van 10K Ohm.
- Ik heb 9 draadjes nodig. (3 voor de servo, 4 voor de drukknoppen en 2 voor de voeding van het breadboard)
- Ik heb een USB kabel nodig, om de Arduino Uno aan te sluiten op de computer.
- Ik heb een computer nodig, om de Arduino IDE te gebruiken.

## Bronnen
https://www.youtube.com/watch?v=v6NsAZ_srsM&ab_channel=Tronicslk