#include <iostream>
#include <cstdlib>
#include <vector>
#include "EnJeu.hpp"

class Affiche
{
public:
 static void afficheJeu(EnJeu* jeu);

 static void afficheMain(Joueur* joueur);
 static void afficheCoutSpe(std::vector<std::string>);
 static void afficheBibliotheque(Joueur* joueur);
 static void afficheCarte(std::vector<Creature*>, std::vector<Terrain*>);
 static void afficheCimetiere(std::vector<Carte*> cimetiere);
 static void afficheCombat();


    
};


