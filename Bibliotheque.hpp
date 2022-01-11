#ifndef BIBLIOTHEQUE_HPP
#define BIBLIOTHEQUE_HPP

#include <iostream>
#include <cstdlib>
#include "Carte.hpp"

class Bibliotheque {
    private :
        std::vector<Carte> m_bibliotheque;

    public :
        Bibliotheque();
        ~Bibliotheque();
        const Bibliotheque& getBibliotheque();

};

#endif