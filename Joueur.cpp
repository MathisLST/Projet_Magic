#include <iostream>
#include <cstdlib>
#include <vector>
#include "Joueur.hpp"
#include "Capacite.hpp"
#include "Creature.hpp"


        Joueur::Joueur(){}

        Joueur::Joueur (int pv, Deck* deck){
            
            m_pv = pv;
            m_deck = deck;
            m_bibliotheque = new Bibliotheque(m_deck);
            std::vector<Carte*> main;
            m_main = main;

        }

        Joueur::~Joueur(){}

        int Joueur::getPV(){
            return m_pv;
        }

        Deck* Joueur::getDeck(){
            return m_deck;
        }

        std::vector<Carte*> Joueur::getCimetiere(){
            return m_cimetiere;
        }
        std::vector<Carte*> Joueur::getMain(){
            return m_main;
        }

        Bibliotheque* Joueur::getBibliotheque(){
            return m_bibliotheque;
        }
        std::vector<Terrain*> Joueur::getLTerrain(){
            return m_LTerrain;
        }

        std::vector<Creature*> Joueur::getLCreature(){
            return m_LCreature;
        }
        
        void Joueur::piocher(int nbrCartes){

            for (int i = 0; i < nbrCartes; i++ ){
                
                m_main.push_back(m_bibliotheque->getBibliotheque().at(0));
                m_bibliotheque->pop_front();
            }
        }

        void Joueur::melanger(){
            m_bibliotheque->melanger();
        }
        