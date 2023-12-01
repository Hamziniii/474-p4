//
// Created by hamza on 11/30/2023.
//
#pragma once
#ifndef INC_474_P4_RECEIVER_H
#define INC_474_P4_RECEIVER_H


#include <memory>
#include <vector>
#include <unordered_map>
#include "Instruction.h"
#include "LinkedList.h"

// According to the directions, the receiver contains both the program memory
// and the data memory

class Receiver {
public:
    std::vector<std::shared_ptr<Instruction>> commands;
    bool halted;
    int maxPc;
    int pc; // Program counter
    std::unordered_map<std::string, WLStruct> dm; // Program memory/

    Receiver();
    void extractCommands(const std::vector<std::string>& fileText);
    void computeHalted();
    void advance();
    bool canContinue();
    void nextInstruction();
    void restOfInstructions();
};


#endif //INC_474_P4_RECEIVER_H
