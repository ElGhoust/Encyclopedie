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

//ptrMaillon rechercher(ptrMaillon pE, int i)
//{
//    ptrMaillon element = pE;
//    while(element->infos->identifiant != i)
//    {
//        element = element->suivant;
//    }
//    return element;
//}

//void supprimer(ptrMaillon *pE, int i)
//{
//    ptrMaillon parcours = *pE;
//    while(parcours->suivant->infos->identifiant != i && parcours->suivant != NULL)
//    {
//        parcours = parcours->suivant;
//    }
//    if(parcours->suivant == NULL) { return; }
//    else
//    {
//        free(parcours);
//    }
//}

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
        printf("Affichage de la pile :\n");
        while(parcours != NULL)
        {
            article = parcours->infos;
            printf("Article numero %d\n", article->identifiant);
            printf("Titre: %s\n", article->titre);
            printf("Contenu: %s\n\n", article->contenu);
            parcours = parcours->suivant;
        }
    }
}
