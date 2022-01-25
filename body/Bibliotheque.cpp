#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "../headers/Bibliotheque.hpp"

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

void Bibliotheque::melanger(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_bibliotheque.begin(), m_bibliotheque.end(), g);
}

