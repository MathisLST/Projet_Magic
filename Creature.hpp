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
        std::vector <Capacite::capaciteStatique> m_capacites;
        std::vector <Creature*> m_estDefenduPar;
        // contient le compte des terrains specifiques necessaires
        std::vector<int> m_cptCoutSpec;
        int m_coutTotal;
        std::vector <Terrain::land> m_coutSpecifique;

	
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
        void addDefenseur(Creature* creature);
        std::vector <Terrain::land> getCoutSpecifique(); //voir si on modifie la facon de compter les terrains
        std::vector <Capacite::capaciteStatique> getCapacites();

        void setDegagee(bool estDegagee);
        void setForce(int force);
        void setEndurance(int endurance);
        bool getCreature();
        bool getAttaque();
        std::vector <Creature*> getEstDefenduPar();

        void setAttaque(bool attaque);
        void swap(int pos1, int pos2);
        std::vector<int> getCptCoutSpec();
        int getCoutTotal();
};

#endif