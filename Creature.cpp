#include <iostream>
#include <cstdlib>
#include <vector>
#include "Creature.hpp"

Creature::Creature(std::string nom, std::string type, int const basedEndurance ,int const basedForce, int coutQuelconque, std::vector <Terrain::land> coutSpec, std::vector <Capacite> capacites){
    m_nom = nom;
    m_type = type;
    m_basedEndurance = basedEndurance;
    m_basedForce = basedForce;
    m_endurance = basedEndurance;
    m_force = basedForce;
    m_coutQuelconque = coutQuelconque;
    m_capacites = capacites;
    setDegagee(true);
    m_creature = true;
    m_attaque = false;

    m_coutTotal = m_coutQuelconque;
    m_cptCoutSpec = std::vector<int>(5, 0);
    // voir si on prefere garder dans creature un vector de typeTerrain ou un vector<int> qui compte le nombre de terrain
    for(Terrain::land terrain : coutSpec){
        int index = static_cast<int>(terrain); // voir si il ne faut pas sortir int du for
        m_cptCoutSpec.at(index) += 1;
        m_coutTotal +=1;
    }


}

Creature::~Creature(){
    
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

std::vector<Capacite> Creature::getCapacites(){
    return m_capacites;
}

void Creature::setDegagee(bool estDegagee){
    m_degagee = estDegagee;
}
void Creature::setForce(int force){
    m_force = force;
}
void Creature::setEndurance(int endurance){
    m_endurance = endurance;
}

bool Creature::getCreature(){
    return m_creature;
}

bool Creature::getAttaque(){
    return m_attaque;
}

std::vector <Creature*> Creature::getEstDefenduPar(){
    return m_estDefenduPar;
}

void Creature::setAttaque(bool attaque){
    m_attaque = attaque;
}

 void Creature::addDefenseur(Creature* creature){
     m_estDefenduPar.push_back(creature);
 }

 void Creature::swap(int pos1, int pos2){
     Creature* temp = m_estDefenduPar.at(pos2);
     m_estDefenduPar.at(pos2) = m_estDefenduPar.at(pos1);
     m_estDefenduPar.at(pos1) = temp;
 }

 std::vector<int> Creature::getCptCoutSpec(){
    return m_cptCoutSpec;
}

int Creature::getCoutTotal(){
    return m_coutTotal;
}