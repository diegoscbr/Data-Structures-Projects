#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "bst.h"
#include<chrono>
#include "treeNode.h"
#include"splay.h"
int main(int argc, const char * argv[]) {
       std:: ifstream treeFile; 
       treeFile.open(argv[1]);

/*------------------------------------------------------------*/ 
/*------------------------------------------------------------*/ 
/*------------------------------------------------------------*/ 
  // Count the number of integers in the first, third, and fifth lines
    int counts[3] = {0, 0, 0};
    std::string line;
    for (int i = 0; i < 5; i++) {
        if (i == 0 || i == 2 || i == 4) {
            std::getline(treeFile, line);
            std::istringstream iss(line);
            int count = 0;
            int n;
            while (iss >> n) {
                count++;
            }
            counts[i/2] = count;
        } else {
            // Skip the other lines
            std::getline(treeFile, line);
        }
    }

    // Print the counts
    //std::cout << "The first line contains " << counts[0] << " integers." << std::endl;
    //std::cout << "The third line contains " << counts[1] << " integers." << std::endl;
   // std::cout << "The fifth line contains " << counts[2] << " integers." << std::endl;

    // Close the file
    treeFile.close();
/*------------------------------------------------------------*/ 
/*------------------------------------------------------------*/ 
/*------------------------------------------------------------*/ 
   BST r1;
   treeFile.open(argv[1]);
   auto start = std::chrono::steady_clock::now(); //starting chronometer
    int firstLine;
    treeFile >> firstLine; 
    //we have to insert the file into the tre
    for(int i =0; i < counts[0]; i++)
    {
        int line1_dat;
        treeFile >> line1_dat;
        r1.insertVal(line1_dat);
    }
   treeFile.close();
    cout<<endl;
/*------------------------------------------------------------*/ 
/*------------------------------------------------------------*/ 
/*------------------------------------------------------------*/ 
    treeFile.open(argv[1]);
    int line1;
    int line2;
    int line3;
    treeFile >> line1;
    treeFile >>line2;
    treeFile >>line3;
    cout<<endl;
    for(int i=0; i < counts[1]; i++)
    {
        
        int searches;
        treeFile >> searches;
       r1.search(searches);
        if(r1.search(searches) == nullptr)
        {
            r1.traversalCount++;
        }
        else{
            r1.traversalCount++;
        }
        
        
    }
     treeFile.close();

/*------------------------------------------------------------*/
cout<<"\nBSTREE After Insertions:";
r1.print();
/*------------------------------------------------------------*/ 
/*------------------------------------------------------------*/ 
treeFile.open(argv[1]);
   std::string linesto; // Variable to store each line of the file
    // Loop through each line of the file until the fifth line is reached
    for (int i = 1; i <= 5; i++) {
        std::getline(treeFile, linesto);
    }
    // Create a stringstream to read the integers from the fifth line
    std::stringstream ss(linesto);
    int numInts = 0;
    int num;
    // Count the number of integers in the line
    while (ss >> num) {
        numInts++;
    }
    // Create an array to store the integers
    int* arr = new int[numInts];
    // Reset the stringstream to read the integers again
    ss.clear();
    ss.seekg(0);
    // Read the integers into the array
    int index = 0;
    while (ss >> num) {
        arr[index++] = num;
    }
    //cout<<numInts<<endl; //outputs number of deletions
    // Print the contents of the array
    /*
    for (int i = 0; i < numInts; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
*/
    for(int i = 0; i < numInts; i++)
    {
        r1.deleteNode(r1.root, arr[i]);
    }
    delete[] arr;
   
auto end = std::chrono::steady_clock::now();
treeFile.close();
std::chrono::duration<double> elapsed_seconds = end-start;

//hard coded the integers to be deleted from p3_test4.txt
//HERE SEG FAULT 
//cout<<"\n11 has been deleted \n \n";
cout<<"\nBSTree After Removals: ";
r1.print();
cout<< "\nBSTree Traversal Count:"<<r1.traversalCount<<endl;
std::cout <<"BSTree Build Time: " << elapsed_seconds.count()*pow(10,9) << " nanoseconds\n";
//r1.deleteNode(r1.root, arr[1]); //deleting 6
//cout<<"\n6 has been deleted \n \n";
//r1.deleteNode(r1.root, arr[2]); //deleting 7
//r1.deleteNode(r1.root, arr[3]); //deleting 2
//r1.deleteNode(r1.root, arr[4]); //deleting 12
    // Close the input file and free memory allocated for the array;
/*********************************************************************************************/ 
cout<<"***********************************************\n";
/*********************************************************************************************/   
/*********************************************************************************************/     
//Splay Tree Insertion
   splayTree s1;
   treeFile.open(argv[1]);
   auto start2 = std::chrono::steady_clock::now(); //starting chronometer
    int firstLine1;
    treeFile >> firstLine1; 
    //we have to insert the file into the tree
    for(int i =0; i < counts[0]; i++)
    {
        int line1_dat;
        treeFile >> line1_dat;
        s1.insert(line1_dat);
    }
   treeFile.close();
    std::cout<<"SplayTree After Insertions:";
    s1.print();
    cout<<endl;
/*********************************************************************************************/ 
/*********************************************************************************************/   
/*********************************************************************************************/ 
 treeFile.open(argv[1]); //searching splay 
    int line_a;
    int line_b;
    int line_c;
    treeFile >> line_a;
    treeFile >>line_b;
    treeFile >>line_c;
    //cout<<endl;
    for(int i=0; i < counts[1]; i++)
    {
        int searches;
        treeFile >> searches;
       s1.search(searches);
        if(s1.search(searches) == nullptr)
        {
            s1.traversalCount++;
        }
        else{
            s1.traversalCount++;
        }
    }
     treeFile.close();
/*********************************************************************************************/ 
/*********************************************************************************************/ 
//delete splay
treeFile.open(argv[1]);
int a;
int b;
int c;
int d;
int e;
treeFile >> a;
treeFile >> b;
treeFile >> c;
treeFile >> d;
treeFile >>e;
for(int i=0; i < counts[1]; i++)
{
    int deleted;
    treeFile >> deleted;
    s1.remove(deleted);
}
auto end2 = std::chrono::steady_clock::now();
treeFile.close();
cout<<"SplayTree After Removals:";//it is deleting 13 not 11
s1.print();
cout<<"\nSplayTree Traversal Count:" << s1.traversalCount<<endl;
std::chrono::duration<double> elapsed_seconds2 = end2-start2;
std::cout <<"SplayTree Build Time: " << elapsed_seconds2.count()*pow(10,9) << " nanoseconds\n";
    return 0;
}



