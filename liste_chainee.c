#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "liste_chainee.h"

void creer_encyclopedie(ptrMaillon *pE)
{
    *pE = NULL;
}

void inserer(ptrMaillon *pE, int i, char *titre, char *contenu)
{
    ptrMaillon nouveau      = malloc(sizeof(struct maillon));
    ptrMaillon_base article = malloc(sizeof(struct maillon_base));
    article->titre   = (char*)malloc((strlen(titre) + 1) * sizeof(char));
    article->contenu = (char*)malloc((strlen(contenu) + 1) * sizeof(char));

    article->identifiant = i;
    strcpy(article->titre, titre);
    strcpy(article->contenu, contenu);

    nouveau->infos = article;
    nouveau->suivant = *pE;

    *pE = nouveau;
}

ptrMaillon_base rechercher(ptrMaillon pE, int i)
{
    ptrMaillon parcours = pE;
    ptrMaillon_base article = NULL;
    ptrMaillon_base matchingElement = NULL;
    int trouve = 0;

    while(parcours != NULL && trouve == 0)
    {
        article = parcours->infos;
        if(article->identifiant == i)
        {
            matchingElement = parcours->infos;
            trouve = 1;
        }
        parcours = parcours->suivant;
    }

    return matchingElement;
}

void supprimer(ptrMaillon *pE, int i)
{
    ptrMaillon parcours = *pE;
    ptrMaillon precedent;
    ptrMaillon_base article = parcours->infos;

    // Suppression en tête
    if(parcours != NULL && article->identifiant == i)
    {
        *pE = parcours->suivant;
        free(parcours);
        return;
    }

    // Suppression au milieu
    while(parcours != NULL && article->identifiant != i)
    {
        precedent = parcours;
        parcours = parcours->suivant;
        if(parcours != NULL)
            article = parcours->infos;
    }

    // Si l'article n'est pas présent
    if(parcours != NULL)
    {
        precedent->suivant = parcours->suivant;
        free(parcours);
    }
}

/****      FONCTIONS DE DEBUG      ****/

int estVide(ptrMaillon pE)
{
    return(pE == NULL);
}

void afficher(ptrMaillon pE)
{
    ptrMaillon parcours = pE;
    ptrMaillon_base article;
    if(pE == NULL) { printf("La liste est vide !"); }
    else
    {
        printf("Affichage de l'encyclopedie...\n");
        while(parcours != NULL)
        {
            article = parcours->infos;
            printf("--- Article numero %d ---\n", article->identifiant);
            printf("Titre: %s\n", article->titre);
            printf("Contenu: %s\n\n", article->contenu);
            parcours = parcours->suivant;
        }
    }
}
