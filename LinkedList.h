//
// Created by Willow Zuvich on 9/5/23.
//
#pragma once

#include "Node.h"

template <class T, class Q> class LinkedList
{
public:
    //constructor
    LinkedList();

    //copy constructor
    LinkedList(const LinkedList &copy);

    //destructor
    ~LinkedList();

    //Copy assignment operator //does this go here??

    //insert node at front of list
    void InsertFront(const T p1 , const Q p2);

    //delete node containing data matching search parameter -- returns true if node was successfully found and deleted, false otherwise
    bool DeleteNode(T search);

    //search list for node containing data matching search parameter -- returns true if node was successfully found, false otherwise
    bool SearchList(T search);

    //get Head ptr
    Node<T,Q>* getHead() const;

private:
    Node <T,Q>* pHead;
};
