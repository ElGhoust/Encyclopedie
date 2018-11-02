#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.h"

void creer_encyclopedie(ptrMaillon *pE)
{
    *pE = NULL;
}

void inserer(ptrMaillon *pE, int i, char *titre, char *contenu)
{

    // Allocation de la mémoire
    ptrMaillon nouveau      = malloc(sizeof(struct maillon));
    ptrMaillon_base article = malloc(sizeof(struct maillon_base));
    article->titre   = (char*)malloc((strlen(titre) + 1) * sizeof(char));
    article->contenu = (char*)malloc((strlen(contenu) + 1) * sizeof(char));

    // Attribution des paramètres
    article->identifiant = i;
    strcpy(article->titre, titre);
    strcpy(article->contenu, contenu);

    // Ajout de l'article dans le maillon
    nouveau->infos = article;

    // Insertion à la racine, sinon on parcourt l'arbre pour déterminer la position correcte
    if(*pE == NULL)
    {
        *pE = nouveau;
    }
    else
    {

    }


}


void supprimer(ptrMaillon *pE, int i)
{
    printf("\n\nAUCUNe SUPPRESSION DISPONIBLE...\n\n");
}

ptrMaillon_base rechercher(ptrMaillon pE, int i)
{
    printf("\n\nAUCUNE RECHERCHE DISPONIBLE...\n\n");
    return NULL;
}
