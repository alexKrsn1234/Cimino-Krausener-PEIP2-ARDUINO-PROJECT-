## TRAVAIL REALISE:
Lors de cette séance, je me suis attelé à faire fonctionner la voiture. Lors de la séance précédente nous avions résolu le bug qui empêchait la voiture de se
déplacer. Cette fois ci j'ai donc réalisé tout les branchements nécessaires pour l'utilisation des 2 ponts en H et j'ai donc testé le [code théorique](code/test/cartests/esploratest/L298nmotortest/receiver/receiver.ino)
réalisé il y a 2 seances auquel j'ai rajouté une fonction pour tourner. Le test se faisait donc à distance à l'aide de la télécommande. Le test a dans l'ensemble
porté ses fruits mais on a pu constaté certains bugs:   
  -La voiture n'a pas le même comportement en marche avant et en marche arrière.

  -Elle est capable de tourner que d'un seul côté.

  -Elle n'est pas capble de réaliser une marche arrière à pleine puissance.

  -Elle peut difficilement avancer et tourner en même temps.

Nous avons donc chercher des solutions pour palier à ces problèmes. Alexandre s'est penché sur la question et vous trouverez ses recherches dans son rapport de
séance. Finalement après de nombreux essais infructueux, nous avons décidé de charger pleinement la batterie (elle était à ~3,8V par cell) jusqu'à ~4,2V par cell.
Il semble alors que cette recharge soit la solution au problème. Une solution qui semble toutefois partielle car nous aimerions dans l'idéal que la voiture
remplisse ses fonctions pendant un maximum de temps d'utilisation. J'ai alors procédé à des tests pour déterminer jusque quel voltage la voiture est totalement 
opérationnelle. Cette valeur est atteinte pour METTRE LE VOLTAGE. Nous en avons donc conclu que METTRE UNE CONCLUSION.

J'ai également décidé de créer une pièce qui servirait de support pour placer l'ensemble de nos composants (jusqu'à présent plus ou moins bien entassés sur 
le chassis de la voiture) afin de rendre un travail plus propre et avec moins de risque de casse(faux-contacts...).
