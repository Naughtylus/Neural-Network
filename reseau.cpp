/*
    Neural Network
    reseau.h
        Créé : 09/09/16
        Fonctions relatives au réseau
    Historique des modifications :
        10/09/16    - Ajout de include reseau
                    - Implémentation de Reseau, ~Reseau, getEntree, getSortie, getNbEntrees, getNbSorties
        28/09/16    - Modification de setEntrees, du constructeur2
        04/10/16    - Modification du constructeur2 (ajout de l'aléatoire)
        10/01/17    - Modification du constructeur2 : adaptation à la nouvelle structure de liaison et de neurone
                    - Modification des diverses fonctions
                    - Implémentation de calculeNeurone
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "reseau.h"

using namespace std;

Reseau::Reseau()
{

}

Reseau::Reseau(vector<unsigned int> nbNeuroneCouche, int mode)
{
    // Le nombre de couches est indiqué dans la taille de nbNeuroneCouche
    srand(time(NULL));
    unsigned int i(0), j(0), k(0);

    Neurone neurone;
    ListeNeurone listeNeurone;
    Liaison liaison;
    ListeLiaison listeLiaison;
    ListeListeLiaison listeListeLiaison;

    //  Création du tableau de neurones
    listeNeurone.vider();
    for (i = 0 ; i < nbNeuroneCouche.size() ; i++ )
    {
        m_nbNeuroneCouche.push_back(nbNeuroneCouche[i]);
        for ( j = 0 ; j < nbNeuroneCouche[i] ; j++ )
        {
            neurone.init();
            listeNeurone.ajouteNeurone(neurone);
        }
        m_neurones.push_back(listeNeurone);
        listeNeurone.vider();
    }
    // Création du tableau 3D de liaisons
    for ( k = 0 ; k < nbNeuroneCouche.size()-1 ; k++)
    {
        listeListeLiaison.vider();
        for ( i = 0 ; i < nbNeuroneCouche[k] ; i++ )
        {
            listeLiaison.vider();
            for ( j = 0 ; j < nbNeuroneCouche[k+1] ; j++ )
            {
                if( mode == 0 )
                {
                    liaison.changerPoids(0);
                }
                else
                {
                    liaison.changerPoids(((rand()%100)+1)/100.);
                }
                listeLiaison.ajouteLiaison(liaison);
            }
            listeListeLiaison.ajouteListeLiaison(listeLiaison);
        }
        m_liaisons.push_back(listeListeLiaison);
    }
}

Reseau::~Reseau()
{

}

Neurone Reseau::getEntree(unsigned int i)
{
    if (i < m_nbNeuroneCouche[0])
    {
        return m_neurones[0].getNeurone(i);
    }
    return 0;
}

Neurone Reseau::getSortie(unsigned int i)
{
    if (i < m_nbNeuroneCouche[m_nbNeuroneCouche.size()-1])
    {
        return m_neurones[m_nbNeuroneCouche.size()-1].getNeurone(i);
    }
    return 0;
}

Liaison Reseau::getLiaison(unsigned int i, unsigned int j, unsigned int k)
{
    if (i < m_nbNeuroneCouche[m_nbNeuroneCouche.size()-1]-1)
    {
        return m_liaisons[i].getLiaison(j, k);
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

bool Reseau::setEntrees(vector<bool> entrees)
{
    unsigned int i(0);

    if (entrees.size() != m_nbNeuroneCouche[0])
    {
        return false;
    }
    for ( i = 0 ; i < m_nbNeuroneCouche[0] ; i++ )
    {
        m_neurones[0].setNeuroneActive(i, entrees[i]);
        m_neurones[0].setNeuroneActuel(i, true);
    }
    return true;
}

void Reseau::setEntreesActuelles(bool actuelles)
{
    unsigned int i(0);

    for (i = 0 ; i < m_nbNeuroneCouche[0] ; i++)
    {
        m_neurones[0].setNeuroneActuel(i, actuelles);
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
            m_neurones[i].setNeuroneActuel(j, false);
        }
    }
    // On demande le calcul des neurones de sortie, via une fonction récursive
    for (i = 0 ; i < m_nbNeuroneCouche[m_nbNeuroneCouche.size()-1] ; i++)
    {
        caluleNeurone(m_nbNeuroneCouche.size()-1, i);
        sorties.push_back(m_neurones[m_nbNeuroneCouche.size()-1].getNeuroneActive(i));
    }
    return sorties;
}


void Reseau::caluleNeurone(unsigned int i, unsigned int j)
{
    float val(0);
    float poi(0);

    unsigned int k(0);
    float somme(0);
    // Si on est pas actualisé, on calcule
    if ( m_neurones[i].getNeuroneActuel(j) == 0)
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
                val = m_neurones[i-1].getNeuroneValeur(k);
                poi = m_liaisons[i-1].getLiaisonPoids(k,j);
                somme += m_neurones[i-1].getNeuroneValeur(k)*m_liaisons[i-1].getLiaisonPoids(k,j);
            }
            // sigmoide actualise le neurone
            m_neurones[i].getNeuroneSigmoide(j, somme);
        }
    }
}
