#include <iostream>
#include <cstdlib>
#include <vector>

class Terrain : public Carte {
    private :
        std::string m_type;

    public :
        Terrain (std::string type);

        std::string getType();
        
};