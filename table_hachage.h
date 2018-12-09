#ifndef TABLE_HACHAGE_H_INCLUDED
#define TABLE_HACHAGE_H_INCLUDED

/****************************
 *                          *
 *      LISTE CHAINEE       *
 *                          *
 ****************************/

 #include "structures.h"
 #include "liste_chainee.h"

// Structure spécifique à une liste chaînée
typedef struct HT_maillon
{
    int val;
    struct LC_maillon *liste;
}HT_maillon;


///*** FONCTIONS SPECIFIQUES ***/

int hachage(int identifiant, int HT_SIZE);

void HT_creer_encyclopedie(HT_maillon *pE, int HT_SIZE);

void HT_afficher(HT_maillon *pE, int HT_SIZE);

void HT_inserer(HT_maillon *tableHachage, int i, char *titre, char *contenu, int HT_SIZE);

void HT_supprimer(HT_maillon *tableHachage, int i, int HT_SIZE);

ptrMaillon_base HT_recherche_article(HT_maillon *tableHachage, int i, int HT_SIZE);

LC_ptrMaillon HT_recherche_article_plein_texte(HT_maillon *tableHachage, char* mot, int HT_SIZE);

void HT_detruire(HT_maillon *tableHachage, int HT_SIZE);

#endif // TABLE_HACHAGE_H_INCLUDED
