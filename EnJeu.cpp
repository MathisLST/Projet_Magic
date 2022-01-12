#include <iostream>
#include <cstdlib>
#include "EnJeu.hpp"

EnJeu::EnJeu(Joueur joueur1, Joueur joueur2){
    m_joueur1 = joueur1;
    m_joueur2 = joueur2;
}

EnJeu::~EnJeu(){}

Joueur EnJeu::getJoueur1(){
    return m_joueur1;
}
Joueur EnJeu::getJoueur2(){
    return m_joueur2;
}

std::vector<Terrain*> EnJeu::getLTerrainJ1(){
    return m_LTerrainJ1;
}

std::vector<Terrain*> EnJeu::getLTerrainJ2(){
    return m_LTerrainJ2;
}

std::vector<Creature*> EnJeu::getLCreatureJ1(){
    return m_LCreatureJ1;
}

std::vector<Creature*> EnJeu::getLCreatureJ2(){
    return m_LCreatureJ2;
}

void jeu(Joueur joueur1, Joueur joueur2){

            joueur1.distribuer();
            joueur2.distribuer();
        
            while ( joueur1.getPV() > 0 || joueur2.getPV() > 0){
            

            }
        }