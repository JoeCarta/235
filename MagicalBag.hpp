/*
MagicalBag.cpp

Joseph Cartafalsa

File for the bag ADT, implementation is included

6/13/2025
*/
#ifndef MAGICALBAG_H
#define MAGICALBAG_H
#include <iostream>

template <typename T> class MagicalBag {
public:
    /**
    Default Constructor
    */
    MagicalBag() : item_count_(0) {}

    /**
    @return: the current number of items
    */
    int getCurrentSize() const {
        return item_count_;
    }

    /**
    @reutrn: true if our bag is empty, false otherwise
    */
    bool isEmpty() const {
        if(item_count_ == 0)
            return true;
        return false;
    }

    /**
    @post: If entry exists in bag, do nothing
    @return: true if newEntry was successfully added to our array, false
    otherwise
    */
    bool add(const T& newEntry) {
        if(contains(newEntry) || item_count_ >= DEFAULT_CAPACITY) {
            return false;
        }
        items_[item_count_] = newEntry;
        item_count_++;
        return true;
    }

    /**
    @return: true if anEntry was successfully removed from our array, false
    otherwise
    */
    bool remove(const T& anEntry) {
        for(int i = 0; i < item_count_; i++) {
            if(items_[i] == anEntry) {
                items_[i] = items_[item_count_ - 1];
                item_count_--;
                return true;
            }
        }
        return false;
    }
    /**
    @post: clears bag
    */
    void clear() {
        item_count_ = 0;
    }
    /**
    @return: true if anEntry is found in our array, false otherwise
    */
    bool contains(const T& anEntry) {
        for(int i = 0; i < item_count_; i++) {
            if(items_[i] == anEntry) {
                return true;
            }
        }
        return false;
    }

protected:
    //Max size of items_ at 100
    static const int DEFAULT_CAPACITY = 100;
    //Array of bag items
    T items_[DEFAULT_CAPACITY];
    //Current count of bag items
    int item_count_;
};
#endif