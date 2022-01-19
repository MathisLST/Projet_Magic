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
            m_nom = "";
            m_cptTerrainPrets = std::vector<int> (5,0);
            m_totalTerrainsPrets = 0;

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

        std::string Joueur::getNom(){
            return m_nom;
        }

        bool Joueur::setPv(int pv){
            if( m_pv - pv > 0){
                return true;
            }else{
                return false;
            }
        }

        void Joueur::setNom(std::string nom){
            m_nom = nom;
        }
        

        void Joueur::addDefenseur(int pos, Creature* creature){
            m_LCreature.at(pos)->addDefenseur(creature);
        }
        
        bool Joueur::piocher(int nbrCartes){

            for (int i = 0; i < nbrCartes; i++ ){
                if ((int)m_bibliotheque->getBibliotheque().size() > 0){
                    m_main.push_back(m_bibliotheque->getBibliotheque().at(0));
                    m_bibliotheque->pop_front();
                }else{
                    return false;
                }
            }
            return true;
        }

        void Joueur::melanger(){
            m_bibliotheque->melanger();
        }
        
        void Joueur::desengager(){
            for(Carte* carte : m_LCreature){
                carte->setDegagee(true);
            }
            for(Carte* carte : m_LTerrain){
                carte->setDegagee(true);
            }
        }

        void Joueur::tropDeCartes(){
            
            while (m_main.size() > 7){
                int posCarte;
                std::cout << m_nom << " vous avez trop de cartes ! Laquelle voulez-vous defausser ? ";
                std::cin >> posCarte;
                std::cout << std::endl;
                //deplace la carte vers le cimetiere
                if(posCarte>0 && posCarte <= (int)m_main.size()){
                    m_cimetiere.push_back(m_main.at(posCarte - 1));
                    m_main.erase(m_main.begin()+posCarte-1);
                    std::cout << "Carte defaussee !" << std::endl;
                }else{
                    std::cout << "La carte demandee n'est pas viable !" << std::endl;
                }
                
            }
        }

        void Joueur::remonterStatsCreatures(){
           for(Creature* creature : m_LCreature){
                creature->setForce(creature->getBasedForce());
                creature->setEndurance(creature->getBasedEndurance());
            }
        }

        bool Joueur::attaque(){
            std::string attaque;
            std::cout << m_nom << " voulez-vous attaquer ? ('t' pour tout, 'r' pour rien, ou 'c' pour choisir) ";
            std::cin >> attaque;
            std::cout << std::endl;

            bool choix = true;
            while(choix){
                if(attaque == "t"){
                    for(Creature* creature : m_LCreature){
                        if(creature->getDegagee()){
                            creature->setAttaque(true);
                            creature->setDegagee(false);
                        }
                    }
                    choix = false;
                    return true;

                }else if(attaque == "r"){
                    choix = false;
                    return false;

                }else if( attaque == "c"){
                    int carte;
                    while(choix){
                        std::cout << m_nom << " veuillez choisir avec qui vous voulez attaquer. ";
                        std::cin >> carte;
                        std::cout << std::endl;
                        if(carte > 0 && carte < (int)m_LCreature.size()){
                            if(m_LCreature.at(carte)->getDegagee()){
                                m_LCreature.at(carte)->setDegagee(false);
                                m_LCreature.at(carte)->setAttaque(true);
                            }
                        }else{
                            std::cout << "Erreur la carte n'est pas valable ! " << std::endl;
                        }
                        std::string continuer;
                        do{
                            std::cout << "Voulez-vous continuer ? ";
                            std::cin >> choix;
                            if(continuer == "o") choix = true;
                            else if(continuer == "n") return true;
                            else { std::cout << "Mauvaise entree !" << std::endl;}

                        } while (continuer != "o" && continuer != "n");
                    }
                }else{
                    std::cout << "Mauvaise entree!" << std::endl;

                }
            }
        }


    void Joueur::defense(Joueur* joueur2){
        std::string defense;
        do{
            std::cout << m_nom << " voulez-vous defendre ? ('o' oui, 'n' non) ";
            std::cin >> defense;
            std::cout << std::endl;
            if(defense == "o"){
                int surQui;
                bool choix = true;
                while(choix){
                    std::cout << "Sur qui voulez-vous defendre ? ";
                    std::cin >> surQui;

                    if(surQui > 0 && surQui < (int)joueur2->getLCreature().size()){
                        if (joueur2->getLCreature().at(surQui-1)->getAttaque()){
                                int avecQui;
                                std::cout << "Avec qui voulez-vous defendre ? ";
                                std::cin >> avecQui;
                                if( m_LCreature.at(avecQui-1)->getDegagee()){
                                    joueur2->addDefenseur(surQui-1, m_LCreature.at(avecQui-1));
                                    m_LCreature.at(avecQui-1)->setDegagee(false);
                                }else{
                                    std::cout << "Cette carte est engagee !" << std::endl;
                                }
                        }else{
                            std::cout << "Cette carte n'attaque pas !" << std::endl;
                        }
                    }else{
                        std::cout << "Mauvaise entree!" << std::endl;
                    }
                    std::string continuer;
                    do{
                            std::cout << "Voulez-vous continuer ? ";
                            std::cin >> continuer;
                            if(continuer == "o") choix = true;
                            else if(continuer == "n") choix = false;
                            else { std::cout << "Mauvaise entree !" << std::endl;}

                        } while (continuer != "o" && continuer != "n");
                }

            }else if(defense == "n"){
                
            }else{
                std::cout << "Mauvaise entree !" << std::endl;
            }
        } while (defense != "o" && defense != "n");  
    }

    void Joueur::choisirAttaque(){
        int i = 1;
        for(Creature* creatureA : m_LCreature){
            if(creatureA->getAttaque() && (int)creatureA->getEstDefenduPar().size()>1){
                int carte;
                for(int y = 0; y < (int)creatureA->getEstDefenduPar().size()-1; y++){
                    std::cout << "Quelle carte voulez-vous defendre en " << y + 1 << " ? ";
                    std::cin >> carte;
                    std::cout << std::endl;
                    if( carte > 0 && carte <= (int)creatureA->getEstDefenduPar().size()){
                        creatureA->swap(carte, 0);
                    }
                }
            }
            i++;
        }
    }

    void Joueur::mortAuCombat(Creature* creature){
            for(int i = 0; i < (int)m_LCreature.size(); i++){
                if(m_LCreature.at(i) == creature){
                    m_cimetiere.push_back(m_LCreature.at(i));
                    m_LCreature.erase(m_LCreature.begin()+i);
                }
            }
        }
    void Joueur::ajoutTerrain(int indexCarte){
        Terrain* terrain = dynamic_cast<Terrain*>(m_main.at(indexCarte));
        m_LTerrain.push_back(terrain);
        std::cout << "Un terrain " <<  Terrain::landToString(terrain->getLandIndex()) << " a ete pose." << std::endl;
        int indexCptTerrain = terrain->getLandIndex();
        m_cptTerrainPrets.at(indexCptTerrain) += 1;
        m_totalTerrainsPrets += 1;
        m_main.erase(m_main.begin() + indexCarte);
        setTerrainPose(true);
        majCptTerrainPrets();
    }
        
    bool Joueur::getTerrainPose(){
        return m_terrainPose;
    }

    void Joueur::setTerrainPose(bool b){
            m_terrainPose = b;
        }

        void Joueur::majCptTerrainPrets(){ // ajouter cette fonction a la fin de la phase de desengagement pour maj le cpt
            std::vector<int> m_cptTerrainPrets(5,0); // voir si il ne faut pas faire un for pour mettre les valeurs a 0
            m_totalTerrainsPrets = 0;
            for(Terrain* terrain : m_LTerrain){
                if(terrain->getDegagee()){
                    m_cptTerrainPrets.at(terrain->getLandIndex()) += 1;
                    m_totalTerrainsPrets +=1;
                }

            }
        }
        void Joueur::ajoutCreature(int indexCarte){
            Creature* creature = dynamic_cast<Creature*>(m_main.at(indexCarte));
            if (creaturePosable(creature)){
                int coutQuelcCopy = creature->getCoutQuelconque();
                int coutSpecCopy = 0;
                for(int i = 0; i < 5; i++){
                    coutSpecCopy = creature->getCptCoutSpec().at(i);
                    if(coutSpecCopy > 0){
                        for(Terrain* terrain : m_LTerrain){
                            if(terrain->getDegagee() && terrain->getLandIndex() == i && coutSpecCopy > 0){  // degagee = desengagee
                                    terrain->setDegagee(false);
                                    coutSpecCopy -= 1;
                            }
                        }
                    }
                }
                while(coutQuelcCopy > 0){
                    majCptTerrainPrets();
                    // refresh affichage
                    int terrainType = -1;
                    std::cout << "Choisissez un terrain a engager (" << coutQuelcCopy << " restant(s) )" << std::endl;
                    while(terrainType > -1 && terrainType < 5){
                        std::cout << "Entrez le chiffre correspondant :  0= PLAINE, 1= ILE, 2= MARAIS, 3= MONTAGNE, 4= FORET" << std::endl;
                        std::cin >> terrainType;
                    }
                    if(m_cptTerrainPrets.at(terrainType) > 0)
                    {
                        for(Terrain* terrain : m_LTerrain){
                            if(terrain->getDegagee() && terrain->getLandIndex() == terrainType){  // degagee = desengagee
                                    terrain->setDegagee(false);
                                    coutQuelcCopy -= 1;
                                    break;
                            }
                        }
                    }
                    else{
                        std::cout << "Vous ne pouvez pas engager de " << Terrain::landToString(terrainType) <<"." << std::endl;
                    }
                }
                majCptTerrainPrets();
                //refresh affichage

                m_LCreature.push_back(creature);
                std::cout << "La creature " << creature->getNom() << " a ete posee" << std::endl;
                creature->setDegagee(false); // permet de ne pas attaquer des le premier tour de la creature
                m_main.erase(m_main.begin() + indexCarte);
            }
            else{
                std::cout << "Cette creature ne peut pas etre posee !" << std::endl;
            }
        }

        bool Joueur::creaturePosable(Creature* creature){
            if(m_totalTerrainsPrets < creature->getCoutTotal())
                return false;
            else{
                for(int i = 0; i < 5; i++){
                    if(creature->getCptCoutSpec().at(i) > m_cptTerrainPrets.at(i))
                        return false;
                }
                return true;
            }
        }