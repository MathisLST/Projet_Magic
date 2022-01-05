#include <iostream>
#include <cstdlib>
#include <vector>
#include "Terrain.hpp"

Terrain::Terrain (std::string type){
    m_type = type;
}

std::string Terrain::getType(){
    return m_type;
}

