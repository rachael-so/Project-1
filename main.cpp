//
//  main.cpp
//  project1
//
//  Created by Rachael So on 9/30/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "orderedList.h"
#include "MTFList.h"

using namespace std;

int main(int argc, const char * argv[])
{
    //variable declarations
    string fName = argv[1];
    bool loadSuccess;
    ifstream inputFile;
    unsigned size;
    string line;
    
    //start of program
    //get file from command line argument
    inputFile.open(fName.c_str());
    
    //check if file opens
    if (!inputFile) {
        loadSuccess = false;
        cout << "Failed to open file" << endl;
    }
    else if (inputFile) {
        cout << "opened file!" << endl;
        getline(inputFile, line);
        istringstream iss1(line);
        iss1 >> size;
        
        //construct orderedList
        orderedList l1(size);
        
        //construct MTFList
        MTFList l2;
        
        //populate both lists
        int value;
        getline(inputFile, line);
        istringstream iss2(line);
        while (iss2 >> value) {
            l1.push(value);
            l2.add(value);
        }
        
        cout << l2.search(100) << endl;
        cout << l2.search(1) << endl;
        cout << l2.search(1) << endl;
        
        l1.mergeSort(0, size - 1);
        cout << l1.search(1) << endl;
        cout << l1.search(2) << endl;
        cout << l1.search(101) << endl;
        
    }
    
    //close the file
    inputFile.close();

}
