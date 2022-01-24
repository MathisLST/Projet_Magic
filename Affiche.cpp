
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

void Affiche::afficheCarte(Carte* carte, int pos, Joueur* joueur){
    if(carte->getCreature()){
        Creature* creature = dynamic_cast<Creature*>(carte) ;
        std::cout << " | " << pos << "- " << getColorDegagee(creature) << creature->getNom() << "\e[0m" <<"(" << creature->getForce() << "," << creature->getEndurance() << ")" << "(" << creature->getCoutQuelconque()  << "," << Affiche::afficheCoutSpe(creature->getCptCoutSpec()) << ")" << getColorAttaque(creature, joueur);
    }else{
        Terrain* terrain = dynamic_cast<Terrain*>(carte) ;
        if (pos == -1){
            std::cout << " | " << getColorDegagee(terrain) << terrain->landToString(terrain->getLandIndex()) << "\e[0m";
        }else{
            std::cout << " | " << pos << "- " << getColorDegagee(terrain) << terrain->landToString(terrain->getLandIndex()) << "\e[0m";
        }
    }
}

void Affiche::afficheMain(Joueur* joueur){
    int i = 1;
     for(Carte* carte : joueur->getMain()){
         afficheCarte(carte, i);
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
            afficheCarte(creaturesJ1, c1, enJeu->getJoueur2());
            c1++;
     }
      for(Terrain* terrainsJ1 : enJeu->getJoueur1()->getLTerrain()){
            afficheCarte(terrainsJ1);
      }

      std::cout << "\n" << std::endl;
        int c2 = 1;
      for(Creature* creaturesJ2 : enJeu->getJoueur2()->getLCreature()){
            afficheCarte(creaturesJ2, c2, enJeu->getJoueur1());            
            c2++;
                 }
      for(Terrain* terrainsJ2 : enJeu->getJoueur2()->getLTerrain()){
          afficheCarte(terrainsJ2);
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
        if(!(creature->getEstDefenduPar().size()==0)){
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
    