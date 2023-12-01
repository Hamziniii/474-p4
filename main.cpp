#include <iostream>
#include <fstream>
#include "Invoker.h"

//  If there is an issue opening the file, it could be beacuse

int main() {
    std::vector<std::string> commands;
    std::string line;
    std::ifstream input("input.wl");

    if(!input.is_open()) {
        std::cout << "Unable to open file!!" << std::endl;
        return 0;
    } else
        while(getline(input, line)) {
            commands.push_back(line);
        }

    input.close();

    Invoker i;
    i.insertInstructions(commands);
    i.startLoop();

    std::cout << "Bye for real!" << std::endl;
    return 0;
}

