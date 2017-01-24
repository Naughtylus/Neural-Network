/*
    Neural Network
    liaison.cpp
        Créé : 10/09/16
        Fonctions relatives aux liaisons
    Historique des modifications :
        10/09/16    - Implémentation des fonctions de Liaison
        11/09/16    - Implémentation de changerEntree, changerSortie
        10/01/17    - Implémentation de ajouteLiaison, vider
*/

#include "liaison.h"

using namespace std;

// Liaison

Liaison::Liaison()
{
    m_poids = 0;
}
Liaison::Liaison(Neurone *entree, Neurone *sortie, float poids)
{
    m_poids = poids;
}

Liaison::Liaison(Liaison const& autre)
{
    m_poids = autre.m_poids;
}

float Liaison::getPoids()
{
    return m_poids;
}

float Liaison::getGradientPrec()
{
    return m_gradientPrec;
}

void Liaison::changerPoids(float nouveau)
{
    m_poids = nouveau;
}

// ListeLiaison

void ListeLiaison::ajouteLiaison(Liaison nouvelle)
{
    m_liaison.push_back(nouvelle);
}

void ListeLiaison::vider()
{
    m_liaison.clear();
}

Liaison ListeLiaison::getLiaison(unsigned int i)
{
    if (i < m_liaison.size())
    {
        return m_liaison[i];
    }
}

float ListeLiaison::getLiaisonPoids(unsigned int i)
{
    if ( i < m_liaison.size())
    {
        return m_liaison[i].getPoids();
    }
    return 0.;
}

float ListeLiaison::getLiaisonGradPrec(unsigned int i)
{
    if ( i < m_liaison.size())
    {
        return m_liaison[i].getGradientPrec();
    }
    return 0.;
}

void ListeLiaison::changerLiaisonPoids(unsigned int i, float nouveau)
{
    if ( i < m_liaison.size())
    {
        m_liaison[i].changerPoids(nouveau);
    }
}

// ListeListeLiaison

void ListeListeLiaison::ajouteListeLiaison(ListeLiaison nouvelle)
{
    m_liaisons.push_back(nouvelle);
}

void ListeListeLiaison::vider()
{
    m_liaisons.clear();
}

Liaison ListeListeLiaison::getLiaison(unsigned int i, unsigned int j)
{
    if ( i < m_liaisons.size() )
    {
        return m_liaisons[i].getLiaison(j);
    }
}

float ListeListeLiaison::getLiaisonPoids(unsigned int i, unsigned int j)
{
    if ( j < m_liaisons.size())
    {
        return m_liaisons[i].getLiaisonPoids(j);
    }
    return 0.;
}

float ListeListeLiaison::getLiaisonGradPrec(unsigned int i, unsigned int j)
{
    if ( j < m_liaisons.size())
    {
        return m_liaisons[i].getLiaisonGradPrec(j);
    }
    return 0.;
}

void ListeListeLiaison::changerLiaisonPoids(unsigned int i, unsigned int j, float nouveau)
{
    if ( j < m_liaisons.size())
    {
        m_liaisons[i].changerLiaisonPoids(j, nouveau);
    }
}
