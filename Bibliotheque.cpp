#include <iostream>
#include <cstdlib>
#include "Bibliotheque.hpp"

Bibliotheque::Bibliotheque(){}

Bibliotheque::Bibliotheque(Deck* deck){
    m_bibliotheque = deck->getDeck();
}


Bibliotheque::~Bibliotheque(){
    for(Carte* carte : m_bibliotheque){
        delete carte;
    }
    m_bibliotheque.clear();
}

std::vector<Carte*> Bibliotheque::getBibliotheque(){
    return m_bibliotheque;
}

void Bibliotheque::pop_front(){
    m_bibliotheque.erase(m_bibliotheque.begin());
}


