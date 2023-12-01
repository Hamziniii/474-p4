//
// Created by hamza on 11/30/2023.
//
#pragma once
#ifndef INC_474_P4_INSTRUCTION_H
#define INC_474_P4_INSTRUCTION_H


#include <string>
#include <utility>
#include <vector>

class Receiver;

class Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name;
    virtual void execute(Receiver& r) = 0;
};

class VarIntInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name;
    void execute(Receiver& r) override;
    explicit VarIntInstruction(std::vector<std::string> args): args(std::move(args)), name("VarIntInstruction") {};
};

class VarListInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name = "VarListInstruction";
    void execute(Receiver& r) override;
    explicit VarListInstruction(std::vector<std::string> args) : args(std::move(args)) {};
};

class CombineInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name = "CombineInstruction";
    void execute(Receiver& r) override;
    explicit CombineInstruction(std::vector<std::string> args) : args(std::move(args)) {};
};

class GetInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name = "GetInstruction";
    void execute(Receiver& r) override;
    explicit GetInstruction(std::vector<std::string> args) : args(std::move(args)) {};
};

class SetInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name = "SetInstruction";
    void execute(Receiver& r) override;
    explicit SetInstruction(std::vector<std::string> args) : args(std::move(args)) {};
};

class CopyInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name = "CopyInstruction";
    void execute(Receiver& r) override;
    explicit CopyInstruction(std::vector<std::string> args) : args(std::move(args)) {};
};

class ChsInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name = "ChsInstruction";
    void execute(Receiver& r) override;
    explicit ChsInstruction(std::vector<std::string> args) : args(std::move(args)) {};
};

class AddInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name = "AddInstruction";
    void execute(Receiver& r) override;
    explicit AddInstruction(std::vector<std::string> args) : args(std::move(args)) {};
};

class GotoInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name = "GotoInstruction";
    void execute(Receiver& r) override;
    explicit GotoInstruction(std::vector<std::string> args) : args(std::move(args)) {};
};

class IfInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name = "IfInstruction";
    void execute(Receiver& r) override;
    explicit IfInstruction(std::vector<std::string> args) : args(std::move(args)) {};
};

class HltInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    std::string name = "HltInstruction";
    void execute(Receiver& r) override;
    explicit HltInstruction(std::vector<std::string> args) : args(std::move(args)) {};
};

#endif //INC_474_P4_INSTRUCTION_H
