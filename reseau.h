/*
    Neural Network
    reseau.h
        Cr�� : 09/09/16
        D�laration de la classe r�seau
*/

#ifndef DEF_RESEAU

#define DEF_RESEAU

#define PRECISION 100000

#include <vector>
#include <string>

#include "neurone.h"
#include "liaison.h"

class Reseau
{
    public :

    //Reseau(); //1
    Reseau(std::vector<unsigned int> nbNeuroneCouche);
    ~Reseau();

    Neurone getEntree(unsigned int i);
    Neurone getSortie(unsigned int i);
    Neurone getNeurone(unsigned int i, unsigned int j);
    Liaison getLiaison(unsigned int i, unsigned int j, unsigned int k);
    int getNbEntrees();
    int getNbSorties();
    int getNbCouches();
    int getNbNeuronesCouches(unsigned int i);
    void setEntrees(std::vector<bool> entrees);     // Retourne 1 si les entrees ont �t� initialis�es
    void setEntreesActuelles(bool actuelles);
    void setLiaisonPoids(unsigned int i, unsigned int j, unsigned int k, float poids);
    void setNeuroneDelta(unsigned int i, unsigned int j, float delta);
    void setNeuroneDeltaActuel(unsigned int i, unsigned int j, bool deltaActuel);

    std::vector<bool> calculeSorties();
    void caluleNeurone(unsigned int i, unsigned int j);

    void afficheNeurones();
    void afficheLiaisons();

    std::vector<unsigned int> learn(std::vector< std::vector<bool> > inputs, unsigned int index);

    private :

    std::vector< unsigned int > m_nbNeuroneCouche;    // liste
    std::vector< std::vector< Neurone > > m_neurones;           // tableau
    std::vector< std::vector< std::vector< Liaison > > > m_liaisons;      // tableau 3D
};

#endif // DEF_RESEAU
