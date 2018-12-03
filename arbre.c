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

/// TERMINE
void inserer(ptrMaillon *pE, int i, char *titre, char *contenu)
{
    ptrMaillon arbre = *pE;
    ptrMaillon nouveau;

    if (arbre == NULL)
    {
        nouveau = creationNoeud(i, titre, contenu);
        *pE = nouveau;
    }
    else
    {
        if ( i <= arbre->infos->identifiant)
        {
            inserer(&(arbre->fils_gauche), i, titre, contenu);
        }
        else
        {
            inserer(&(arbre->fils_droit), i, titre, contenu);
        }
    }
}

ptrMaillon supprimer(ptrMaillon *pE, int i)
{

}

/// TERMINE
ptrMaillon rechercher(ptrMaillon pE, int i)
{
    ptrMaillon articleRecherche = NULL;

    if( pE != NULL )
    {
        if ( pE->infos->identifiant == i )
        {
            articleRecherche = pE;
        }
        else
        {
            if ( i < pE->infos->identifiant )
                articleRecherche = rechercher(pE->fils_gauche, i);
            else
                articleRecherche = rechercher(pE->fils_droit, i);
        }
    }

    return articleRecherche;
}

/// TERMINE
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

/// TERMINE
void afficher(ptrMaillon pE)
{
    if(pE != NULL)
    {
        printf("========================================\n");
        printf("Id : %d\n", pE->infos->identifiant);
        printf("Titre : %s\n", pE->infos->titre);
        printf("Extrait : %s", pE->infos->contenu);
        afficher(pE->fils_gauche);
        afficher(pE->fils_droit);
    }
}
