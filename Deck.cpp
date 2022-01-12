#include <iostream>
#include <cstdlib>
#include <vector>
#include "Deck.hpp"

Deck::Deck(){}

Deck::Deck( std::vector<Carte&> deck){
    m_deck = deck;
}


Deck::~Deck(){}

std::vector<Carte&> Deck::getDeck(){
    return m_deck;
}


