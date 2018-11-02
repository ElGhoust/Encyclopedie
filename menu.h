#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "liste_chainee.h"

int choix();

int choixASupprimer();

void processus_suppression(ptrMaillon *ptrTete);

ptrMaillon_base processus_recherche(ptrMaillon ptrTete);

void afficherMenu();

#endif // MENU_H_INCLUDED
