#include <iostream>
#include <cstdlib>
#include <vector>
#include "Terrain.hpp"


Terrain::Terrain(land landType){
    m_land = landType;
    setDegagee(true);
    m_creature = false;
}

Terrain::~Terrain(){};


bool Terrain::getDegagee(){
    return m_degagee;
}

void Terrain::setDegagee(bool estDegagee){
    m_degagee = estDegagee;
}

bool Terrain::getCreature(){
    return m_creature;
}

Terrain::land Terrain::getLand(){
    return m_land;
}

int Terrain::getLandIndex(){
    if(m_land >= PLAINE && m_land <= FORET)
        return static_cast<int>(m_land);
    else return -1; // verifier
}

const char* Terrain::landToString(int i, bool abregee) throw(){
    switch (static_cast<land>(i))
    {
        case Terrain::PLAINE: if (!abregee) {return "PLAINE";} else return "P";
        case Terrain::ILE: if (!abregee) return "ILE"; else return "I";
        case Terrain::MARAIS: if (!abregee) return "MARAIS"; else return "Ma";
        case Terrain::MONTAGNE: if (!abregee) return "MONTAGNE"; else return "Mo";
        case Terrain::FORET: if (!abregee) return "FORET"; else return "F";
        default: throw std::invalid_argument("Unimplemented item");
    }
}
