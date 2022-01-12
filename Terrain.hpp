#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Carte.hpp"

class Terrain : public Carte {
    private :
        std::string m_type;

    public :
        Terrain (std::string type);
        
        bool getDegagee();
        std::string getType();
        void setDegagee(bool estDegagee);
        
};

#endif