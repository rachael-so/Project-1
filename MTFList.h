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
    //MTFList( const List<int> & );
    //~MTFList();
    int search(int findMe);
    void moveToFront(int i);
    
private:
    unsigned sz;
    Node<int> *frontPtr;
    
}; //END class declaration

MTFList::MTFList() {
    this->sz = 0;
    this->frontPtr = NULL;
}

int MTFList::search(int findMe) {
    
}

void MTFList::moveToFront(int i) {
    
}

#endif /* MTFList_h */
