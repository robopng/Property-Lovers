/**
 * @file sim_dialogScroll.cpp
 * @author Liam Wilson lwilson18@luc.edu
 * @brief Dialog logic and flow control for the dating sim
 * @version 0.0
 * @date 2024-03-17
 * 
 * TODO:
 *  - If you don't know regex, Liam will implement it to parse through the dummy text 
 *    files; just worry about everything else. Otherwise, set up something to break down
 *    dialog files into a buffer(-type) so that they can be passed along sequentially and
 *    depending on player answers. KEEP IN MIND : double quotes in the string, commas in 
 *    the string
 *  - Implement a "stringrunner" class of sorts that encapsulates the functionality of
 *    proceeding string by string, retains memory of past strings in an accessible record,
 *    traverses the dialog flow chart given a player input, and provides input options to
 *    the player
 *  - Figure out how to design the dialog txt files based on your needs for the
 *    class here (maybe one NPC file per date, one player file per date? each string has
 *    an index/encode for flow control)
 *  - Anything else you think of that needs implementation
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include "sim_dialogScroll.hpp"

DialogController::DialogController(std::string npcPath, std::string playerPath){
    std::ifstream npcFile(npcPath);
    if (!npcFile) throw std::invalid_argument("Cannot read npc dialog file!");
    std::string line;
    while (npcFile >> line){
        // maybe find a way to get this working with regex like anticipated later
        std::string delimeter = ",";
        // 2 and -1 to trim off [" and " respectively
        std::string dialog = line.substr(2, line.find(delimeter)-1);
        // 2 and -1 to trim off ,\  and ], respectively
        std::string awaitStr = line.substr(line.find(delimeter)+2, line.length()-1);
        bool await;
        std::istringstream(awaitStr) >> std::boolalpha >> await;
        dialogReader->fullText.push_back(std::pair(dialog, await));
    }
    npcFile.close();

    std::ifstream playerFile(playerPath);
    if(!playerFile) throw std::invalid_argument("Cannot read player dialog file!");
    while(playerFile >> line){
        std::smatch match;
        std::regex expr("\"[A-Z][a-Z,./;'\"?!]+\", \d+");
        std::regex_search(line, match, expr);
        std::vector<std::pair<std::string, int>> vec;
        for (int i = 0; i < match.length(); i ++){
            // feels like namespace std would be nice but I don't wanna delete all of these...
            std::smatch num;
            std::smatch dialog;
            std::regex numExpr(" \d+]\Z");
            std::regex dialogExpr("[A-Z].+[.!?]");
            std::string search = match[i].str();
            std::regex_search(search, num, numExpr);
            std::regex_search(search, dialog, dialogExpr);
            // utterly disgusting but don't want to refactor
            // -1 to get rid of the ] at the end
            vec.push_back(std::pair(dialog.str(), stoi(num.str().substr(0,num.str().length()-1))));
        }
        // why is this not working? $10 to whoever can find out
        playerReader->fullText.push_back(vec);
    }

    playerFile.close();
    dialogReader->currentLine = 0;
}

DialogController::~DialogController(){
    // don't worry about this because for now I don't know either
}

std::string DialogController::next(){
    /**
     * @brief Proceed to the immediately next line in the dialog flow, without player input
    */
    // postfix iterate to be oh so fancy
    return std::get<0>(dialogReader->fullText.at(dialogReader->currentLine++));
}

std::string DialogController::jump(int choice){
    /**
     * @brief Proceed to the next line in the dialog flow, based on player input
     * @param choice - either 0, 1, or 2, corresponding to the player's choice
     */
    // assert choice < 3?
    // line number will be the right hand of the pair
    int result = std::get<1>(playerReader->fullText.at(playerReader->currentLine).at(choice));
    dialogReader->currentLine = result;
    playerReader->currentLine++;
    return std::get<0>(dialogReader->fullText.at(dialogReader->currentLine++));
}

std::vector<std::string> DialogController::options(){
    /**
     * @brief Return a vector of the player's next available dialog options
     */
    std::vector<std::string> vec;
    for (auto pair : playerReader->fullText.at(playerReader->currentLine))
        vec.push_back(std::get<0>(pair));
    return vec;
}

bool DialogController::await(){
    /**
     * @brief Return whether or not the NPC is awaiting player input to proceed
     */
    // await bool will be the right hand of the pair
    return std::get<1>(dialogReader->fullText.at(dialogReader->currentLine));
}

bool DialogController::hasNext(){
    return dialogReader->currentLine < dialogReader->fullText.size();
}
