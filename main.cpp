//"Ethics Statement: Other than anything noted in the disclosures
//below, the code submitted is of my design and my design alone.
//I recieved no help nor used any references, resources, and had no
//discussion with other classmates.
//I understand the University policy concerning ethics and
//understand that violating this policy will result in drastic repercussions.
//
//Disclosures: no disclosures

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
    
    if (argc < 2) {
        cout << "ERROR: NEED INPUT FILE";
    }
    else {
        //start of program
        //get file from command line argument
        inputFile.open(fName.c_str());
        
        //check if file opens
        if (!inputFile) {
            loadSuccess = false;
            cout << "Failed to open file" << endl;
        }
        else if (inputFile) {
            //        cout << "opened file!" << endl;
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
            
            //        cout << l2.search(100) << endl;
            //        cout << l2.search(1) << endl;
            //        cout << l2.search(1) << endl;
            
            l1.mergeSort(0, size - 1); //sort orderedList
            
            //        cout << l1.search(1) << endl;
            //        cout << l1.search(2) << endl;
            //        cout << l1.search(101) << endl;
            
            int numQ;
            int query;
            clock_t t; //initialize
            //        int u;
            int t1 = 0, t2 = 0;
            inputFile >> numQ;
            //        cout << endl << numQ << endl;
            for (int i = 0; i < numQ; i++) {
                inputFile >> query;
                
                //search and time for orderedList
                t = clock();
                l1.search(query);
                t = clock() - t;
                t1 += t;
                
                //search and time for MTFList
                t = clock();
                l2.search(query);
                t = clock() - t;
                t2 += t;
                //            u++;
            }
            //        cout << u << endl;
            
            cout << "Time needed to complete the sequence of retrievals for the "
            << " Ordered Array Structure: " << t1 << " clock ticks per second" << endl << endl;
            
            cout << "Time needed to complete the sequence of retrievals for the MTF Linked "
            << "List Structure: " << t2 << " clock ticks per second" << endl << endl;
            
            cout << "Total retrieval times for both Lists: " << t1 + t2 << " clock ticks per second"
            << endl << endl;
            
            if (t1 < t2) {
                cout << "Retrievals for the Ordered Array Stucture was faster than for the MTF Linked "
                << "List Structure\n";
            }
            else {
                cout << "MTF Linked List Structure for the Ordered Array Stucture was faster than for "
                << "Ordered Array Structure\n";
            }
            
        }
        
        //close the file
    inputFile.close();
    }

}
