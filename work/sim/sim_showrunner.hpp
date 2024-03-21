#include "sim_dialogScroll.hpp"
#include "sim_render.hpp"

class Showrunner {
    public:
        Showrunner(int);
        ~Showrunner();
        void start();
        void end();
    private:
        void renderAll();
        void derenderAll();
        struct dialogBox {
            // render::element npcRender
            // std::vector<render::element> playerRender
            // std::vector<listener::element> listener
            DialogController controller;
        } *dialog;
        struct button {
            // render::element renderer
            // listener::element listener
        } *pastDialog, *menuReturn, *settingsReturn; // show past dialog, to menu, etc.
        // render::element background;
        // render::element house;
        int date; // which date we're on
};