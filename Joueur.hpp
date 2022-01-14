#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Deck.hpp"
#include "Carte.hpp"
#include "Bibliotheque.hpp"


class Joueur {
    private :
        int m_pv;
        Deck* m_deck;
        Bibliotheque* m_bibliotheque;
        std::vector<Carte*> m_cimetiere;
        std::vector<Carte*> m_main;
        std::vector<Creature*> m_LCreature;
        std::vector<Terrain*> m_LTerrain;

    public :
        Joueur();
        Joueur (int pv, Deck* deck);
        ~Joueur();
        int getPV();
        Deck* getDeck();
        std::vector<Carte*> getCimetiere();
        std::vector<Carte*> getMain();
        Bibliotheque* getBibliotheque();
        std::vector<Creature*> getLCreature();
        std::vector<Terrain*> getLTerrain();
        void piocher(int nbrCartes);
        void melanger();
    

};

#endif