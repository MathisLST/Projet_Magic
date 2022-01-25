#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Deck.hpp"

Deck::Deck(){}


Deck::Deck(std::string nom,std::vector<int> deck, Encyclopedie* encyclopedie){
    m_nom = nom;
    m_deckIndex = deck;
    m_encyclopedie = encyclopedie;
}
/*
Deck::Deck (std::string nom, std::vector<Carte*> deck, Encyclopedie* encyclopedie){ // ici encyclopedie pas tres utile en arguments
    m_nom = nom;
    std::vector<Carte*> m_deck;
    m_deck = deck;
    m_encyclopedie = encyclopedie;
} */

Deck::~Deck(){
    for(Carte* carte : m_deck){
        delete carte;
    }
}

std::vector<int> Deck::getDeckIndex(){
    return m_deckIndex;
}

std::vector<Carte*> Deck::getDeck(){
    return m_deck;
}

std::string Deck::getNom(){
    return m_nom;
}

Encyclopedie* Deck::getEncyclopedie(){
    return m_encyclopedie;
}

void Deck::ajouterCarte(int idCarte){
    if(idCarte > -1 && idCarte < (int)m_encyclopedie->getEncyclopedie().size()){
            Carte* carteref = m_encyclopedie->getCarte(idCarte);
            if(carteref->getCreature() == true){
                Creature* creature = dynamic_cast<Creature*>(carteref);
                m_deck.push_back(new Creature(creature->getNom(), creature->getType(), creature->getBasedEndurance(), 
                    creature->getBasedForce(), creature->getCoutQuelconque(), creature->getCoutSpecifique(), creature->getCapacites()));
            }
            else{
                Terrain* terrain = dynamic_cast<Terrain*>(carteref);
                m_deck.push_back(new Terrain(terrain->getLand()));
            }
    }
    else
        std::cout << "La carte n°" << idCarte << " n'existe pas dans l'encyclopedie et n'a pas pu etre ajoutee" << std::endl; 
}

