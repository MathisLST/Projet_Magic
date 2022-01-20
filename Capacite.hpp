#ifndef CAPACITE_HPP
#define CAPACITE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Carte.hpp"

class Capacite{
    public :
        enum capaciteStatique{
            VOL = 0,
            PORTEE,
            VIGILANCE,
            CONTACTMORTEL,
            DEFENSEUR,
            INITIATIVE,
            DOUBLEINITIATIVE,
            HATE,
            IMBLOCABLE,
            LIENDEVIE,
            MENACE,
            PIETINEMENT,
            PROTECTIONBLANC,
            PROTECTIONBLEU,
            PROTECTIONNOIR,
            PROTECTIONROUGE,
            PROTECTIONVERT,
            INDESTRUCTIBLE // ajoute
        };
        Capacite(std::string nom, std::string description);
        std::string getNom();
        std::string getDescription();
    private :
        std::string m_nom;
        std::string m_description;
    
};

#endif