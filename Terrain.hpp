#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

class Terrain : public Carte {
    private :
        std::string m_type;

    public :
        Terrain (std::string type);

        std::string getType();
        
};

#endif