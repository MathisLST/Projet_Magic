#include <iostream>
#include <cstdlib>
#include <vector>
#include "Carte.hpp"
#include "Creature.hpp"
#include "Terrain.hpp"

class Encyclopedie{
    private:
        std::vector<Carte*> m_encyclopedie;
    public:
        Encyclopedie();
        ~Encyclopedie();
        std::vector<Carte*> getEncyclopedie();

};