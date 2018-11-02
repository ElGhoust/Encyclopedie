#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct maillon_base
{
    unsigned int identifiant;
    char *titre;
    char *contenu;
} maillon_base, *ptrMaillon_base;

#endif // STRUCTURES_H_INCLUDED
