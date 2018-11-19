//
//  hashtable.h
//  240lab10
//
//  Created by Mehmet Alican Görk on 15/04/16.
//  Copyright © 2016 Mehmet Alican Görk. All rights reserved.
//

#ifndef hashtable_h
#define hashtable_h

#ifndef SETHT
#define SETHT

#include<list>
#include<vector>
#include<string>
#include "BankAccount.h"

/*
	The class SetHT uses a chained hash table as the data
 structure for implementing a Set.  The only methods
 provided are a constructor, a addItem method and a
 method to return the load factor.
 */

typedef BankAccount* ValueType;
typedef int KeyType;
typedef pair<KeyType, ValueType> ItemType;


typedef int(*hashFunc)(KeyType name, int tsize);

class SetHT{
    
public:
    
    SetHT(int size, hashFunc func);
    //input: size of hash table to be constructed
    //       and the hash function to be used
    //output: none
    //side effects: a chained hashtable is created
    
    
    double loadFactor() const;
    //input: none
    //output: load factor of the hashtable
    //side effects: none
    
    int size() const;
    //input: none
    //output: returns the number of items in the SetHT object
    //side effects: none
    
    bool empty() const;
    //input: none
    //output: returns true if the SetHT object is empty, false otherwise
    //side effects: none
    
    bool addItem(KeyType& key, ValueType& value);
    //input: an item to be added
    //output: true if the item is added, false if the key already existed in the list
    //side effects: item has been added to the hash table
    
    bool find(KeyType & itemToFind);
    //input: an item to search for and the list(a member of the vector) to search the item in
    //output: return true if the item is found, false otherwise
    //side effects: none
    
    ValueType retrieve(KeyType itemToRetrieve);
    //input: takes a KeyType(string) as an argument.
    //output: returns the BankAccount object corresponding to the input
    //side effects: none.
    
    ValueType remove(KeyType itemToRemove);
    //input: takes a KeyType(string) as an argument.
    //output: returns the BankAccount object corresponding to the input
    //side effects: removes the returned BankAccount from SetHT object, returns the memory used by it to the heap.
    
    void display(ostream& out);
    //input: takes an ostream object as a pointer
    //output: displays the information of items in Set
    //
    
    void displayStats(ostream& out);
    //
    //
    //
    
    
private:
    // declare data members for:
    // the size of the hash table
    int tsize;
    
    // the hash table - a vector of lists containing items
    std::vector<std::list<ItemType>> items;
    
    // the number of items stored in the hash table
    int numberOfItems;
    
    // the hash function
    hashFunc hash;
    
    double calcAvgSynLength();
    //
    //
    //
    unsigned long calcMaxSynLength();
    //
    //
    //
    
    
};

#endif







#endif /* hashtable_h */
