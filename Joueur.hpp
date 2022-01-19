#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Deck.hpp"
#include "Carte.hpp"
#include "Bibliotheque.hpp"
#include "Creature.hpp"
#include "Terrain.hpp"


class Joueur {
    private :
        std::string m_nom;
        int m_pv;
        Deck* m_deck;
        Bibliotheque* m_bibliotheque;
        std::vector<Carte*> m_cimetiere;
        std::vector<Carte*> m_main;
        std::vector<Creature*> m_LCreature;
        std::vector<Terrain*> m_LTerrain;

    public :
        Joueur();
        Joueur (int pv, Deck* deck);
        ~Joueur();
        int getPV();
        Deck* getDeck();
        std::vector<Carte*> getCimetiere();
        std::vector<Carte*> getMain();
        Bibliotheque* getBibliotheque();
        std::vector<Creature*> getLCreature();
        std::vector<Terrain*> getLTerrain();
        std::string getNom();
        bool setPv(int pv);
        void setNom(std::string nom);
        void addDefenseur(int pos, Creature* creature);
        bool piocher(int nbrCartes);
        void melanger();
        void desengager();
        void tropDeCartes();
        void remonterStatsCreatures();
        bool attaque();
        void defense(Joueur* joueur);
        void choisirAttaque();
        void mortAuCombat(Creature* creature);

};

#endif