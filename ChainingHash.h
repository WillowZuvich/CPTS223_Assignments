/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"


// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
    //vector of lists
    vector<list<pair<K,V>>> mData;

    //current number of elements in table
    int numElements;

public:
    ChainingHash(int n = 11) {
        mData.resize(n);
        numElements = 0;
    }

    ~ChainingHash() {
        this->clear();
    }

    int size() {
        return numElements;
    }

    V operator[](const K& key) {
        list<pair<K,V>> & curList = mData[hash(key)];

        auto itr = curList.begin();

        for(; itr->first != key; itr++);

        return itr->second;
    }

    bool insert(const std::pair<K, V>& pair) {
        //hash
        list<std::pair<K,V>> & insertList = mData[hash(pair.first)];
        //check for duplicates
        if(find(insertList.begin(), insertList.end(), pair) == insertList.end())
        {
            //insert into list
            insertList.push_back(pair);
            ++numElements;
            if(this->load_factor() >= 0.75)
            {
                //rehash
                reHash();
            }
            return true;
        }
        else
            return false;
    }

    void erase(const K& key) {
        list<pair<K,V>> & curList = mData[hash(key)];

        auto itr = curList.begin();

        for(; itr->first != key; itr++);

        curList.erase(itr);

        --numElements;
    }

    void clear() {
        for(int i = 0; i < mData.capacity(); ++i)
        {
            mData[i].clear();
        }
        numElements = 0;
    }

    int bucket_count() {
        return mData.capacity();
    }

    float load_factor() {
        return ((float) numElements / (float)this->bucket_count());
    }

private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return key % mData.capacity();  //key mod tableSize
    }

    void reHash() {

        vector<list<pair<K,V>>> oldTable = mData; //create copy of old table

        mData.resize(findNextPrime(2*mData.capacity())); //resize new table
        this->clear(); //clear elements from new table

        //copy all elements to new table
        for(int i = 0; i < oldTable.capacity(); i++)
        {
            auto itr = oldTable[i].begin();
            while(itr != oldTable[i].end())
            {
                insert(*itr);
                ++itr;
            }
        }
    }

};

#endif //__CHAINING_HASH_H
