
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Affiche.hpp"



/*
template<typename Base, typename T>
inline bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
}
*/
void Affiche::afficheJeu(EnJeu* jeu){
    system("clear");

    afficheBibliotheque(jeu->getJoueur1());
    std::cout << "\t";
    afficheMain(jeu->getJoueur1());
    std::cout << "\n_______________________________________________________________________________________________________________" << std::endl;
    afficheCombat(jeu);
    std::cout << "_______________________________________________________________________________________________________________\n" << std::endl;
    afficheBibliotheque(jeu->getJoueur2());
    std::cout << "\t";
    afficheMain(jeu->getJoueur2());
    std::cout << std::endl;


}

void Affiche::afficheMain(Joueur* joueur){
     for(Carte* carte : joueur->getMain()){
         if(carte->getCreature()){
            Creature* creature = dynamic_cast<Creature*>(carte) ;
            std::cout << " | " << getColorDegagee(creature) << creature->getNom() << "\e[0m" <<"(" << creature->getForce() << "," << creature->getEndurance() << ")" << "(" << creature->getCoutQuelconque()  << ",";
            Affiche::afficheCoutSpe(creature->getCoutSpecifique());
            std::cout << ")";
         }else{
             Terrain* terrain = dynamic_cast<Terrain*>(carte) ;
             std::cout << " | " << getColorDegagee(terrain) << terrain->getType();
         }
     } 
 }

void Affiche::afficheCoutSpe(std::vector<std::string> coutSpecifique){
    for(std::string cout : coutSpecifique){
        std::cout << " " << cout;
    }
}

void Affiche::afficheBibliotheque(Joueur* joueur){
     std::cout << "Bibliotheque : " << joueur->getBibliotheque()->getBibliotheque().size();
 }

 void Affiche::afficheCarte(std::vector<Creature*> lCreature, std::vector<Terrain*> lTerrain){
     for(Creature* creature : lCreature){
         std::cout << " | " << creature->getNom() << "(" << creature->getForce() << "," << creature->getEndurance() << ")";
     }
     for(Terrain* terrain : lTerrain){
         std::cout << " | " << terrain->getType();
     }
 }
 void afficheCimetiere();

 void Affiche::afficheCombat(EnJeu* enJeu){
     for(Creature* creaturesJ1 : enJeu->getJoueur1()->getLCreature()){
            std::cout << " | " << getColorDegagee(creaturesJ1) << creaturesJ1->getNom() << "\e[0m" <<"(" << creaturesJ1->getForce() << "," << creaturesJ1->getEndurance() << ")" << "(" << creaturesJ1->getCoutQuelconque()  << ",";
            Affiche::afficheCoutSpe(creaturesJ1->getCoutSpecifique());
            std::cout << ")";
     }
      for(Terrain* terrainsJ1 : enJeu->getJoueur1()->getLTerrain()){
            std::cout << " | " << getColorDegagee(terrainsJ1) << terrainsJ1->getType();
      }

      std::cout << std::endl;

      for(Creature* creaturesJ2 : enJeu->getJoueur1()->getLCreature()){
            std::cout << " | " << getColorDegagee(creaturesJ2) << creaturesJ2->getNom() << "\e[0m" <<"(" << creaturesJ2->getForce() << "," << creaturesJ2->getEndurance() << ")" << "(" << creaturesJ2->getCoutQuelconque()  << ",";
            Affiche::afficheCoutSpe(creaturesJ2->getCoutSpecifique());
            std::cout << ")";
     }
      for(Terrain* terrainsJ2 : enJeu->getJoueur1()->getLTerrain()){
            std::cout << " | " << getColorDegagee(terrainsJ2) << terrainsJ2->getType();
      }
      std::cout << std::endl;
 }


std::string Affiche::getColorType(Creature* creature){
    if(creature->getType()==""){
        return "";
        
    }else if (creature->getType()==""){
        return "";
    }
    return"";
}

std::string Affiche::getColorDegagee(Carte* carte){
    if(carte->getDegagee()){
        return "\e[47;30m";
    }else{
        return "";
    }
}