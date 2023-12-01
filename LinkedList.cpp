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

int LinkedList::getSize() const {
    return size;
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

bool LinkedList::accessible(int index) const {
    return !(index < 0 || index >= this->size);
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

void LinkedList::prepend(const WLStruct& val) {
    if(root == nullptr) {
        root = std::make_shared<Node>(val);
        end = root;
    } else {
        auto node = std::make_shared<Node>(val);
        node->next = root;
        root = node;
    }

    this->size++;
}

void LinkedList::set(int index, const WLStruct& w) {
    if(!accessible(index))
        throw std::runtime_error("Out of bounds!");

    auto node = root;
    for(int i = 0; i < index; i++)
        node = node->next;

    node->val = w;
}

std::shared_ptr<LinkedList> LinkedList::copyOf() {
    LinkedList other;

    auto node = root;
    WLStruct temp;
    for(int i = 0; i < size; i++) {
        temp = node->val;
        if(temp.type == INT)
            other.append(temp);
        else if(temp.type == LIST) {
            temp.type = LIST;
            temp.List = temp.List->copyOf();
            other.append(temp);
        }
        node = node->next;
    }

    return std::make_shared<LinkedList>(other);
}

void LinkedList::combine(const std::shared_ptr<LinkedList>& other) {
    for(int i = other->size - 1; i >= 0; i--)
        this->prepend(other->access(i));
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