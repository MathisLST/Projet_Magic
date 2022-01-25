#ifndef ENJEU_HPP
#define ENJEU_HPP

#include <iostream>
#include <cstdlib>
#include "../headers/Carte.hpp"
#include "../headers/Terrain.hpp"
#include "../headers/Creature.hpp"
#include "../headers/Joueur.hpp"
#include "../headers/Affiche.hpp"


class EnJeu{
    private :
        Joueur* m_joueur1;
        Joueur* m_joueur2;
        Joueur* m_j1;
        Joueur* m_j2;
        bool m_partieFinie;
        bool m_t1;
        std::string m_gagnant;

    public :
        EnJeu(Joueur* joueur1, Joueur* joueur2);
        ~EnJeu();

        Joueur* getJoueur1();
        Joueur* getJoueur2();
        Joueur* getJ1();
        Joueur* getJ2();
    

        void setLTerrainJ1();
        void setLTerrainJ2();
        void setLCreatureJ1();
        void setLCreatureJ2();

        bool tirerAuSort();   
        bool phasePioche(Joueur* j1, Joueur* j2);
        void phaseDesengagement(Joueur* j1);
        void phasePose(Joueur* j1);
        bool phaseCombat(Joueur* j1, Joueur* j2);
        void phaseFinTour(Joueur* j1, Joueur* j2);

        bool tour(Joueur* j1, Joueur* j2);

        void start(Joueur* joueur1, Joueur* joueur2);
        

};

#endif