#include <iostream>
#include <cstdlib>
#include <vector>
#include "Creature.hpp"

Creature::Creature (std::string nom, std::string type, int const basedEndurance ,int const basedForce, int endurance,
 int force, int coutQuelconque, std::vector <std::string> coutSpecifique, std::vector <Capacite> capacites){
    m_nom = nom;
    m_type = type;
    m_basedEndurance = basedEndurance;
    m_basedForce = basedForce;
    m_endurance = endurance;
    m_force = force;
    m_coutQuelconque = coutQuelconque;
    m_coutSpecifique = coutSpecifique;
    m_capacites = capacites;
    setDegagee(false);
    
}

std::string Creature::getNom(){
    return m_nom;
}
std::string Creature::getType(){
    return m_type;
}
int Creature::getBasedEndurance(){
    return m_basedEndurance;
}
int Creature::getBasedForce(){
    return m_basedForce;
}
int Creature::getEndurance(){
    return m_endurance;
}
int Creature::getForce(){
    return m_force;
}
int Creature::getCoutQuelconque(){
    return m_coutQuelconque;
}

bool Creature::getDegagee(){
    return m_degagee;
}

std::vector<std::string> Creature::getCoutSpecifique(){
    return m_coutSpecifique;
}
std::vector<Capacite> Creature::getCapacites(){
    return m_capacites;
}

void Creature::setDegagee(bool estDegagee){
    m_degagee = estDegagee;
}