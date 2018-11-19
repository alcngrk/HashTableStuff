//
//  hashtable.cpp
//  240lab10
//
//  Created by Mehmet Alican Görk on 15/04/16.
//  Copyright © 2016 Mehmet Alican Görk. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include "hashtable.h"



SetHT::SetHT(int size, hashFunc func){
    items.resize(size);
    numberOfItems = 0;
    tsize = size;
    hash = func;
}


bool SetHT::addItem(KeyType & key, ValueType& value){
    ItemType addItem = make_pair(key, value);
    int index = hash(key,tsize);
    
    if(!find(addItem.first))
    {
        items[index].push_back(addItem);
        numberOfItems++;
        return true;
    }
    return false;
}


double SetHT::loadFactor()const {
    return double(numberOfItems) / double(tsize);
}


int SetHT::size() const
{
    return numberOfItems;
}


bool SetHT::empty() const
{
    return (numberOfItems==0);
}


bool SetHT::find(KeyType & itemToFind)
{
    int index = hash(itemToFind,tsize);
    
    
    for(auto iter = items[index].begin() ; iter != items[index].end() ; iter++)
    {
        if(iter->first == itemToFind)
        {
            return true;
        }
    }
    return false;
}


ValueType SetHT::retrieve(KeyType itemToRetrieve)
{
    int index = hash(itemToRetrieve, tsize);
    
    for(auto iter = items[index].begin() ; iter != items[index].end() ; iter++)
    {
        if(iter->first == itemToRetrieve)
        {
            return iter->second;
        }
    }
    return NULL;
}


ValueType SetHT::remove(KeyType itemToRemove)
{
    int index = hash(itemToRemove,tsize);
    ValueType returnVal = NULL;
    
    for(auto iter = items[index].begin() ; iter != items[index].end() ; iter++)
    {
        if(iter->first == itemToRemove)
        {
            returnVal = iter->second;
            items[index].erase(iter);
            numberOfItems--;
            return returnVal;
        }
    }
    return NULL;
}


void SetHT::display(ostream& out)
{
    for(int i = 0 ; i < items.size() ; i++)
    {
        if(!items[i].empty())
        {
            for(auto iter = items[i].begin() ; iter != items[i].end() ; iter++)
            {
                out << *(iter -> second);
            }
        }
    }
}


double SetHT::calcAvgSynLength()
{
    double total = 0;
    double numOfNonEmptyLists = 0;
    
    for(int i = 0; i<items.size() ; i++)
    {
        if(!items[i].empty())
        {
            numOfNonEmptyLists++;
            total += items[i].size();
        }
    }
    
    return  (total/numOfNonEmptyLists);
}


unsigned long SetHT::calcMaxSynLength()
{
    unsigned long result = 0;
    
    for(int i = 0; i < items.size() ; i++)
    {
        if(items[i].size() > result)
            result = items[i].size();
    }
    
    return result;
}


void SetHT::displayStats(ostream& out)
{
    out << "STATS:" << endl;
    out << "Number of items : " << numberOfItems << endl;
    out << "Load Factor: " << loadFactor() << endl;
    out << "Average Synonym List Length: " << calcAvgSynLength() << endl;
    out << "Maximum Synonym List Length: " << calcMaxSynLength() << endl;
}







