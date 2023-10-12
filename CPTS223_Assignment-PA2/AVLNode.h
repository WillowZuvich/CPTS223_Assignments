//
// Created by Willow Zuvich on 10/5/23.
//

#ifndef CPTS223_ASSIGNMENTS_AVLNODE_H
#define CPTS223_ASSIGNMENTS_AVLNODE_H

template <class T> class AVLNode
{
public:
    //constructor -- accepts argument of type T
    AVLNode(T data) : mpLeft(nullptr), mpRight(nullptr), mHeight(0), mData(data) {}

    //Destructor
    ~AVLNode() {}

    //setters and getters

    //Function accepts a pointer to a node and sets mpLeft to this pointer
    void setLeftPtr(AVLNode<T>* newPtr) {mpLeft = newPtr;}

    //Function accepts a pointer to a node and sets mpRight to this pointer
    void setRightPtr(AVLNode<T>* newPtr) {mpRight = newPtr;}

    //Function accepts an integer and sets the Height member to the new value
    void setHeight(const int newHeight) {mHeight = newHeight;}

    //Function returns a pointer to the left node
    AVLNode<T>* &getLeftPtr();

    //function returns a pointer to the right node
    AVLNode<T>* &getRightPtr();

    //Function returns the value of the mData member
    T getData() const;

    //Function returns the height of the node or the value in the mHeight member
    int getHeight() const;


private:
    int mHeight;
    T mData;
    AVLNode<T> * mpLeft;
    AVLNode<T> * mpRight;
};

//Function returns the height of the node or the value in the mHeight member
template<class T>
int AVLNode<T>::getHeight() const {

    if(this != nullptr)
    {
        return mHeight;
    }
    else
        return -1;
}


//Function returns the value of the mData member
template<class T>
T AVLNode<T>::getData() const {
    return mData;
}

//function returns a pointer to the right node
template<class T>
AVLNode<T> *&AVLNode<T>::getRightPtr() {
    return mpRight;
}

//Function returns a pointer to the left node
template<class T>
AVLNode<T> *&AVLNode<T>::getLeftPtr() {
    return mpLeft;
}


#endif //CPTS223_ASSIGNMENTS_AVLNODE_H
