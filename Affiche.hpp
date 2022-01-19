#ifndef AFFICHE_HPP
#define AFFICHE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "EnJeu.hpp"

class Affiche
{
public:
 static void afficheJeu(EnJeu* jeu);

 static void afficheMain(Joueur* joueur);
 static std::string afficheCoutSpe(std::vector<int> coutSpe);
 static void afficheBibliotheque(Joueur* joueur);
 static void afficheCarte(std::vector<Creature*>, std::vector<Terrain*>);
 static void afficheCimetiere(std::vector<Carte*> cimetiere);
 static void afficheCombat(EnJeu* enJeu);

static std::string getColorDegagee(Carte* carte);
static std::string getColorType(Creature* carte);
    
};

#endif

