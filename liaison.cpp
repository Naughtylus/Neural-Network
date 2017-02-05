/*
    Neural Network
    liaison.cpp
        Créé : 10/09/16
        Fonctions relatives aux liaisons
*/

#include "liaison.h"

using namespace std;

Liaison::Liaison()
{
    m_poids=0;
}

Liaison::Liaison(float poids)
{
    m_poids = poids;
}

Liaison::Liaison(Liaison const& liaison)
{
    m_poids = liaison.m_poids;
}

float Liaison::getPoids()
{
    return m_poids;
}

void Liaison::changerPoids(float nouveau)
{
    m_poids = nouveau;
}

Liaison Liaison::copie()
{
    Liaison copie;
    copie.m_poids = m_poids;
    return copie;
}
