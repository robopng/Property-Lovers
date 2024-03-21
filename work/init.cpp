#include "sim_showrunner.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char* argv[]) {

  VideoMode vm(960, 540);
  RenderWindow window(vm, "Window");
  Showrunner showrunner(1, &window);

  showrunner.start();

  return 0;
}
