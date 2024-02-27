## BUT DE LA SEANCE:
Le but que je m'étais fixé lors de cette séance était d'isoler la panne rencontrée la semaine dernière et de parvenir à la contourner.
Pour revenir un peu sur la panne, la voiture ne réagissait pas malgrè la bonne réception des données de la télécommande (côté emmeteur), il s'agissait donc
d'un problème côté voiture (code jusqu'à présent théorique, branchements ou composant(s) deffectueux). 

## TRAVAIL REALISE LORS DE LA SEANCE:
Afin d'isoler cette panne j'ai donc décidé de tester l'ensemble de la partie côté recepteur (code, branchements et composants). Afin de ne pas rajouter une potentiel nouvelle panne
j'ai décidé de ne pas travailler avec la télécommande mais d'implémenter directement le code nécessaire aux tests sur l'arduino de la voiture.
### Partie code:
Pour être sûr de la fiabilité de mon code, j'ai analyser chaque ligne de mon code ainsi que leur but et comparer avec le code de la séance de travail effectuée 
au cours du 1er semestre avec les ponts en H LN298N. Aucun problème de semblait venir du code. Les bons usages étaient respectés ainsi que les bonnes 
procédures. J'ai pu tester les fonctions du code sur une autre voiture et celui-ci fonctionnait convenablement. Le bug ne venait donc pas du code.

### Partie branchements et composants:
Dans le but de tester mes branchements et mes composants j'ai utilisé un multimètre principalement en tant que voltmètre afin de tester les tensions aux bornes de
ceux-ci. J'avais déjà des indcations visuelles (carte arduino bien alimentée car diode de contrôle alummée). J'ai alors testé les tensions en entrée et en sortie 
des ponts en H en implémentant des codes simples (ex : avancer en continue à fond, on est censé récupérer un haut voltage en sortie (out1,out2), le même qu'en entrée sur 
la patte enable. Lors de ce test je me suis rendu compte que les ponts en H étaient obsolètes. Ils ne fonctionnaient pas ou plus (impossible à déterminer) étant
donné qu'on avait jamais su les faire fonctionner (soit parce qu'ils étaient obsolètes initialement ou car nous les avions rendu hors service suite à une mauvaise
utilisation au départ). J'ai alors demandé de nouveaux ponts en H et était très précautioneux. Après les avoir branchés correctement (non sans mal car il s'agit 
d'un vrai travail d'orfèvre), j'ai réalisé à nouveau des tests qui se sont avérés fructueux. La panne provenait seulement des ponts en H. Nous pouvons reprendre 
l'avancement du projet.

