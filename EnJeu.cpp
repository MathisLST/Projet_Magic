#include <iostream>
#include <cstdlib>
#include "EnJeu.hpp"

EnJeu::EnJeu(Joueur* joueur1, Joueur* joueur2){
    m_joueur1 = joueur1;
    m_joueur2 = joueur2;
    partieFinie = false;
    t1 = true;
    gagnant = nullptr;
}

EnJeu::~EnJeu(){}

Joueur* EnJeu::getJoueur1(){
    return m_joueur1;
}
Joueur* EnJeu::getJoueur2(){
    return m_joueur2;
}

Joueur* EnJeu::tirerAuSort(Joueur* joueur1, Joueur* joueur2 ){}
void EnJeu::phasePioche(Joueur* j1){}
void EnJeu::phaseDesengagement(Joueur* j1){}
void EnJeu::phasePose(Joueur* j1){}
void EnJeu::phaseCombat(Joueur* j1, Joueur* j2){}
void EnJeu::phasePose(Joueur* j1){}
void EnJeu::phaseFinTour(Joueur* j1, Joueur* j2){}

void EnJeu::tour(Joueur* j1, Joueur* j2){
    if(!t1){
            phasePioche(j1);
        }
    phaseDesengagement(j1);
    phasePose(j1);
    phaseCombat(j1,j2);
    phasePose(j1);
    phaseFinTour(j1, j2);

}

void EnJeu::start(Joueur* joueur1, Joueur* joueur2){

    joueur1->melanger();
    joueur2->melanger();
    
    joueur1->piocher(7);
    joueur2->piocher(7);

    Joueur *j1, *j2 = tirerAuSort(joueur1, joueur2);
        
    bool t1 = true;

    while (!partieFinie){
        tour(j1, j2);
        tour(j2,j1);
    }
}