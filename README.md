# BOUHMIDI_lab2 : Let’s count stuff
## Sketch de l'architecture
L'architecture du design intègre un système Nios II avec une mémoire dans Qsys, accompagné d'un timer pour synchroniser l'incrémentation du compteur à un seconde. 
Du côté logiciel, un compteur décimal à 3 chiffres a été mis en œuvre en coordination avec le signal du timer, la valeur du compteur est ainsi traduite dans le programme en BCD, le choix a été fait d'utiliser un unique PIO pour les trois digits, générant ainsi une sortie logicielle de 12 bits, à savoir 4 bits par digit. 
Au niveau matériel, un composant VHDL, "bin_to_7seg.vhd", a été développé comme décodeur pour les afficheurs 7 segments. 
La sortie de notre architecture globale comprend donc 21 bits pour correspondre aux entrées des décodeurs 7 segments de chaque afficheur, permettant l'affichage des unités, disaines et centaines.
![image](https://github.com/ESN2024/BOUHMIDI_lab2/assets/144927751/fae476ee-3986-4d6c-9eb7-872b55294ee0)

## Développement HW
Bin_2_7seg en VHDL

## Développement SW
Nombre <=999 en BCD


## Compteur de secondes
![IMG_4643](https://github.com/ESN2024/BOUHMIDI_lab2/assets/144927751/fff81306-65bf-4d25-833d-a0d9de7cd030)
