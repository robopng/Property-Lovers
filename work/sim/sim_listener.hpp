# pragma once

#include <SFML\Graphics.hpp>

// very very bare bones right now just for the demo
class Listener {
    public:
        Listener();
        ~Listener();
        bool checkEvent(sf::Event);
    private:
        // for now, nothing.. we will eventually want stuff here, though
};