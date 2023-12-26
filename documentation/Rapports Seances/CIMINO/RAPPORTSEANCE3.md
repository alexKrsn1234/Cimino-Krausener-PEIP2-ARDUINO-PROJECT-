### Ce rapport est particulièrement long car il contient également le travail réalisé pendant les vacances de noël

# I/Travail réalisé pendant les vacances

##  I.1 Modules HC-12

Découverte des modules et de leur fonctionnement, reconfiguration de ceci grâce aux commandes AT afin de communiquer sur une certaine fréquence(choix du canal)
à une certaine vitesse(baud rate) et du mode de fonctionnement(maitre/esclave, emmeteur/recepteur...).
Nombreux tests de communication effectués afin d'acquérir l'expérience nécessaire et de choisir un mode de fonctionnement paraissant adapté (les 4 premiers test 
ont étés réalisés sur 2 arduino uno (emmeteur/récepteur).
  1. envoie d'un bit d'information (0 ou 1)
  2. [contrôle à distance d'une led](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/tree/cebb8eb280bce17945ba15044184ac086a9e09f4/code/TELECOMMUNICATION/HC-12/HC12-commSR/LEDTEST) 
  3. envoie d'informations avec des bits de contôle (start, end)
  4. envoie d'informations destinées à des actions différentes côté recepteur
  Emmetteur maintenant placé sur une Arduino Esplora
  5. [envoie d'informations depuis le joystick de l'esplora](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/tree/cebb8eb280bce17945ba15044184ac086a9e09f4/code/TELECOMMUNICATION/HC-12/HC12-commSR/ESPLORATEST)
  6. envoie d'informations correctement encodées (bits de contrôles + bits liés au module d'envoie) à l'arduino uno du récepteur
  

##  I.2 Arduino Esplora

Découverte de l'Arduino Eplora ainsi que de la librairie associée. La carte est simple d'utilisation niveau code, cependant le challenge résidait dans la 
faible documentation concernant les pins. Après quelques recherches j'ai trouvé une documentation non-officielle qui semble correcte. 
Réalisation de tests permettant de récupérer les informations données par les différents modules de la télécommande. La librairie est simple.
Définition des modules que nous utiliserons pour notre projet.
![image](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/assets/127763192/239b7123-25a9-473f-9b85-8eb9a99dbf49)

1. potentiomètre, ajuste la puissance délivrée aux moteurs 
2. joystick, permet d'avancer, reculer, tourner
3. vérifie la bonne communication entre la télécommande et la voiture (alummme une led de couleur en fonction de l'état de la connection)

Test réalisé:
Récupération de l'état du potentiomètre(1), du joystick(2), et du bouton d'état de la connection(3).


## I.3 HC-12 ET ESPLORA

Définission d'un algorithme d'envoie/réception des données pour éviter les confusions.
Chaque envoie de données de l'esplora par le modules HC-12 est certi de 2 bits de contrôle 'S'(Start) et 'E'(End) ainsi qu'un bit de confirmation
'P'(Potentiomètre), 'J'(Joystick) et 'C'(Communication).

Un envoie de données du potetiomètre ressemble par exemple à "SP120E".
Une fois ces données reçues, l'HC-12 placé sur l'arduino de la voiture transmet ces données à l'arduino qui les "décrypte" et envoie l'infomation
nécessaire au pont en H qui contrôle les moteurs ou au HC-12 récepteur qui devient émmeteur en cas de réception de la balise 'C'.
