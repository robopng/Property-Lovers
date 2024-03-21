#include "sim_showrunner.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char* argv[]) {

  VideoMode vm(960, 540);
  RenderWindow window(vm, "Window")

  while(window.isOpen()){
    if (Keyboard::isKeyPressed(Keyboard::Escape)){
      window.close();
    }
      /*
      * put stuff in here for
      * updating scenes, drawing scenes, etc
      */
    //clear last frame
    window.clear();
    
    //render graphics
    
    //render game scene
    window.display();
  }

  return 0;
}
