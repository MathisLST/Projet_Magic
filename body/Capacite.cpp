#include <iostream>
#include <cstdlib>
#include <vector>
#include "../headers/Capacite.hpp"


Capacite::Capacite(capaciteStatique capaciteStatique){
    m_capaciteStatique = capaciteStatique;
}

Capacite::~Capacite(){}


const char* Capacite::capaToString(capaciteStatique capacite, bool abregee){
    switch (capacite)
    {
        case Capacite::VOL: if (!abregee) {return "VOL" ;} else return "Vo";
        case Capacite::PORTEE: if (!abregee) return "PORTEE"; else return "Po";
        case Capacite::VIGILANCE: if (!abregee) return "VIGILANCE"; else return "Vi";
        case Capacite::CONTACTMORTEL: if (!abregee) return "CONTACTMORTEL"; else return "CM";
        case Capacite::DEFENSEUR: if (!abregee) return "DEFENSEUR"; else return "D"; 
        case Capacite::HATE: if (!abregee) return "HATE"; else return "H"; 
        case Capacite::IMBLOCABLE: if (!abregee) return "IMBLOCABLE"; else return "Im"; 
        case Capacite::LIENDEVIE: if (!abregee) return "LIENDEVIE"; else return "LV";
        case Capacite::MENACE: if (!abregee) return "MENACE"; else return "M";
        case Capacite::PIETINEMENT: if (!abregee) return "PIETINEMENT"; else return "Pi";
        case Capacite::PROTECTIONBLANC: if (!abregee) return "PROTECTIONBLANC"; else return "PBlanc";
        case Capacite::PROTECTIONBLEU: if (!abregee) return "PROTECTIONBLEU"; else return "PBleu";
        case Capacite::PROTECTIONNOIR: if (!abregee) return "PROTECTIONNOIR"; else return "PN";
        case Capacite::PROTECTIONROUGE: if (!abregee) return "PROTECTIONROUGE"; else return "PR";
        case Capacite::PROTECTIONVERT: if (!abregee) return "PROTECTIONVERT"; else return "PV";
        case Capacite::INITIATIVE: if (!abregee) return "⚠️INITIATIVE⚠️"; else return "In";
        case Capacite::DOUBLEINITIATIVE: if (!abregee) return "⚠️DOUBLEINITIATIVE⚠️"; else return "DIn";
        default: throw std::invalid_argument("Unimplemented item");
    }
}