/*
    Neural Network
    apprentissage.h
        Créé : 03/02/17
        Déclaration des fonctions d'apprentissage
*/

#ifndef DEF_APPRENTISSAGE

#define DEF_APPRENTISSAGE

#include "reseau.h"

unsigned int Score(std::vector<bool> expected, std::vector<bool> got);
int calculeErreur(Reseau reseau);
float calculeG_ijk(Reseau* reseau, unsigned int i, unsigned int j, unsigned int k);
float calculeDelta_ij(Reseau* reseau, unsigned int i, unsigned int j);
void apprentissage(Reseau* reseau);

#endif // DEF_APPRENTISSAGE
