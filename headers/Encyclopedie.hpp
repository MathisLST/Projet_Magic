#ifndef ENCYCLOPEDIE_HPP
#define ENCYCLOPEDIE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "../headers/Carte.hpp"
#include "../headers/Creature.hpp"
#include "../headers/Terrain.hpp"
#include "../headers/Deck.hpp"

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
        Deck* choisirDeck(std::string nomJoueur);
        void afficherDecks();


};

#endif