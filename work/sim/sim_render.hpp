#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class SimRender {
    public: //x coord, y coord, file name, window, opacity, scale
        SimRender(RenderWindow*);
        SimRender(int, int, std::string, RenderWindow*);
        ~SimRender();
        void render();
        void setOpacity(double);
        void setScale(double);
        void setCoordinates(int, int);
        void setInvisible(bool);
        void showDialog();
        void setDialog(int, int, std::string, int);
        // Renders NPC model during dating sim    
    private:
        Sprite sprite;
        RenderWindow* window;
        std::string fileName;
        Text text;
        int x;
        int y;
};