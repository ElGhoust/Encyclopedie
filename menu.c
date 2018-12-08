#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

int choix()
{
    int choix = -1;
    printf("->");
    scanf("%d", &choix);
    return choix;
}

int choixImplementation(int limiteBasse, int limiteHaute)
{
    int choix;
    do
    {
        printf("->");
        scanf("%d", &choix);
    }while( limiteBasse > choix || limiteHaute < choix );
    return choix;
}

void afficherMenuImplementation()
{
    printf("---- CHOIX DE LA METHODE D'IMPLEMENTATION ----\n");
    printf("1) Liste chainee\n");
    printf("2) Arbre binaire de recherche\n");
    printf("3) Table de hachage\n");
}

void afficherMenu()
{
    printf("\n\n---- MENU ----\n");
    printf("1) Effectuer une recherche\n");
    printf("2) Supprimer un article\n");
    printf("3) Afficher l'encyclopedie\n");
    printf("4) Recherche plein texte\n");
    printf("5) Vider\n");
    printf("6) Quitter\n");
}
