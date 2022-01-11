#include <iostream>
#include <cstdlib>
#include <vector>
#include "Joueur.hpp"


        Joueur::Joueur (int pv, Deck deck){
            m_pv = pv;
            m_deck = deck;
            //m_bibliotheque* = new Bibliotheque(deck); 
        }

        int Joueur::getPV(){
            return m_pv;
        }

        Deck Joueur::getDeck(){
            return m_deck;
        }

        std::vector<Carte&> Joueur::getCimetiere(){
            return m_cimetiere;
        }
        std::vector<Carte&> Joueur::getMain(){
            return m_main;
        }
        /*
        void Joueur::distribuer(){
            for (int x = 0; x < 7; i++ ){
                m_main.push_back()
            }
        }
        */