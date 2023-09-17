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
    LinkedList(const LinkedList<T,Q> &copy);

    //destructor
    ~LinkedList();

    //Copy assignment operator //does this go here??
    LinkedList& operator= (const LinkedList<T,Q> &l);

    //insert node at front of list
    void insertFront(const T p1 , const Q p2);

    //delete node containing data matching search parameter -- returns true if node was successfully found and deleted, false otherwise
    bool removeNode(const T search);

    //search list for node containing data matching search parameter -- returns true if node was successfully found, false otherwise
    bool searchList(const T search);

    //get Head ptr
    Node<T,Q>* getHead() const;

    //set Head ptr
    void setHead(Node<T,Q>* newHead);

private:
    //ptr to front of list
    Node <T,Q>* mpHead;

    //recursive destructor helper
    void deleteList(Node<T,Q>* pCur);
};

//default constructor
template <class T, class Q> LinkedList<T,Q>::LinkedList()
{
    mpHead = nullptr;
}

//copy constructor
template <class T, class Q> LinkedList<T,Q>::LinkedList(const LinkedList<T,Q> &copy)
{
    Node<T,Q>* pPrev = nullptr;
    Node<T,Q>* pCur = nullptr;

    //loop through list until all nodes are copied
    for(Node<T,Q>* pCpy = copy.getHead(); pCpy != nullptr; pCpy = pCpy->getNext())
    {
        //create new node
         pCur = new Node<T,Q>(pCpy->getP1(), pCpy->getP2());
         //link previous to current
        if(pPrev != nullptr)
        {
            pPrev->setNext(pCur);
        }
        else
        {
            mpHead = pCur;
        }

        pPrev = pCur;
    }
}

//destructor
template <class T, class Q> LinkedList<T,Q>::~LinkedList()
{
    deleteList(mpHead);
}

//copy assignment operator
template <class T, class Q>
LinkedList<T, Q> &LinkedList<T, Q>::operator=(const LinkedList<T, Q> &l)
{
    Node<T,Q>* pPrev = nullptr;
    Node<T,Q>* pCur = nullptr;

    //loop through list until all nodes are copied
    for(Node<T,Q>* pCpy = l.getHead(); pCpy != nullptr; pCpy = pCpy->getNext())
    {
        //create new node
        pCur = new Node<T,Q>(pCpy->getP1(), pCpy->getP2());
        //link previous to current
        if(pPrev != nullptr)
        {
            pPrev->setNext(pCur);
        }
        else
        {
            mpHead = pCur;
        }

        pPrev = pCur;
    }

    return *this;
}

//Insert at front of list function
template <class T, class Q> void LinkedList<T, Q>::insertFront(const T p1, const Q p2)
{
    //create new node
    Node<T,Q>* pMem = new Node<T,Q>(p1, p2);

    //set nxt ptr
    pMem->setNext(mpHead);

    //update head ptr
    setHead(pMem);
}

//delete node that contains data that matches search argument -return true if node is found and deleted
template <class T, class Q> bool LinkedList<T,Q>::removeNode(const T search)
{
    bool found = false; //set found to false
    Node<T,Q>* pCur = mpHead; //set current node to head ptr
    Node<T,Q>* pPrev = nullptr;

    //iterate through list until either target or end of list is found
    for(;!found && pCur != nullptr; )
    {
        if(pCur->getP1() == search)
        {
            found = true;
        }
        else
        {
            pPrev = pCur;
            pCur = pCur->getNext();
        }
    }

    if(found)
    {
        if (pPrev == nullptr)//if head ptr must be updated
        {
            mpHead = pCur->getNext(); //update head
        } else {
            pPrev->setNext(pCur->getNext()); //link prev ptr to next in list
        }
        delete pCur; //delete node
    }

    return found;
}

//search for node that contains data matching search argument - return true if found
template <class T, class Q> bool LinkedList<T,Q>::searchList(const T search)
{
    bool found = false; //set found to false
    Node<T,Q>* pCur = mpHead; //set current node to head ptr

    //iterate through list until either target or end of list is found
    for(;!found && pCur != nullptr; pCur = pCur->getNext())
    {
        if(pCur->getP1() == search)
        {
            found = true;
        }
    }

    return found;
}

//return head ptr of list
template <class T, class Q>Node<T, Q> *LinkedList<T, Q>::getHead() const
{
    return mpHead;
}

//set head ptr
template <class T, class Q> void LinkedList<T,Q> ::setHead(Node<T,Q>* newHead)
{
    mpHead = newHead;
}

//delete helper function
template <class T, class Q> void LinkedList<T, Q>::deleteList(Node<T,Q>* pCur)
{
    //recursive call until pCur->pnext = nullptr
    if(pCur!= nullptr && pCur->getNext() != nullptr)
    {
        deleteList(pCur->getNext());
    }

    delete pCur; //delete node
}