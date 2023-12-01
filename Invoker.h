//
// Created by hamza on 11/30/2023.
//

#ifndef INC_474_P4_INVOKER_H
#define INC_474_P4_INVOKER_H

#include "Receiver.h"

// Matches Command Loop
// Calls receiver to handle commands

class Invoker {
private:
    Receiver r;
    std::vector<std::shared_ptr<Instruction>> commands;

public:
    void startLoop();
    void insertInstructions(std::vector<std::string> fileText);
    void nextInstruction();
    void restOfInstructions();
};

#endif //INC_474_P4_INVOKER_H
