#include "sim_dialogScroll.hpp"
#include "sim_render.hpp"
#include "sim_listener.hpp"

class Showrunner {
    public:
        Showrunner(int, sf::RenderWindow*);
        ~Showrunner();
        void start();
        void end();
    private:
        void renderAll();
        struct dialogBox {
            DialogController* controller;
            std::vector<SimRender> playerRenderer;
            std::vector<Listener> playerListener;
            SimRender* npcRenderer;
        } *dialog;
        // currently unused
        struct button {
            SimRender* renderer;
            Listener* listener;
        } *pastDialog, *menuReturn, *settingsReturn;

        sf::RenderWindow* window;
        SimRender* background;
        SimRender* npc;
        // Set coords for dialog
        int dialogX;
        int dialogY;
        // Set coords for sprites
        int spriteX;
        int spriteY;
};
