#ifndef AFFICHE_HPP
#define AFFICHE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "../headers/EnJeu.hpp"

class EnJeu;
class Joueur;
class Affiche
{
public:
 static void afficheJeu(EnJeu* jeu);

 static void afficheMain(Joueur* joueur);
 static std::string afficheCoutSpe(std::vector<int> coutSpe);
 static void afficheBibliotheque(Joueur* joueur);
 static void afficheCimetiere(std::vector<Carte*> cimetiere);
 static void afficheCombat(EnJeu* enJeu);
 static void afficheCarte(Carte* carte, int pos = -1, Joueur* joueur = nullptr);

static std::string afficheCapacite(Creature* creature);
static std::string afficheNom(Creature* creature);
static std::string getColorDegagee(Carte* carte);
static std::string getColorType(Creature* carte);
static std::string getColorAttaque(Creature* creature, Joueur* j2);
    
};

#endif

