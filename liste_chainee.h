#include "structures.h"

/****************************
 *                          *
 *      LISTE CHAINEE       *
 *                          *
 ****************************/

// Structure spécifique à une liste chaînée
typedef struct maillon
{
    struct ptrMaillon_base *infos;
    struct maillon *suivant;
}maillon, *ptrMaillon;


///*** FONCTIONS SPECIFIQUES ***/

void creer_encyclopedie(ptrMaillon *pE);

void inserer(ptrMaillon *pE, int i, char *titre, char *contenu);

void supprimer(ptrMaillon *pE, int i);

ptrMaillon_base rechercher(ptrMaillon pE, int i);

void afficher(ptrMaillon pE);

