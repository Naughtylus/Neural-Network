/*
    Neural Network
    reseau.h
        Créé : 09/09/16
        Fonctions relatives au réseau
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "reseau.h"

using namespace std;

template <int nbCouches>
Reseau::Reseau(vector<unsigned int> nbNeuroneCouche)
{
    // Le nombre de couches est indiqué dans la taille de nbNeuroneCouche
    srand(time(NULL));
    unsigned int i(0), j(0), k(0);

    Neurone neurone;
    Liaison liaison;
    vector<Liaison> liLiaison;  // liste temporaire

    //  Création du tableau de neurones
    for (i = 0 ; i < nbCouches ; i++ )
    {
        m_nbNeuroneCouche.push_back(nbNeuroneCouche[i]);
        for ( j = 0 ; j < nbNeuroneCouche[i] ; j++ )
        {
            neurone.init();
            m_neurones[i].push_back(neurone);
        }
    }

    // Création du tableau 3D de liaisons
    for ( k = 0 ; k < nbCouches-1 ; k++)
    {
        for ( i = 0 ; i < nbNeuroneCouche[k] ; i++ )
        {
            liLiaison.clear();
            for ( j = 0 ; j < nbNeuroneCouche[k+1] ; j++ )
            {
                liaison.changerPoids(((rand()%100)+1)/100.);
                liLiaison.push_back(liaison);
            }
            m_liaisons[k].push_back(listeLiaison);
        }
    }
    liLiaison.clear();
}

Reseau::~Reseau()
{

}

Neurone Reseau::getEntree(unsigned int i)
{
    if (i < m_nbNeuroneCouche[0])
    {
        return m_neurones[0][i];
    }
    return 0;
}

Neurone Reseau::getSortie(unsigned int i)
{
    if (i < m_nbNeuroneCouche[m_nbNeuroneCouche.size()-1])
    {
        return m_neurones[m_nbNeuroneCouche.size()-1][i];
    }
    return 0;
}

Liaison Reseau::getLiaison(unsigned int i, unsigned int j, unsigned int k)
{
    if (i < m_nbNeuroneCouche[m_nbNeuroneCouche.size()-1]-1)
    {
        return m_liaisons[i][j][k];
    }
}

int Reseau::getNbEntrees()
{
    return m_nbNeuroneCouche[0];
}

int Reseau::getNbSorties()
{
    return m_nbNeuroneCouche[m_nbNeuroneCouche.size()-1];
}

void Reseau::setEntrees(bool *entrees)
{
    unsigned int i(0);

    for ( i = 0 ; i < m_nbNeuroneCouche[0] ; i++ )
    {
        m_neurones[0][i].setActive(entrees[i]);
        m_neurones[0][i].setActuel(true);
    }
}

void Reseau::setEntreesActuelles(bool actuelles)
{
    unsigned int i(0);

    for (i = 0 ; i < m_nbNeuroneCouche[0] ; i++)
    {
        m_neurones[0][i].setActuel(actuelles);
    }
}


vector<bool> Reseau::calculeSorties()
{
    unsigned int i(0), j(0);
    vector<bool> sorties;

    // On désactualise les neurones de la couche 1 à la couche de sortie
    for (i=1 ; i < m_nbNeuroneCouche.size() ; i++)
    {
        for (j = 0 ; j < m_nbNeuroneCouche[i] ; j++)
        {
            m_neurones[i][j].setActuel(false);
        }
    }
    // On demande le calcul des neurones de sortie
    for (i = 0 ; i < m_nbNeuroneCouche[m_nbNeuroneCouche.size()-1] ; i++)
    {
        // Fonction récursive
        caluleNeurone(m_nbNeuroneCouche.size()-1, i);
        // On ajoute l'activation de la sortie à la variable de retour
        sorties.push_back(m_neurones[m_nbNeuroneCouche.size()-1].getNeuroneActive(i));
    }
    return sorties;
}


void Reseau::caluleNeurone(unsigned int i, unsigned int j)
{
    unsigned int k(0);
    float somme(0);
    // Si on est pas actualisé, on calcule
    if ( m_neurones[i][j].getActuel() == 0)
    {
        // Si une entrée est non actualisée, on a un problème
        if ( i == 0 )
        {
            exit(EXIT_FAILURE);
        }
        else
        {
            somme = 0;
            for ( k = 0 ; k < m_nbNeuroneCouche[i-1] ; k++ )
            {
                caluleNeurone(i-1,k);
                somme += (m_neurones[i-1][k].getActuel()*2-1)*m_liaisons[i-1][k][j].getPoids();
            }
            // sigmoide actualise le neurone
            m_neurones[i][j].sigmoide(somme);
        }
    }
}
