## QUICK HC-12 DOCSHEET
![image](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/assets/127763192/5ca17a5a-b225-4c54-b240-8da6913d776c)

### PINS
![image](https://github.com/alexKrsn1234/Cimino-Krausener-PEIP2-ARDUINO-PROJECT-/assets/127763192/df87c886-d5de-467c-9d7a-7d16c6354462)   

Les pins VCC et GRD servent sans surprise à l'alimentation des modules.   
Les pins TXD et RXD eux permettent l'envoie d'information à travers le module.   
Le pin SET est utilisé pour configurer le module(mode, fréquence...).   


### CONFIG
Après avoir mis le pin "SET" à la masse, le module devrait être dans le mode "AT" prêt à recevoir les informations afin d'être paramétré (féquence, baud rate...)
Les différentes commandes utiles sont:   
  AT+Bxxxx pour modifier le baud-rate   
  AT+Cxxx pour modifier la chaine et ainsi la fréquence sur laquelle le module communique   
  AT+FUx pour modifier le mode de communication (délai d'envoie de bits, distance max de communication et optimisation de l'utilisation d'énergie)

### [Une documentation complète ici](https://statics3.seeedstudio.com/assets/file/bazaar/product/HC-12_english_datasheets.pdf)
