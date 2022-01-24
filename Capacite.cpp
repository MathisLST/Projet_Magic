#include <iostream>
#include <cstdlib>
#include <vector>
#include "Capacite.hpp"


Capacite::Capacite(capaciteStatique capaciteStatique){
    m_capaciteStatique = capaciteStatique;
}

Capacite::~Capacite(){}


const char* Capacite::capaToString(capaciteStatique capacite, bool abregee) throw(){
    switch (capacite)
    {
        case Capacite::VOL: if (!abregee) {return "VOL" ;} else return "Vo";
        case Capacite::PORTEE: if (!abregee) return "PORTEE"; else return "P";
        case Capacite::VIGILANCE: if (!abregee) return "VIGILANCE"; else return "Vi";
        case Capacite::CONTACTMORTEL: if (!abregee) return "CONTACTMORTEL"; else return "CM";
        case Capacite::DEFENSEUR: if (!abregee) return "DEFENSEUR"; else return "D"; 
        case Capacite::HATE: if (!abregee) return "HATE"; else return "H"; 
        case Capacite::IMBLOCABLE: if (!abregee) return "IMBLOCABLE"; else return "I"; 
        case Capacite::LIENDEVIE: if (!abregee) return "LIENDEVIE"; else return "LV";
        case Capacite::MENACE: if (!abregee) return "MENACE"; else return "M";
        default: throw std::invalid_argument("Unimplemented item");
    }
}