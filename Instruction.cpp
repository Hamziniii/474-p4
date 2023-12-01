//
// Created by hamza on 11/30/2023.
//

#include <iostream>
#include "Instruction.h"
#include "Receiver.h"

VarIntInstruction::VarIntInstruction(std::vector<std::string> args) {

}

void VarIntInstruction::execute(Receiver &r) {
        std::cout << "VarIntInstruction" << std::endl;
}

VarListInstruction::VarListInstruction(std::vector<std::string> args) {

}

void VarListInstruction::execute(Receiver &r) {
    std::cout << "VarListInstruction" << std::endl;
}

CombineInstruction::CombineInstruction(std::vector<std::string> args) {

}

void CombineInstruction::execute(Receiver &r) {
    std::cout << "CombineInstruction" << std::endl;
}

GetInstruction::GetInstruction(std::vector<std::string> args) {

}

void GetInstruction::execute(Receiver &r) {
    std::cout << "GetInstruction" << std::endl;
}

SetInstruction::SetInstruction(std::vector<std::string> args) {

}

void SetInstruction::execute(Receiver &r) {
    std::cout << "SetInstruction" << std::endl;
}

CopyInstruction::CopyInstruction(std::vector<std::string> args) {

}

void CopyInstruction::execute(Receiver &r) {
    std::cout << "CopyInstruction" << std::endl;
}

ChsInstruction::ChsInstruction(std::vector<std::string> args) {

}

void ChsInstruction::execute(Receiver &r) {
    std::cout << "ChsInstruction" << std::endl;
}

AddInstruction::AddInstruction(std::vector<std::string> args) {

}

void AddInstruction::execute(Receiver &r) {
    std::cout << "AddInstruction" << std::endl;
}

GotoInstruction::GotoInstruction(std::vector<std::string> args) {

}

void GotoInstruction::execute(Receiver &r) {
    std::cout << "GotoInstruction" << std::endl;
}

IfInstruction::IfInstruction(std::vector<std::string> args) {

}

void IfInstruction::execute(Receiver &r) {
    std::cout << "IfInstruction" << std::endl;
}

HltInstruction::HltInstruction(std::vector<std::string> args) {

}

void HltInstruction::execute(Receiver &r) {
    std::cout << "HltInstruction" << std::endl;
}