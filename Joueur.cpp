#include <iostream>
#include <cstdlib>
#include <vector>
#include "Joueur.hpp"

Joueur::Joueur() {}

Joueur::Joueur(int pv, std::string nom, Encyclopedie *encyclopedie)
{
    m_nom = nom;
    m_pv = pv;
    m_deck = encyclopedie->choisirDeck(m_nom);
    construireDeck();
    m_bibliotheque = new Bibliotheque(m_deck);
    std::vector<Carte *> main;
    m_main = main;
    m_cptTerrainPrets = std::vector<int>(5, 0);
    m_totalTerrainsPrets = 0;
}

Joueur::~Joueur() {}

int Joueur::getPV()
{
    return m_pv;
}

Deck *Joueur::getDeck()
{
    return m_deck;
}

std::vector<Carte *> Joueur::getCimetiere()
{
    return m_cimetiere;
}
std::vector<Carte *> Joueur::getMain()
{
    return m_main;
}

Bibliotheque *Joueur::getBibliotheque()
{
    return m_bibliotheque;
}
std::vector<Terrain *> Joueur::getLTerrain()
{
    return m_LTerrain;
}

std::vector<Creature *> Joueur::getLCreature()
{
    return m_LCreature;
}

std::string Joueur::getNom()
{
    return m_nom;
}

bool Joueur::getAAttaque()
{
    return m_aAttaque;
}

void Joueur::setAAttaque(bool aAttaque)
{
    m_aAttaque = aAttaque;
}

bool Joueur::getCreatureReady()
{
    for (Creature *creature : m_LCreature)
    {
        if (creature->getDegagee() && !creature->aLaCapacite(Capacite::DEFENSEUR))
        {
            return true;
        }
    }
    return false;
}

bool Joueur::setPv(int pv)
{
    m_pv = pv;
    if (m_pv > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Joueur::setNom(std::string nom)
{
    m_nom = nom;
}

void Joueur::addDefenseur(int pos, Creature *creature)
{
    m_LCreature.at(pos)->addDefenseur(creature);
}

bool Joueur::piocher(int nbrCartes)
{

    for (int i = 0; i < nbrCartes; i++)
    {
        if ((int)m_bibliotheque->getBibliotheque().size() > 0)
        {
            m_main.push_back(m_bibliotheque->getBibliotheque().at(0));
            m_bibliotheque->pop_front();
        }
        else
        {
            return false;
        }
    }
    return true;
}

void Joueur::melanger()
{
    m_bibliotheque->melanger();
}

void Joueur::desengager()
{
    for (Carte *carte : m_LCreature)
    {
        carte->setDegagee(true);
    }
    for (Carte *carte : m_LTerrain)
    {
        carte->setDegagee(true);
    }
}

void Joueur::tropDeCartes()
{

    while (m_main.size() > 7)
    {
        int posCarte;
        std::cout << m_nom << " vous avez trop de cartes ! Laquelle voulez-vous defausser ? " << std::endl;
        while (!(std::cin >> posCarte))
        {
            std::cout << "Numero de carte invalide, veuillez rentrer un entier !" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << m_nom << " vous avez trop de cartes ! Laquelle voulez-vous defausser ? " << std::endl;
        }

        if (posCarte > 0 && posCarte <= (int)m_main.size())
        {
            m_cimetiere.push_back(m_main.at(posCarte - 1));
            m_main.erase(m_main.begin() + posCarte - 1);
            std::cout << "Carte defaussee !" << std::endl;
        }
        else
        {
            std::cout << "La carte demandee n'est pas viable !" << std::endl;
        }
    }
}

void Joueur::remonterStatsCreatures()
{
    for (Creature *creature : m_LCreature)
    {
        creature->setForce(creature->getBasedForce());
        creature->setEndurance(creature->getBasedEndurance());
    }
}

bool Joueur::attaque(EnJeu *enJeu)
{

    bool choix = true;
    while (choix)
    {
        std::string attaque;
        std::cout << m_nom << " voulez-vous attaquer ? ('t' pour tout, 'n' pour non, ou 'c' pour choisir) " << std::endl;
        std::cin >> attaque;
        if (attaque == "t")
        {
            for (Creature *creature : m_LCreature)
            {
                if (creature->getDegagee() && !creature->aLaCapacite(Capacite::DEFENSEUR))
                {
                    creature->setAttaque(true);
                    if (!creature->aLaCapacite(Capacite::VIGILANCE))
                    {
                        creature->setDegagee(false);
                    }
                }
            }
            setAAttaque(true);
            choix = false;
            return true;
        }
        else if (attaque == "n")
        {
            choix = false;
            return false;
        }
        else if (attaque == "c")
        {
            int carte;
            while (choix)
            {
                std::cout << m_nom << " veuillez choisir avec qui vous voulez attaquer. " << std::endl;
                while (!(std::cin >> carte))
                {
                    std::cout << "Numero de carte invalide, veuillez rentrer un entier !" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << m_nom << " veuillez choisir avec qui vous voulez attaquer. " << std::endl;
                }

                if (carte > 0 && carte <= (int)m_LCreature.size())
                {
                    if (m_LCreature.at(carte - 1)->getDegagee() && !m_LCreature.at(carte - 1)->aLaCapacite(Capacite::DEFENSEUR))
                    {
                        if (!m_LCreature.at(carte - 1)->aLaCapacite(Capacite::VIGILANCE))
                        {
                            m_LCreature.at(carte - 1)->setDegagee(false);
                        }
                        m_LCreature.at(carte - 1)->setAttaque(true);
                        setAAttaque(true);
                        Affiche::afficheJeu(enJeu);
                    }
                    else
                    {
                        std::cout << "Cette creature ne peut pas attaquer !" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Erreur la carte n'est pas valable ! " << std::endl;
                }
                std::string continuer;
                do
                {
                    std::cout << "Voulez-vous continuer ? " << std::endl;
                    std::cin >> continuer;
                    if (continuer == "o")
                        choix = true;
                    else if (continuer == "n")
                        return true;
                    else
                    {
                        std::cout << "Mauvaise entree !" << std::endl;
                    }

                } while (continuer != "o" && continuer != "n");
            }
        }
        else
        {
            std::cout << "Mauvaise entree!" << std::endl;
        }
    }
    return false;
}

bool Joueur::peutDefendre(Creature* creatureA, Creature* creatureD){
    if (creatureA->aLaCapacite(Capacite::VOL) && (!creatureD->aLaCapacite(Capacite::VOL) && !creatureD->aLaCapacite(Capacite::PORTEE))){
        std::cout << "Votre creature n'a pas VOL ou PORTEE !" << std::endl;
        return false;
    }
    else if(creatureA->aLaCapacite(Capacite::PROTECTIONBLANC) && creatureD->aLaCouleur("BLANC")){
        std::cout << creatureD->getNom() << " ne peut pas defendre sur une carte avec PROTECTIONBLANC" << std::endl;
        return false;
    }else if(creatureA->aLaCapacite(Capacite::PROTECTIONBLEU) && creatureD->aLaCouleur("BLEU")){
        std::cout << creatureD->getNom() << " ne peut pas defendre sur une carte avec PROTECTIONBLEU" << std::endl;
        return false;
    }else if(creatureA->aLaCapacite(Capacite::PROTECTIONNOIR) && creatureD->aLaCouleur("NOIR")){
        std::cout << creatureD->getNom() << " ne peut pas defendre sur une carte avec PROTECTIONNOIR" << std::endl;
        return false;
    }else if(creatureA->aLaCapacite(Capacite::PROTECTIONROUGE) && creatureD->aLaCouleur("ROUGE")){
        std::cout << creatureD->getNom() << " ne peut pas defendre sur une carte avec PROTECTIONROUGE" << std::endl;
        return false;
    }else if(creatureA->aLaCapacite(Capacite::PROTECTIONVERT) && creatureD->aLaCouleur("VERT")){
        std::cout << creatureD->getNom() << " ne peut pas defendre sur une carte avec PROTECTIONVERT" << std::endl;
        return false;
    }else{
        return true;
    }
}

void Joueur::choixDefenseur(Joueur* joueur2, int surQui)
{
    int avecQui;
    std::cout << "Avec qui voulez-vous defendre ? " << std::endl;
    do
    {
        while (!(std::cin >> avecQui))
        {
            std::cout << "Numero de carte invalide, veuillez rentrer un entier !" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Avec qui voulez-vous defendre ? " << std::endl;
        }
    } while (avecQui <= 0 || avecQui > (int)m_LCreature.size());

    if (m_LCreature.at(avecQui - 1)->getDegagee())
    {
        if ( peutDefendre(joueur2->getLCreature().at(surQui - 1), m_LCreature.at(avecQui - 1) ))
        {
            joueur2->addDefenseur(surQui - 1, m_LCreature.at(avecQui - 1));
            m_LCreature.at(avecQui - 1)->setDegagee(false);
        }
    }
    else
    {
        std::cout << "Cette carte est engagee !" << std::endl;
    }
}

void Joueur::defense(Joueur *joueur2, EnJeu *enJeu)
{
    std::string defense;
    do
    {
        std::cout << m_nom << " voulez-vous defendre ? ('o' oui, 'n' non) " << std::endl;
        std::cin >> defense;
        if (defense == "o")
        {
            int surQui;
            bool choix = true;
            while (choix)
            {
                std::cout << "Sur qui voulez-vous defendre ? " << std::endl;
                while (!(std::cin >> surQui))
                {
                    std::cout << "Numero de carte invalide, veuillez rentrer un entier !" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Sur qui voulez-vous defendre ? " << std::endl;
                }
                if (surQui > 0 && surQui <= (int)joueur2->getLCreature().size())
                {
                    if (joueur2->getLCreature().at(surQui - 1)->getAttaque() && joueur2->getLCreature().at(surQui - 1)->aLaCapacite(Capacite::MENACE) && !joueur2->getLCreature().at(surQui - 1)->aLaCapacite(Capacite::IMBLOCABLE))
                    {
                        int nbrCreatureDispo = 0;
                        for (Creature *creature : m_LCreature)
                        {
                            if (creature->getDegagee())
                            {
                                nbrCreatureDispo++;
                            }
                        }
                        if (nbrCreatureDispo >= 2)
                        {
                            std::cout << "Cette creature a menace vous devez la defendre avec au moins 2 cartes ! " << std::endl;
                            bool continuer = true;
                            while (joueur2->getLCreature().at(surQui - 1)->getEstDefenduPar().size() < 2 && continuer == true)
                            {
                                choixDefenseur(joueur2, surQui);
                                if (joueur2->getLCreature().at(surQui - 1)->getEstDefenduPar().size() > 2)
                                {
                                    std::string c;
                                    do
                                    {
                                        std::cout << m_nom << " voulez-vous continuer à placer des defenseurs sur " << joueur2->getLCreature().at(surQui - 1)->getNom() << " ? ('o' oui, 'n' non)" << std::endl;
                                        std::cin >> c;
                                        if (c == "n")
                                        {
                                            continuer = false;
                                        }
                                        else if (c == "o")
                                        {
                                            continuer = true;
                                        }
                                    } while (c != "n" && c != "o");
                                }
                            }
                        }
                        else
                        {
                            std::cout << "Vous n'avez pas assez de creatures disponibles pour defendre sur " << joueur2->getLCreature().at(surQui - 1)->getNom() << " !" << std::endl;
                        }
                    }
                    else if (joueur2->getLCreature().at(surQui - 1)->getAttaque() && !joueur2->getLCreature().at(surQui - 1)->aLaCapacite(Capacite::IMBLOCABLE))
                    {
                        choixDefenseur(joueur2, surQui);
                    }
                    else if (joueur2->getLCreature().at(surQui - 1)->aLaCapacite(Capacite::IMBLOCABLE))
                    {
                        std::cout << "Cette carte ne peut pas etre bloquee ! " << std::endl;
                    }
                    else
                    {
                        std::cout << "Cette carte n'attaque pas !" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Mauvaise entree!" << std::endl;
                }
                std::string continuer;
                do
                {
                    std::cout << "Voulez-vous continuer ? ('o' oui, 'n' non)" << std::endl;
                    std::cin >> continuer;
                    if (continuer == "o")
                        choix = true;
                    else if (continuer == "n")
                        choix = false;
                    else
                    {
                        std::cout << "Mauvaise entree !" << std::endl;
                    }

                } while (continuer != "o" && continuer != "n");
            }
        }
        else if (defense == "n")
        {
        }
        else
        {
            std::cout << "Mauvaise entree !" << std::endl;
        }
    } while (defense != "o" && defense != "n");
}

void Joueur::choisirAttaque(Joueur *j2, EnJeu *enJeu)
{
    int i = 1;
    for (Creature *creatureA : m_LCreature)
    {
        if (creatureA->getAttaque() && (int)creatureA->getEstDefenduPar().size() > 1)
        {
            int carte;
            for (int y = 0; y < (int)creatureA->getEstDefenduPar().size() - 1; y++)
            {
                std::cout << "Quelle carte voulez-vous defendre en " << y + 1 << " ? " << std::endl;
                while (!(std::cin >> carte))
                {
                    std::cout << "Numero de carte invalide, veuillez rentrer un entier !" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Quelle carte voulez-vous defendre en " << y + 1 << " ? " << std::endl;
                }

                if (carte > 0 && carte <= (int)creatureA->getEstDefenduPar().size())
                {
                    int index = 0;
                    for (Creature *creature : creatureA->getEstDefenduPar())
                    {
                        if (creature == j2->getLCreature().at(carte - 1))
                        {
                            creatureA->swap(index, y);
                            Affiche::afficheJeu(enJeu);
                        }
                        index++;
                    }
                }
            }
        }
        i++;
    }
}

void Joueur::mortAuCombat(Creature *creature)
{
    for (int i = 0; i < (int)m_LCreature.size(); i++)
    {
        if (m_LCreature.at(i) == creature)
        {
            m_cimetiere.push_back(m_LCreature.at(i));
            m_LCreature.erase(m_LCreature.begin() + i);
        }
    }
}
void Joueur::ajoutTerrain(int indexCarte, EnJeu *enJeu)
{
    Terrain *terrain = dynamic_cast<Terrain *>(m_main.at(indexCarte));
    m_LTerrain.push_back(terrain);

    int indexCptTerrain = terrain->getLandIndex();
    m_cptTerrainPrets.at(indexCptTerrain) += 1;
    m_totalTerrainsPrets += 1;
    m_main.erase(m_main.begin() + indexCarte);
    setTerrainPose(true);
    majCptTerrainPrets();
    Affiche::afficheJeu(enJeu);
    std::cout << "Un terrain " << Terrain::landToString(terrain->getLandIndex()) << " a ete pose." << std::endl;
}

bool Joueur::getTerrainPose()
{
    return m_terrainPose;
}

void Joueur::setTerrainPose(bool b)
{
    m_terrainPose = b;
}

void Joueur::majCptTerrainPrets()
{                                             // ajouter cette fonction a la fin de la phase de desengagement pour maj le cpt
    std::vector<int> m_cptTerrainPrets(5, 0); // voir si il ne faut pas faire un for pour mettre les valeurs a 0
    m_totalTerrainsPrets = 0;
    for (Terrain *terrain : m_LTerrain)
    {
        if (terrain->getDegagee())
        {
            m_cptTerrainPrets.at(terrain->getLandIndex()) += 1;
            m_totalTerrainsPrets += 1;
        }
    }
}
void Joueur::ajoutCreature(int indexCarte, EnJeu *enJeu)
{
    Creature *creature = dynamic_cast<Creature *>(m_main.at(indexCarte));
    if (creaturePosable(creature))
    {
        int coutQuelcCopy = creature->getCoutQuelconque();
        int coutSpecCopy = 0;
        for (int i = 0; i < 5; i++)
        {
            coutSpecCopy = creature->getCptCoutSpec().at(i);
            if (coutSpecCopy > 0)
            {
                for (Terrain *terrain : m_LTerrain)
                {
                    if (terrain->getDegagee() && terrain->getLandIndex() == i && coutSpecCopy > 0)
                    { // degagee = desengagee
                        terrain->setDegagee(false);
                        coutSpecCopy -= 1;
                    }
                }
            }
        }
        while (coutQuelcCopy > 0)
        {
            majCptTerrainPrets();
            Affiche::afficheJeu(enJeu);
            int terrainType = -1;
            std::cout << "Choisissez un terrain a engager (" << coutQuelcCopy << " restant(s) )" << std::endl;
            while (terrainType <= -1 || terrainType >= 5)
            {
                std::cout << "Entrez le chiffre correspondant :  0= PLAINE, 1= ILE, 2= MARAIS, 3= MONTAGNE, 4= FORET" << std::endl;
                while (!(std::cin >> terrainType))
                {
                    std::cout << "Numero de carte invalide, veuillez rentrer un entier !" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Entrez le chiffre correspondant :  0= PLAINE, 1= ILE, 2= MARAIS, 3= MONTAGNE, 4= FORET" << std::endl;
                }
            }
            if (m_cptTerrainPrets.at(terrainType) > 0)
            {
                for (Terrain *terrain : m_LTerrain)
                {
                    if (terrain->getDegagee() && terrain->getLandIndex() == terrainType)
                    { // degagee = desengagee
                        terrain->setDegagee(false);
                        coutQuelcCopy -= 1;
                        break;
                    }
                }
            }
            else
            {
                std::cout << "Vous ne pouvez pas engager de " << Terrain::landToString(terrainType) << "." << std::endl;
            }
        }
        majCptTerrainPrets();
        m_LCreature.push_back(creature);
        std::cout << "La creature " << creature->getNom() << " a ete posee" << std::endl;
        if (!creature->aLaCapacite(Capacite::HATE))
        {
            creature->setDegagee(false); // permet de ne pas attaquer des le premier tour de la creature
        }
        m_main.erase(m_main.begin() + indexCarte);
        Affiche::afficheJeu(enJeu);
    }
    else
    {
        std::cout << "Cette creature ne peut pas etre posee !" << std::endl;
    }
}

bool Joueur::creaturePosable(Creature *creature)
{
    if (m_totalTerrainsPrets < creature->getCoutTotal())
        return false;
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (creature->getCptCoutSpec().at(i) > m_cptTerrainPrets.at(i))
                return false;
        }
        return true;
    }
}

void Joueur::construireDeck()
{
    for (int id : m_deck->getDeckIndex())
    {
        m_deck->ajouterCarte(id);
    }
}