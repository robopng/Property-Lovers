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
        void derenderAll();
        struct dialogBox {
            DialogController* controller;
            std::vector<SimRender*> playerRenderer;
            std::vector<Listener*> playerListener;
            SimRender* npcRenderer;
        } *dialog;
        struct button {
            SimRender* renderer;
            Listener* listener;
        } *pastDialog, *menuReturn, *settingsReturn; // show past dialog, to menu, etc.
        sf::RenderWindow* window;
        SimRender* background;
        SimRender* npc;
};