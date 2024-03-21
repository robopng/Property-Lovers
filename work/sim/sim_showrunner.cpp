/**
 * @file sim_runner.cpp
 * @author Liam Wilson lwilson18@luc.edu
 * @brief Master file of all parts of the dating sim (listener, renderer, and game logic)
 * @version 0.0
 * @date 2024-03-17
 * 
 * TODO:
 *  - Await dialog control and render control
 *  - Setup listeners for player input to next dialog, buttons, etc
 *  - Link menu elements for functionality (i.e. view past dialog, etc) (implemment first
 *    with keybinds?)
 *  - Setup sim with full functionality:
 *     - Display everything
 *     - Open date sequence
 *     - Dialog box, dialog, dialog progression, dialog past view
 *     - Player options, player option buttons
 *     - Close date sequence, progression to next part of game
 */

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "sim_showrunner.hpp"
#include "sim_dialogScroll.hpp"
#include "sim_render.hpp"
#include "sim_listener.hpp"

Showrunner::Showrunner(int date, sf::RenderWindow* window){
    // the number of the date will become relevant once we have more than one
    // if you get Intellisense errors on push_back or the = signs, they are incorrect. ignore
    // a value of type "SimRender *" cannot be assigned to an entity of type "SimRender *" <- nonsense
    dialog->controller = &DialogController("../../dialog/test_npc.txt", "../../dialog/text_player.txt");
    auto opt = dialog->controller->options();
    for each(auto x in dialog->controller->options()){
        dialog->playerRenderer.push_back(SimRender::SimRender(window));
        dialog->playerListener.push_back(Listener::Listener());
    }
    dialog->npcRenderer = &SimRender(window);
    background = &SimRender(0, 0, "path/to/background", window);
    npc = &SimRender(0, 0, "../../art/DatingSimSprites/MainHouse.png", window);
    // this b/c of ambiguity
    this->window = window;
    
    //temp values
    this->dialogX = 200;
    this->dialogY = 300;
    this->spriteX = 100;
    this->spriteY = 100;

    // //temp obj
    // this->dialog->mainHouseRenderer = new SimRender(spriteX, spriteY, "path/to/MainHouse.png", window);
    // //once backgrounds uploaded
    // // this->background = new SimRender(0, 0, "path/to/Neighborhood.png", window)
    // this->mainCharacter = new SimRender(0, 0, "path/to/mc.png", window);
}

Showrunner::~Showrunner(){
    // include the frees, etc
    // delete this->dialog;
    // delete this->pastDialog;
    // delete this->menuReturn;
    // delete this->settingReturn;
    // delete this.date;
}

void Showrunner::start(){
    /**
     * @brief Process the core loop of the dating sim.
     * Step through the relevant date's dialog flow tree one line at a time,
     * awaiting player input (click) before proceeding to the next line. When
     * npc is awaiting player response, process clicks on dialog buttons, then
     * jump to the relevant dialog flow tree option.
     */
    // program should run thru entire date before yielding control
    // if player closes to menu, quits window, etc. exception handling will occur in init
    while(dialog->controller->hasNext()){
        this->renderAll();
        sf::Event event;

        // auto-progress possible but for now we will await click to do anything
        while(window->pollEvent(event)){
            // player input not needed
            if (!dialog->controller->await()){
                dialog->npcRenderer->setDialog(dialogX, dialogY, dialog->controller->next(), 0);
                break;
            }

            for(int i = 0; i < dialog->playerListener.size(); i ++){
                if (dialog->playerListener.at(i).checkEvent(event)){
                    dialog->npcRenderer->setDialog(dialogX, dialogY, dialog->controller->jump(i), 0);
                    break;
                }
            }
            // pre-loading player options for the next input run
            // when player selects an option the next set will automatically be loaded in dialog->controller
            auto options = dialog->controller->options();
            for(int i = 0; i < options.size(); i ++)
                dialog->playerRenderer.at(i).setDialog(dialogX, dialogY, options.at(i), 0);
            // until I verify this is not needed it will stay here for safety - liam
            break;
        }
        window->clear();
    }
    // date over; final render
    this->renderAll();
    // SFML bug?
    // sf::sleep(sf::Time(5));
    // have a fade-out at the same time as this for effect
    Sleep(5000);
    window->clear();
    // this->end();
}

void Showrunner::end(){
    /**
     * @brief End the core loop of the dating sim, and deconstruct.
     * Currently not in use
     */
}

void Showrunner::renderAll(){
    /**
     * @brief Prepare all elements in the dating sim for display
     */
    background->render();
    npc->render();
    dialog->npcRenderer->render();
    for each(auto element in dialog->playerRenderer)
        element.showDialog();
    window->display();
}
