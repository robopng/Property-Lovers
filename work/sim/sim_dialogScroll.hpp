#include <vector>
#include <string>

class DialogController{
    public:
        DialogController(std::string path); // constructor
        ~DialogController(); // destructor 
        std::string next(); // get next dialog line
        std::string jump(int); // jump to a specific dialog line given input option
        std::vector<std::string> options(); // get next player dialog options
    private:
        struct {
            std::vector<std::string> fullText;
            std::vector<std::string>* dialogRecall;
            int currentLine;
        } dialogReader, playerReader;
};