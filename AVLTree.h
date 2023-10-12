//
// Created by Willow Zuvich on 10/5/23.
//

#ifndef CPTS223_ASSIGNMENTS_PA2_AVLTREE_H
#define CPTS223_ASSIGNMENTS_PA2_AVLTREE_H

#include <iostream>
#include <cstdlib>
#include<algorithm>
#include "AVLNode.h"

template <class T> class AVLTree
{
public:
    //constructor
    AVLTree() {mRoot = nullptr;}

    //destructor
    ~AVLTree();

    //Function allows for new data to be correctly inserted into tree such that the tree remains balanced
    void insert(T newData);

    //Function returns current height of the tree
    int height();

    //Function checks for a given value of type T in the tree -- returns 1 if found, 0 if not
    bool contains(T search);

    //Function checks that the tree is balanced -- returns 1 if balances, 0 if not
    bool validate();

private:
    AVLNode<T> * mRoot;

    //Function deletes each node in tree recursively
    void destructorHelper(AVLNode<T>* &pCur);

    //function returns height of tree/subtree -
    int heightHelper(AVLNode<T>* &root);

    //function inserts value into tree, abiding be the balancing requirements
    void insertHelper(T &newData, AVLNode<T> *&pTree);

    //function performs single left rotation on given node
    void rotateWithLeftChild(AVLNode<T> *&k);

    //function performs single right rotation on given node
    void rotateWithRightChild(AVLNode<T> *&k);

    //function performs double rotation with left child
    void doubleWithLeftChild(AVLNode<T>* &k);

    //function performs double rotation with right child
    void doubleWithRightChild(AVLNode<T>* &k);

    //function validates that the AVL tree is balanced
    bool validateHelper(AVLNode<T>* &pTree);

};

//destructor
template<class T>
AVLTree<T>::~AVLTree() {

    destructorHelper(mRoot);
}

//Function deletes each node in tree recursively
template<class T>
void AVLTree<T>::destructorHelper(AVLNode<T> *&pCur) {
    if(pCur != nullptr){
        destructorHelper(pCur->getLeftPtr());
        destructorHelper(pCur->getRightPtr());
        delete pCur;
    }
}

//Function allows for new data to be correctly inserted into tree such that the tree remains balanced
template<class T>
void AVLTree<T>::insert(T newData)
{
    insertHelper(newData, mRoot);
}


//Function checks for a given value of type T in the tree -- returns 1 if found, 0 if not
template<class T>
bool AVLTree<T>::contains(T search) {
    bool found = false;
    AVLNode<T>* pCur = mRoot;

    while(!found && pCur != nullptr)
    {
        if(search < pCur->getData())
        {
            pCur = pCur->getLeftPtr();
        }
        else if(search > pCur->getData())
        {
            pCur = pCur->getRightPtr();
        }
        else
        {
            found = true;
        }
    }
}

//Function checks that the tree is balanced -- returns 1 if balances, 0 if not

template<class T>
bool AVLTree<T>::validate()
{
    validateHelper(mRoot);
}

template<class T>
int AVLTree<T>::height() {
    heightHelper(mRoot);
}

template<class T>
int AVLTree<T>::heightHelper(AVLNode<T> *&root) {
    if (root == nullptr) {
        return -1;
    }
    else {
        return 1 + std::max(heightHelper(root->getLeftPtr()), heightHelper(root->getRightPtr()));
    }
}

/*******************************************************************************
 * The following function definitions heavily reference the 5_trees_2_avl PowerPoint slides 34-35 example code
*/

//function inserts value into tree, abiding be the balancing requirements
template<class T>
void AVLTree<T>::insertHelper(T &newData, AVLNode<T> *&pTree)
{
    if(pTree == nullptr) //base case
    {
        pTree = new AVLNode<T>(newData);

    }
    else if ( newData < pTree->getData())
    {
        insertHelper(newData, pTree->getLeftPtr()); //recursive call
        if(heightHelper(pTree->getLeftPtr()) - heightHelper(pTree->getRightPtr()) == 2) //fix height balance at deepest location
        {
            if (newData < pTree->getLeftPtr()->getData()) //check if case 1
                rotateWithLeftChild(pTree);
            else //if case 2
                doubleWithLeftChild(pTree);
        }
    }
    else if(newData > pTree->getData())
    {
        insertHelper(newData, pTree->getRightPtr()); //recursive call
        if(heightHelper(pTree->getRightPtr()) - heightHelper(pTree->getLeftPtr()) == 2) //fix height balance at deepest location
        {
            if(newData > pTree->getRightPtr()->getData()) //case 4
                rotateWithRightChild(pTree);
            else
                doubleWithRightChild(pTree); //case 3
        }
    }
    else //duplicate data item
        ;

    //update effected node heights
    pTree->setHeight(std::max(heightHelper(pTree->getLeftPtr()), heightHelper(pTree->getRightPtr())) + 1);
}

//function performs single left rotation on given node
//insert case 1
template<class T>
void AVLTree<T>::rotateWithLeftChild(AVLNode<T> *&k)
{
    AVLNode<T> *kL = k->getLeftPtr();
    k->setLeftPtr(kL->getRightPtr());
    kL->setRightPtr(k);
    k->setHeight(std::max(heightHelper(k->getLeftPtr()), heightHelper(k->getRightPtr())) + 1); //set new height
    kL->setHeight(std::max(heightHelper(kL->getLeftPtr()), heightHelper(kL->getRightPtr())) + 1); //set new height
    k = kL;
}

//function performs single right rotation on given node
//insert case 4
template<class T>
void AVLTree<T>::rotateWithRightChild(AVLNode<T> *&k)
{
    AVLNode<T> *kR = k->getRightPtr();
    k->setRightPtr(kR->getLeftPtr());
    kR->setLeftPtr(k);
    k->setHeight(std::max(heightHelper(k->getLeftPtr()), heightHelper(k->getRightPtr())) + 1); //set new height
    kR->setHeight(std::max(heightHelper(kR->getLeftPtr()), heightHelper(kR->getRightPtr())) + 1); //set new height
    k = kR;
}

//function performs double rotation with left child
//case 2
template<class T>
void AVLTree<T>::doubleWithLeftChild(AVLNode<T> *&k)
{
    rotateWithRightChild(k->getLeftPtr());
    rotateWithLeftChild(k);
}

//function performs double rotation with right child
//case 3
template<class T>
void AVLTree<T>::doubleWithRightChild(AVLNode<T> *&k)
{
    rotateWithLeftChild(k->getRightPtr());
    rotateWithRightChild(k);
}

//function validates that the AVL tree is balanced
template<class T>
bool AVLTree<T>::validateHelper(AVLNode<T>* &pTree)
{
    if(pTree == nullptr) //tree is empty or all nodes in subtree where checked
        return true;
    //check that current subtree is balanced (height differance no more than 1), and all its subtrees are balanced
    else if(abs(pTree->getLeftPtr()->getHeight() - pTree->getRightPtr()->getHeight()) <= 1 //current subtree check
    && validateHelper(pTree->getLeftPtr())  //left subtree check (recursive call)
    && validateHelper(pTree->getRightPtr())) //right subtree check (recursive call)
        return true;

    else
        return false; //previous conditions failed, the bst is not balanced

}



#endif //CPTS223_ASSIGNMENTS_PA2_AVLTREE_H
