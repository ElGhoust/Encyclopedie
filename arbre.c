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
    ptrMaillon nouveau = creationNoeud(i, titre, contenu);
    ptrMaillon arbre = *pE;
    ptrMaillon noeud = NULL;

    if(arbre)
    {
        do
        {
            noeud = arbre;
            if(i > arbre->infos->identifiant)
            {
                arbre = arbre->fils_droit;
                if(!arbre) noeud->fils_droit = nouveau;
            }
            else
            {
                arbre = arbre->fils_gauche;
                if(!arbre) noeud->fils_gauche = nouveau;
            }
        }
        while(arbre);
    }
    else
    {
        *pE = nouveau;
    }
}

void supprimer(ptrMaillon *pE, int i)
{
    printf("\n\nAUCUNE SUPPRESSION DISPONIBLE...\n\n");
}

ptrMaillon_base rechercher(ptrMaillon pE, int i)
{
    ptrMaillon_base articleRecherche = NULL;
    int trouve = 0;

    while(pE != NULL && trouve == 0)
    {
        if(pE->infos->identifiant == i)
        {
            articleRecherche = pE->infos;
            trouve = 1;
        }

        if(i < pE->infos->identifiant)
            pE = pE->fils_gauche;
        else
            pE = pE->fils_droit;
    }

    return articleRecherche;
}

void detruire(ptrMaillon *pE)
{
    ptrMaillon parcours = *pE;
    if(!pE) return;

    if(parcours->fils_gauche) detruire(&parcours->fils_gauche);

    if(parcours->fils_droit) detruire(&parcours->fils_droit);

    free(parcours->infos->titre);
    free(parcours->infos->contenu);
    free(parcours->infos);
    free(parcours);

    *pE = NULL;
}

void afficher(ptrMaillon pE)
{
    if(!pE) return;

    if(pE->fils_gauche)
    {
        afficher(pE->fils_gauche);
    }

    printf("Valeur = %d\n", pE->infos->identifiant);

    if(pE->fils_droit)
    {
        afficher(pE->fils_droit);
    }
}
