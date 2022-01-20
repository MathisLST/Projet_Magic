
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
    std::cout << jeu->getJoueur1()->getNom() << "\nPV : \e[32m" << jeu->getJoueur1()->getPV() << "\e[0m " << std::endl;
    afficheBibliotheque(jeu->getJoueur1());
    std::cout << "\n" << std::endl;
    afficheMain(jeu->getJoueur1());
    std::cout << "\n_________________________________________________________________________________________________________________________________________________________________________________________________________________" << std::endl;
    afficheCombat(jeu);
    std::cout << "_________________________________________________________________________________________________________________________________________________________________________________________________________________\n" << std::endl;
    afficheMain(jeu->getJoueur2());
    std::cout << "\n" <<std::endl;
    afficheBibliotheque(jeu->getJoueur2());
    std::cout << "\nPV : \e[32m" << jeu->getJoueur2()->getPV() << "\e[0m \n" << jeu->getJoueur2()->getNom() ;
    std::cout << "\n" << std::endl;


}

void Affiche::afficheMain(Joueur* joueur){
    int i = 1;
     for(Carte* carte : joueur->getMain()){
         if(carte->getCreature()){
            Creature* creature = dynamic_cast<Creature*>(carte) ;
            std::cout << " | " << i << "- " << creature->getNom() << "\e[0m" <<"(" << creature->getForce() << "," << creature->getEndurance() << ")" << "(" << creature->getCoutQuelconque()  << "," << Affiche::afficheCoutSpe(creature->getCptCoutSpec()) << ")";
            
         }else{
             Terrain* terrain = dynamic_cast<Terrain*>(carte) ;
             std::cout << " | " << i << "- " << terrain->landToString(terrain->getLandIndex()) << "\e[0m";
         }
         i++;
     } 
 }

std::string Affiche::afficheCoutSpe(std::vector<int> coutSpecifique){
    int i = 0;
    std::string coutSpe="";
    for(int cpt : coutSpecifique){
        for(int j = 0; j < cpt; j++ ){
            coutSpe = coutSpe + Terrain::landToString(i,true) + " ";
        }
        i++;
    }
    return coutSpe;
}

void Affiche::afficheBibliotheque(Joueur* joueur){
     std::cout << "Bibliotheque : " << joueur->getBibliotheque()->getBibliotheque().size();
 }

 void afficheCimetiere();

 void Affiche::afficheCombat(EnJeu* enJeu){
    int c1 = 1;
     for(Creature* creaturesJ1 : enJeu->getJoueur1()->getLCreature()){
            std::cout << " | " << c1 << "- " << getColorDegagee(creaturesJ1) << creaturesJ1->getNom()  << "(" << creaturesJ1->getForce() << "," << creaturesJ1->getEndurance() << ")" << "(" << creaturesJ1->getCoutQuelconque()  << "," << Affiche::afficheCoutSpe(creaturesJ1->getCptCoutSpec()) << ")" << Affiche::getColorAttaque(creaturesJ1, enJeu->getJoueur2());
            c1++;
     }
      for(Terrain* terrainsJ1 : enJeu->getJoueur1()->getLTerrain()){
            std::cout << " | " << getColorDegagee(terrainsJ1) << terrainsJ1->landToString(terrainsJ1->getLandIndex());
      }

      std::cout << "\n" << std::endl;
        int c2 = 1;
      for(Creature* creaturesJ2 : enJeu->getJoueur2()->getLCreature()){
            std::cout << " | " << c2 << "- "   << getColorDegagee(creaturesJ2) << creaturesJ2->getNom() << "(" << creaturesJ2->getForce() << "," << creaturesJ2->getEndurance() << ")" << "(" << creaturesJ2->getCoutQuelconque()  << ","<< Affiche::afficheCoutSpe(creaturesJ2->getCptCoutSpec()) << ")" << Affiche::getColorAttaque(creaturesJ2, enJeu->getJoueur1());

                 }
      for(Terrain* terrainsJ2 : enJeu->getJoueur2()->getLTerrain()){
            std::cout << " | " << getColorDegagee(terrainsJ2) << terrainsJ2->landToString(terrainsJ2->getLandIndex()) ;
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
        return "\e[47;30mE\e[0m ";
    }else{
        return "";
    }
}

std::string Affiche::getColorAttaque(Creature* creature, Joueur* j2){
  if( creature->getAttaque()){
        std::string texteAttaque = "";
        texteAttaque+= " \e[41;37mA";
        if(!creature->getEstDefenduPar().size()==0){
            for(Creature* defenseur : creature->getEstDefenduPar() ){
                int index = 1;
                for(Creature* creatureD : j2->getLCreature()){
                    if(creatureD == defenseur){
                        texteAttaque = texteAttaque + " " + std::to_string(index) ;
                    }
                    index++;
                }
                
            }
        }
        texteAttaque+= "\e[0m";
        return texteAttaque;
    }
    return "";
    
}
    