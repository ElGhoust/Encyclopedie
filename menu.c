#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

// TODO: Probleme si l'utilisateur entre un caractere
int choix()
{
    int choix;
    scanf("%d", &choix);
    return choix;
}

void afficherMenu()
{
    printf("---- MENU ----\n");
    printf("1) Effectuer une recherche\n");
    printf("2) Supprimer un article\n");
    printf("3) Afficher l'encyclopedie\n");
    printf("4) Quitter\n");
}
