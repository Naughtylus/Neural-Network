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

#define NB_COUCHES 5

using namespace std;

int main()
{
    unsigned int i(0);

    vector<unsigned int> nbNeuroneCouche;
    vector<bool> entrees;
    vector<bool> sorties;

    Neurone neurone;        //debug
    Liaison li;             //debug

    // Je fais tout à la main pour les tests (flemme de déclarer des incréments)
    nbNeuroneCouche.clear();
    nbNeuroneCouche.push_back(15);
    nbNeuroneCouche.push_back(14);
    nbNeuroneCouche.push_back(8);
    nbNeuroneCouche.push_back(6);
    nbNeuroneCouche.push_back(15);

    Reseau<NB_COUCHES> res_test(nbNeuroneCouche);

    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);
    entrees.push_back(false);

    res_test.setEntrees(entrees);

    neurone=res_test.getEntree(0);    //debug
    li = res_test.getLiaison(0,0,0);  //debug

    sorties = res_test.calculeSorties();

    for (i = 0 ; i < sorties.size() ; i++)
    {
        cout << entrees[i] << " ";
    }
    cout << endl;
    for (i = 0 ; i < sorties.size() ; i++)
    {
        cout << sorties[i] << " ";
    }
    cout << endl;

    return 0;
}
