#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "../headers/Deck.hpp"
#include "../headers/Carte.hpp"
#include "../headers/Bibliotheque.hpp"
#include "../headers/Creature.hpp"
#include "../headers/Terrain.hpp"
#include "../headers/EnJeu.hpp"

class EnJeu;
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
        bool m_terrainPose;
        std::vector<int> m_cptTerrainPrets;
        int m_totalTerrainsPrets;
        bool m_aAttaque;
    public :
        Joueur();
        Joueur (int pv, std::string nom, Encyclopedie* encyclopedie);
        ~Joueur();

        int getPV();
        Deck* getDeck();
        std::vector<Carte*> getCimetiere();
        std::vector<Carte*> getMain();
        Bibliotheque* getBibliotheque();
        std::vector<Creature*> getLCreature();
        std::vector<Terrain*> getLTerrain();
        std::string getNom();
        bool getTerrainPose();
        std::vector<int> getCptTerrainPrets();
        bool getCreatureReady();
        bool getAAttaque();

        bool setPv(int pv);
        void setNom(std::string nom);
        void setTerrainPose(bool b);
        void setAAttaque(bool aAttaque);
        void addDefenseur(int pos, Creature* creature);

        bool piocher(int nbrCartes);
        void melanger();
        void desengager();
        void tropDeCartes();
        void remonterStatsCreatures();
        bool attaque(EnJeu* enJeu);
        void defense(Joueur* joueur, EnJeu* enJeu);
        void choixDefenseur(Joueur *joueur2, int surQui, EnJeu* enJeu);
        void choisirAttaque(Joueur* j2, EnJeu* enJeu);
        void mortAuCombat(Creature* creature);
        void ajoutTerrain(int indexCarte, EnJeu* enJeu);   
        void ajoutCreature(int indexCarte, EnJeu* enJeu);
        bool creaturePosable(Creature* creature);
        void majCptTerrainPrets();
        void construireDeck();
        bool peutDefendre(Creature* creatureA, Creature* creatureD);
        void resetEstDefenduPar();
        

    


};

#endif