#include <iostream>
#include <fstream>
#include "Invoker.h"

//  If there is an issue opening the file, it could be beacuse

int main() {
    LinkedList l;
    WLStruct w;
        w.List = nullptr;
        w.type = INT;
        w.Integer = 5;
    l.append(w);
    l.append(w);
    l.append(w);

    LinkedList l2;
    l2.append(w);
    w.List = std::make_shared<LinkedList>(l);
    w.type = LIST;
    l2.append(w);
    l2.append(w);
    l2.append(w);
    l2.append(w);

    std::cout << l.toString() << std::endl;
    std::cout << l2.toString() << std::endl;

//    std::vector<std::string> commands;
//    std::string line;
//    std::ifstream input("input.wl");
//
//    if(!input.is_open()) {
//        std::cout << "Unable to open file!!" << std::endl;
//        return 0;
//    } else
//        while(getline(input, line)) {
//            commands.push_back(line);
//        }
//
//    input.close();
//
//    Invoker i;
//    i.insertInstructions(commands);
//    i.startLoop();

    std::cout << "Bye for real!" << std::endl;
    return 0;
}

