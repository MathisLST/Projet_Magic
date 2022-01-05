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
        void setBibliotheque(std::vector<Carte> cartes);

};