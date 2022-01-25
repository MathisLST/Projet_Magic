#include "Creature.hpp"
#include "Deck.hpp"
#include "Joueur.hpp"
#include "Affiche.hpp"


int main(){
    
    system("clear");

    Encyclopedie* encyclopedie = new Encyclopedie();
    
    std::string nomJ1;
    std::string nomJ2;

    std::cout << "Joueur 1 veuillez choisir un Pseudo." << std::endl;
    std::cin >> nomJ1;

    std::cout << "Joueur 2 veuillez choisir un Pseudo." << std::endl;
    std::cin >> nomJ2;

    Joueur* j1 = new Joueur(20, nomJ1, encyclopedie);
    Joueur* j2 = new Joueur(20, nomJ2, encyclopedie);

    EnJeu* enJeu = new EnJeu(j1, j2);

    enJeu->start(j1,j2);

return 0;

}