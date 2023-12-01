//
// Created by hamza on 11/30/2023.
//

#ifndef INC_474_P4_LINKEDLIST_H
#define INC_474_P4_LINKEDLIST_H

#include <string>
#include <memory>
#include <cstring>

// Need LinkedList type ahead of time for WLStruct
class LinkedList;

// Enum to figure out what type is held in struct
enum WLType {
    INT, LIST
};

// Essentially a union without the union part
// Contains either an int or a list
struct WLStruct {
    WLType type;
    std::shared_ptr<LinkedList> List{};
    int Integer{};
};

// Node, where each node can either be a list or int
class Node {
public:
    WLStruct val;
    std::shared_ptr<Node> next;
    explicit Node(WLStruct val);
};

// Regular LL implementation but smart
class LinkedList {
private:
    std::shared_ptr<Node> root;
    std::shared_ptr<Node> end;
    int size;

public:
    LinkedList();
    int getSize() const;
    void append(const WLStruct& val);
    void prepend(const WLStruct& val);
    WLStruct access(int index) const;
    bool accessible(int index) const;
    void set(int index, const WLStruct& w);
    void combine(const std::shared_ptr<LinkedList>& other);
    std::shared_ptr<LinkedList> copyOf();
    std::string toString() const;
};

#endif //INC_474_P4_LINKEDLIST_H
