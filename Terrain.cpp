#include <iostream>
#include <cstdlib>
#include <vector>
#include "Terrain.hpp"

Terrain::Terrain (std::string type){
    m_type = type;
    setDegagee(false);
}

std::string Terrain::getType(){
    return m_type;
}

bool Terrain::getDegagee(){
    return m_degagee;
}

void Terrain::setDegagee(bool estDegagee){
    m_degagee = estDegagee;
}