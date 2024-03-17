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