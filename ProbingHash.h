#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K,V> { // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    vector<pair<pair<K,V>, EntryState>> mData;
    int numElements;

public:
    ProbingHash(int n = 11) {
        mData.resize(n);
        numElements = 0;
    }

    ~ProbingHash() {
        this->clear();
    }

    int size() {
        return numElements;
    }

    V operator[](const K& key) {

        int index = hash(key);

        for(int i = 0;mData[index].first.first != key; ++ i)
        {
            index = hash(key + i);
        }

        return mData[index].first.second;
    }

    bool insert(const std::pair<K, V>& pair) {

        bool duplicate = false;

        int index = hash(pair.first); //initial hash

        for(int i = 0; mData[index].second == VALID && !duplicate; ++i) //check spot is empty or deleted
        {
            if(mData[index].first.first == pair.first) //check for duplicates
            {
                duplicate = true;
            }
            index = hash(pair.first + i); //next hashes, until empty or deleted spot is found
        }
        //insert element
        if(!duplicate)
        {
            mData[index].first = pair;
            mData[index].second = VALID;
            ++numElements;

            //rehash if needed
            if(this->load_factor() >= 0.75)
                rehash();

        }

        return !duplicate;
    }

    void erase(const K& key) {

        int index = hash(key); //initial hash

        for(int i = 0; mData[index].first.first != key; ++i) //iterate until found
        {
            index = hash(key + i); //next hashes
        }
        //"delete" element
        mData[index].second = DELETED;
        --numElements;
    }

    void clear() {
        mData.clear();
        numElements = 0;
    }

    int bucket_count() {
        return mData.capacity();
    }

    float load_factor() {
        return ((float) numElements / (float) bucket_count());
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
        return key % mData.capacity();
    }

    void rehash(){
        vector<pair<pair<K,V>, EntryState>> oldTable = mData;

        this->clear();
        mData.resize(findNextPrime(2*oldTable.capacity()));

        for(int i = 0; i < oldTable.capacity(); ++i)
        {
            if(oldTable[i].second != DELETED)
            {
                this->insert(oldTable[i].first);
            }
        }
    }
    
};

#endif //__PROBING_HASH_H
