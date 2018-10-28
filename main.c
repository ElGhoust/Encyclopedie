#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "liste_chainee.h"
#include "menu.h"

void lectureFichier(char* nomFichier, ptrMaillon *ptrTete)
{
    FILE* fp;
    int identifiant;
    int i = 0;
    char* Titre;
    char* Contenu;
    char* token;
    char* ligne = malloc(sizeof(char) * 5000);

    fp = fopen(nomFichier, "r");
    while(fgets(ligne, 5000, fp) != NULL)
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
}

int main(int argc, char const *argv[])
{
    int menuChoix = -1;
    ptrMaillon ptrTete;
    ptrMaillon_base elementRecherche;

    creer_encyclopedie(&ptrTete);
    lectureFichier("B46_10.dat", &ptrTete);

    do
    {
        afficherMenu();
        menuChoix = choix();
        switch(menuChoix)
        {
            case 1:
                elementRecherche = rechercher(ptrTete, 8441741);
                if(elementRecherche != NULL) {printf("\nTitre de l'element recherche : %s\n", elementRecherche->titre);}
                break;
            case 2:
                supprimer(&ptrTete, 2);
                break;
            case 3:
                afficher(ptrTete);
                break;
            case 4:
                printf("Au plaisir de vous revoir !\n");
                break;
            default:
                printf("...");
        }
    }while(menuChoix != 4);

    return 0;
}
