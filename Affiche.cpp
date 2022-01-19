
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Joueur.hpp"
#include "Affiche.hpp"




/*
template<typename Base, typename T>
inline bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
}
*/
void Affiche::afficheJeu(EnJeu* jeu){
    system("clear");
    std::cout << jeu->getJoueur1()->getNom() << " : PV :" << jeu->getJoueur1()->getPV() << " ";
    afficheBibliotheque(jeu->getJoueur1());
    std::cout << "\t";
    afficheMain(jeu->getJoueur1());
    std::cout << "\n_______________________________________________________________________________________________________________" << std::endl;
    afficheCombat(jeu);
    std::cout << "_______________________________________________________________________________________________________________\n" << std::endl;
    std::cout << jeu->getJoueur2()->getNom() << " : PV :" << jeu->getJoueur2()->getPV() << " ";
    afficheBibliotheque(jeu->getJoueur2());
    std::cout << "\t";
    afficheMain(jeu->getJoueur2());
    std::cout << std::endl;


}

void Affiche::afficheMain(Joueur* joueur){
     for(Carte* carte : joueur->getMain()){
         if(carte->getCreature()){
            Creature* creature = dynamic_cast<Creature*>(carte) ;
            std::cout << " | " << getColorDegagee(creature) << creature->getNom() << "\e[0m" <<"(" << creature->getForce() << "," << creature->getEndurance() << ")" << "(" << creature->getCoutQuelconque()  << "," << Affiche::afficheCoutSpe(creature->getCptCoutSpec()) << ")";
            
         }else{
             Terrain* terrain = dynamic_cast<Terrain*>(carte) ;
             std::cout << " | " << getColorDegagee(terrain) << terrain->landToString(terrain->getLandIndex()) << "\e[0m";
         }
     } 
 }

std::string Affiche::afficheCoutSpe(std::vector<int> coutSpecifique){
    int i = 0;
    std::string coutSpe="";
    for(int cpt : coutSpecifique){
        for(int j = 0; j < cpt; j++ ){
            coutSpe = coutSpe + Terrain::landToString(i,true) + " ";
        }
    }
    return coutSpe;
}

void Affiche::afficheBibliotheque(Joueur* joueur){
     std::cout << "Bibliotheque : " << joueur->getBibliotheque()->getBibliotheque().size();
 }

 void afficheCimetiere();

 void Affiche::afficheCombat(EnJeu* enJeu){
     for(Creature* creaturesJ1 : enJeu->getJoueur1()->getLCreature()){
            std::cout << " | " << getColorDegagee(creaturesJ1) << creaturesJ1->getNom() << "\e[0m" <<"(" << creaturesJ1->getForce() << "," << creaturesJ1->getEndurance() << ")" << "(" << creaturesJ1->getCoutQuelconque()  << "," << Affiche::afficheCoutSpe(creaturesJ1->getCptCoutSpec()) << ")";
     }
      for(Terrain* terrainsJ1 : enJeu->getJoueur1()->getLTerrain()){
            std::cout << " | " << getColorDegagee(terrainsJ1) << terrainsJ1->landToString(terrainsJ1->getLandIndex()) << "\e[0m";
      }

      std::cout << std::endl;

      for(Creature* creaturesJ2 : enJeu->getJoueur2()->getLCreature()){
            std::cout << " | " << getColorDegagee(creaturesJ2) << creaturesJ2->getNom() << "\e[0m" <<"(" << creaturesJ2->getForce() << "," << creaturesJ2->getEndurance() << ")" << "(" << creaturesJ2->getCoutQuelconque()  << ","<< Affiche::afficheCoutSpe(creaturesJ2->getCptCoutSpec()) << ")";
     }
      for(Terrain* terrainsJ2 : enJeu->getJoueur2()->getLTerrain()){
            std::cout << " | " << getColorDegagee(terrainsJ2) << terrainsJ2->landToString(terrainsJ2->getLandIndex())<< "\e[0m";
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
    if(!carte->getDegagee()){
        return "\e[47;30m";
    }else{
        return "";
    }
}