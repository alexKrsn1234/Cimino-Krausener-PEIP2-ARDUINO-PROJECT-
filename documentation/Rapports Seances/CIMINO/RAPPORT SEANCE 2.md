#      SEANCE DU 22/12/2023 


Lors de cette séance j'ai été occupé par l'aspect télécommunication que recquiert notre projet. Il s'agissait alors de paramétrer les modules HC-12
qui nous ont étés confiés afin de réaliser la liaison entre la télécommande (Arduino esplora) et la voiture (commandée par l'arduino UNO).

J'ai alors paramétré les modules afin qu'ils communiquent sur les mêmes fréquences et qu'ils possèdent la même vitesse de transmission grâce aux commandes AT.
   
  -paramétrage de la vitesse de transmission entre les 2 modules:
    AT+Bxxxx avec xxxx vitesse de transmission des informations. J'ai choisi la valeur de 9600 bauds car je ne pense pas qu'utiliser 
    une valeur élevée soit une bonne idée, on risque de surcharger le canal et les cartes arduino alors que les moteurs de la voiture ne pourront pas suivre
    l'ensemble des ordes données à une telle vitesse car ils sont assujettis à une certaine inertie (je pense qu'il vaut mieux leur donner des valeurs "lissées 
    dans le temps"). Cette valeur pourra être modifier en fonction des résultats des expérimenttaions menées. 
  
  -paramétrage de la fréquence utilisée pour communiquer réalisé en choisissant la chaine sur laquelle communiquer:
    AT+Cxxx avec xxx numéro de chaine allant de 001 à 100 (001 correspond à une fréquence d'émission/réception de 433,4MHz elle augmente de 400KHz
    par augmentation de chaine). J'ai choisi arbitrairement le channel 050 mais encore une fois cette valeur pourra évoluer au cours du temps en fonction de 
    l'analyse empirique de la qualité de la télécommunication.
    
    
Ensuite, le but était de faire communiquer les 2 modules à distance.

Pour cela je me suis renseigner sur la documentation peu fournie du HC-12 pour établir un code établissant cette communication et la vérifiant.
Le but était d'envoyer des bits d'information 0 ou 1 d'un module à l'autre et de retranscrire les informations reçues sur le moniteur série de l'IDE Arduino.
Cependant malgrè de nombreuses tentatives, je n'ai pas réussi à faire passer une information d'un module à l'autre, je m'y atèlerai donc pendant les vacances.

Je suis alors parvenu à un programme à tenir avant la séance du 12 janvier:
-établir la communcation entre les 2 modules
-établir un protocole perfectionné d'envoie des bits pour envoyer des informations plus complexe sans confusion de données.
-connecter correctement un des modules à la télécommande (Arduino esplora) et récupérer conformément au protocole établie précedemment les informations
entrées par l'utilisateur de la télécommande.
-envoyer ces informations à l'autre module placé sur l'arduino uno (qui sera sur la voiture) selon le protocole.
-transférer les donées reçues et effectuer les actions demandées (donc nécessite un codage des informations selon le même
protocole définit précedemment).
