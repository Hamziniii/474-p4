//
// Created by hamza on 11/30/2023.
//

#include <stdexcept>
#include <iostream>
#include "LinkedList.h"

Node::Node(WLStruct val) {
    this->val = val;
    this->next = nullptr;
}

LinkedList::LinkedList() {
    this->root = nullptr;
    this->end = nullptr;
    this->size = 0;
}

WLStruct LinkedList::access(int index) const {
    if(index < 0 || index >= this->size)
        throw std::runtime_error("Out of bounds!");

    std::shared_ptr<Node> n = this->root;
    int i = 0;
    while(n != nullptr && i != index) {
        n = n->next;
        i++;
    }

    return n->val;
}

void LinkedList::append(const WLStruct& val) {
    if(root == nullptr) {
        root = std::make_shared<Node>(val);
        end = root;
    } else {
        end->next = std::make_shared<Node>(val);
        end = end->next;
    }

    this->size++;
}


void LinkedList::deepCopy(const LinkedList& other) {

}

void LinkedList::combine(const LinkedList& other) {

}

std::string LinkedList::toString() const {
    std::string s = "[ ";
    auto temp = this->root;
    for(int i = 0; i < this->size; i++) {
        if(temp->val.type == INT) {
            s += std::to_string(temp->val.Integer);
        } else if(temp->val.type == LIST) {
            s += temp->val.List->toString();
        }
        s += " ";
        temp = temp->next;
    }
    s += "]";

    return s;
}