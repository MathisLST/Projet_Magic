
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

void Affiche::afficheMain(Joueur* joueur){
     for(Carte* carte : joueur->getMain()){
         if(carte->getCreature()){
            Creature* creature = dynamic_cast<Creature*>(carte) ;
            std::cout << " | " << "\e[41m" << creature->getNom() << "\e[0m" <<"(" << creature->getForce() << "," << creature->getEndurance() << ")" << "(" << creature->getCoutQuelconque()  << ",";
            Affiche::afficheCoutSpe(creature->getCoutSpecifique());
            std::cout << ")";
         }else{
             
         }

     }
     
 }

void Affiche::afficheCoutSpe(std::vector<std::string> coutSpecifique){
    for(std::string cout : coutSpecifique){
        std::cout << " " << cout;
    }
}

void Affiche::afficheJeu(EnJeu* jeu){
    afficheBibliotheque(jeu->getJoueur1());
    std::cout << "\t";
    afficheMain(jeu->getJoueur1());
    std::cout << "\n\n\n" << std::endl;
    afficheBibliotheque(jeu->getJoueur2());
    std::cout << "\t";
    afficheMain(jeu->getJoueur2());


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

 void afficheCombat();
