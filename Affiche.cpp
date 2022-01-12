
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Affiche.hpp"

template<typename T, typename std::enable_if<std::is_base_of<Carte, T>::value>::type* = nullptr>
void afficheMain(Joueur joueur){
     for(T carte : joueur.getMain()){
         if(){
            int x = carte.getForce();
         }
     }
     
 }

 void afficheJeu(EnJeu jeu);

 
 void Affiche::afficheBibliotheque(Joueur joueur){
     std::cout << "Bibliotheque : " << joueur.getBibliotheque().getBibliotheque().size();
 }

 void Affiche::afficheCarte(std::vector<Creature> lCreature, std::vector<Terrain> lTerrain){
     for(Creature creature : lCreature){
         std::cout << " | " << creature.getNom() << "(" << creature.getForce() << "," << creature.getEndurance() << ")";
     }
     for(Terrain terrain : lTerrain){
         std::cout << " | " << terrain.getType();
     }
 }
 void afficheCimetiere();

 void afficheCombat();
