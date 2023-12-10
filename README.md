# Labo 07 - Jeu de la Vie


### Objectif
- Présentation du code aussi propre que possible
- Décomposition en librairies et sous-programmes réutilisables

### A faire
Le jeu de la vie, inventé par J. H. Conway, utilise une grille rectangulaire de cellules, chacune d’entre elles pouvant contenir 0 ou 1 habitant.
Chaque cellule a jusqu’à huit et nous utiliserons « occ(k) » pour désigner le nombre de cellules voisines de la cellule k qui sont occupées.

L’état d’une nouvelle génération est obtenu à partir de la précédente en appliquant deux règles simples :

- Un habitant situé dans la cellule k survit à la génération suivante si occ(k) = 2 ou 3, et meurt dans le cas contraire
- Il y aura une “naissance” dans une cellule k vide si occ(k) = 3, sinon la cellule restera vide.

Ecrire un programme en C++ qui, partant d’une configuration initiale donnée (cf. Indications), calcule un certain nombre de générations suivantes en application des règles ci-dessus et affiche chacune des configurations trouvées.

L’affichage sera fait en utilisant les symboles

- O cellule vide
- X cellule occupée

### Complément

- [Jeu de la Vie - Wikipedia](https://fr.wikipedia.org/wiki/Jeu_de_la_vie)
- La taille et le contenu du tableau sont connues à la compilation dans le programme appelant (main) ainsi que le nombre de générations max à créer
- Le programme stoppe lorsqu'il n'y a plus d'évolution
- Représenter les grilles comme dans les exemples ci-dessous

Les instructions suivantes permettent d’effacer l’écran avant de le réafficher.

~~~
#ifdef _WIN32
   system("CLS");
#else
   system("clear");
#endif
~~~


### Modalités
- à faire **par groupe de 2 étudiants**
- 6 périodes

<details>
<summary>Output - mode normal</summary>

~~~
Ce programme ...

------------------------------
         GENRATION NO 0
------------------------------
     0  1  2  3  4  5  6  7  8
  0  .  .  .  .  .  .  .  .  .
  1  .  .  .  .  .  .  .  .  .
  2  .  .  .  X  X  X  .  .  .
  3  .  .  .  .  X  .  .  .  .
  4  .  .  .  .  X  .  .  .  .
  5  .  .  .  .  X  .  .  .  .
  6  .  .  .  .  .  .  .  .  .
  7  .  .  .  .  .  .  .  .  .
  8  .  .  .  .  .  .  .  .  .

------------------------------
         GENRATION NO 1
------------------------------
     0  1  2  3  4  5  6  7  8
  0  .  .  .  .  .  .  .  .  .
  1  .  .  .  .  X  .  .  .  .
  2  .  .  .  X  X  X  .  .  .
  3  .  .  .  .  .  .  .  .  .
  4  .  .  .  X  X  X  .  .  .
  5  .  .  .  .  .  .  .  .  .
  6  .  .  .  .  .  .  .  .  .
  7  .  .  .  .  .  .  .  .  .
  8  .  .  .  .  .  .  .  .  .

------------------------------
         GENRATION NO 2
------------------------------
     0  1  2  3  4  5  6  7  8
  0  .  .  .  .  .  .  .  .  .
  1  .  .  .  X  X  X  .  .  .
  2  .  .  .  X  X  X  .  .  .
  3  .  .  .  .  .  .  .  .  .
  4  .  .  .  .  X  .  .  .  .
  5  .  .  .  .  X  .  .  .  .
  6  .  .  .  .  .  .  .  .  .
  7  .  .  .  .  .  .  .  .  .
  8  .  .  .  .  .  .  .  .  .

------------------------------
         GENRATION NO 3
------------------------------
     0  1  2  3  4  5  6  7  8
  0  .  .  .  .  X  .  .  .  .
  1  .  .  .  X  .  X  .  .  .
  2  .  .  .  X  .  X  .  .  .
  3  .  .  .  X  .  X  .  .  .
  4  .  .  .  .  .  .  .  .  .
  5  .  .  .  .  .  .  .  .  .
  6  .  .  .  .  .  .  .  .  .
  7  .  .  .  .  .  .  .  .  .
  8  .  .  .  .  .  .  .  .  .

------------------------------
         GENRATION NO 4
------------------------------
     0  1  2  3  4  5  6  7  8
  0  .  .  .  .  X  .  .  .  .
  1  .  .  .  X  .  X  .  .  .
  2  .  .  X  X  .  X  X  .  .
  3  .  .  .  .  .  .  .  .  .
  4  .  .  .  .  .  .  .  .  .
  5  .  .  .  .  .  .  .  .  .
  6  .  .  .  .  .  .  .  .  .
  7  .  .  .  .  .  .  .  .  .
  8  .  .  .  .  .  .  .  .  .

------------------------------
         GENRATION NO 5
------------------------------
     0  1  2  3  4  5  6  7  8
  0  .  .  .  .  X  .  .  .  .
  1  .  .  X  X  .  X  X  .  .
  2  .  .  X  X  .  X  X  .  .
  3  .  .  .  .  .  .  .  .  .
  4  .  .  .  .  .  .  .  .  .
  5  .  .  .  .  .  .  .  .  .
  6  .  .  .  .  .  .  .  .  .
  7  .  .  .  .  .  .  .  .  .
  8  .  .  .  .  .  .  .  .  .

------------------------------
         GENRATION NO 6
------------------------------
     0  1  2  3  4  5  6  7  8
  0  .  .  .  X  X  X  .  .  .
  1  .  .  X  .  .  .  X  .  .
  2  .  .  X  X  .  X  X  .  .
  3  .  .  .  .  .  .  .  .  .
  4  .  .  .  .  .  .  .  .  .
  5  .  .  .  .  .  .  .  .  .
  6  .  .  .  .  .  .  .  .  .
  7  .  .  .  .  .  .  .  .  .
  8  .  .  .  .  .  .  .  .  .
~~~
</details>

---
Bon travail
