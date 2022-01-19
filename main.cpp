// #ifndef PERSONNE_HPP
// #define PERSONNE_HPP
#include "Creature.hpp"
#include "Deck.hpp"
#include "Joueur.hpp"
#include "Affiche.hpp"


int main(){
    std::vector<Terrain::land> coutSpe = {Terrain::PLAINE};

    
    Capacite vol = Capacite((std::string)"Vol", (std::string)"Il Vol");
    std::vector<Capacite> capa = {vol};
    
    Creature* crea = new Creature((std::string)"Le roi dieux", (std::string)"ange", 2, 2, 0, coutSpe, capa); 
    Creature* crea1 = new Creature((std::string)"Le roi dieux1", (std::string)"ange", 2, 2, 0, coutSpe, capa); 
    Creature* crea2 = new Creature((std::string)"Le roi dieux2", (std::string)"ange", 2, 2, 0, coutSpe, capa); 
    Creature* crea3 = new Creature((std::string)"Le roi dieux3", (std::string)"ange", 2, 2, 0, coutSpe, capa); 
    Creature* crea4 = new Creature((std::string)"Le roi dieux4", (std::string)"ange", 2, 2, 0, coutSpe, capa); 
    Creature* crea5 = new Creature((std::string)"Le roi dieux5", (std::string)"ange", 2, 2, 0, coutSpe, capa); 
    Creature* crea6 = new Creature((std::string)"Le roi dieux6", (std::string)"ange", 2, 2, 0, coutSpe, capa); 
    Creature* crea7 = new Creature((std::string)"Le roi dieux7", (std::string)"ange", 2, 2, 0, coutSpe, capa); 
    Creature* crea8 = new Creature((std::string)"Le roi dieux8", (std::string)"ange", 2, 2, 0, coutSpe, capa); 
    Creature* crea9 = new Creature((std::string)"Le roi dieux9", (std::string)"ange", 2, 2, 0, coutSpe, capa); 
    Terrain* terr1 = new Terrain(Terrain::PLAINE);
    Terrain* terr2 = new Terrain(Terrain::PLAINE);
    Terrain* terr3 = new Terrain(Terrain::PLAINE);
    Terrain* terr4 = new Terrain(Terrain::PLAINE);
    Terrain* terr5 = new Terrain(Terrain::PLAINE);
    Terrain* terr6 = new Terrain(Terrain::PLAINE);

    
    
    std::vector<Carte*> deckVec = {crea, crea1, crea2, crea3, crea4, crea5, crea6, crea7, crea8, crea9,terr1,terr2,terr3,terr4,terr5,terr6};
    
    Deck* deck = new Deck(deckVec);
    
    Joueur* j1 = new Joueur(20, deck);
    Joueur* j2 = new Joueur(20, deck);

    j1->setNom("Joueur 1");
    j2->setNom("Joueur 2");

    EnJeu* enJeu = new EnJeu(j1, j2);

    enJeu->start(j1,j2);

return 0;

}
// #endif       dans chaque fichier