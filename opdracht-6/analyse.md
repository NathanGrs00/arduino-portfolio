# Opdracht 6
## Opdrachtomschrijving
Maak een schakeling en een sketch waarbij:  
- Een servomotor in rust op 0 graden staat.  
- Als een object binnen 10 cm van de ultrasoon zender / ontvanger komt, dan staat de motor linksom.  
- Als het object op 4 cm staat, staat de servo volledig rechtsom. (180 graden.)
- Alle afstanden tussen 10 cm en 4 cm worden lineair omgezet naar een hoek tussen 0 en 180 graden.

Het is hierbij niet duidelijk wat de servomotor doet als het object verder weg is dan 10 cm.  
Ik ga ervanuit dat de servo dan op 0 graden blijft staan.  
Net zoals als een object dichterbij komt dan 4 cm, dat de servo dan op 180 graden blijft staan.

## Eigen onderzoek
Op Tinkercad lijkt de ultrasoonzender ook 3 pinnen te hebben, GND, 5V en SIG.  
Door op de site van Arduino te kijken, zie ik dat de sensor werkt OUTPUT en INPUT afwisselend.  
Eerst wordt er een signaal uitgezonden, en daarna wordt er gewacht op een signaal terug.  
Dit signaal in milliseconden wordt dan gebruikt om de afstand te berekenen.  
De formule hiervoor is: 
```markdown
cm = ms / 29 / 2
```
De snelheid van geluid is 340 m/s of 29 ms/cm.  
Omdat het signaal heen en weer gaat, moet de tijd gedeeld worden door 2.

Tijdens het uitvoeren van de proef met de Arduino, kwam ik erachter dat we de ultrasoonsensor hebben met 4 pinnen, niet met 3.  
Hierdoor moest ik wat extra informatie opzoeken over deze andere sensor. Het enige verschil is dat er geen pingPin is, maar een triggerPin en een echoPin.  
Hierdoor hoef ik ook niet de INPUT of OUTPUT te veranderen van de pin, maar kan je dus de twee pinnen los van elkaar gebruiken.

## Verzameling
- Ik heb een Arduino Uno kit nodig.
- Ik heb een BreadBoard nodig.
- Ik heb 1 servomotor nodig.
- Ik heb 1 ultrasoon zender/ontvanger nodig.
- Ik heb 9 draadjes nodig. (3 voor de servo, 4 voor de ultrasoonzender en 2 voor de voeding van het breadboard.)
- Ik heb een USB kabel nodig, om de Arduino Uno aan te sluiten op de computer.
- Ik heb een computer nodig, om de Arduino IDE te gebruiken.

## Bronnen
https://docs.arduino.cc/built-in-examples/sensors/Ping/
https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1