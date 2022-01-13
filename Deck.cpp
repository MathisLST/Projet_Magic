#include <iostream>
#include <cstdlib>
#include <vector>
#include "Deck.hpp"

Deck::Deck(){}


Deck::Deck( std::vector<Carte*> deck){
    m_deck = deck;
}


Deck::~Deck(){
    for(Carte* carte : m_deck){
        delete carte;
    }
    m_deck.clear();
}

std::vector<Carte*> Deck::getDeck(){
    return m_deck;
}


