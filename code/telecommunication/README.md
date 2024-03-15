### Comment la télécommunication est-elle assurée ?

Celle-ci est assurée par les modules émetteurs/récepteurs Radio Fréquence HC-12. Ces modules se présentent comme ceci:   
![image](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/assets/127763192/2eabf3e1-c9c6-444f-9d1b-0715361f4296)



Un des modules est placé sur l'arduino émetteur et l'autre sur l'arduino récepteur.
Le but final est d'envoyer le minimum d'informations afin d'éviter tout problème de surcharge des canaux, perte d'information... Il s'agit alors d'envoyer une 
valeur de vitesse visée de la voiture (roll) et de direction (direction)
L'ensemble des calculs nécessaires à la récupération de ces valeurs sont ainsi effectués côté émetteur avant leur envoi.
Les informations sont ensuite encodées au moment de l'envoi c'est à dire qu'elles sont serties de différents bits de contrôle.

Une fois réceptionées par l'arduino récepteur ces informations sont décodées et les valeurs reçues de roll et direction sont redirigées vers les pont en H. 

##### Détails techniques

fréquence: 433.4 MHz   
channel: 001   
baudrate: 9600
