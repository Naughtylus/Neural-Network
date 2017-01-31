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
    nbNeuroneCouche.push_back(5);
    nbNeuroneCouche.push_back(5);
    nbNeuroneCouche.push_back(6);
    nbNeuroneCouche.push_back(8);
    nbNeuroneCouche.push_back(15);

    Reseau<8> reseau(nbNeuroneCouche);

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

    reseau.setEntrees(entrees);

    neurone=reseau.getEntree(0);    //debug
    li = reseau.getLiaison(0,0,0);  //debug

    sorties = reseau.calculeSorties();

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
