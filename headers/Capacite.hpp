#ifndef CAPACITE_HPP
#define CAPACITE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "../headers/Carte.hpp"

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
            PROTECTIONVERT
        };

        Capacite(capaciteStatique capaciteStatique);
        ~Capacite();

        capaciteStatique getCapaciteStatique();

        static const char* capaToString(capaciteStatique capacite, bool abregee) throw();

    private : 
        capaciteStatique m_capaciteStatique;
    
};

#endif