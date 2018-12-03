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
    printf("\n\n---- MENU ----\n");
    printf("1) Effectuer une recherche\n");
    printf("2) Supprimer un article\n");
    printf("3) Afficher l'encyclopedie\n");
    printf("4) Vider\n");
    printf("5) Quitter\n");
}

void processus_suppression(ptrMaillon *ptrTete)
{
    int idASup = -1;

    printf("Veuillez entrer l'identifiant de l'article a supprimer...\n");
    idASup = choix();
    supprimer(ptrTete, idASup);
}

ptrMaillon_base processus_recherche(ptrMaillon ptrTete)
{
    int idARechercher;
    ptrMaillon recherche;

    printf("Veuillez entrer l'identifiant de l'article a rechercher...\n");
    idARechercher = choix();
    recherche = rechercher(ptrTete, idARechercher);

    return recherche->infos;
}
