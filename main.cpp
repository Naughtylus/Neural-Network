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

#define NB_ENTREES 10
#define INPUT_VECTORS_COUNT 12

using namespace std;

vector<bool> buildInput()
{
    vector<bool> entrees;
    for (int i = 0 ; i < NB_ENTREES ; i++)
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
    return entrees;
}


void showResults(vector<bool> expected, vector<bool> got)
{
    cout << "Expected :" << endl;
    for (const bool &value : expected)
    {
        cout << value << " ";
    }
    cout << endl;

    cout << "Got :" << endl;
    for (const bool &value : got)
    {
        cout << value << " ";
    }
    cout << endl;

    cout << "Accuracy : ";
    cout << Score(expected, got) << "/" << expected.size() << endl;
}


int main()
{
    srand(time(NULL));
    unsigned int i(0);

    vector<unsigned int> nbNeuroneCouche;

    nbNeuroneCouche.clear();
    nbNeuroneCouche.push_back(NB_ENTREES);
    nbNeuroneCouche.push_back(5);
    nbNeuroneCouche.push_back(NB_ENTREES);

    Reseau res_test(nbNeuroneCouche);

    vector< vector<bool> > entrees;

    for (i = 0; i < INPUT_VECTORS_COUNT; ++i)
    {
        entrees.push_back(buildInput());
    }

    cout << "Learning..." << endl;
    for (i = 0; i < INPUT_VECTORS_COUNT; ++i)
    {
        vector<unsigned int> res = res_test.learn(entrees, i);
        cout << "Vecteur d'entrainement #" << i << endl;
        cout << "Appris en " << res[0] << " essais" << endl;
        cout << "Plus " << res[1] << " passes de reapprentissage" << endl;
        //cin.get();
    }

//    cout << endl << "Results" << endl;
//
//    for (i = 0; i < INPUT_VECTORS_COUNT; ++i)
//    {
//        cout << "Vecteur d'entrainement #" << i << endl;
//        res_test.setEntrees(entrees[i]);
//        showResults(entrees[i], res_test.calculeSorties());
//    }

    return 0;
}
