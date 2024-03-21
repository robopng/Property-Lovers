/**
 * @file listener.cpp
 * @author Liam Wilson lwilson18@luc.edu
 * @brief Listener control for buttons, etc
 * @version 0.0
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "sim_listener.hpp"

Listener::Listener(){

}

Listener::~Listener(){
    
}

bool Listener::checkEvent(sf::Event event){
    switch(event.type){
        case sf::Event::Closed:
            throw std::invalid_argument("KILL");
            break;
        case sf::Event::MouseButtonPressed:
        case sf::Event::KeyPressed:
        default:
            return true;
    }
    return false;
}