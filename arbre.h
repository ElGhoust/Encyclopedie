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
    struct ptrMaillon_base *infos;
    struct maillon *fils_gauche;
    struct maillon *fils_droit;
}maillon, *ptrMaillon;


///*** FONCTIONS SPECIFIQUES ***/

void creer_encyclopedie(ptrMaillon *pE);

void inserer(ptrMaillon *pE, int i, char *titre, char *contenu);

void supprimer(ptrMaillon *pE, int i);

ptrMaillon_base rechercher(ptrMaillon pE, int i);

void afficher(ptrMaillon pE);

#endif // ARBRE_H_INCLUDED
