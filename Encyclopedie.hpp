#ifndef ENCYCLOPEDIE_HPP
#define ENCYCLOPEDIE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Carte.hpp"
#include "Creature.hpp"
#include "Terrain.hpp"
#include "Deck.hpp"

class Deck;
class Encyclopedie{
    private:
        std::vector<Carte*> m_encyclopedie;
        std::vector<Deck*> m_decks;
    public:
        Encyclopedie();
        ~Encyclopedie();
        std::vector<Carte*> getEncyclopedie();
        Carte* getCarte(int i) throw(); // voir warning avec throw : case ?
        Deck* choisirDeck();


};

#endif