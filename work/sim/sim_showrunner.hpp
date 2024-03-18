#include "sim_dialogScroll.hpp"
#include "sim_render.hpp"

class Showrunner {
    public:
        Showrunner();
        ~Showrunner();
        void start();
        void end();
    private:
        struct dialogBox {
            // render::element
            // listener::element
            std::vector<std::string> options;
        } playerDialog, dialogHistory;
        struct button {
            // render::element
            // listener::element
        }; // show past dialog, to menu, etc.
        // render::element background;
};