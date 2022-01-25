#include <iostream>
#include <cstdlib>
#include <random>
#include "../headers/EnJeu.hpp"

EnJeu::EnJeu(Joueur* joueur1, Joueur* joueur2){
    m_joueur1 = joueur1;
    m_joueur2 = joueur2;
    m_partieFinie = false;
    m_tour1 = true;
    m_gagnant = "";
}

EnJeu::~EnJeu(){}

Joueur* EnJeu::getJoueur1(){
    return m_joueur1;
}
Joueur* EnJeu::getJoueur2(){
    return m_joueur2;
}

bool EnJeu::tirerAuSort(){
    std::mt19937 rng(std::random_device{}());
    return std::uniform_int_distribution<>{0, 1}(rng);
  
}

bool EnJeu::phasePioche(Joueur* j1, Joueur* j2){
    if (!j1->piocher(1)){
        m_gagnant = j2->getNom();
        std::cout << j1->getNom() << " n'a plus de carte dans sa bibliotheque !" << std::endl;
        return false;
    }else{
        return true;
    }
}

void EnJeu::phaseDesengagement(Joueur* j1){
    j1->desengager();
    j1->majCptTerrainPrets();
}

void EnJeu::phasePose(Joueur* j1){
    int nbCartesMain = j1->getMain().size();
    int carteAPoser;
    bool veutContinuer = true;
    std::string rep;
    do{
            std::cout << j1->getNom() << " voulez-vous poser une carte ? ('o' oui, 'n' non)" << std::endl;
            std::cin >> rep;
            if(rep == "o") veutContinuer = true;
            else if(rep == "n") veutContinuer = false;
        } while (!(rep == "o") && !(rep == "n"));
    while(veutContinuer){
        std::cout << j1->getNom() << " choisissez une carte a poser." << std::endl;
         while (!(std::cin >> carteAPoser)){
            std::cout << "Numero de carte invalide, veuillez rentrer un entier !" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << j1->getNom() << " choisissez une carte a poser." << std::endl;
        }   
        carteAPoser--;
        nbCartesMain = j1->getMain().size();
        
        // On vérifie que le numéro renseigné est valable
        if(carteAPoser < nbCartesMain && carteAPoser > -1){
            // Si la carte désignée est une créature
            if(j1->getMain().at(carteAPoser)->getCreature()){
                j1->ajoutCreature(carteAPoser, this);
            }
            // Si la carte désignée est un terrain
            else{
                // Si un terrain n'a pas été posé ce tour
                if(!j1->getTerrainPose()){
                    j1->ajoutTerrain(carteAPoser, this);
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
        do{
            std::cout << "Voulez-vous poser une autre carte ? o/n" << std::endl;
            std::cin >> rep;
            if(rep == "o") veutContinuer = true;
            else if(rep == "n") veutContinuer = false;
        } while (!(rep == "o") && !(rep == "n"));

    } 
}

bool EnJeu::phaseCombat(Joueur* j1, Joueur* j2){
    if(j1->attaque(this)){
        Affiche::afficheJeu(this);
        if(j2->getLCreature().size()>0 && j2->getCreatureReady()){
            j2->defense(j1, this);
            Affiche::afficheJeu(this);
            j1->choisirAttaque(j2, this);
        }
        Affiche::afficheJeu(this);
        std::string pause;
        std::cout << "Rentrez qqc pour lancer le combat" << std::endl;
        std::cin >> pause;
        
    }
   


    for(Creature* creature : j1->getLCreature()){
        if(creature->getAttaque()){

            creature->setAttaque(false);

            if(creature->getEstDefenduPar().size() == 0){
                if(j2->setPv(j2->getPV()-creature->getForce())){

                    if(creature->aLaCapacite(Capacite::LIENDEVIE)){
                        j1->setPv(j1->getPV() + creature->getForce());
                    }

                }else{
                    m_gagnant = j1->getNom();
                    std::cout << j2->getNom() << " n'a plus de PV !" << std::endl;
                    return false;
                }
            }else{

                for(Creature* creatureD : creature->getEstDefenduPar()){
                    if ((creatureD->aLaCapacite(Capacite::CONTACTMORTEL) && creatureD->getForce() > 0 ) && ( creature->aLaCapacite(Capacite::CONTACTMORTEL) && creature->getForce() > 0)){
                        creatureD->setEndurance(- (creature->getForce() - 1));
                        creature->setEndurance(- (creatureD->getForce() - 1));
                    }else if(creatureD->aLaCapacite(Capacite::CONTACTMORTEL) && creatureD->getForce() > 0){
                        creatureD->setEndurance(creatureD->getEndurance() - creature->getForce());
                        creature->setEndurance(- (creatureD->getForce() - 1));
                    }else if (creature->aLaCapacite(Capacite::CONTACTMORTEL) && creature->getForce() > 0){
                        creatureD->setEndurance(- (creature->getForce() - 1));
                        creature->setEndurance(creature->getEndurance() - creatureD->getForce());
                    }else{ 
                        creatureD->setEndurance(creatureD->getEndurance() - creature->getForce());
                        creature->setEndurance(creature->getEndurance() - creatureD->getForce());
                    }

                    if ( creature->aLaCapacite(Capacite::PIETINEMENT) && creatureD->getEndurance() <= 0){
                        j2->setPv(j2->getPV() + creatureD->getEndurance());
                    }

                    if(creature->aLaCapacite(Capacite::LIENDEVIE)){
                        j1->setPv(j1->getPV() + creature->getForce());
                    }
                    if(creatureD->aLaCapacite(Capacite::LIENDEVIE)){
                        j2->setPv(j2->getPV() + creature->getForce());
                    }
                    

                    if(creature->getEndurance() <= 0 && creatureD->getEndurance() <= 0){
                        j1->mortAuCombat(creature);
                        j2->mortAuCombat(creatureD);
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
    j1->setTerrainPose(false);
    j2->setTerrainPose(false);
    j1->setAAttaque(false);
    j2->setAAttaque(false);

}

bool EnJeu::tour(Joueur* j1, Joueur* j2){
   
    if(!m_tour1){
        if(!phasePioche(j1, j2)){
            return false;
        }
    }
    phaseDesengagement(j1);
    Affiche::afficheJeu(this);
    
    phasePose(j1);
    
    if(j1->getLCreature().size()>0 && j1->getCreatureReady()){
        if(!phaseCombat(j1,j2)){
            return false;
        }
    }
    Affiche::afficheJeu(this);
    if(j1->getAAttaque()){
        phasePose(j1);
        Affiche::afficheJeu(this);
    }    
    
    phaseFinTour(j1, j2);
    
   return true;
    
}

void EnJeu::start(Joueur* joueur1, Joueur* joueur2){

    joueur1->melanger();
    joueur2->melanger();
    
    joueur1->piocher(7);
    joueur2->piocher(7);
    
    if (tirerAuSort()){
       while (1){

            if (!tour(joueur1, joueur2)){
                break;
            }
            m_tour1 = false;
            Affiche::afficheJeu(this);

            if(!tour(joueur2,joueur1)){
                break;
            }
           
        }
        
    }else{
        
        while (1){
            if (!tour(joueur2, joueur1)){
                break;
            }
            m_tour1 = false;
            Affiche::afficheJeu(this);

            if(!tour(joueur1,joueur2)){
                break;
            }
            
        }
        
    }
    

    std::cout << m_gagnant << " a gagné !! gg ! " << std::endl;
    
}