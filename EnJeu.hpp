#include <iostream>
#include <cstdlib>
#include "Carte.hpp"
#include "Terrain.hpp"
#include "Creature.hpp"
#include "Joueur.hpp"


class EnJeu{
    private :
        Joueur m_joueur1;
        Joueur m_joueur2;
        std::vector<Terrain> m_LTerrainJ1;
        std::vector<Terrain> m_LTerrainJ2;
        std::vector<Creature> m_LCreatureJ1;
        std::vector<Creature> m_LCreatureJ2;

    public :
        EnJeu(Joueur joueur1, Joueur joueur2);
        ~EnJeu();

        Joueur getJoueur1();
        Joueur getJoueur2();
        std::vector<Terrain> getLTerrainJ1;
        std::vector<Terrain> getLTerrainJ2;
        std::vector<Creature> getLCreatureJ1;
        std::vector<Creature> getLCreatureJ2;

        void setLTerrainJ1();
        void setLTerrainJ2();
        void setLCreatureJ1();
        void setLCreatureJ2();

};