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
        Deck m_deck;
        Bibliotheque m_bibliotheque;
        std::vector<Carte*> m_cimetiere;
        std::vector<Carte*> m_main;

    public :
        Joueur (int pv, Deck& deck);
        int getPV();
        Deck& getDeck();
        std::vector<Carte*> getCimetiere();
        std::vector<Carte*> getMain();
        Bibliotheque& getBibliotheque();
        void distribuer();
    

};

#endif