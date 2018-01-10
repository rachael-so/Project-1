# Project-1

Classes:
orderedList
MTFList
Node

Ordered List:
    private-
        unsigned sz

    public-
        void mergeSort(int a[], int low, int high)
        void merge(int a[], int low, int mid, int high)
        int search(int)

MTFList:
    private-
        unsigned sz
        Node<int> *frontPtr
    public-
        search(int findMe)
        moveToFront(int i)

Node:
    public-
        int info
        Node<int> *next
        Node<int> *previous
        Node<int>(int, Node<int>* = NULL, Node<int>* = NULL)
