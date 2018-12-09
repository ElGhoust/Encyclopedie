#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.h"

void ABR_creer_encyclopedie(ABR_ptrMaillon *pE)
{
    *pE = NULL;
}

/// Permet de créer un maillon et d'allouer la mémoire.
ABR_ptrMaillon ABR_creationNoeud(int i, char *titre, char* contenu)
{
    // Allocation de la mémoire
    ABR_ptrMaillon nouveau      = malloc(sizeof(struct ABR_maillon));
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
void ABR_inserer(ABR_ptrMaillon *pE, int i, char *titre, char *contenu)
{
    ABR_ptrMaillon arbre = *pE;
    ABR_ptrMaillon nouveau;

    if (arbre == NULL)
    {
        nouveau = ABR_creationNoeud(i, titre, contenu);
        *pE = nouveau;
    }
    else
    {
        if ( i <= arbre->infos->identifiant)
        {
            ABR_inserer(&(arbre->fils_gauche), i, titre, contenu);
        }
        else
        {
            ABR_inserer(&(arbre->fils_droit), i, titre, contenu);
        }
    }
}

/// TODO: A REVOIR
ABR_ptrMaillon ABR_supprimer(ABR_ptrMaillon *pE, int i)
{
    ABR_ptrMaillon arbre = *pE;

    if (arbre == NULL) return arbre;

    if (i < arbre->infos->identifiant)
        arbre->fils_gauche = ABR_supprimer(&(arbre->fils_gauche), i);
    else if (i > arbre->infos->identifiant)
        arbre->fils_droit = ABR_supprimer(&(arbre->fils_droit), i);

    else
    {
        if (arbre->fils_gauche == NULL)
        {
            ABR_ptrMaillon temp = arbre->fils_droit;
            free(arbre);
            return temp;
        }
        else if (arbre->fils_droit == NULL)
        {
            ABR_ptrMaillon temp = arbre->fils_gauche;
            free(arbre);
            return temp;
        }

        ABR_ptrMaillon temp = arbre->fils_droit;
        while (temp->fils_gauche != NULL)
            temp = arbre->fils_gauche;

        arbre->infos->identifiant = temp->infos->identifiant;

        arbre->fils_droit = ABR_supprimer(&(arbre->fils_droit), temp->infos->identifiant);
    }
    return arbre;
}

/// TERMINE
ABR_ptrMaillon ABR_rechercher(ABR_ptrMaillon pE, int i)
{
    ABR_ptrMaillon articleRecherche = NULL;

    if( pE != NULL )
    {
        if ( pE->infos->identifiant == i )
        {
            articleRecherche = pE;
        }
        else
        {
            if ( i < pE->infos->identifiant )
                articleRecherche = ABR_rechercher(pE->fils_gauche, i);
            else
                articleRecherche = ABR_rechercher(pE->fils_droit, i);
        }
    }

    return articleRecherche;
}

/// TERMINE
void ABR_detruire(ABR_ptrMaillon *pE)
{
    ABR_ptrMaillon parcours = *pE;
    if(!pE) return;

    if(parcours->fils_gauche) ABR_detruire(&parcours->fils_gauche);

    if(parcours->fils_droit) ABR_detruire(&parcours->fils_droit);

    ABR_libererMaillon(&parcours);

    *pE = NULL;
}

/// TERMINE
void ABR_afficher(ABR_ptrMaillon pE)
{
    if(pE != NULL)
    {
        printf("========================================\n");
        printf("Id : %d\n", pE->infos->identifiant);
        printf("Titre : %s\n", pE->infos->titre);
        printf("Extrait : %s", pE->infos->contenu);
        ABR_afficher(pE->fils_gauche);
        ABR_afficher(pE->fils_droit);
    }
}

ABR_ptrMaillon ABR_recherche_article_plein_texte(ABR_ptrMaillon pE, char* mot)
{
    ABR_ptrMaillon listeArticleMot = NULL;
    ptrMaillon_base informationsArticle = NULL;
    if(pE != NULL)
    {
        informationsArticle = pE->infos;
        if (strstr(informationsArticle->contenu, mot) != NULL)
        {
            ABR_inserer(&listeArticleMot, informationsArticle->identifiant, informationsArticle->titre, informationsArticle->contenu);
        }
        ABR_recherche_article_plein_texte(pE->fils_gauche, mot);
        ABR_recherche_article_plein_texte(pE->fils_droit, mot);
    }
    ABR_afficher(listeArticleMot);
    return listeArticleMot;
}

void ABR_libererMaillon(ABR_ptrMaillon *pE)
{
    ABR_ptrMaillon maillon = *pE;
    free(maillon->infos->titre);
    free(maillon->infos->contenu);
    free(maillon->infos);
    free(maillon);
}

void AfficherConsole(ABR_ptrMaillon a, int space) {

	if (a == NULL)
		return;

	space += 5;

	AfficherConsole(a->fils_droit, space);

	printf("\n");

	int i;
	for (i = 5; i < space; i++)
		printf(" ");
	printf("%d", a->infos->identifiant);
	printf("\n");

	AfficherConsole(a->fils_gauche, space);
}
