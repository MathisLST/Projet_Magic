#ifndef CARTE_HPP
#define CARTE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

class Carte {
    protected :
        // booléen true si la carte n'est pas engagee, false sinon
        bool m_degagee;
        // booléen true si la carte est une creature, false si c'est un terrain
        bool m_creature;
    
    public :
        virtual ~Carte(){};
        virtual bool getDegagee() = 0;
       
        virtual void setDegagee(bool estDegagee) = 0;

        virtual bool getCreature() = 0;
};


#endif