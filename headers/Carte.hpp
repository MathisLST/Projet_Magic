#ifndef CARTE_HPP
#define CARTE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

class Carte {
    protected :
        bool m_degagee;
        bool m_creature;
    
    public :
        virtual ~Carte(){};
        virtual bool getDegagee() = 0;
       
        virtual void setDegagee(bool estDegagee) = 0;

        virtual bool getCreature() = 0;
};


#endif