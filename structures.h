#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

/** Definition de la structure contenant les elements de base
 *  d'un article (identifiant, titre et contenu).
 *  Le type ptrMaillon_base fait référence à un pointeur sur cette structure
 */
typedef struct maillon_base
{
    unsigned int identifiant;
    char *titre;
    char *contenu;
} maillon_base, *ptrMaillon_base;

#endif // STRUCTURES_H_INCLUDED
