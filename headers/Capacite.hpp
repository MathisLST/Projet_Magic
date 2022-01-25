#ifndef CAPACITE_HPP
#define CAPACITE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "../headers/Carte.hpp"

class Capacite{
    public :
        // liste des capacites statiques implementees
        enum capaciteStatique{
            VOL = 0,
            PORTEE,
            VIGILANCE,
            CONTACTMORTEL,
            DEFENSEUR,
            INITIATIVE,         // TODO
            DOUBLEINITIATIVE,   // TODO
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

        // Prend en paramètre une capacite et renvoie sa facon de l'afficher sous forme de string
        static const char* capaToString(capaciteStatique capacite, bool abregee = false);

    private : 
        capaciteStatique m_capaciteStatique;
    
};

#endif