//
// Created by hamza on 11/30/2023.
//

#include <sstream>
#include <memory>
#include <iostream>
#include <algorithm>

#include "Receiver.h"
#include "Instruction.h"

Receiver::Receiver() {
    halted = false;
    maxPc = 0;
    pc = 0;
}

void Receiver::extractCommands(const std::vector<std::string>& fileText) {
    for(auto& _str : fileText) {
        std::string str = _str;
        str.erase(std::remove(str.begin(), str.end(), ','), str.end());

        std::string cmd;
        std::vector<std::string> all;

        std::stringstream ss(str);
        std::string snip;

        while(std::getline(ss, snip, ' ')) {
            all.push_back(snip);
        }

        cmd = all[0];
        std::vector<std::string> args(all.begin() + 1, all.end());

        std::shared_ptr<Instruction> command;

        if(cmd == "VARINT")
            this->commands.push_back(std::make_shared<VarIntInstruction>(args));
        else if(cmd == "VARLIST")
            this->commands.push_back(std::make_shared<VarListInstruction>(args));
        else if(cmd == "COMBINE")
            this->commands.push_back(std::make_shared<CombineInstruction>(args));
        else if(cmd == "GET")
            this->commands.push_back(std::make_shared<GetInstruction>(args));
        else if(cmd == "SET")
            this->commands.push_back(std::make_shared<SetInstruction>(args));
        else if(cmd == "COPY")
            this->commands.push_back(std::make_shared<CopyInstruction>(args));
        else if(cmd == "CHS")
            this->commands.push_back(std::make_shared<ChsInstruction>(args));
        else if(cmd == "ADD")
            this->commands.push_back(std::make_shared<AddInstruction>(args));
        else if(cmd == "GOTO")
            this->commands.push_back(std::make_shared<GotoInstruction>(args));
        else if(cmd == "IF")
            this->commands.push_back(std::make_shared<IfInstruction>(args));
        else if(cmd == "HLT")
            this->commands.push_back(std::make_shared<HltInstruction>(args));
    }

    this->maxPc = this->commands.size();
}

void Receiver::nextInstruction() {
    if(canContinue()) {
        auto& cmd = this->commands[pc];
        std::cout << "Executing " << cmd.get()->name << std::endl;
        cmd->execute(*this);
        advance();
        printData();
    }
}

void Receiver::restOfInstructions() {
    while(canContinue()) {
        this->commands[pc]->execute(*this);
        advance();
    }
    printData();
}

void Receiver::computeHalted() {
    if(pc >= maxPc)
        halted = true;
}

void Receiver::advance() {
    if(!canContinue())
        std::cout << "Halted! shouldn't be going any farther!!!" << std::endl;
    this->pc++;
    computeHalted();
}

bool Receiver::canContinue() {
    computeHalted();
    return !halted;
}

void Receiver::printData() {
    std::cout << "PC: " <<  this->pc - 1 << std::endl;
    for(auto& p : this->dm) {
        if(p.second.type == LIST)
           std::cout << p.first << ": " << p.second.List->toString() << std::endl;
        else if(p.second.type == INT)
            std::cout << p.first << ": " << p.second.Integer << std::endl;
    }
}