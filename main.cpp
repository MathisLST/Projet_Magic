// #ifndef PERSONNE_HPP
// #define PERSONNE_HPP
#include "Creature.hpp"
#include "Deck.hpp"
#include "Joueur.hpp"
#include "Affiche.hpp"


int main(){
    std::vector<Terrain::land> coutSpe = {Terrain::PLAINE};

    /*
    Creature* crea = new Creature((std::string)"Le roi dieu", (std::string)"ange", 20, 2, 0, coutSpe, {Capacite::VOL}); 
    Creature* crea1 = new Creature((std::string)"Le roi dieu1", (std::string)"ange", 20, 2, 0, coutSpe, {Capacite::VOL}); 
    Creature* crea2 = new Creature((std::string)"Le roi dieu2", (std::string)"ange", 20, 2, 0, coutSpe, {Capacite::VOL}); 
    Creature* crea3 = new Creature((std::string)"Le roi dieu3", (std::string)"ange", 2, 2, 0, coutSpe, {Capacite::VOL}); 
    Creature* crea4 = new Creature((std::string)"Le roi dieu4", (std::string)"ange", 2, 2, 0, coutSpe, {Capacite::VOL}); 
    Creature* crea5 = new Creature((std::string)"Le roi dieu5", (std::string)"ange", 2, 2, 0, coutSpe, {Capacite::VOL}); 
    Creature* crea6 = new Creature((std::string)"Le roi dieu6", (std::string)"ange", 2, 2, 0, coutSpe, {Capacite::VOL}); 
    Creature* crea7 = new Creature((std::string)"Le roi dieu7", (std::string)"ange", 2, 2, 0, coutSpe, {Capacite::VOL}); 
    Creature* crea8 = new Creature((std::string)"Le roi dieu8", (std::string)"ange", 2, 2, 0, coutSpe, {Capacite::VOL}); 
    Creature* crea9 = new Creature((std::string)"Le roi dieu9", (std::string)"ange", 2, 2, 0, coutSpe, {Capacite::VOL}); 
    */

    
    system("clear");
    std::vector<Carte*> deckVec = {new Creature("Maitre-chien alpin", "humain et guerrier", 2, 2, 0, std::vector<Terrain::land>({Terrain::MONTAGNE, Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})),
    new Creature("Mentor du conclave", "centaure et clerc", 2, 2, 0, std::vector<Terrain::land>({Terrain::FORET, Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})),
    new Creature("Belliciste de la flotte implacable", "orque et pirate", 3, 3, 1, std::vector<Terrain::land>({Terrain::MARAIS, Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})),
    new Creature("Patricienne indulgente", "vampire et noble", 4, 1, 1, std::vector<Terrain::land>({Terrain::PLAINE, Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({Capacite::VOL, Capacite::LIENDEVIE})),
    new Creature("Vengeur sangfeuille", "elemental et druide", 3, 4, 2, std::vector<Terrain::land>({Terrain::MONTAGNE, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})),
    new Creature("Coatl aux ecailles de sapience", "serpent", 2, 2, 1, std::vector<Terrain::land>({Terrain::FORET, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})),
    new Creature("Niambi, oratrice respectee", "humain et clerc", 1, 2, 0, std::vector<Terrain::land>({Terrain::PLAINE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})),
    new Creature("Raccomodeuse obsessionnelle", "humain et sorcier", 3, 0, 1, std::vector<Terrain::land>({Terrain::ILE, Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})),
    new Creature("Radha, coeur de Keld", "elfe et guerrier", 3, 3, 1, std::vector<Terrain::land>({Terrain::MONTAGNE, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})),
    new Creature("Assassins jumelames", "elfe et assassin", 4, 5, 3, std::vector<Terrain::land>({Terrain::MARAIS, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})),
    new Creature("Gardien des spheres", "oiseau et sorcier", 2, 2, 0, std::vector<Terrain::land>({Terrain::PLAINE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})),
    new Terrain(Terrain::PLAINE),
    new Terrain(Terrain::MONTAGNE),
     new Terrain(Terrain::MARAIS),
     new Terrain(Terrain::FORET),
     new Terrain(Terrain::ILE),
     new Terrain(Terrain::PLAINE)};
    
    Deck* deck = new Deck(deckVec);
    
    Joueur* j1 = new Joueur(20, deck);
    Joueur* j2 = new Joueur(20, deck);

    std::string nomJ1;
    std::string nomJ2;

    std::cout << "Joueur 1 veuillez choisir un Pseudo." << std::endl;
    std::cin >> nomJ1;
    j1->setNom(nomJ1);

    std::cout << "Joueur 2 veuillez choisir un Pseudo." << std::endl;
    std::cin >> nomJ2;
    j2->setNom(nomJ2);

    EnJeu* enJeu = new EnJeu(j1, j2);

    enJeu->start(j1,j2);

return 0;

}
// #endif       dans chaque fichier