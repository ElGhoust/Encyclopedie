#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#include "menu.h"

#define EXIT_NUMBER 5

void lectureFichier(char* nomFichier, ptrMaillon *ptrTete)
{
    FILE* fp;
    int time = 0;
    int identifiant;
    int i = 0;
    char* Titre;
    char* Contenu;
    char* token;
    char* ligne = malloc(sizeof(char) * 50000);

    fp = fopen(nomFichier, "r");
    while(fgets(ligne, 50000, fp) != NULL)
    {
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
        inserer(ptrTete, identifiant, Titre, Contenu);
        i = 0;
    }
    fclose(fp);
    time = clock();
    printf("L'ensemble des articles a ete insere en %f\n\n", (float)time/CLOCKS_PER_SEC);
}

int main(int argc, char const *argv[])
{
    int menuChoix = -1;
    ptrMaillon ptrTete;
    ptrMaillon_base elementRecherche;

    creer_encyclopedie(&ptrTete);
    lectureFichier("B46_310000.dat", &ptrTete);

    do
    {
        afficherMenu();
        menuChoix = choix();
        switch(menuChoix)
        {
            case 1:
                elementRecherche = processus_recherche(ptrTete);
                break;
            case 2:
                processus_suppression(&ptrTete);
                break;
            case 3:
                afficher(ptrTete);
                break;
            case 4:
                detruire(&ptrTete);
                break;
            case EXIT_NUMBER:
                printf("Au plaisir de vous revoir !\n");
                break;
            default:
                printf("\n...\n\n");
        }
    }while(menuChoix != EXIT_NUMBER);

    return 0;
}
