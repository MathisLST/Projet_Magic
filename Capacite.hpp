#ifndef CAPACITE_HPP
#define CAPACITE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Carte.hpp"

class Capacite{
    private :
        std::string m_nom;
        std::string m_description;
    public :
        Capacite(std::string nom, std::string description);
        std::string getNom();
        std::string getDescription();
};

#endif