#include <iostream>
#include <cstdlib>
#include <vector>
#include "Encyclopedie.hpp"

Encyclopedie::Encyclopedie(){

}

Encyclopedie::~Encyclopedie(){
    for(Carte* carte : m_encyclopedie){
        delete carte;
    }
}

std::vector<Carte*> Encyclopedie::getEncyclopedie(){
    return m_encyclopedie;
}

