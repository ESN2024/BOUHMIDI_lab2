# BOUHMIDI_lab2 : Let’s count stuff
## Sketch de l'architecture
L'architecture du design intègre un système Nios II avec une mémoire dans Qsys, accompagné d'un timer pour synchroniser l'incrémentation du compteur à un seconde. 
Du côté logiciel, un compteur décimal à 3 chiffres a été mis en œuvre en coordination avec le signal du timer, la valeur du compteur est ainsi traduite dans le programme en BCD, le choix a été fait d'utiliser un unique PIO pour les trois digits, générant ainsi une sortie logicielle de 12 bits, à savoir 4 bits par digit. 
Au niveau matériel, un composant VHDL, "bin_to_7seg.vhd", a été développé comme décodeur pour les afficheurs 7 segments. 
La sortie de notre architecture globale comprend donc 21 bits pour correspondre aux entrées des décodeurs 7 segments de chaque afficheur, permettant l'affichage des unités, disaines et centaines.
![image](https://github.com/ESN2024/BOUHMIDI_lab2/assets/144927751/fae476ee-3986-4d6c-9eb7-872b55294ee0)

## Architecture sur QSYS
Comme décrit ci-dessus, l'architecture software comprend un timer et un unique PIO pour les 3 chiffres étalé sur 12bits, comme on peut le voir sur la figure suivante :

![image](https://github.com/ESN2024/BOUHMIDI_lab2/assets/144927751/8e3c6065-b7af-46ad-857c-9181727ac108)


## Développement HW
**Bin_2_7seg en VHDL**
La conception matérielle en VHDL du convertisseur "bin to 7 seg" est privilégiée en raison de son adaptabilité naturelle à la structure séquentielle des afficheurs à sept segments. En utilisant des registres et des bascules, le VHDL offre une approche parallèle pour générer les signaux de commande nécessaires pour afficher les chiffres en sortie.

![image](https://github.com/ESN2024/BOUHMIDI_lab2/assets/144927751/e4252d56-e16a-49ca-a1d8-b74e436cc056)


## Développement SW
**Nombre <=999 en BCD**

La conception logicielle en langage C pour le convertisseur "chiffre to BCD" est privilégiée quant à elle en raison de la nécessité d'utiliser des opérations arithmétiques telles que la division et l'opérateur modulo. Ces opérations sont naturellement gérées par le langage C, offrant une approche plus simple pour la conversion des chiffres en code décimal binaire. En revanche, la description matérielle pourrait devenir complexe et potentiellement lourde en utilisant ces opérations arithmétiques directement dans le VHDL. C'est pourquoi la conception conjointe, combinant la conception matérielle et logicielle, est adoptée dans notre cas. 

![image](https://github.com/ESN2024/BOUHMIDI_lab2/assets/144927751/c5d6414e-d32f-4f59-86c4-9c64ba005608)


## Compteur de secondes


Le programme crée un compteur visuel qui s'incrémente à chaque seconde grâce au timer. Le timer génère une interruption toute les secondes, et à chaque fois que l'interruption se produit, l'ISR, handle_timer_interrupt, est déclenchée, celle ci met en place la logique pour convertir le compteur en trois chiffres distincts représentant les centaines, dizaines et unités. Ces chiffres sont ensuite combinés pour former une valeur entière qui est converti de binaire en 7 segment (en VHDL), puis affiché sur l'afficheur à sept segments.

Le compteur est conçu pour afficher une séquence croissante de chiffres, reflétant le passage du temps. Les opérations de division et de modulo sont utilisées pour extraire les chiffres individuels du compteur, et cette information est ensuite écrite dans le registre de sortie du PIO. Cela met à jour l'affichage à chaque seconde, créant une animation visuelle d'incrémentation du compteur.

Le programme fonctionne en boucle infinie, le compteur continue de s'incrémenter et d'afficher la séquence de chiffres correspondante à une fréquence régulière, offrant une représentation visuelle du passage du temps.

![IMG_4643](https://github.com/ESN2024/BOUHMIDI_lab2/assets/144927751/fff81306-65bf-4d25-833d-a0d9de7cd030)

## Conclusion 
Ce LAB en particulier, nous permet de tirer la conclusion que la conception conjointe permet de tirer parti de la puissance des deux méthodes, à savoir la description software en C et hardware en VHDL, en utilisant la souplesse du logiciel pour les opérations arithmétiques et la réactivité du matériel pour la gestion séquentielle des afficheurs à sept segments.
