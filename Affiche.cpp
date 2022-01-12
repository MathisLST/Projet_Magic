
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Affiche.hpp"



 void afficheJeu(EnJeu& jeu);

 void Affiche::afficheMain(Joueur& joueur){
     for(Carte& carte : joueur.getMain()){
         if(carte.estCreature()){
             


         }
     }
     
 }
 void Affiche::afficheBibliotheque(Joueur& joueur){
     std::cout << "Bibliotheque : " << joueur.getBibliotheque().size();
 }

 void Affiche::afficheCarte(std::vector<Creature&> lCreature, std::vector<Terrain&> lTerrain){
     for(Creature& creature : lCreature){
         std::cout << " | " << creature.getNom() << "(" << creature.getForce() << "," << creature.getEndurance() << ")";
     }
     for(Terrain& terrain : lTerrain){
         std::cout << " | " << terrain.getType();
     }
 }
 void afficheCimetiere();

 void afficheCombat();
