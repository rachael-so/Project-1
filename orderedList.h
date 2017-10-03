//
//  orderedList.h
//  project1
//
//  Created by Rachael So on 9/30/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#ifndef orderedList_h
#define orderedList_h

#include<iostream>
#include "Node.h"

using namespace std;

/****************************************************************************
 ****************************************************************************
 *                                                                          *
 *                    class orderedList declaration                         *
 *                                                                          *
 ****************************************************************************
 ****************************************************************************/

class orderedList
{
public:
    orderedList();
    //orderedList( const List<int> & );
    //~orderedList();
    void mergeSort(int a[], int low, int high);
    void merge(int a[], int low, int mid, int high);
    int search(int findMe);
    
private:
    unsigned sz;
    Node *frontPtr;
    Node *backPtr;
    
}; //END class declaration

orderedList::orderedList() {
    this->sz = 0;
    this->frontPtr = NULL;
    this->backPtr = NULL;
}

void orderedList::mergeSort(int a[], int low, int high) {
    
}

void orderedList::merge(int a[], int low, int mid, int high) {
    
}

int orderedList::search(int findMe) {
    return 0;
}


#endif /* orderedList_h */
