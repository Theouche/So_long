# so_long

## Description

`so_long` est un jeu minimaliste développé en C, qui utilise une carte pour déplacer un personnage à travers différents niveaux. Le jeu fonctionne avec la bibliothèque `mlx` pour la gestion des graphismes, et inclut des fonctionnalités pour charger des cartes personnalisées, vérifier leur validité et permettre au joueur de se déplacer à l'écran.

## Fonctionnalités

- Chargement de cartes au format `.ber`.
- Détection et validation de la structure de la carte.
- Gestion des mouvements du joueur dans l'environnement du jeu.
- Affichage graphique avec gestion des images pour représenter les éléments de la carte.
- Vérification des chemins et des conditions de victoire.

## Installation

### Prérequis

- Un compilateur compatible avec le C (comme `gcc` ou `clang`).
- La bibliothèque `mlx` pour la gestion des fenêtres graphiques.
- La bibliothèque `libft` pour certaines fonctions utilitaires.

### Étapes d'installation :

1. Clonez le dépôt dans votre répertoire local :
   ```bash
   git clone <url_du_projet>
   cd so_long

2. Compilez le projet avec le Makefile :
    make

3. Lancez le jeu avec une carte :
    ./so_long maps/map.ber

## Utilisation

Le projet prend en charge les cartes spécifiées dans des fichiers `.ber`. Ces fichiers décrivent la disposition des éléments de jeu tels que les murs, les espaces vides, le joueur, et les objectifs.

Voici un exemple de structure de fichier `.ber` :

1111111
1000001
10C00E1
1000001
1111111



- `1` : Mur
- `0` : Espace vide
- `C` : Collectible
- `E` : Sortie
- `P` : Joueur

### Commandes du jeu

Pendant le jeu, vous pouvez utiliser les commandes suivantes pour interagir :

- **Déplacement du joueur :**
  - `W` : Avancer (haut)
  - `S` : Reculer (bas)
  - `A` : Aller à gauche
  - `D` : Aller à droite

- **Quitter le jeu :**
  - `ESC` : Quitter le jeu.

## Dossiers du projet

- `libft` : Contient la bibliothèque `libft` utilisée dans le projet.
- `maps` : Dossier avec des exemples de cartes `.ber` prêtes à être utilisées dans le jeu.
- `img` : Contient les images utilisées pour représenter les éléments graphiques du jeu (murs, joueur, collectibles, etc.).
- `srcs` : Contient le code source du projet.

