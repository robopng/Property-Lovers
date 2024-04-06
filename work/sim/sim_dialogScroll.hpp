# pragma once

#include <vector>
#include <string>
#include <sstream>
#include <map>

class DialogController{
    public:
        DialogController(std::string, std::string); // constructor
        ~DialogController(); // destructor 
        std::string next();
        std::string jump(int);
        std::vector<std::string> options();
        bool await();
        bool hasNext();
    private:
        // potential optimizations: transform fullText to stringstream,
        // transform currentLine to an iterator (w/ fullText as a map)
        struct {
            std::vector<std::pair<std::string, bool>> fullText;
            std::vector<std::string> dialogRecall; // nonfunctional 3/21
            int currentLine;
        } *dialogReader;
        struct {
            std::vector<std::vector<std::pair<std::string, int>>> fullText;
            std::vector<std::string> dialogRecall; // nonfunctional 3/21
            int currentLine;
        } *playerReader;
};