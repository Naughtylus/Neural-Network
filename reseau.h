/*
    Neural Network
    reseau.h
        Créé : 09/09/16
        Délaration de la classe réseau
    Historique des modifications :
        10/09/16    - Ajout des directives de préprocesseur
                    - Ajout de la classe Reseau
        11/09/16    - Modification de m_liaisons en m_liaisonsE
                    - Ajout de m_liaisonsF, Reseau (deux constructeurs), getEntree, getCouchesInternes, getSortie
        15/09/16    - Suppression de m_couchesInternes, getCouchesInternes, m_liaisonsF
                    - Modification de m_liaisonsE en m_liaisons
        16/09/16    - Ajout de ~Reseau, getNbEntrees, getNbSorties, setEntrees, calculeSorties
        28/09/16    - Modification de setEntrees
        13/10/16    - Modification de la structure du Reseau (cf main)
                        Variables obsolètes :
                            m_entrees   (10/01/17)
                            m_sorties   (10/01/17)
                        Fonctions obsolètes :
                        Variables à modifier :
                            m_liaisons
                                -> tableau (taille fixe, dim 3) de Liaisons (pas pointeurs)
                        Fonctions à modifier :
                            Constructeurs
                            Destructeur
                            Accesseurs (get+set)
                            calculeSortie   (11/01/17)
                        Variables à ajouter :
                            m_neurones  (10/01/17)
                                -> tableau (taille fixe, dim 2) de Neurones (pas pointeurs)
                            Taille des différentes listes
                        Fonctions à ajouter :
                            calculNeurone   (10/01/17)
*/

#ifndef DEF_RESEAU

#define DEF_RESEAU

#include <vector>
#include <string>

#include "neurone.h"
#include "liaison.h"

template <unsigned int nbCouches>
class Reseau
{
    public :

    Reseau(); //1
    Reseau(std::vector<int> *nbNeuroneCouche);
    ~Reseau();

    Neurone getEntree(unsigned int i);
    Neurone getSortie(unsigned int i);
    Liaison getLiaison(unsigned int i, unsigned int j, unsigned int k);
    int getNbEntrees();
    int getNbSorties();
    bool setEntrees(bool *entrees);     // Retourne 1 si les entrees ont été initialisées
    void setEntreesActuelles(bool actuelles);

    std::vector<bool> calculeSorties();
    void caluleNeurone(unsigned int i, unsigned int j);

    private :

    std::vector<unsigned int> m_nbNeuroneCouche;    // liste
    std::vector<Neurone> m_neurones[nbCouches];           // tableau
    std::vector< std::vector< ListeListeLiaison > > m_liaisons[nbCouches-1];      // tableau 3D
};

#endif // DEF_RESEAU
