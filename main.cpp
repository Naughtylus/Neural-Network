/*
    Neural Network
        Un réseau de neurones sur le même modèle que "Réseau Neurones liaisons"
    main.cpp
        Créé : 09/09/16
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "reseau.h"
#include "apprentissage.h"

#define NB_ENTREES 50

using namespace std;

int main()
{
    srand(time(NULL));
    unsigned int i(0);

    vector<unsigned int> nbNeuroneCouche;
    vector<bool> entrees;
    vector<bool> sorties;

    nbNeuroneCouche.clear();
    nbNeuroneCouche.push_back(NB_ENTREES);
    nbNeuroneCouche.push_back(5);
    nbNeuroneCouche.push_back(NB_ENTREES);

    Reseau res_test(nbNeuroneCouche);

    for (i = 0 ; i < NB_ENTREES ; i++)
    {
        if (rand()%10 < 5)
        {
            entrees.push_back(true);
        }
        else
        {
            entrees.push_back(false);
        }
    }

    res_test.setEntrees(entrees);
    sorties = res_test.calculeSorties();

    res_test.afficheNeurones();

    for (i = 0 ; i < 10 ; i++)
    {
        res_test.setEntrees(entrees);
        sorties = res_test.calculeSorties();
        apprentissage(res_test);
    }

    res_test.afficheNeurones();

    return 0;
}
