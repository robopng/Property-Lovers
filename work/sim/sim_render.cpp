/**
 * @file sim_render.cpp
 * @author Celeste Payton tpayton1@luc.edu
 * @author Liam Wilson lwilson18@luc.edu
 * @brief Rendering and (static) display for the dating sim implemented with SFML
 * @version 0.0
 * @date 2024-03-17
 * 
 * TODO:
 *  - Set up a class that can hold and statically render images 
 *  - Set up subclasses for the background, NPC, dialog box, etc. Or, whatever
 *    implementation of this that you prefer.
 *  - Figure out how the art files should be stored in src to meet your needs here
 */

#include <vector>
#include <string>
#include <SFML\Graphics.hpp>
#include "sim_render.hpp"

// Just input 1 and 1 for scale and opacity for now
SimRender::SimRender(int x, int y, std::string FileName, RenderWindow* window) {
    this->window = window;
    sf::Texture texture;
    texture.loadFromFile(FileName);
    texture.update(*window);
    sprite.setTexture(texture); 
    setCoordinates(x,y);
    setScale(1); //temporarily just 1
}
SimRender::SimRender(RenderWindow* window){
    this->window = window;
}
SimRender::~SimRender() {
    //not neededd as of 3/20
}

void SimRender::render() {
    window->draw(sprite);
}
void SimRender::setOpacity(double opacity) {
    //not needed as of 3/20
}
void SimRender::setScale(double scale) {
    sprite.setScale(scale, scale);
}
void SimRender::setCoordinates(int x, int y) {
    sprite.setPosition(x,y);
}
void SimRender::setInvisible(bool isInvisible) {
    //not needed as of 3/20
}
void SimRender::setDialog(int x, int y, std::string dialogue, int size){
    text.setString(dialogue);
    text.setCharacterSize(size);
    text.setFillColor(Color::Black);
    text.setPosition(x,y);
}
void SimRender::showDialog() {
    window->draw(text);
}