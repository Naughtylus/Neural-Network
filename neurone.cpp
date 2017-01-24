/*
    Neural Network
    neurone.cpp
        Créé : 10/09/16
        Fonctions relatives aux neurones
    Historique des modifications :
        10/09/16    - Implémentation des fonctions de Neurone
        15/09/16    - Implémentation de getNbEntrees et getEntree
                    - Modification de fActivation et getActive
        28/09/16    - Implémentation de setActuel, setActive, ajouteEntree
        29/09/16    - Toutes les occurences de m_entrees.size() remplacées par m_nbEntrees
        04/10/16    - Modification de fActivation en calcul
                    - Implémentation de getValeur, sigmoide
        08/12/16    - Supression des fonctions obsolètes
                    - Vidage de getActive
*/

#include <math.h>
#include <ctime>
#include <cstdlib>

#include "neurone.h"
#include "liaison.h"

// Neurone

Neurone::Neurone()
{
    m_active = false;
    m_seuil = 0.5;
    m_actuel = false;
    m_valeur = 0.;
}

Neurone::Neurone(float seuil)
{
    m_active = false;
    m_seuil = seuil;
    m_actuel = false;
    m_valeur = 0.;
}

Neurone::Neurone(Neurone const& autre)
{
    m_active = false;
    m_seuil = autre.m_seuil;
    m_actuel = false;
    m_valeur = autre.m_valeur;
}

bool Neurone::getActive()
{
    return m_active;
}

float Neurone::getSeuil()
{
    return m_seuil;
}

bool Neurone::getActuel()
{
    return m_actuel;
}

float Neurone::getValeur()
{
    return m_valeur;
}

float Neurone::sigmoide(float x)
{
    m_valeur = tanh(x);
    m_actuel = true;
    m_active = m_valeur >= m_seuil;
    return m_valeur;
}

void Neurone::setActuel(bool actuel)
{
    m_actuel = actuel;
}

void Neurone::setActive(bool active)
{
    m_active = active;
    if (active)
    {
        m_valeur = 1.;
    }
    else
    {
        m_valeur = -1.;
    }
}

void Neurone::init()
{
    m_active = 0;
    m_seuil = 0;
    m_valeur = 0;
    m_actuel = 0;
}

Neurone Neurone::copie()
{
    Neurone copie;
    copie.m_active = m_active;
    copie.m_actuel = m_actuel;
    copie.m_seuil = m_seuil;
    copie.m_valeur = m_valeur;
    return copie;
}

// ListeNeurone

Neurone ListeNeurone::getNeurone(unsigned int i)
{
    if (i >= m_neurone.size())
    {
        return m_neurone[m_neurone.size()-1];
    }
    return m_neurone[i];
}

void ListeNeurone::ajouteNeurone(Neurone nouveau)
{
    m_neurone.push_back(nouveau);
}

void ListeNeurone::vider()
{
    m_neurone.clear();
}

bool ListeNeurone::getNeuroneActive(unsigned int i)
{
    if ( i < m_neurone.size() )
    {
        return m_neurone[i].getActive();
    }
    return false;
}

float ListeNeurone::getNeuroneSeuil(unsigned int i)
{
    if ( i < m_neurone.size() )
    {
        return m_neurone[i].getSeuil();
    }
    return 0.;
}

float ListeNeurone::getNeuroneValeur(unsigned int i)
{
    if ( i < m_neurone.size() )
    {
        return m_neurone[i].getValeur();
    }
    return 0.;
}

bool ListeNeurone::getNeuroneActuel(unsigned int i)
{
    if ( i < m_neurone.size() )
    {
        return m_neurone[i].getActuel();
    }
    return false;
}

float ListeNeurone::getNeuroneSigmoide(unsigned int i, float x)
{
    if ( i < m_neurone.size() )
    {
        return m_neurone[i].sigmoide(x);
    }
    return 0.;
}

void ListeNeurone::setNeuroneActuel(unsigned int i, bool actuel)
{
    if ( i < m_neurone.size() )
    {
        m_neurone[i].setActuel(actuel);
    }
}

void ListeNeurone::setNeuroneActive(unsigned int i, bool active)
{
    if ( i < m_neurone.size() )
    {
        m_neurone[i].setActive(active);
    }
}
