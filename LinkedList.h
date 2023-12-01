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
