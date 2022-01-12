#ifndef CARTE_HPP
#define CARTE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

class Carte {
    private :
        bool m_degagee;
    
    public :
       virtual bool getDegagee() = 0;
};

#endif