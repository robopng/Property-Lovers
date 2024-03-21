#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "sim_render.hpp"

using namespace sf;
/**
 * @file sim_render.cpp
 * @author Layla Payton tpayton1@luc.edu
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

struct {
    Sprite sprite;
    Window window;
    RenderTarget& target;
} str;

//Just input 1 and 1 for scale and opacity for now
SimRender::SimRender(int x, int y, std::string FileName, Window* window, double opacity, double scale) {
    sf::Texture texture;
    texture.loadFromFile(FileName);
    str.sprite.setTexture(texture); 
    setCoordinates(x,y);
    setScale(1);
}
SimRender::~SimRender() {
    //not neededd as of 3/20
}

void SimRender::render() {
    str.target.draw(str.sprite, RenderStates::Default);
}
void SimRender::removeRender(){
    SimRender::~SimRender();
}
void SimRender::setOpacity(double opacity) {
    //not needed as of 3/20
}
void SimRender::setScale(double scale) {
    str.sprite.setScale(scale, scale);
}
void SimRender::setCoordinates(int x, int y) {
    str.sprite.setPosition(x,y);
}
void SimRender::setInvisible(bool isInvisible) {
    //not needed as of 3/20
}