#include <iostream>
#include <cstdlib>
#include "Bibliotheque.hpp"

Bibliotheque::Bibliotheque(std::vector<Carte> cartes){
    m_bibliotheque = cartes;
}

Bibliotheque::~Bibliotheque(){}

std::vector<Carte> Bibliotheque::getBibliotheque(){
    return m_bibliotheque;
}


