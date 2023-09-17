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
    Node(const T p1, const Q p2);

    //copy constructor
    Node(const Node<T,Q> &copy);

    //copy assignment operator
    Node& operator=(const Node<T,Q> &n);

    //destructor
    ~Node();

    //Parameter 1 getter, returns value of type T
    T getP1()const;

    //Parameter 2 getter, returns value of type Q
    Q getP2()const;

    //Parameter 1 setter
    void setP1(const T newP1);

    //Parameter 2 setter
    void setP2(const Q newP2);

    //get next ptr
    Node<T,Q>* getNext()const;

    //set next ptr
    void setNext(Node<T,Q>* newNxt);

private:
    T mP1;
    Q mP2;
    Node <T,Q>* mpNext;
};

//default constructor
template <class T, class Q> Node<T,Q>::Node()
{
    mpNext = nullptr;
}

//constructor with parameters
template <class T, class Q> Node<T,Q>::Node(const T p1, const Q p2)
{
    mpNext = nullptr;
    mP1 = p1;
    mP2 = p2;
}

//copy constructor
template <class T, class Q> Node<T,Q>::Node(const Node<T, Q> &copy)
{
    mpNext = nullptr;
    mP1(copy.mP1);
    mP2(copy.mP2);

}

//copy assignment operator
template <class T, class Q>Node<T, Q> &Node<T, Q>::operator=(const Node<T, Q> &n)
{
    mpNext = nullptr;
    mP1(n.mP1);
    mP2(n.mP2);
}

//destructor
template <class T, class Q> Node<T,Q>::~Node() {}

//getter for p1
template <class T, class Q> T Node<T,Q>::getP1() const
{
    return mP1;
}

//getter for p2
template <class T, class Q> Q Node<T,Q>::getP2() const
{
    return mP2;
}

template <class T, class Q> void Node<T,Q>::setP1(const T newP1)
{
    mP1 = newP1;
}

template <class T, class Q> void Node<T,Q>::setP2(const Q newP2)
{
    mP2 = newP2;
}

//get next ptr
template <class T, class Q> Node<T,Q>* Node<T,Q>::getNext() const
{
    return mpNext;
}

//set next ptr
template <class T, class Q> void Node<T,Q>::setNext(Node<T, Q> *newNxt)
{
    mpNext = newNxt;
}