#include <iostream>
#include <cstdlib>
#include <vector>
#include "Capacite.hpp"

Capacite::Capacite(std::string nom, std::string description){
    m_nom = nom;
    m_description = description;
}

std::string Capacite::getNom(){
    return m_nom;
}

std::string Capacite::getDescription(){
    return m_description;
}
