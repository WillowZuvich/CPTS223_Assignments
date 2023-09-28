#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <queue> //added 9/28/23 by Willow Zuvich
using namespace std;


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

    /* Free all nodes in Tree
     * added 9/26/23 by Willow Zuvich
     */
    void destructorHelper(Node<T>* root)
    {
        if(root != nullptr)
        {
            destructorHelper(root->left); //traverse left tree
            destructorHelper(root->right); //traverse right tree
            delete root;
        }
    }

    /* Print maximum length path
     * added 9/27/23 by Willow Zuvich
     */
    void printMaxPathHelper(Node<T>* root)
    {
        if(root != nullptr)
        {
            std::cout << root->value << " "; //print root of subtree

            if (heightHelper(root->left) >= heightHelper(root->right)) { //navigate to the 'tallest' subtree
                printMaxPathHelper(root->left);
            } else {
                printMaxPathHelper(root->right);
            }
        }
    }


	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 * changed on 9/26/23 by Willow Zuvich
	 */
	~BST() {
        destructorHelper(this->_root);
	}

	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}

	/**
	 * Print the nodes level by level, starting from the root
	 * 9/27/23 attempted to implement with array
	 * 9/28/23 implemented with use of queue
	 */
	void printLevelOrder() {
        if(this->_root != nullptr)
        {
            queue<Node<T>*> queue; //queue to hold current level nodes

            for(queue.push(this->_root);!queue.empty();) //level control loop
            {
                //loop to print each node in level
                for(int numNodes = queue.size(); numNodes > 0; queue.pop(), --numNodes)
                {
                    std::cout << queue.front()->value << " "; //print front node

                    if(queue.front()->left != nullptr) //check for left child
                    {
                        queue.push(queue.front()->left); //enqueue left child if exists
                    }
                    if(queue.front()->right != nullptr) //check for right child
                    {
                        queue.push(queue.front()->right); //enqueue right child if exists
                    }
                }

                std::cout << std::endl; //place newline after each level
            }
        }
	}

	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	/**
	 * Print the maximum path in this tree
	 * changed on 9/27/23 by Willow Zuvich
	 */
	void printMaxPath() {
        printMaxPathHelper(_root);
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	/**
	 * Find if the BST contains the value
	 * changes on 9/26/23 by Willow Zuvich
	 */
	bool contains(T value) {
	    bool found = false;
        Node<T>* pCur = _root;

        while(pCur != nullptr && !found)
        {
            if(value < pCur->value)
            {
                pCur = pCur->left;
            }
            else if(value > pCur->value)
            {
                pCur = pCur->right;
            }
            else
            {
                found = true;
            }
        }
        return found;
	}
};

#endif

