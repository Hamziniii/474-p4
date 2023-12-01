//
// Created by hamza on 11/30/2023.
//

#include <iostream>
#include <utility>
#include "Invoker.h"

void Invoker::startLoop() {
    std::cout
        << "Enter a letter [o, a, q]" << std::endl
        << "o - run next line" << std::endl
        << "a - run remaining lines" << std::endl
        << "q - quit" << std::endl;

    std::string input;

    while(true) {
        std::cin >> input;

        if (input == "o") {
            this->nextInstruction();
        } else if (input == "a") {
            this->restOfInstructions();
        } else if (input == "q") {
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid input. Please enter 'o', 'a', or 'q'." << std::endl;
        }

        if(!r.canContinue())
            break;

        std::cout << "Enter a letter [o, a, q]" << std::endl;
    }
}

void Invoker::nextInstruction() {
    this->r.nextInstruction();
}

void Invoker::restOfInstructions() {
    this->r.restOfInstructions();
}

void Invoker::insertInstructions(std::vector<std::string> fileText) {
    this->r.extractCommands(std::move(fileText));
}
