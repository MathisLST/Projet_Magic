#ifndef CARTE_HPP
#define CARTE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

class Carte {
    protected :
        bool m_degagee;
    
    public :
       virtual bool getDegagee() = 0;
       virtual void setDegagee(bool estDegagee) = 0;
};

#endif