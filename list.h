#ifndef LIST_H
#define LIST_H


#include <iostream>

/**
 * Singly linked list
 */
class List {
public:

    struct node
    {
        std::string data;
        node *next;
    };
    List();

    void createnode(std::string value);
    void display();
    /**
     * insert at the beginning of the list
     * @param value string
     */
    void insert(std::string value);
    /**
     * Delete last value
     * @return deleted value
     */
    std::string pop();

private:


    node *head, *tail;

};

#endif // LIST_H
