//
// Created by hamza on 11/30/2023.
//
#pragma once
#ifndef INC_474_P4_INSTRUCTION_H
#define INC_474_P4_INSTRUCTION_H


#include <string>
#include <vector>

class Receiver;

class Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r) = 0;
};

class VarIntInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r);
    explicit VarIntInstruction(std::vector<std::string> args);
};

class VarListInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r);
    explicit VarListInstruction(std::vector<std::string> args);
};

class CombineInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r);
    explicit CombineInstruction(std::vector<std::string> args);
};

class GetInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r);
    explicit GetInstruction(std::vector<std::string> args);
};

class SetInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r);
    explicit SetInstruction(std::vector<std::string> args);
};

class CopyInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r);
    explicit CopyInstruction(std::vector<std::string> args);
};

class ChsInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r);
    explicit ChsInstruction(std::vector<std::string> args);
};

class AddInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r);
    explicit AddInstruction(std::vector<std::string> args);
};

class GotoInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r);
    explicit GotoInstruction(std::vector<std::string> args);
};

class IfInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r);
    explicit IfInstruction(std::vector<std::string> args);
};

class HltInstruction: public Instruction {
private:
    std::vector<std::string> args;
public:
    virtual void execute(Receiver& r);
    explicit HltInstruction(std::vector<std::string> args);
};

#endif //INC_474_P4_INSTRUCTION_H
