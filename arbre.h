#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

/*****************************************
 *                                       *
 *      ARBRE BINAIRE DE RECHERCHE       *
 *                                       *
 *****************************************/

 #include "structures.h"

 // Structure spécifique à un arbre
typedef struct maillon
{
    struct maillon_base *infos;
    struct maillon *fils_gauche;
    struct maillon *fils_droit;
}maillon, *ptrMaillon;


///*** FONCTIONS SPECIFIQUES ***/

void creer_encyclopedie(ptrMaillon *pE);

ptrMaillon creationNoeud(int i, char *titre, char* contenu);

void inserer(ptrMaillon *pE, int i, char *titre, char *contenu);

ptrMaillon supprimer(ptrMaillon *pE, int i);

ptrMaillon rechercher(ptrMaillon pE, int i);

void afficher(ptrMaillon pE);

void detruire(ptrMaillon *pE);

#endif // ARBRE_H_INCLUDED
