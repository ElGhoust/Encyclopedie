#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.h"

void creer_encyclopedie(ptrMaillon *pE)
{
    *pE = NULL;
}

/// Permet de créer un maillon et d'allouer la mémoire.
ptrMaillon creationNoeud(int i, char *titre, char* contenu)
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
    nouveau->fils_gauche = NULL;
    nouveau->fils_droit = NULL;

    // Ajout de l'article dans le maillon
    nouveau->infos = article;
    return nouveau;
}

void inserer(ptrMaillon *pE, int i, char *titre, char *contenu)
{
}

void supprimer(ptrMaillon *pE, int i)
{
    printf("\n\nAUCUNE SUPPRESSION DISPONIBLE...\n\n");
}

ptrMaillon_base rechercher(ptrMaillon pE, int i)
{
    printf("\n\nAUCUNE RECHERCHE DISPONIBLE...\n\n");
    return NULL;
}

void afficher(ptrMaillon pE)
{
    if(!pE) return;

    if(pE->fils_gauche != NULL)
    {
        afficher(pE->fils_gauche);
    }

    ptrMaillon_base article = pE->infos;
    printf("Valeur = %d\n", article->identifiant);

    if(pE->fils_droit != NULL)
    {
        afficher(pE->fils_droit);
    }
}
