#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Deck.hpp"
#include "Carte.hpp"

class Joueur {
    private :
        int m_pv;
        Deck m_deck;
        std::vector<Carte&> m_cimetiere;
        std::vector<Carte&> m_main;

    public :
        int getPV();
        Deck getDeck();
        std::vector<Carte&> getCimetiere();
        std::vector<Carte&> getMain();

};

#endif