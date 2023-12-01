//
// Created by hamza on 11/30/2023.
//

#ifndef INC_474_P4_LINKEDLIST_H
#define INC_474_P4_LINKEDLIST_H

#include <string>
#include <memory>
#include <cstring>

class LinkedList;

enum WLType {
    INT, LIST
};
struct WLStruct {
    WLType type;
    std::shared_ptr<LinkedList> List{};
    int Integer{};
};

class Node {
public:
    WLStruct val;
    std::shared_ptr<Node> next;
    explicit Node(WLStruct val);
};

class LinkedList {
private:
    std::shared_ptr<Node> root;
    std::shared_ptr<Node> end;
    int size;

public:
    LinkedList();
    void append(const WLStruct& val);
    WLStruct access(int index) const;
    void combine(const LinkedList& other);
    void deepCopy(const LinkedList& other);
    std::string toString() const;
};

#endif //INC_474_P4_LINKEDLIST_H
