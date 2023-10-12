//
// Created by Willow Zuvich on 10/5/23.
//
#include <array>
#include<random>
#include<chrono>
#include "AVLTree.h"

#define SIZE 50
int main()
{
    //init arrays
    std::array<int, SIZE> ascending {}, descending{}, random{};
    //setup seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    //populate arrays
    for(int i = 1, j = 99; i < 100; i += 2, j-=2)
    {
        ascending[(i - 1) / 2] = i;
        random[(i - 1) / 2] = i;
        descending[(i-1) /2] = j;
    }

    //shuffle random array
    shuffle (random.begin(), random.end(), std::default_random_engine(seed));

    //create AVLTrees
    AVLTree<int> T1, T2, T3;

    for(int n = 0; n < SIZE; n += 1)
    {
        T1.insert(ascending[n]);
       // T2.insert(descending[n]);
       // T3.insert(random[n]);
    }

    std::cout<< "Tree One Height: " << T1.height() << std::endl;
   // std::cout<< "Tree Two Height: " << T2.height() << std::endl;
   // std::cout<< "Tree Three Height: " << T3.height() << std::endl;

    //std::cout << "T1 Validate: " << T1.validate() << std::endl;
    //std::cout << "T2 Validate: " << T2.validate() << std::endl;
    //std::cout << "T3 Validate: " << T3.validate() << std::endl;

    int contains = false;
    for(int k = 1; k <= 100; k += 1)
    {
        contains = T1.contains(k);
        if(k % 2 == 0 && contains)
        {
            std:: cout << "My AVL tree implementation is Wrong." << std::endl;
        }

        contains = T2.contains(k);
        if(k % 2 == 0 && contains)
        {
            std:: cout << "My AVL tree implementation is Wrong." << std::endl;
        }

        contains = T3.contains(k);
        if(k % 2 == 0 && contains)
        {
            std:: cout << "My AVL tree implementation is Wrong." << std::endl;
        }

    }

};