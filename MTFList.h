//
//  MTFList.h
//  project1
//
//  Created by Rachael So on 10/1/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#ifndef MTFList_h
#define MTFList_h

#include<iostream>
#include "Node.h"

using namespace std;

/****************************************************************************
 ****************************************************************************
 *                                                                          *
 *                      class MTFList declaration                           *
 *                                                                          *
 ****************************************************************************
 ****************************************************************************/

class MTFList
{
public:
    MTFList();
    //MTFList( const MTFList<int> & );
    ~MTFList();
    void add(int);
    int search(int);
    void moveToFront(Node*);
    void clear();
    
private:
    unsigned sz;
    Node *frontPtr;
    
}; //END class declaration

MTFList::MTFList()
{
    this->sz = 0;
    this->frontPtr = NULL;
}

MTFList::~MTFList()
{
//    cout << "MTFList::~MTFList() Entered destructor for class MTFList\n";
    if ( frontPtr != NULL ) {
//        unsigned long oldCount = sz;
//        cout << "calling member function clear() ";
//        cout << "to deallocate memory for all objects on the list\n";
        
        clear();
        
//        cout << "number of elements on the list was: " << oldCount << std::endl;
//        cout << "number of elements on list now is:  " << sz << std::endl;
        
        frontPtr = NULL;
    }
    
//    cout << "MTFList::~MTFList() Exiting destructor for class MTFList\n";

}

void MTFList::add(int value)
{
//    cout << "entering add\n";
    Node *addMe = new Node(value, NULL, NULL);
    
    if (sz == 0) {
        // this is first object to be added to the list
        frontPtr = addMe;
        sz = 1;
    }
    else {
        addMe->next = frontPtr;
        frontPtr->previous = addMe;
        addMe->previous = NULL;
        frontPtr = addMe;
        sz++;
    }
//    cout << "exiting add\n";

}

int MTFList::search(int value)
{
//    cout << "entering MTFList search\n";
    Node *current = frontPtr;
    int index = 0;

    while (current->next != NULL && current->info != value) {
        current = current->next;
        index++;
    }
    if ( current->info == value ) {
        moveToFront(current);
//        cout << "exiting MTFList search\n";
        return index;
    }
    
    return -1;
}

void MTFList::moveToFront(Node *moveMe)
{
//    cout << "entering moveToFront\n";
    if ( moveMe->previous != NULL ) {
        
        moveMe->previous->next = moveMe->next;
        
        if (moveMe->next != NULL)
            moveMe->next->previous = moveMe->previous;
    
        moveMe->next = frontPtr;
        frontPtr->previous = moveMe;
        moveMe->previous = NULL;
        frontPtr = moveMe;
    }
//    cout << "exiting moveToFront\n";
}

void MTFList::clear()
{
    Node *current = frontPtr;
//    int i = 0;
    
//    cout << "\tMTFList::clear() preparing to remove " << sz;
//    cout << " Nodes from the linked list\n";
    
    while (frontPtr != NULL)
    {
//        i++;
        frontPtr = frontPtr->next;
        delete [] current;
        current = frontPtr;
        sz--;
    }
    
    
//    cout << "\tMTFList::clear() removed " << i << " Nodes from the list\n";
//    cout << "\tMTFList::clear() new count is: " << sz << endl;
    
}


#endif /* MTFList_h */
