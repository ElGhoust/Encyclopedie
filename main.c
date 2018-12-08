#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#include "menu.h"
#include "arbre.h"
#include "liste_chainee.h"

#define EXIT_NUMBER 6

void lectureFichier(char* nomFichier, LC_ptrMaillon *LC_ptrTete, ABR_ptrMaillon *ABR_ptrTete, int efz, int typeImplementation)
{
    FILE* fp;
    int time = 0;
    int identifiant;
    int i;
    char* Titre;
    char* Contenu;
    char* token;
    char* ligne = malloc(sizeof(char) * 80000);

    fp = fopen(nomFichier, "r");
    while(fgets(ligne, 80000, fp) != NULL)
    {
        i = 0;
        token = strtok(ligne, "|");
        while(token != NULL)
        {
            switch(i)
            {
                case 0:
                    identifiant = atoi(token);
                    break;
                case 1:
                    Titre = token;
                    break;
                case 2:
                    Contenu = token;
                    break;
            }
            token = strtok(NULL, "|");
            i++;
        }

        switch(typeImplementation)
        {
            case 1:
                LC_inserer(LC_ptrTete, identifiant, Titre, Contenu);
                break;
            case 2:
                ABR_inserer(ABR_ptrTete, identifiant, Titre, Contenu);
                break;
            case 3:
                //HT_inserer(HT_ptrTete, identifiant, Titre, Contenu);
                break;
        }
    }
    fclose(fp);
    time = clock();
    printf("L'ensemble des articles a ete insere en %f\n\n", (float)time/CLOCKS_PER_SEC);
}

int main(int argc, char const *argv[])
{
    char* motCompletRecherche = malloc(sizeof(char) * 50);

    int typeImplementation = -1;
    int menuChoix = -1;
    int idARechercher = -1;
    int idArticleASupprimer = -1;

    LC_ptrMaillon LC_ptrTete;
    LC_ptrMaillon LC_listeArticleMotComplet;
    ptrMaillon_base elementRecherche;

    ABR_ptrMaillon ABR_ptrTete;
    ABR_ptrMaillon ABR_ArticleRecherche;
    ABR_ptrMaillon ABR_listeArticleMotComplet;

    afficherMenuImplementation();
    typeImplementation = choixImplementation(1, 3);

    switch (typeImplementation)
    {
        /** LISTE CHAINEE **/
        case 1 :
            LC_creer_encyclopedie(&LC_ptrTete);
            lectureFichier("B46_500.dat", &LC_ptrTete, &ABR_ptrTete, 3, typeImplementation);
            do
            {
                afficherMenu();
                menuChoix = choix();
                switch(menuChoix)
                {
                    case 1:
                        printf("Veuillez entrer l'identifiant de l'article a rechercher...\n");
                        idARechercher = choix();
                        elementRecherche = LC_rechercher(LC_ptrTete, idARechercher);
                        if(elementRecherche != NULL)
                        {
                            printf("\nTitre de l'element recherche : %s.\n", elementRecherche->titre);
                        }
                        else
                        {
                            printf("\nAucun element ne correspond a cet identidiant.\n\n");
                        }
                        break;
                    case 2:
                        idArticleASupprimer = -1;
                        printf("Veuillez entrer l'identifiant de l'article a supprimer...\n");
                        idArticleASupprimer = choix();
                        LC_supprimer(&LC_ptrTete, idArticleASupprimer);
                        break;
                    case 3:
                        LC_afficher(LC_ptrTete);
                        break;
                    case 4:
                        printf("Entrez le mot a rechercher : ");
                        scanf("%s", motCompletRecherche);
                        LC_listeArticleMotComplet = LC_recherche_article_plein_texte(LC_ptrTete, motCompletRecherche);
                        LC_afficher(LC_listeArticleMotComplet);
                        free(motCompletRecherche);
                        break;
                    case 5:
                        LC_detruire(&LC_ptrTete);
                        break;
                    case EXIT_NUMBER:
                        printf("Au plaisir de vous revoir !\n");
                        break;
                    default:
                        printf("\n...\n\n");
                }
            }while(menuChoix != EXIT_NUMBER);
            break;
        case 2 :
            /** ARBRE BINAIRE DE RECHERCHE **/
            ABR_creer_encyclopedie(&ABR_ptrTete);
            lectureFichier("B46_10.dat", &LC_ptrTete, &ABR_ptrTete, 3, typeImplementation);
            do
            {
                afficherMenu();
                menuChoix = choix();
                switch(menuChoix)
                {
                    case 1:
                        printf("Veuillez entrer l'identifiant de l'article a rechercher...\n");
                        idARechercher = choix();
                        ABR_ArticleRecherche = ABR_rechercher(ABR_ptrTete, idARechercher);
                        if(ABR_ArticleRecherche != NULL)
                        {
                            printf("\nTitre de l'element recherche : %s.\n", ABR_ArticleRecherche->infos->titre);
                        }
                        else
                        {
                            printf("\nAucun element ne correspond a cet identidiant.\n\n");
                        }
                        break;
                    case 2:
                        idArticleASupprimer = -1;
                        printf("Veuillez entrer l'identifiant de l'article a supprimer...\n");
                        idArticleASupprimer = choix();
                        ABR_supprimer(&ABR_ptrTete, idArticleASupprimer);
                        break;
                    case 3:
                        ABR_afficher(ABR_ptrTete);
                        AfficherConsole(ABR_ptrTete, 0);
                        break;
                    case 4:
//                      printf("Entrez le mot a rechercher : ");
//                      scanf("%s", motCompletRecherche);
//                      ABR_listeArticleMotComplet = ABR_recherche_article_plein_texte(ABR_ptrTete, motCompletRecherche);
//                      LC_afficher(LC_listeArticleMotComplet);
//                      free(motCompletRecherche);
                        break;
                    case 5:
                        //detruire(&ABR_ptrTete);
                        break;
                    case EXIT_NUMBER:
                        printf("Au plaisir de vous revoir !\n");
                        break;
                    default:
                        printf("\n...\n\n");
                }
            }while(menuChoix != EXIT_NUMBER);
            break;
        case 3 :
            // Table de hachage
            break;
    }

    return 0;
}
