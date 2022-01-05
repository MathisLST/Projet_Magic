#include <iostream>
#include <cstdlib>
#include <vector>
#include "Terrain.hpp"
#include "Capacite.hpp"



class Creature : public Carte {
    private :
        std::string m_nom;
        std::string m_type;
        int const m_basedEndurance;
        int const m_basedForce;
        int m_endurance;
        int m_force;
        int m_coutQuelconque;
        std::vector < Terrain > m_coutSpecifique;
        std::vector < Capacite > m_capacites;
	
    public :
        Creature (std::string nom, std::string type, int const basedEndurance ,int const basedForce, int endurance, int force, int coutQuelconque, std::vector < Terrain > coutSpecifique, std::vector < Capacite > capacites);

        std::string getNom();
        std::string getType();
        int getBasedEndurance();
        int getBasedForce();
        int getEndurance();
        int getForce();
        int getCoutQuelconque();
        std::vector < Terrain > getCoutSpecifique();
        std::vector < Capacite > getCapacites();
        
};