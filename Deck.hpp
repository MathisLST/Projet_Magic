#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Carte.hpp"

class Deck {
    private :
        std::vector<Carte&> m_deck;
    public :
        Deck (std::vector<Carte&> deck);
        std::vector<Carte&> getDeck();  
};

#endif