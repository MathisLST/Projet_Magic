#include <iostream>
#include <cstdlib>
#include <vector>
#include "Terrain.hpp"

Terrain::Terrain (std::string type){
    m_type = type;
    Carte::setDegagee(false);
}

std::string Terrain::getType(){
    return m_type;
}

bool Carte::getDegagee(){
    return m_degagee;
}

void Carte::setDegagee(bool estDegagee){
    m_degagee = estDegagee;
}