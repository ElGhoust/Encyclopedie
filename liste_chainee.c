#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "liste_chainee.h"

/** Fonction d'initialisation de la liste chainee.
 *
 *  *pE un pointeur correspondant à l'entree de la liste chainee
 */
void LC_creer_encyclopedie(LC_ptrMaillon *pE)
{
    *pE = NULL;
}

// Permet de créer un maillon et d'allouer la mémoire.
/** Creation d'un maillon de la liste chainee, pointant vers un article dont les
 *  valeurs de l'identidiant, du titre et du contenu sont assignees.
 *
 *  int i         = entier pour l'identifiant
 *  char *titre   = chaine de caracteres pour le titre
 *  char *contenu = chaine de caracteres pour le contenu
 *
 *  Retourne le maillon créé
 */
LC_ptrMaillon LC_creationNoeud(int i, char *titre, char* contenu)
{
    LC_ptrMaillon nouveau      = malloc(sizeof(struct LC_maillon));
    ptrMaillon_base article = malloc(sizeof(struct maillon_base));
    article->titre   = (char*)malloc((strlen(titre) + 1) * sizeof(char));
    article->contenu = (char*)malloc((strlen(contenu) + 1) * sizeof(char));

    article->identifiant = i;
    strcpy(article->titre, titre);
    strcpy(article->contenu, contenu);

    nouveau->infos = article;
    return nouveau;
}

// Permet l'insertion d'un maillon dans une liste
void LC_inserer(LC_ptrMaillon *pE, int i, char *titre, char *contenu)
{
    LC_ptrMaillon nouveau = LC_creationNoeud(i, titre, contenu);

    nouveau->suivant = *pE;

    *pE = nouveau;
}

ptrMaillon_base LC_rechercher(LC_ptrMaillon pE, int i)
{
    LC_ptrMaillon parcours = pE;
    ptrMaillon_base matchingElement = NULL;
    ptrMaillon_base article = NULL;
    int trouve = 0;

    while(parcours != NULL && trouve == 0)
    {
        article = parcours->infos;
        if(article->identifiant == i)
        {
            matchingElement = parcours->infos;
            trouve = 1;
        }
        parcours = parcours->suivant;
    }

    return matchingElement;
}

/** Retourne une encyclopedie contenant tous les articles contenant le mot "mot"
 *  à la manière d'un moteur de recherche
 * \param ptrMaillon pE L'entree de l'encyclopedie
 * \param char* mot Le mot a rechercher dans l'encyclopedie
 * \return Une encyclopedie contenant les articles trouves
 */

LC_ptrMaillon LC_recherche_article_plein_texte(LC_ptrMaillon pE, char* mot)
{
    LC_ptrMaillon listeArticleMot = NULL;
    ptrMaillon_base informationsArticle = NULL;
    while(pE != NULL)
    {
        informationsArticle = pE->infos;
        if (strstr(informationsArticle->contenu, mot) != NULL)
        {
            LC_inserer(&listeArticleMot, informationsArticle->identifiant, informationsArticle->titre, informationsArticle->contenu);
        }
        pE = pE->suivant;
    }
    return listeArticleMot;
}

void LC_supprimer(LC_ptrMaillon *pE, int i)
{
    LC_ptrMaillon parcours = *pE;
    LC_ptrMaillon precedent;

    // Suppression en tête
    if(parcours != NULL && parcours->infos->identifiant == i)
    {
        *pE = parcours->suivant;
        LC_libererMaillon(&parcours);
        return;
    }

    // Suppression au milieu
    while(parcours != NULL && parcours->infos->identifiant != i)
    {
        precedent = parcours;
        parcours = parcours->suivant;
    }

    // Si l'article est trouve, le supprimer
    if(parcours != NULL)
    {
        precedent->suivant = parcours->suivant;
        LC_libererMaillon(&parcours);
    }
}

void LC_detruire(LC_ptrMaillon *pE)
{
    LC_ptrMaillon parcours = *pE;
    LC_ptrMaillon prochain;

    while(parcours != NULL)
    {
        prochain = parcours->suivant;
        LC_libererMaillon(&parcours);
        parcours = prochain;
    }

    *pE = NULL;
}

void LC_libererMaillon(LC_ptrMaillon *pE)
{
    LC_ptrMaillon maillon = *pE;
    free(maillon->infos->titre);
    free(maillon->infos->contenu);
    free(maillon->infos);
    free(maillon);
}

/****      FONCTIONS DE DEBUG      ****/

int LC_estVide(LC_ptrMaillon pE)
{
    return(pE == NULL);
}

void LC_afficher(LC_ptrMaillon pE)
{
    LC_ptrMaillon parcours = pE;
    ptrMaillon_base article;
    if(pE == NULL) { printf("La liste est vide !\n\n"); }
    else
    {
        printf("Affichage de l'encyclopedie...\n");
        while(parcours != NULL)
        {
            article = parcours->infos;

            printf("========================================\n");
            printf("Id : %d\n", article->identifiant);
            printf("Titre : %s\n", article->titre);
            printf("Extrait : %s", article->contenu);
            parcours = parcours->suivant;
        }
    }
}
