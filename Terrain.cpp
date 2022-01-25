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
        case Terrain::PLAINE: if (!abregee) {return "\e[97mPLAINE\e[0m" ;} else return "\e[97mP\e[0m";
        case Terrain::ILE: if (!abregee) return "\e[34mILE\e[0m"; else return "\e[34mI\e[0m";
        case Terrain::MARAIS: if (!abregee) return "\e[90mMARAIS\e[0m"; else return "\e[90mMa\e[0m";
        case Terrain::MONTAGNE: if (!abregee) return "\e[31mMONTAGNE\e[0m"; else return "\e[31mMo\e[0m";
        case Terrain::FORET: if (!abregee) return "\e[32mFORET\e[0m"; else return "\e[32mF\e[0m";
        default: throw std::invalid_argument("Unimplemented item");
    }
}

const char* Terrain::landToColor(Terrain::land land) throw(){
    switch (land)
    {
        case Terrain::PLAINE: return "BLANC";
        case Terrain::ILE: return "BLEU";
        case Terrain::MARAIS: return "NOIR";
        case Terrain::MONTAGNE: return "ROUGE";
        case Terrain::FORET: return "VERT";
        default: throw std::invalid_argument("Unimplemented item");
    }
}
