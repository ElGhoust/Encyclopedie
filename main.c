#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "liste_chainee.h"

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
    ptrMaillon ptrTete;

    creer_encyclopedie(&ptrTete);

    lectureFichier("B46_10.dat", &ptrTete);

    afficher(ptrTete);

    printf("\nTout les article ont ete inseres.\n");

    return 0;
}
