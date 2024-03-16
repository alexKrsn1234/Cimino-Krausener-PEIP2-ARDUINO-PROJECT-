### Ce rapport est particulièrement long car il contient également le travail réalisé pendant les vacances de noël

# I/Travail réalisé pendant les vacances

##  I.1 MODULES HC-12

Découverte des modules et de leur fonctionnement, reconfiguration de ceci grâce aux commandes AT afin de communiquer sur une certaine fréquence(choix du canal)
à une certaine vitesse(baud rate) et du mode de fonctionnement(maitre/esclave, emmeteur/recepteur...).
Nombreux tests de communication effectués afin d'acquérir l'expérience nécessaire et de choisir un mode de fonctionnement paraissant adapté (les 3 premiers test 
ont étés réalisés sur 2 arduino uno (emmeteur/récepteur).
  1. envoie d'un bit d'information (0 ou 1)
  2. [contrôle à distance d'une led](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/tree/75dc7679b8dd1df151e483f3b57c5de4d6d7daa8/code/telecommunication/HC-12/HC12%20tests/ledtest)
  3. [envoie d'informations avec des bits de contôle (start, end)](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/tree/c85a4c9da3db763ce2f43376df78de46311b8d21/code/test/HC12%20tests/TEST3)
     
  Emmetteur maintenant placé sur une Arduino Esplora   
  
  4. [envoie d'informations depuis le joystick de l'esplora](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/tree/c85a4c9da3db763ce2f43376df78de46311b8d21/code/test/car%20tests/esploratest/Joystick%20test)
  5. [envoie d'informations correctement encodées (bits de contrôles + bits liés au module d'envoie) à l'arduino uno du récepteur](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/tree/c85a4c9da3db763ce2f43376df78de46311b8d21/code/test/car%20tests/esploratest/Cytron%20motor%20test)
  


## I.2 HC-12 ET ESPLORA ET VOITURE

Définition d'un algorithme d'envoie/réception des données pour éviter les confusions.
Les valeurs envoyées sont les suivantes : Roll (enclenche le roulage du véhicule en fonction de la valeur de -255 à 255), Direction (décide de la valeur
de l'angle donnée aux roues avant de -255 à 255) et Communication (démarre une vérifiaction de la connexion).   

Les valeurs de Roll et de Direction sont calculées à l'aide des input de l'utilisateur. Ces calculs sont donc réalisés avant même l'envoie des données 
afin de priviliéger un envoie d'informations plus compacte.    

Ainsi, comme dans le [test 5](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/tree/c85a4c9da3db763ce2f43376df78de46311b8d21/code/test/car%20tests/esploratest/Cytron%20motor%20test), la valeur de roll est fonction de l'inclinaison du joystick(2) en Y et du slider(1), la valeur de direction dépend uniquement de l'inclinaison du joystick(2) en X.    

Ce sont ces données qui sont ensuite envoyées à l'arduino de la voiture par les modules RF HC-12.
Chaque envoie de données de l'esplora est certi de 2 bits de contrôle 's'(start) et 'e'(end) ainsi qu'un bit de séparation 'd'. 

Un envoie de données ressemble par exemple à "s120d58e", avec 120 pour la valeur de roll et 58 pour celle de direction.   

Une fois ces données reçues, l'HC-12 placé sur l'arduino de la voiture transmet ces données à l'arduino qui les "décrypte" et envoie l'infomation
nécessaire au pont en H qui contrôle les moteurs. Pour reprendre l'exemple précédent on demande au pont en H d'envoyer 120 au moteur 2 qui contôle 
la vitesse de la voiture et 58 au moteur 1(servo).  

La voiture semble lente, il faudra tester avec 2 ponts en H fonctionnels car je pense qu'avoir mis les 2 moteurs responsables de la vitesse de la voiture
sur la même sortie du pont en H divise le courant sortant de celui-ci en 2 (moteurs placés en parrallèles). Cela semble avoir un impact non négligeable
sur la puissance électrique reçue par les moteurs (divisée également par 2) et ainsi diminuant leur performance.


## I.3 POINTS A AMELIORER:

### 1. vitesse de la voiture:   

  Hypothèse: mettre 2 pont en H ou envoyer plus de patate
  

### 2. télécommunication:    

  -De nombreuses données semblent être perdues lors de la télécommunication   
  Hypothèse: Jouer sur les réglages des modules HC-12 afin de gagner en performance   
             Mettre des capacités en amont des modules comme recommandé   
             Changer de modules...    
             
  -Créer une vérification de la communication pour voir lorsque des données sont perdues (allumage led esplora)

### 3. branchements:
  -Réaliser des soudures pour simplifier les branchements réalisés et éviter les faux-contacts.   


## I.4 CREATION DE PLANS DANS LE BUT DE REALISER NOTRE PROPRE CHASSIS  

Nous avons décidé de prendre de l'avance sur la potentielle suite du projet en commençant à réaliser des plans 3D du futur chassis sur OnShape.
Alexandre réalisera l'ensemble de la partie transmission (Engrenages moteur, axe...) et les "suspensions" tandis que je tenterai de réaliser le bloc
chassis ainsi que l'aspect directionnel.
  


