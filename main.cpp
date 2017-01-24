/*
    Neural Network
        Un réseau de neurones sur le même modèle que "Réseau Neurones liaisons"
    main.cpp
        Créé : 09/09/16
        Utilisation du réseau (complété en dernier)
    Historique des modifications :
        28/09/16    - Test de création / utilisation d'un réseau
        04/10/16    - Dans tout le projet : adaptation du réseau pour traiter des floats
        13/10/16    - Suppression du test
                    - Dans tout le projet : modification de la structure du Reseau, des Neurones et des Liaisons
                        Reseau : listes de Neurones et de Liaisons
                            Pour une liste de Liaison : la liaison i+n*j relie le neurone i de la couche "entree" (de taille n)
                                et le neurone j le la couche "sortie" (relativement à cette liste de liaisons)
                        Neurone : Ne "connait" plus les liaisons entrantes (ou sortantes) relativement à lui
                        Liaison : Ne connait plus ses Neurones "entrée" et "sortie" relatifs
                            Ajout des variables "actuel" (bool) et des variables d'erreur pour la réropropagation du gradient
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

    nbNeuroneCouche.clear();
    nbNeuroneCouche.push_back(15);
    nbNeuroneCouche.push_back(14);
    nbNeuroneCouche.push_back(8);
    nbNeuroneCouche.push_back(5);
    nbNeuroneCouche.push_back(5);
    nbNeuroneCouche.push_back(6);
    nbNeuroneCouche.push_back(8);
    nbNeuroneCouche.push_back(15);

    Reseau reseau(nbNeuroneCouche, 1);

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
    li = reseau.getLiaison(0,0,0);

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
