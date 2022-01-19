#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Terrain.hpp"
#include "Capacite.hpp"
#include "Carte.hpp"



class Creature : public Carte {
    private :
        std::string m_nom;
        std::string m_type;
        int m_basedEndurance;
        int m_basedForce;
        int m_endurance;
        int m_force;
        int m_coutQuelconque;
        bool m_attaque;
        std::vector <std::string> m_coutSpecifique;
        std::vector <Capacite> m_capacites;
        std::vector <Creature*> m_estDefenduPar;
	
    public :
        Creature (std::string nom, std::string type, int const basedEndurance ,int const basedForce, int endurance, 
        int force, int coutQuelconque, std::vector <std::string> coutSpecifique, std::vector <Capacite> capacites);
        virtual ~Creature();
        std::string getNom();
        std::string getType();
        int getBasedEndurance();
        int getBasedForce();
        int getEndurance();
        int getForce();
        int getCoutQuelconque();
        bool getDegagee();
        void addDefenseur(Creature* creature);
        std::vector <std::string> getCoutSpecifique();
        std::vector <Capacite> getCapacites();

        void setDegagee(bool estDegagee);
        void setForce(int force);
        void setEndurance(int endurance);
        bool getCreature();
        bool getAttaque();
        std::vector <Creature*> getEstDefenduPar();

        void setAttaque(bool attaque);
        void swap(int pos1, int pos2);
        
};

#endif