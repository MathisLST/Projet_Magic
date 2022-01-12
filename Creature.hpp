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
        std::vector <std::string> m_coutSpecifique;
        std::vector <Capacite> m_capacites;
	
    public :
        Creature (std::string nom, std::string type, int const basedEndurance ,int const basedForce, int endurance, 
        int force, int coutQuelconque, std::vector <std::string> coutSpecifique, std::vector <Capacite> capacites);

        std::string getNom();
        std::string getType();
        int getBasedEndurance();
        int getBasedForce();
        int getEndurance();
        int getForce();
        int getCoutQuelconque();
        bool getDegagee();
        std::vector <std::string> getCoutSpecifique();
        std::vector <Capacite> getCapacites();

        void setDegagee(bool estDegagee);
        bool getCreature();
        
};

#endif