#include <iostream>
#include <cstdlib>
#include <vector>
#include "Joueur.hpp"


        Joueur::Joueur(){}

        Joueur::Joueur (int pv, Deck deck){
            m_pv = pv;
            m_deck = deck;
            m_bibliotheque = Bibliotheque(deck);
        }

        int Joueur::getPV(){
            return m_pv;
        }

        Deck& Joueur::getDeck(){
            return m_deck;
        }

        std::vector<Carte> Joueur::getCimetiere(){
            return m_cimetiere;
        }
        std::vector<Carte> Joueur::getMain(){
            return m_main;
        }

        Bibliotheque& Joueur::getBibliotheque(){
            return m_bibliotheque;
        }

        
        void Joueur::distribuer(){
            for (int i = 0; i < 7; i++ ){
                m_main.push_back(m_bibliotheque.getBibliotheque().at(0));
                m_bibliotheque.getBibliotheque().erase(m_bibliotheque.getBibliotheque().begin());
            }
        }
        