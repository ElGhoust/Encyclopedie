#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table_hachage.h"
#include "liste_chainee.h"

int hachage(int identifiant, int HT_SIZE)
{
    return identifiant % HT_SIZE;
}

void HT_creer_encyclopedie(HT_maillon *tableHachage, int HT_SIZE)
{
    int i;
    for(i = 0; i < HT_SIZE; i++)
    {
        LC_creer_encyclopedie(&(tableHachage[i].liste));
    }
}

void HT_afficher(HT_maillon tableHachage[], int HT_SIZE)
{
    int i;
    for(i = 0; i < HT_SIZE; i++)
    {
        printf("Affichage de l'encyclopedie TableHachage[%d] :\n", i);
        LC_afficher(tableHachage[i].liste);
        printf("\n");
    }
}

void HT_inserer(HT_maillon *tableHachage, int i, char *titre, char *contenu, int HT_SIZE)
{
    int index = hachage(i, HT_SIZE);
    LC_inserer(&(tableHachage[index].liste), i, titre, contenu);
}

void HT_supprimer(HT_maillon *tableHachage, int i, int HT_SIZE)
{
    int index = hachage(i, HT_SIZE);
    LC_supprimer(&(tableHachage[index].liste), i);
}

ptrMaillon_base HT_recherche_article(HT_maillon *tableHachage, int i, int HT_SIZE)
{
    int index = hachage(i, HT_SIZE);
    return LC_rechercher(tableHachage[index].liste, i);
}

LC_ptrMaillon HT_recherche_article_plein_texte(HT_maillon *tableHachage, char* mot, int HT_SIZE)
{
    LC_ptrMaillon listeArticleMot = NULL;
    LC_ptrMaillon parcours = NULL;
    int i;
    for(i = 0; i < HT_SIZE; i++)
    {
        parcours = tableHachage[i].liste;
        while(parcours != NULL)
        {
            if (strstr(parcours->infos->contenu, mot) != NULL)
            {
                LC_inserer(&listeArticleMot, parcours->infos->identifiant, parcours->infos->titre, parcours->infos->contenu);
            }
            parcours = parcours->suivant;
        }
    }

    return listeArticleMot;
}

void HT_detruire(HT_maillon *tableHachage, int HT_SIZE)
{
    int i;
    for(i = 0; i < HT_SIZE; i++)
    {
        LC_detruire(&(tableHachage[i].liste));
    }
}
