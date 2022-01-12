#include <iostream>
#include <cstdlib>
#include <vector>
#include "EnJeu.hpp"

const class Affiche
{
public:
 void afficheJeu(EnJeu jeu);

 void afficheMain(Joueur joueur);
 void afficheBibliotheque(Joueur joueur);
 void afficheCarte(std::vector<Creature>, std::vector<Terrain>);
 void afficheCimetiere(std::vector<Carte> cimetiere);
 void afficheCombat();


    
};


