#include <iostream>
#include <cstdlib>
#include "EnJeu.hpp"

EnJeu::EnJeu(Joueur* joueur1, Joueur* joueur2){
    m_joueur1 = joueur1;
    m_joueur2 = joueur2;
    m_j1 = new Joueur();
    m_j2 = new Joueur();
    m_partieFinie = false;
    m_t1 = true;
    m_gagnant = "";
}

EnJeu::~EnJeu(){}

Joueur* EnJeu::getJoueur1(){
    return m_joueur1;
}
Joueur* EnJeu::getJoueur2(){
    return m_joueur2;
}
Joueur* EnJeu::getJ1(){
    return m_j1;
}
Joueur* EnJeu::getJ2(){
    return m_j2;
}

int EnJeu::tirerAuSort(){
    return rand() % 1;  
}

bool EnJeu::phasePioche(Joueur* j1, Joueur* j2){
    if (!j1->piocher(1)){
        m_gagnant = j2->getNom();
        return false;
    }else{
        return true;
    }
}

void EnJeu::phaseDesengagement(Joueur* j1){
    j1->desengager();
}

void EnJeu::phasePose(Joueur* j1){
    int nbCartesMain = j1->getMain().size();
    int carteAPoser;
    bool veutContinuer = true;
    do{
        std::cout << j1->getNom() << " choisissez une carte a poser." << std::endl;
        std::cin >> carteAPoser;
        carteAPoser--;
        nbCartesMain = j1->getMain().size();
        
        // On vérifie que le numéro renseigné est valable
        if(carteAPoser < nbCartesMain && carteAPoser > -1){
            // Si la carte désignée est une créature
            if(j1->getMain().at(carteAPoser)->getCreature()){
                j1->ajoutCreature(carteAPoser);
            }
            // Si la carte désignée est un terrain
            else{
                // Si un terrain n'a pas été posé ce tour
                if(!j1->getTerrainPose()){
                    j1->ajoutTerrain(carteAPoser);
                }
                // Si un terrain a déjà été posé ce tour
                else{
                    std::cout << "Vous avez deja pose un terrain ce tour." << std::endl;
                }
            }
        }
        else {
            std::cout << "Le numero rentre n'est pas valide !" << std::endl;
        }
        // On demande si le joueur veut poser une autre carte
        std::cout << "Voulez-vous poser une autre carte ? o/n" << std::endl;
        std::string rep;
        do{
            std::cin >> rep;
            if(rep == "o") veutContinuer = true;
            else if(rep == "n") veutContinuer = false;
        } while (!(rep == "o") && !(rep == "n"));

    } while(veutContinuer);
}

bool EnJeu::phaseCombat(Joueur* j1, Joueur* j2){
    if(j1->attaque()){
        j2->defense(j1);
    }
    j1->choisirAttaque();
    for(Creature* creature : j1->getLCreature()){
        if(creature->getAttaque()){
            if(creature->getEstDefenduPar().size() == 0){
                if(j2->setPv(creature->getForce())){

                }else{
                    m_gagnant = j1->getNom();
                    return false;
                }
            }else{
                for(Creature* creatureD : creature->getEstDefenduPar()){
                    creatureD->setEndurance(creatureD->getEndurance() - creature->getForce());
                    creature->setEndurance(creature->getEndurance() - creatureD->getForce());
                    if(creature->getEndurance() <= 0 && creatureD->getEndurance() <= 0){
                        j1->mortAuCombat(creature);
                        j1->mortAuCombat(creatureD);
                        break;
                    }else if(creature->getEndurance() <= 0 ){
                        j1->mortAuCombat(creature);
                        break;
                    }else if(creatureD->getEndurance() <= 0 ){
                        j2->mortAuCombat(creatureD);
                    } 
                }
            }
        }
    }
    return true;
}

void EnJeu::phaseFinTour(Joueur* j1, Joueur* j2){
    j1->tropDeCartes();
    j2->tropDeCartes();
    j1->remonterStatsCreatures();
    j2->remonterStatsCreatures();

}

bool EnJeu::tour(Joueur* j1, Joueur* j2){
   
    if(!m_t1){
        if(!phasePioche(j1, j2)){
            return false;
        }
    }
    
    Affiche::afficheJeu(this);
        
   
    phaseDesengagement(j1);
    
    phasePose(j1);
    
    if(j1->getLCreature().size()>0){
        
    }
    if(!phaseCombat(j1,j2)){
            return false;
        }
    
    phasePose(j1);
    
    phaseFinTour(j1, j2);
    
   return true;
    
}

void EnJeu::start(Joueur* joueur1, Joueur* joueur2){

    joueur1->melanger();
    joueur2->melanger();
    
    joueur1->piocher(7);
    joueur2->piocher(7);

    std::cout << joueur1->getNom() << std::endl;
    
    
    if (tirerAuSort() == 0){
       while (1){

            if (!tour(joueur1, joueur2)){
                break;
            }

            Affiche::afficheJeu(this);

            if(!tour(joueur2,joueur1)){
                break;
            }
            m_t1 = false;

            std::cout << "FIN DE TOUR" << std::endl;
            
        }
        
    }else{
        
        while (1){
            if (!tour(joueur2, joueur1)){
                break;
            }

            Affiche::afficheJeu(this);

            if(!tour(joueur1,joueur2)){
                break;
            }
            m_t1 = false;

            std::cout << "FIN DE TOUR" << std::endl;
        }
        
    }
    

    std::cout << m_gagnant << " à gagné !! gg ! " << std::endl;
    
}