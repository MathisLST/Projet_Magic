#include <iostream>
#include <cstdlib>
#include "Bibliotheque.hpp"
#include "Deck.hpp"

Bibliotheque::Bibliotheque(Deck* deck){
    m_bibliotheque = deck->getDeck();
}

Bibliotheque::~Bibliotheque(){}

std::vector<Carte&> Bibliotheque::getBibliotheque(){
    return m_bibliotheque;
}


