/**
 * @file sim_dialogScroll.cpp
 * @author Ethan Radke eradke1@luc.edu
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
 *  - Figure out how to design the dialogue txt files based on your needs for the
 *    class here (maybe one NPC file per date, one player file per date? each string has
 *    an index/encode for flow control)
 *  - Anything else you think of that needs implementation
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "sim_dialogScroll.hpp"

DialogController::DialogController(std::string path){
    std::ifstream file;
    file.open(path);
    if (!file.is_open()) throw std::invalid_argument("Cannot read file!");

    std::string line;
    while(file >> line){
        // put something here to get it to remove everything after the end of the string
        dialogReader.fullText.push_back(line);
    }

    file.close();
    dialogReader.currentLine = 0;
}

DialogController::~DialogController(){
    // don't worry about this because for now I don't know either
}

std::string DialogController::next(){
    return dialogReader.fullText.at(dialogReader.currentLine++);
}

std::string DialogController::jump(int choice){  // 0, 1, 2
    // given a user input option, follow the dialog flow chart (we can talk about how to
    // implement a system for this with modular math, maybe? Or you can do what you like)
    /* Is called with a user input
    * Uses that input to find the proper next line of dialogue
    * Skips a certain number of lines based on the integer passed in.
    * return the line it lands at
    */
    // Determine the jump-to line given the choice 0,1,2
    // Parse the currentline to pull out the new line value  "dialog text" [(9,"Hey there"),(10,"Hows it goin"),..]
    // Use REGEX to get that:
    // pattern = "\(([0-9]+),"  <- attempting a pattern to find the line numbers. Should return a match object with three entries
    // need a find-all regex command that should return an array of matches. Let's assume the resulting array is called matches.
    // The first element (matches[0]) in REGEX matching response is usually the full string.
    // matches[1] would be the first choice ("9") -- choice 0
    // matches[2] .... choice = 1 ("10")
    string conversion = matches[choice + 1];
    int newLine = stoi(conversion);
    dialogReader.currentline = newLine;
    return dialogReader.fullText.at(dialogReader.currentLine);
}

std::vector<std::string> DialogController::options(){
    // return the three dialog options available to the player at the moment
    // Parse the text of fullText-currentLine to pull out the text of the options next to the numbers.
    // Create a vector from them.
    // Return that vector
    //
    std::vector<std::string> optionsList;
}
