/*
    Neural Network
    reseau.h
        Créé : 09/09/16
        Délaration de la classe réseau
*/

#ifndef DEF_RESEAU

#define DEF_RESEAU

#include <vector>
#include <string>

#include "neurone.h"
#include "liaison.h"

class Reseau
{
    public :

    Reseau(); //1
    Reseau(std::vector<unsigned int> nbNeuroneCouche, int mode);   //2 mode -> 0 : Initialisation neutre, 1 : Initialisation aléatoire
    ~Reseau();

    Neurone getEntree(unsigned int i);
    Neurone getSortie(unsigned int i);
    Liaison getLiaison(unsigned int i, unsigned int j, unsigned int k);
    int getNbEntrees();
    int getNbSorties();
    bool setEntrees(std::vector<bool> entrees);     // Retourne 1 si les entrees ont été initialisées
    void setEntreesActuelles(bool actuelles);

    std::vector<bool> calculeSorties();
    void caluleNeurone(unsigned int i, unsigned int j);

    private :

    std::vector<unsigned int> m_nbNeuroneCouche;    // liste
    std::vector<ListeNeurone> m_neurones;           // tableau
    std::vector<ListeListeLiaison> m_liaisons;      // tableau 3D
};

#endif // DEF_RESEAU
