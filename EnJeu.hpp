#ifndef ENJEU_HPP
#define ENJEU_HPP

#include <iostream>
#include <cstdlib>
#include "Carte.hpp"
#include "Terrain.hpp"
#include "Creature.hpp"
#include "Joueur.hpp"


class EnJeu{
    private :
        Joueur* m_joueur1;
        Joueur* m_joueur2;
        bool partieFinie;
        bool t1;
        Joueur* gagnant;

    public :
        EnJeu(Joueur* joueur1, Joueur* joueur2);
        ~EnJeu();

        Joueur* getJoueur1();
        Joueur* getJoueur2();
        std::vector<Terrain*> getLTerrainJ1();
        std::vector<Terrain*> getLTerrainJ2();
        std::vector<Creature*> getLCreatureJ1();
        std::vector<Creature*> getLCreatureJ2();

        void setLTerrainJ1();
        void setLTerrainJ2();
        void setLCreatureJ1();
        void setLCreatureJ2();

        Joueur* tirerAuSort(Joueur* joueur1, Joueur* joueur2 );   
        void phasePioche(Joueur* j1, int nbrCartes);
        void phaseDesengagement(Joueur* j1);
        void phasePose(Joueur* j1);
        void phaseCombat(Joueur* j1, Joueur* j2);
        void phasePose(Joueur* j1);
        void phaseFinTour(Joueur* j1, Joueur* j2);

        void tour(Joueur* j1, Joueur* j2);

        void start(Joueur* joueur1, Joueur* joueur2);
        

};

#endif