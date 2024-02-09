## I/Problèmes rencontrés:
Les problèmes liés aux batteries fournies ont coûté plusieurs heures à l'avancement du projet. En effet, la première batterie récupérée avant la semaine de ski
s'est avérée être deffectueuse. J'ai pu la tester seulement au retour de la semaine de ski car je n'ai pas le matériel adapté chez moi et je n'ai pas pensé à le 
faire avant en cours (lors de la séance 5) pensant que le matériel ne serait pas deffectueux. Suite au test du voltage en sortie de la batterie, je me suis rendu 
compte qu'il ne sortait qu'environ 2,5V par cell contrairement à 3,7V minimum si celle-ci n'est que très peu chargée. J'ai alors demandé une autre batterie 3 cell
mais celle-ci posait le même problème, la rendant HS. Elle s'est même étonnemment déformée (gonflement anormal) la rendant dangeureuse (risque d'explosion).
La troisième batterie s'est avérée être en bon état. Mais la perte de temps est considérable. Tout le travail que je comptais réaliser pendant la semaine de ski
reposait sur l'utilisation de la batterie. Le projet a donc repris son cours lors de cette séance.

## II/Travail réalisé lors de la séance:
J'ai alors réalisé tout les branchements nécessaire pour tester le code théorique écrit à la seance précedente. Ce code visait à remplacer la version 1 du code 
fonctionnel côté recepteur car on a changer de pont en H en même temps que de batterie. L'ancien pont en H étaient obsolète pour une telle puissance délivrée (cf
RAPPORT SEANCE 5). Dans ce code j'ai utilisé une librairie conçut pour faciliter l'usage des ponts en H LN298, cependant malgrè les tests effectués, la voiture
ne se déplacait pas. En isolant le problème, je me suis rendu compte que les ponts en H ne délivraient pas la puissance aux moteurs. J'ai donc décidé de ne 
pas utiliser cette librairie et de créer les fonctions dont j'ai besoin par moi même. J'ai donc codé deux fonctions simple pour faire avancer et tourner la 
voiture en fonction des données reçues. Et j'ai remplacé les fonctions de la librairie par celles-ci. 
