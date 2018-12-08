#ifndef LISTE_CHAINEE_H_INCLUDED
#define LISTE_CHAINEE_H_INCLUDED

/****************************
 *                          *
 *      LISTE CHAINEE       *
 *                          *
 ****************************/

 #include "structures.h"

// Structure spécifique à une liste chaînée
typedef struct LC_maillon
{
    struct maillon_base *infos;
    struct LC_maillon *suivant;
}LC_maillon, *LC_ptrMaillon;


///*** FONCTIONS SPECIFIQUES ***/

void LC_creer_encyclopedie(LC_ptrMaillon *pE);

LC_ptrMaillon LC_creationNoeud(int i, char *titre, char* contenu);

void LC_inserer(LC_ptrMaillon *pE, int i, char *titre, char *contenu);

void LC_supprimer(LC_ptrMaillon *pE, int i);

ptrMaillon_base LC_rechercher(LC_ptrMaillon pE, int i);

LC_ptrMaillon LC_recherche_article_plein_texte(LC_ptrMaillon pE, char* mot);

void LC_afficher(LC_ptrMaillon pE);

void LC_detruire(LC_ptrMaillon *pE);

void LC_libererMaillon(LC_ptrMaillon *pE);

#endif // LISTE_CHAINEE_H_INCLUDED
