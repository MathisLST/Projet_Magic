#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "../headers/Carte.hpp"
#include "../headers/Encyclopedie.hpp"

class Encyclopedie;
class Deck {
    private :
        std::string m_nom;
        std::vector<int> m_deckIndex;
        std::vector<Carte*> m_deck;
        Encyclopedie* m_encyclopedie;
    public :
        Deck();
        Deck (std::string nom, std::vector<int> deck, Encyclopedie* encyclopedie); // reference ?
        //Deck (std::string nom, std::vector<Carte*> deck, Encyclopedie* encyclopedie); //reference ?
        ~Deck();
        std::vector<int> getDeckIndex();
        std::vector<Carte*> getDeck();
        std::string getNom();
        Encyclopedie* getEncyclopedie();

        void ajouterCarte(int idCarte);

};

#endif