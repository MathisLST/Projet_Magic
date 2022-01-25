#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "../headers/Terrain.hpp"
#include "../headers/Capacite.hpp"
#include "../headers/Carte.hpp"



class Creature : public Carte {
    private :
        std::string m_nom;
        std::string m_type;

        // force et endurance de base, valeurs ecrites sur la carte
        int m_basedEndurance;
        int m_basedForce;

        int m_endurance;
        int m_force;
        int m_coutQuelconque;

        // bool true si la creature veut attaquer ce tour
        bool m_attaque;

        std::vector <Capacite::capaciteStatique> m_capacites;
        std::vector <Creature*> m_estDefenduPar;

        // vector d'int contenant le nombre de chaque type de terrains specifiques demandes par la creature
        std::vector<int> m_cptCoutSpec;

        int m_coutTotal;

        // vector contenant les terrains demandes par la creature
        std::vector <Terrain::land> m_coutSpecifique;

        std::vector<std::string> m_couleur;
        void setCouleur();

	
    public :
        Creature(std::string nom, std::string type, int const basedEndurance ,int const basedForce, int coutQuelconque, std::vector <Terrain::land> coutSpec, std::vector <Capacite::capaciteStatique> capacites);
        virtual ~Creature();

        std::string getNom();
        std::string getType();
        int getBasedEndurance();
        int getBasedForce();
        int getEndurance();
        int getForce();
        int getCoutQuelconque();
        bool getDegagee();
        std::vector <Terrain::land> getCoutSpecifique();
        std::vector <Capacite::capaciteStatique> getCapacites();
        bool getCreature();
        bool getAttaque();
        std::vector <Creature*> getEstDefenduPar();
        std::vector<int> getCptCoutSpec();
        int getCoutTotal();
        std::vector<std::string> getCouleur();
        
        void setDegagee(bool estDegagee);
        void setForce(int force);
        void setEndurance(int endurance);
        void setAttaque(bool attaque);
        void addDefenseur(Creature* creature);

        void swap(int pos1, int pos2);
        bool aLaCapacite(Capacite::capaciteStatique capacite);
        bool aLaCouleur(std::string couleur);
        

        
};

#endif