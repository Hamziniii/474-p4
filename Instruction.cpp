//
// Created by hamza on 11/30/2023.
//

#include <iostream>
#include <algorithm>
#include "Instruction.h"
#include "Receiver.h"

bool isNumber(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](char c) {
        return std::isdigit(c);
    });
}

bool exists(const std::string& str, Receiver &r) {
    return r.dm.count(str) != 0;
}

WLStruct WLInt(int val) {
    WLStruct w;
    w.type = INT;
    w.List = nullptr;
    w.Integer = val;
    return w;
}

WLStruct WLList() {
    WLStruct w;
    w.type = LIST;
    w.List = std::make_shared<LinkedList>();
    w.Integer = -1;
    return w;
}

void VarIntInstruction::execute(Receiver &r) {
    std::string x = this->args[0];
    std::string rough_i = this->args[1];

    if(isNumber(rough_i)) {
        int i = std::stoi(rough_i);
        r.dm[x] = WLInt(i);
    } else if (exists(rough_i, r)) {
        r.dm[x] = r.dm[rough_i];
    } else {
        std::cout << "VarInt: " << rough_i << " isn't a variable or int." << std::endl;
    }
}

void VarListInstruction::execute(Receiver &r) {
    std::string y = this->args[0];
    std::vector<std::string> rest(this->args.begin() + 1, this->args.end());

    WLStruct w = WLList();
    for(auto& rough_arg : rest) {
        if(isNumber(rough_arg)) {
            int arg = std::stoi(rough_arg);
            w.List->append(WLInt(arg));
        } else if(exists(rough_arg, r)) {
            w.List->append(r.dm[rough_arg]);
        } else {
            std::cout << "VarList: " << rough_arg << " isn't a variable or int." << std::endl;
        }
    }

    r.dm[y] = w;
}

void CombineInstruction::execute(Receiver &r) {
    std::string rough_list1 = this->args[0];
    std::string rough_list2 = this->args[1];

    if(!(exists(rough_list1, r)))
        return;

    WLStruct list1 = r.dm[rough_list1];

    if(list1.type == INT) {
        std::cout << "Arg 1 is not a list." << std::endl;
        return;
    }

    if(!exists(rough_list2, r)) {
        r.dm[rough_list2] = list1;
        return;
    }

    WLStruct list2 = r.dm[rough_list2];
    if(list2.type == LIST)
        r.dm[rough_list2].List->combine(list1.List);
}

void GetInstruction::execute(Receiver &r) {
    std::string x = this->args[0];
    std::string rough_i = this->args[1];
    std::string rough_list = this->args[2];

    int i = -1;

    if(isNumber(rough_i)) {
        i = std::stoi(rough_i);
    } else if(exists(rough_i, r)) {
        WLStruct semi_i = r.dm[rough_i];
        if(semi_i.type == INT)
            i = semi_i.Integer;
        else
            std::cout << "Get: " << rough_i << " isn't a variable or int." << std::endl;
    }

    if(exists(rough_list, r)) {
        WLStruct semi_list = r.dm[rough_list];
        if(semi_list.type == LIST) {
            if(semi_list.List->accessible(i))
                r.dm[x] = semi_list.List->access(i);
            else
                std::cout << "Get: " << i << " outside the bounds of" << rough_list << "." << std::endl;
        } else {
            std::cout << "Get: " << rough_list << " isn't a list." << std::endl;
        }
    } else {
        std::cout << "Get: " << rough_list << " isn't a variable." << std::endl;
    }
}

void SetInstruction::execute(Receiver &r) {
    std::string rough_x = this->args[0];
    std::string rough_i = this->args[1];
    std::string rough_list = this->args[2];

    int i = -1;
    WLStruct x;

    if(isNumber(rough_x)) {
        x = WLInt(std::stoi(rough_x));
    } else if(exists(rough_x, r)) {
        x = r.dm[rough_x];
    } else {
        std::cout << "Set: " << rough_x << " isn't a variable." << std::endl;
    }

    if(isNumber(rough_i)) {
        i = std::stoi(rough_i);
    } else if(exists(rough_i, r)) {
        WLStruct semi_i = r.dm[rough_i];
        if(semi_i.type == INT)
            i = semi_i.Integer;
        else
            std::cout << "Set: " << rough_i << " isn't a variable or int." << std::endl;
    }

    if(exists(rough_list, r)) {
        WLStruct semi_list = r.dm[rough_list];
        if(semi_list.type == LIST) {
            if(semi_list.List->accessible(i))
                semi_list.List->set(i, x);
            else
                std::cout << "Set: " << i << " outside the bounds of" << rough_list << "." << std::endl;
        } else {
            std::cout << "Set: " << rough_list << " isn't a list." << std::endl;
        }
    } else {
        std::cout << "Set: " << rough_list << " isn't a variable." << std::endl;
    }
}

void CopyInstruction::execute(Receiver &r) {
    std::string rough_list1 = this->args[0];
    std::string rough_list2 = this->args[1];

    if(!exists(rough_list2, r))
        return;

    WLStruct list2 = r.dm[rough_list2];

    if(list2.type == INT) {
        std::cout << "Copy: arg2 isn't a list." << std::endl;
        return;
    }

    r.dm[rough_list1].type = LIST;
    r.dm[rough_list1].List = list2.List->copyOf();
}

void ChsInstruction::execute(Receiver &r) {
    std::string rough_x = this->args[0];

    if(exists(rough_x, r)) {
        WLStruct semi_x = r.dm[rough_x];
        if(semi_x.type == INT)
            r.dm[rough_x].Integer *= -1;
    }
}

void AddInstruction::execute(Receiver &r) {
    std::string rough_x = this->args[0];
    std::string rough_y = this->args[1];

    int y = 0;

    if(exists(rough_y, r)) {
        WLStruct semi_y = r.dm[rough_y];
        if(semi_y.type == INT)
            y = semi_y.Integer;
    }

    if(exists(rough_x, r)) {
        WLStruct semi_x = r.dm[rough_x];
        if(semi_x.type == INT)
            r.dm[rough_x].Integer += y;
    } else if(!isNumber(rough_x)) {
        r.dm[rough_x] = WLInt(y);
    }
}

void GotoInstruction::execute(Receiver &r) {
    std::string rough_i = this->args[0];
    int i = INT_MIN;

    if(exists(rough_i, r)) {
        WLStruct semi_i = r.dm[rough_i];
        if(semi_i.type == INT)
            i = semi_i.Integer;
    } else if(isNumber(rough_i)) {
        i = std::stoi(rough_i);
    }

    if(i > -1)
        r.pc = i - 1;
}

void IfInstruction::execute(Receiver &r) {
    std::string rough_x = this->args[0];
    std::string rough_i = this->args[1];

    int i = INT_MIN;
    int x = -1;

    // If it isn't a variable... then doesnt matter
    if(exists(rough_x, r)) {
        WLStruct semi_x = r.dm[rough_x];
        if(semi_x.type == INT)
            x = semi_x.Integer;
        else if(semi_x.type == LIST)
            x = semi_x.List->getSize();
    } else if(isNumber(rough_x)) {
        x = std::stoi(rough_x);
    } else {
        std::cout << "If: " << rough_x << " isn't a variable or int." << std::endl;
        return;
    }

    if(exists(rough_i, r)) {
        WLStruct semi_i = r.dm[rough_i];
        if(semi_i.type == INT)
            i = semi_i.Integer;
    } else if(isNumber(rough_i)) {
        i = std::stoi(rough_i);
    }

    if(i > -1 && x == 0)
        r.pc = i - 1;
}

void HltInstruction::execute(Receiver &r) {
    r.halted = true;
}