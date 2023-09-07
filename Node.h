//
// Created by Willow Zuvich on 9/6/23.
//

#pragma once
#include <iostream>

template <class T, class Q> class Node
{
public:
    //default constructor
    Node();
    //constructor with parameters
    Node(T p1, Q p2);
    //destructor
    ~Node();
    //Parameter 1 getter, returns value of type T
    T getP1()const;
    //Parameter 2 getter, returns value of type Q
    Q getP2()const;

private:
    T p1;
    Q p2;
    Node <T,Q>* pNext;
};
