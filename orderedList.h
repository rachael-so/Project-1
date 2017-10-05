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
    orderedList(int sz);
    ~orderedList();
    void push(int);
    void mergeSort(int first, int last);
    void merge(int a[], int first, int last);
    int search(int key);
    
private:
    unsigned sz;
    int *a;
    
}; //END class declaration

orderedList::orderedList()
{
    this->sz = 0;
}

orderedList::orderedList(int sz)
{
    this->sz = sz;
    this->a = new int[sz];
}

orderedList::~orderedList()
{
    delete [] a;
}

void orderedList::push(int value) {
    for (int i = sz; i > 0; i--) {
        a[i] = a[i-1];
    }
    a[0] = value;
    sz++;

}

void orderedList::mergeSort(int first, int last)
{
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(first, mid);
        mergeSort(mid + 1, last);
        merge(a, first, last);
    }
}

void orderedList::merge(int a[], int first, int last)
{
    int mid = (first + last ) / 2;
    int i1 = 0;
    int i2 = first;
    int i3 = mid + 1;
    int temp[sz];
    
    while (i2 <= mid && i3 <= last) {
        if (a[i2] < a[i3]) {
            temp[i1++] = a[i2++];
        }
        else {
            temp[i1++] = a[i3++];
        }
    }
    
    while (i2 <= mid)
    {
        temp[i1] = a[i2];
        i1++;
        i2++;
    }
    while (i3 <= last)
    {
        temp[i1] = a[i3];
        i1++;
        i3++;
    }
    
    for (i2 = first; i2 <= last; i2++)
    {
        a[i2] = temp[i2-first];
    }
    
}

int orderedList::search(int key)
{
    int low = 0, mid, high = sz - 1;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (key < a[mid]) {
            high = mid - 1;
        }
        else if (a[mid] < key) {
            low = mid + 1;
        }
        else
            return mid;
    }

    return -1;
}


#endif /* orderedList_h */
