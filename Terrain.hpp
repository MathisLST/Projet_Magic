#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Carte.hpp"

class Terrain : public Carte {
    public :
        enum land {
            PLAINE = 0,
            ILE,
            MARAIS,
            MONTAGNE,
            FORET
        };
        
        
        Terrain(land landType);
        virtual ~Terrain();
        bool getDegagee();
       
        void setDegagee(bool estDegagee);
        bool getCreature();

        land getLand();
        int getLandIndex();
        static const char* landToString(int l, bool abregee = false) throw();

    private :
        

        land m_land;

    
};

#endif