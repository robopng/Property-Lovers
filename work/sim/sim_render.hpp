#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;
 /* TODO:
 *  - Set up a class that can hold and statically render images 
 *  - Set up subclasses for the background, NPC, dialog box, etc. Or, whatever
 *    implementation of this that you prefer.
 *  - Figure out how the art files should be stored in src to meet your needs here
 */

class SimRender {
    public: //x coord, y coord, file name, window, opacity, scale
        SimRender(RenderWindow*);
        SimRender(int, int, std::string, RenderWindow*); // constructor
        ~SimRender(); // deconstructor
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