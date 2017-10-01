//
//  orderedList.h
//  project1
//
//  Created by Rachael So on 9/30/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#ifndef orderedList_h
#define orderedList_h

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
    orderedList( const List<T> & );
    ~List();
    void mergeSort(int a[], int low, int high)
    void merge(int a[], int low, int mid, int high)
    int search(int findMe)
    
private:
    unsigned sz
    Node<int> *frontPtr
    Node<int> *backPtr
    
}; //END class declaration



#endif /* orderedList_h */
