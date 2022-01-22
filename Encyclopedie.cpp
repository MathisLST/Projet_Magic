#include <iostream>
#include <cstdlib>
#include <vector>
#include "Encyclopedie.hpp"

Encyclopedie::Encyclopedie(){
    //std::vector<Carte*> m_encyclopedie;
    //std::vector<Deck*> m_decks; // vector de decks sous forme d'int (id des cartes dans l'encyclopedie)

    // Reference : Edition de base 2021

    // TERRAINS /* 0 a 4 */
    m_encyclopedie.push_back(new Terrain(Terrain::PLAINE));
    m_encyclopedie.push_back(new Terrain(Terrain::ILE));
    m_encyclopedie.push_back(new Terrain(Terrain::MARAIS));
    m_encyclopedie.push_back(new Terrain(Terrain::MONTAGNE));
    m_encyclopedie.push_back(new Terrain(Terrain::FORET));

    // CREATURES
    
    // PLAINE /* 5 a 29 */
    m_encyclopedie.push_back(new Creature("Chien de garde alpin", "chien", 2, 2, 1, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::VIGILANCE})));
    m_encyclopedie.push_back(new Creature("Choriste consacre", "humain et clerc", 1, 1, 0, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::LIENDEVIE})));
    m_encyclopedie.push_back(new Creature("Maitre du troupeau avemain", "oiseau et guerrier", 3, 4, 3, std::vector<Terrain::land>({Terrain::PLAINE, Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Ange pourfendeur", "ange", 5, 5, 3, std::vector<Terrain::land>({Terrain::PLAINE, Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL, Capacite::INITIATIVE, Capacite::LIENDEVIE}))); // existe aussi protection contre types de creatures
    m_encyclopedie.push_back(new Creature("Acolyte de Basri", "chat et clerc", 3, 2, 2, std::vector<Terrain::land>({Terrain::PLAINE, Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::LIENDEVIE})));
    m_encyclopedie.push_back(new Creature("Lieutenant de Basri", "humain et chevalier", 4, 3, 3, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::VIGILANCE}))); // protection multicolore
    m_encyclopedie.push_back(new Creature("Argousine celeste", "humain et clerc", 3, 2, 2, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Pegase de Concordia", "pegase", 3, 1, 1, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Pretresse du confinement", "humain et clerc", 2, 2, 1, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({}))); // flash
    m_encyclopedie.push_back(new Creature("Batailleur de l'aube", "licorne", 1, 3, 1, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Experte fauconniere", "humain et soldat", 3, 2, 3, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Voltigeur des bourrasques", "griffon", 2, 3, 3, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Bataillon improvise", "humain et soldat", 2, 3, 2, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Mangara, le diplomate", "humain et clerc", 4, 2, 3, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::LIENDEVIE})));
    m_encyclopedie.push_back(new Creature("Chef de la meute", "chien", 2, 2, 1, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Cabot turbulent", "chien", 4, 3, 3, std::vector<Terrain::land>({Terrain::PLAINE, Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Sacrelame aguerri", "humain et guerrier", 1, 3, 1, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Sauveur devoue", "chien", 1, 1, 0, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Frappeur de siege", "humain et soldat", 1, 1, 2, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::DOUBLEINITIATIVE})));
    m_encyclopedie.push_back(new Creature("Orateur des Cieux", "humain et clerc", 1, 1, 0, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::VIGILANCE, Capacite::LIENDEVIE})));
    m_encyclopedie.push_back(new Creature("Compagnon bouclier inebranlable", "nain et soldat", 3, 1, 0, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Veterane irascible", "humain et chevalier", 2, 1, 1, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Destrier valeureux", "licorne", 3, 3, 4, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::VIGILANCE})));
    m_encyclopedie.push_back(new Creature("Cheval aile de Vryn", "pegase", 1, 2, 2, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Remparts aux runes de garde", "mur", 3, 0, 2, std::vector<Terrain::land>({Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({Capacite::DEFENSEUR})));

    // ILE /* 30 a 49 */
    m_encyclopedie.push_back(new Creature("Barrin, archimage tolarian", "humain et sorcier", 2, 2, 1, std::vector<Terrain::land>({Terrain::ILE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Chapardeur fantomal", "esprit et gredin", 1, 2, 1, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Doyenne jeskai", "humain et moine", 2, 1, 1, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Planachutiste passionne", "humain et soldat", 1, 2, 1, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Voleuse de bibliotheque", "ondin et gredin", 2, 1, 2, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Chanteuse de mistral", "sirene", 2, 2, 2, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Baleine pourchassee", "baleine", 8, 8, 5, std::vector<Terrain::land>({Terrain::ILE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Luminesprit errant", "esprit", 2, 3, 3, std::vector<Terrain::land>({Terrain::ILE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Geist ferre", "esprit", 2, 2, 1, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Sourcier des epaves", "ondin et sorcier", 3, 3, 3, std::vector<Terrain::land>({Terrain::ILE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Megalodon a piquants", "requin", 7, 5, 5, std::vector<Terrain::land>({Terrain::ILE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Entite ailorage", "elemental", 3, 3, 3, std::vector<Terrain::land>({Terrain::ILE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Protegee de Tefeiri", "humain et sorcier", 3, 2, 2, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Ecumeur du ressac", "drakon", 3, 2, 3, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Kraken de Tolaria", "kraken", 6, 4, 4, std::vector<Terrain::land>({Terrain::ILE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Anima de grimoire", "esprit", 3, 3, 3, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Arcaniste vodalian", "ondin et sorcier", 3, 1, 1, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Eveilleur des vagues", "baleine", 7, 7, 5, std::vector<Terrain::land>({Terrain::ILE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Mur des runes", "mur", 4, 0, 0, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({Capacite::DEFENSEUR})));
    m_encyclopedie.push_back(new Creature("Crabe piecevoeu", "crabe", 5, 2, 3, std::vector<Terrain::land>({Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));

    // MARAIS /* 50 a 72 */
    m_encyclopedie.push_back(new Creature("Receptacle de l'archifielleux", "humain et clerc", 1, 1, 0, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({Capacite::LIENDEVIE})));
    m_encyclopedie.push_back(new Creature("Goinfre de sang", "vampire", 3, 4, 4, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({Capacite::LIENDEVIE})));
    m_encyclopedie.push_back(new Creature("Zombie emprisonne", "zombie", 3, 2, 2, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Larve charognarde", "insecte", 5, 0, 3, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Guetteur de la crypte", "horreur", 4, 3, 3, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Thallide a fleurs de mort", "fongus", 2, 3, 2, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Diablotin fetide", "diablotin", 2, 1, 1, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Semeur de tenebres", "horreur", 6, 8, 5, std::vector<Terrain::land>({Terrain::MARAIS, Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Gourmet d'entrailles", "demon", 5, 5, 4, std::vector<Terrain::land>({Terrain::MARAIS, Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Pestecroc cagoulard", "serpent", 4, 1, 2, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Kaervek, le malveillant", "humain et psychagogue", 2, 3, 2, std::vector<Terrain::land>({Terrain::MARAIS, Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Flibustiere a voile volante", "humain et pirate", 2, 1, 1, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Devot de Liliana", "humain et psychagogue", 3, 2, 2, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Porte-etendard de liliana", "zombie et chevalier", 1, 3, 2, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Intendant de Liliana", "zombie", 2, 1, 0, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Garde noire masquee", "humain et gredin", 1, 2, 1, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Guivre du massacre", "guivre", 5, 6, 3, std::vector<Terrain::land>({Terrain::MARAIS, Terrain::MARAIS, Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Goule piquee a l'argent", "zombie et vampire", 1, 3, 2, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Archer squelette", "squelette", 3, 3, 3, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Filouteuse de taverne", "humain et gredin", 2, 2, 1, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Argousine de la guilde des voleurs", "humain et gredin", 1, 1, 0, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Vito, Epine de la Rose du crepuscule", "vampire et clerc", 3, 1, 2, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Cadavre ambulant", "zombie", 2, 2, 1, std::vector<Terrain::land>({Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));

    // MONTAGNE /* 73 a 94 */
    m_encyclopedie.push_back(new Creature("Shamane a crecelle de guerre", "gobelin et shamane", 2, 2, 3, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Chien d'eclair", "elemental et chien", 2, 2, 2, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({Capacite::HATE}))); // celerite normalement
    m_encyclopedie.push_back(new Creature("Brute de la fosse aux ossements", "cyclope", 5, 4, 4, std::vector<Terrain::land>({Terrain::MONTAGNE, Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({Capacite::MENACE})));
    m_encyclopedie.push_back(new Creature("Taquineur effronte", "gobelin", 1, 1, 4, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({Capacite::INDESTRUCTIBLE})));
    m_encyclopedie.push_back(new Creature("Incinerateur de Chandra", "elemental", 6, 6, 5, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({Capacite::PIETINEMENT})));
    m_encyclopedie.push_back(new Creature("Molosse de magma de Chandra", "elemental et chien", 2, 2, 1, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Pyrolin de Chandra", "elemental et lezard", 3, 1, 1, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Fouineur flagrant", "gobelin et gredin", 2, 2, 0, std::vector<Terrain::land>({Terrain::MONTAGNE, Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Gadrak, le fleau des couronnes", "dragon", 4, 5, 2, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Incendiaire gobelin", "gobelin et shamane", 1, 1, 0, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Bouffon ravageur", "diable", 5, 5, 4, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Immolateur pyrocoeur", "humain et sorcier", 2, 2, 1, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Chatieur escouflenfer", "dragon", 6, 6, 5, std::vector<Terrain::land>({Terrain::MONTAGNE, Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Fielleux croque pieds", "diable", 1, 2, 1, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({Capacite::PIETINEMENT})));
    m_encyclopedie.push_back(new Creature("Cabot ignescent", "elemental et chien", 2, 1, 1, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Augure cinétique", "humain et shamane", 4, 3, 3, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({Capacite::PIETINEMENT}))); // attaque depend normalement de son passif
    m_encyclopedie.push_back(new Creature("Ogre onakke", "ogre et guerrier", 2, 4, 2, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Diables brulegoudron", "diable", 3, 3, 4, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Anomalie englousorts", "anomalie", 2, 2, 2, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Soubira, cavaniere des Tulzidi", "humain et shamane", 3, 2, 2, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({Capacite::HATE}))); // celerite normalement
    m_encyclopedie.push_back(new Creature("Terreur des pics", "dragon", 4, 5, 3, std::vector<Terrain::land>({Terrain::MONTAGNE, Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));
    m_encyclopedie.push_back(new Creature("Ogre des tourelles", "ogre et guerrier", 3, 4, 3, std::vector<Terrain::land>({Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({Capacite::PORTEE})));

    //FORET /* 95 a 119 */
    m_encyclopedie.push_back(new Creature("Azusa, egaree mais en quete", "humain et moine", 2, 1, 2, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Chene aux poings noueux", "sylvin", 3, 2, 2, std::vector<Terrain::land>({Terrain::FORET, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Pisteur de la canopee", "chat", 2, 4, 3, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Gueuleffroi colossal", "dinosaure", 6, 6, 4, std::vector<Terrain::land>({Terrain::FORET, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({Capacite::PIETINEMENT})));
    m_encyclopedie.push_back(new Creature("Tyrannodon somnolant", "dinosaure", 3, 3, 1, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({Capacite::DEFENSEUR})));
    m_encyclopedie.push_back(new Creature("Ancetre gargaroth", "bete", 6, 6, 3, std::vector<Terrain::land>({Terrain::FORET, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({Capacite::VIGILANCE, Capacite::PORTEE, Capacite::PIETINEMENT})));
    m_encyclopedie.push_back(new Creature("Souverain felin", "chat", 3, 2, 2, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Empathe farouche", "elfe", 1, 1, 2, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Corneboyaux de Garruk", "bete", 3, 7, 4, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Annonciateur de Garruk", "bete", 3, 4, 1, std::vector<Terrain::land>({Terrain::FORET, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({Capacite::PROTECTIONNOIR})));
    m_encyclopedie.push_back(new Creature("Sage noueux", "sylvin et druide", 4, 4, 3, std::vector<Terrain::land>({Terrain::FORET, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({Capacite::PORTEE})));
    m_encyclopedie.push_back(new Creature("Jolrael, recluse de la Mwonvouli", "humain et druide", 2, 1, 1, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Visionnaire de Llanowar", "elfe et druide", 2, 2, 2, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Dilophosaure hargneux", "dinosaure", 2, 2, 3, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({Capacite::CONTACTMORTEL})));
    m_encyclopedie.push_back(new Creature("Lierre de herse", "plante et mur", 3, 0, 0, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({Capacite::DEFENSEUR})));
    m_encyclopedie.push_back(new Creature("Mitouard de la fierte", "chat", 1, 2, 2, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Dryade quirionaise", "dryade", 1, 1, 1, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Meurtrisseur a dents de sabre", "chat", 3, 3, 3, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Limon necrophage", "limon", 2, 2, 1, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Franc-tireuse de Cielouvert", "elfe et archer", 2, 1, 0, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({Capacite::PORTEE})));
    m_encyclopedie.push_back(new Creature("Fileuse de collet", "araignee", 3, 1, 1, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({Capacite::PORTEE})));
    m_encyclopedie.push_back(new Creature("Tisseuse de sporetoile", "araignee", 4, 1, 2, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({Capacite::PORTEE, Capacite::PROTECTIONBLEU})));
    m_encyclopedie.push_back(new Creature("Brontodonte farouche", "dinosaure", 4, 3, 1, std::vector<Terrain::land>({Terrain::FORET, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Cochon truffier", "sanglier", 2, 2, 2, std::vector<Terrain::land>({Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Garde des bois", "sylvin", 7, 5, 4, std::vector<Terrain::land>({Terrain::FORET, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({Capacite::VIGILANCE})));

    // MIXTE /* 120 a 130 */
    m_encyclopedie.push_back(new Creature("Maitre-chien alpin", "humain et guerrier", 2, 2, 0, std::vector<Terrain::land>({Terrain::MONTAGNE, Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Mentor du conclave", "centaure et clerc", 2, 2, 0, std::vector<Terrain::land>({Terrain::FORET, Terrain::PLAINE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Belliciste de la flotte implacable", "orque et pirate", 3, 3, 1, std::vector<Terrain::land>({Terrain::MARAIS, Terrain::MONTAGNE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Patricienne indulgente", "vampire et noble", 4, 1, 1, std::vector<Terrain::land>({Terrain::PLAINE, Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({Capacite::VOL, Capacite::LIENDEVIE})));
    m_encyclopedie.push_back(new Creature("Vengeur sangfeuille", "elemental et druide", 3, 4, 2, std::vector<Terrain::land>({Terrain::MONTAGNE, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Coatl aux ecailles de sapience", "serpent", 2, 2, 1, std::vector<Terrain::land>({Terrain::FORET, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Niambi, oratrice respectee", "humain et clerc", 1, 2, 0, std::vector<Terrain::land>({Terrain::PLAINE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Raccomodeuse obsessionnelle", "humain et sorcier", 3, 0, 1, std::vector<Terrain::land>({Terrain::ILE, Terrain::MARAIS}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Radha, coeur de Keld", "elfe et guerrier", 3, 3, 1, std::vector<Terrain::land>({Terrain::MONTAGNE, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Assassins jumelames", "elfe et assassin", 4, 5, 3, std::vector<Terrain::land>({Terrain::MARAIS, Terrain::FORET}), std::vector<Capacite::capaciteStatique>({})));
    m_encyclopedie.push_back(new Creature("Gardien des spheres", "oiseau et sorcier", 2, 2, 0, std::vector<Terrain::land>({Terrain::PLAINE, Terrain::ILE}), std::vector<Capacite::capaciteStatique>({Capacite::VOL})));

    // CARTES TEST /* 131 a ... */



    // Preparation decks
    Deck* deckBlanc = new Deck("Deck Blanc", std::vector<int>({0,0,0,0,0,0,0,0,0,0,0,0,5,5,6,6,8,13,13,14,14,16,16,22,22,24,24,27,29,29}), this);
    Deck* deckBleu = new Deck("Deck Bleu", std::vector<int>({1,1,1,1,1,1,1,1,1,1,1,1,31,31,33,33,35,35,36,37,38,38,39,40,42,42,43,44,48,49}), this);
    Deck* deckNoir = new Deck("Deck Noir", std::vector<int>({2,2,2,2,2,2,2,2,2,2,2,2,50,50,51,52,52,53,54,55,57,58,58,59,61,61,62,67,68,72}), this);
    Deck* deckRouge = new Deck("Deck Rouge", std::vector<int>({3,3,3,3,3,3,3,3,3,3,3,3,73,74,74,75,76,76,77,82,82,85,87,87,88,89,89,90,93,94}), this);
    Deck* deckVert = new Deck("Deck Vert", std::vector<int>({4,4,4,4,4,4,4,4,4,4,4,4,98,99,99,103,104,105,107,109,109,110,111,115,115,116,117,117,118,119}), this);


    m_decks.push_back(deckBlanc);
    m_decks.push_back(deckBleu);
    m_decks.push_back(deckNoir);
    m_decks.push_back(deckRouge);
    m_decks.push_back(deckVert);
}

Encyclopedie::~Encyclopedie(){
    for(Carte* carte : m_encyclopedie){
        delete carte;
    }
}

std::vector<Carte*> Encyclopedie::getEncyclopedie(){
    return m_encyclopedie;
}

Carte* Encyclopedie::getCarte(int i) throw(){
    if(i > -1 && i < (int)m_encyclopedie.size())
        return m_encyclopedie.at(i);
    else
        throw std::invalid_argument("index de carte invalide"); 
    
}

Deck* Encyclopedie::choisirDeck(){
    // gerer affichage decks dans la console au moment de chosir
    bool deckValide = false;
    int indexDeck;
    while(!deckValide){
        std::cout << "Veuillez choisir un deck. 1-" << m_decks.size() << std::endl;
        while(!(std::cin >> indexDeck)){
            std::cout << "Numero de deck invalide, veuillez rentrer un entier !" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Veuillez choisir un deck. 1-" << m_encyclopedie.size() << std::endl;
        }
        if(indexDeck > -1 && indexDeck < (int)m_decks.size()){
            deckValide = true;
        }
    }
    return m_decks.at(indexDeck-1);



}
