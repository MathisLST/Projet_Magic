#ifndef BIBLIOTHEQUE_HPP
#define BIBLIOTHEQUE_HPP

#include <iostream>
#include <cstdlib>
#include "../headers/Carte.hpp"
#include "../headers/Deck.hpp"

class Bibliotheque {
    private :
        std::vector<Carte*> m_bibliotheque;

    public :
        Bibliotheque();
        Bibliotheque(Deck* deck);
        ~Bibliotheque();
        std::vector<Carte*> getBibliotheque();
        void pop_front();
        void melanger();

};

#endif