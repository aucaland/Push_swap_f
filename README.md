# Push_swap

## Description
Le projet **Push_swap** consiste à trier une pile d'entiers en utilisant un ensemble d'instructions limitées et en minimisant le nombre d'opérations effectuées. L'objectif est de manipuler les données à l'aide de différentes techniques de tri et d'algorithmes pour trouver la solution la plus efficace pour trier les entiers.

## Objectifs
- Implémenter un algorithme de tri efficace en C.
- Minimiser le nombre d'opérations nécessaires pour trier une pile d'entiers.
- Le programme doit utiliser un ensemble d'instructions spécifiques (swap, push, rotate, reverse rotate).
- Calculer le programme de tri le plus court possible.
- Respecter les normes de programmation (pas de variables globales, gestion correcte de la mémoire, etc.).

## Instructions disponibles
- **sa** : Swap entre les deux premiers éléments de la pile a.
- **sb** : Swap entre les deux premiers éléments de la pile b.
- **ss** : Swap entre les deux piles a et b.
- **pa** : Push de l'élément du sommet de b vers a.
- **pb** : Push de l'élément du sommet de a vers b.
- **ra** : Rotation de la pile a.
- **rb** : Rotation de la pile b.
- **rr** : Rotation simultanée des piles a et b.
- **rra** : Reverse rotation de la pile a.
- **rrb** : Reverse rotation de la pile b.
- **rrr** : Reverse rotation simultanée des piles a et b.

## Programme principal : `push_swap`
- Le programme reçoit une liste d'entiers en paramètre (pile a).
- Il doit afficher la plus courte série d'instructions permettant de trier la pile a, le plus petit nombre étant au sommet.
- En cas d'erreur (paramètres invalides, doublons), il doit afficher "Error".

### Exemple
```bash
$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

Pour 100 nombres, le programme doit trier en moins de 700 opérations.

Pour 500 nombres, le programme doit trier en moins de 5500 opérations.
