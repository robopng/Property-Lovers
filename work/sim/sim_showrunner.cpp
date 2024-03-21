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

// #include SFML MOUSE
#include "sim_showrunner.hpp"
#include "sim_dialogScroll.hpp"
#include "sim_render.hpp"

Showrunner::Showrunner(int date){
    // the number of the date will become relevant once we have more than one
    // render::element background(filepath)
    // render::element npc(filepath)
    // this->playerDialog.renderer = render::element()
    // this->playerDialog.listener = listener::element()
    // this->dialog->controller = DialogController::DialogController("path");
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
    // while(dialog.controller.hasNext()){
    //     this->renderAll();
    //     bool await = true;

    //     while(await){
    //         if sfml::mouse.buttonPressed(){
    //             if (!dialog.controller.await()){
    //                 dialog.npcRender.content = dialog.controller.next();
    //                 break;
    //             }

    //             for(int i = 0; i < dialog.listener.length(); i ++){
    //                 if dialog.listener.at(i).isPressed(){
    //                     dialog.npcRender.content = dialog.controller.jump(i);
    //                     break;
    //                 }
    //             }

    //             auto options = dialog.controller.options();
    //             for(int i = 0; i < options.length(); i ++)
    //                 dialog.playerRender.at(i).content = options.at(i);
                    
    //             await = false;
    //         }
    //     }

    //     this->derenderAll();
    // }
    // this->renderAll();
    // system.sleep(5000);
    // this->derenderAll();
    // this->end();
}

void Showrunner::end(){

}

void Showrunner::renderAll(){
    // background.render();
    // npc.render();
    // dialog.npcRender.render();
    // for each(auto element in dialog.playerRender)
    //     element.render();
}

void derenderAll(){
    // background.render();
    // npc.render();
    // dialog.npcRender.render();
    // for each(auto element in dialog.playerRender)
    //     element.render();
}