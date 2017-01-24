/*
    Neural Network
    liaison.h
        Créé : 10/09/16
        Déclaration de la classe Liaison
    Historique des modifications :
        10/09/16    - Ajout des directives de préprocesseur
                    - Ajout de la classe Liaison
                    - Ajout de changerEntree, changerSortie
                    - Modification de la structure de Liaison (cf main)
                        Variables obsolètes :
                            m_entree        (08/12/16)
                            m_sortie        (08/12/16)
                        Fonctions obsolètes :
                            getEntree       (08/12/16)
                            getSortie       (08/12/16)
                            changerEntree   (08/12/16)
                            changerSortie   (08/12/16)
                        Variables à modifier :
                        Fonctions à modifier :
                        Variables à ajouter :
                            gradientPrec    (08/12/16)
                                gradient d'erreur de l'exécution précédente
                        Fonctions à ajouter :
                            Accesseur
        10/01/17    - Ajout de la classe ListeLiaison
                    - Ajout de m_liaison à ListeLiaison
                    - Ajout de ajouteLiaison et vider à ListeLiaison
        11/01/17    - Ajout d'accesseurs directs aux attributs de Liaison par Liste- et ListeListe- Liaison
*/

#ifndef DEF_LIAISON

#define DEF_LIAISON

#include "neurone.h"

class Liaison
{
    public :

    Liaison();
    Liaison(class Neurone* entree, class Neurone* sortie, float poids);
    Liaison(Liaison const& liaison);

    float getPoids();
    float getGradientPrec();

    void changerPoids(float nouveau);

    private :

    float m_poids;
    float m_gradientPrec;
};

class ListeLiaison
{
    public :

    void ajouteLiaison(Liaison nouvelle);
    void vider();

    Liaison getLiaison(unsigned int i);

    float getLiaisonPoids(unsigned int i);
    float getLiaisonGradPrec(unsigned int i);

    void changerLiaisonPoids(unsigned int i, float nouveau);

    private :

    std::vector<Liaison> m_liaison;
};

class ListeListeLiaison
{
    public :

    void ajouteListeLiaison(ListeLiaison nouvelle);
    void vider();

    Liaison getLiaison(unsigned int i, unsigned int j);

    float getLiaisonPoids(unsigned int i, unsigned int j);
    float getLiaisonGradPrec(unsigned int i, unsigned int j);

    void changerLiaisonPoids(unsigned int i, unsigned int j, float nouveau);

    private :

    std::vector<ListeLiaison> m_liaisons;
};

#endif // DEF_LIAISON
