## I/ Partie pratique et résumé:
Cette semaine mon travail consistait pleinement à mettre en fonctionnement la voiture avec la nouvelle batterie et les nouveaux ponts en H confiés pour l'occasion.   

<img width="308" alt="image" src="https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/assets/127763192/941f4895-55b0-4a7b-af56-a30ade71fbc9">

Nous somme passé d'une batterie 2 cells(7,4V) à une 3 cells(11,1V) dans le but d'acquérir plus de puissance. Cette batterie envoyant un débit plus élevé il s'agit
donc de mettre à l'épreuve de nouveaux ponts en H car le précedent devenait ainsi obsolète. Nous possédant désormais 2 ponts en H montés sur leur module LN298N.
Pour la sélection des ponts en H et de leur nombre nous avons effectué des test d'ampérage en entrée des moteurs. En roulage avec resistance infligée afin de 
simuler les forces de frottement et le poids de la voiture s'opposant au mouvement on obtient pour une tension d'entrée de 5V un ampérage totale en entrée des 
moteurs d'environ 2 ampères. Les modules LN298N pouvant sortir jusqu'à 1,2 ampères sans compromettre la sécurité, j'ai donc choisi d'utiliser 2 ponts en H.
Le premier s'occupera de la motorisation des roues et l'autre de la direction et du potentiel futur bras dont la création repose sur Alexandre.

Afin de pouvoir alimenter ces 2 ponts en H à l'aide d'une seule batterie, J'ai soudé à chaque fil + et -d'un connecteur XT60 qui sera relié à la batterie
2 fils qui se connecteront chacuns à leur borne respective des LN298N. Les ponts en H sont ainsi connectés en parrallèle à la batterie et alimenteront ensuite
les moteurs.   

![image](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/assets/127763192/2e6678e8-c3e0-4fd5-9a46-a52d65238c74)


## II/Partie code:

Afin de finir la mise en place de ces nouveux composants, j'ai réalisé le [code théorique](/code/TELECOMMUNICATION/HC-12/HC12-commSR/ESPLORATEST/RECEIVER_HBRIDGE_V2/receiverV1/receiver/receiver.ino) pour commander les moteurs de la voiture après avoir installé 
une librairie permettant de se servir facilement des fonctionnalités du LN298N. Cependant, je n'ai pas pu vérifier le bon fonctionnement du code (cf III).

## III/Problèmes rencontrés:

Il semblait à première vue que la batterie qui nous avez été confiée etait Hors Service. En effet après l'avoir mise en charge nous avons voulu la connecter 
afin de tester nos avancées, cependant elle ne fournissait pas le courant nécessaire pour alimenter l'arduino depuis le Pont en H. ALors j'ai testé son voltage
et celui-ci était de seulement 3V au lieu de 11,1 en moyenne. Après quelques recherches (étude de graphe du potentiel d'une 3 cell) j'en ai conclu que celle-ci
était hors d'état de service. J'ai donc demandé une autre batterie mais lors de la mise en charge, le même problème apparaissait c'est à dire que 
les leds du chargeur fournit clignotait en rouge, hors ce clignotement n'est même pas renseigné sur la docsheet du chargeur. La batterie ne charge pas.
Je me questionne donc sur l'état du chargeur et sur sa bonne compatibilité avec les batteries utilisées. Je n'ai pas résolu ce problème. Je tacherai de le 
résoudre avant la prochaine séance.


