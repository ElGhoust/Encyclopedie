#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

/*****************************************
 *                                       *
 *      ARBRE BINAIRE DE RECHERCHE       *
 *                                       *
 *****************************************/

 #include "structures.h"

 // Structure spécifique à un arbre
typedef struct ABR_maillon
{
    struct maillon_base *infos;
    struct ABR_maillon *fils_gauche;
    struct ABR_maillon *fils_droit;
}ABR_maillon, *ABR_ptrMaillon;


///*** FONCTIONS SPECIFIQUES ***/

void ABR_creer_encyclopedie(ABR_ptrMaillon *pE);

ABR_ptrMaillon ABR_creationNoeud(int i, char *titre, char* contenu);

void ABR_inserer(ABR_ptrMaillon *pE, int i, char *titre, char *contenu);

ABR_ptrMaillon ABR_supprimer(ABR_ptrMaillon *pE, int i);

ABR_ptrMaillon ABR_rechercher(ABR_ptrMaillon pE, int i);

void ABR_afficher(ABR_ptrMaillon pE);

void ABR_detruire(ABR_ptrMaillon *pE);

ABR_ptrMaillon ABR_recherche_article_plein_texte(ABR_ptrMaillon pE, char* mot);

void ABR_libererMaillon(ABR_ptrMaillon *pE);

void AfficherConsole(ABR_ptrMaillon a, int space);

#endif // ARBRE_H_INCLUDED
