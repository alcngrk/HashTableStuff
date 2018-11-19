//
//  main.cpp
//  240lab10
//
//  Created by Mehmet Alican Görk on 15/04/16.
//  Copyright © 2016 Mehmet Alican Görk. All rights reserved.
//

#include <iostream>
#include "hashtable.h"
//using namespace std;

// prototype for the hash function to be used
int hash(ItemType name, int tsize);


int main(){
    // create a SetHT with the tsize and hash function provided
    SetHT ht(100, hash);
    ht.addItem("Susan Smith");
    ht.addItem("John Jones");
    ht.addItem("Kevin Utley");
    ht.addItem("Barbara Wilson");
    ht.addItem("Mary Ellen Jones");
    ht.addItem("Sam Adams");
    ht.addItem("Jason Matthews");
    ht.addItem("John Jones");
    ht.addItem("Helen Hastings");
    ht.addItem("Mary Mason");
    std::cout << "load factor: " << ht.loadFactor() << std::endl;
}


int hash(ItemType name, int tsize)
{
    const unsigned long BIG_PRIME = 4294967291;
    int address = 0;
    for (int i = 0; i < name.length(); i++)
        address = address * 13 + name[i];
    
    return (address * BIG_PRIME) % tsize;
}
// implementation of the hash function to be used