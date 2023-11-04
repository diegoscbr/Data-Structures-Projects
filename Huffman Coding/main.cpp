#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>   
#include "priorityQueue.h"
using namespace std;
const int ARRAY_SIZE = 256;
Node* generateTree(PriorityQueue pq);
char getChar(int asciiCode){
    char character = static_cast<char>(asciiCode);
    return character;
}
int main(int argc, const char * argv[]) {
    int *asciiCodes = new int[ARRAY_SIZE]; //array that stores unsorted ascii codes
    int *frequencies = new int[ARRAY_SIZE]; //array that stores unsorted frequencies
    ifstream file(argv[1]);
    if (!file) {
        cout << "Error: Unable to open file";
        return 1;
    }
    char ch;
    while (file.get(ch)) { //while file is oen use the get operator to read each charachter 
        int asciiValue = (int)ch; //converts ascii characters to their ascii code representation
        asciiCodes[asciiValue]++; //iterates character by character, pushing each to the array,
        //note: the ascii value == index of array
       // count++; //increments the count as each character is read
    }
    file.close();
    //cout << "The number of characters read from the file is: " << count << endl;
   // cout<<endl;
   // cout <<"ASCII|FREQUENCY\n";
   // cout<<"-------------------\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (asciiCodes[i] > 0) {
            frequencies[i] = asciiCodes[i];
            //cout << i << ": " << frequencies[i] << endl;
        }
    }
    delete[] asciiCodes;
    //ASCII_CODES are stored in asciiCodes[]
    //ASCII_FREQUENCIES Stored in frequencies[]
    //an external array where we will iterativly insert ASCII_CODES and ASCII_FREQUENCIES
    Node* lazyInsert = new Node[ARRAY_SIZE];
    for(int i =0; i < ARRAY_SIZE; i++)
    {
        lazyInsert[i].asciiCode = i;
        lazyInsert[i].frequency = frequencies[i];
     
    } 
    auto start = std::chrono::steady_clock::now(); 
   PriorityQueue p1;
   //building the heap from the indicies
    for(int i =0; i < ARRAY_SIZE; i++)
    {  
        if(lazyInsert[i].frequency > 0)
        {
            p1.insert(lazyInsert[i]);
        }
            //cout<<p1.getNodeatIndex(i).frequency<<" "<<endl;  
    }
    delete[] lazyInsert;
    
    cout<<"Queue(ASCII code, Frequency): "<<endl;
    for(int i =0; i < p1.getSize(); i++)
    {   
        char letter = getChar(p1.getNodeatIndex(i).asciiCode);
            cout<<"[ '"<<letter<<"', "<<p1.getNodeatIndex(i).frequency<<"]"<<endl; 
    }
    
   
    Node* root = p1.generateTree();
    //cout<<root->left->frequency<<endl;
   // cout<<root->right->right<<endl;
    // cout<<root->frequency<<endl;
    //p1.assignCodes(root);
   // p1.printCodes(huff);

auto end = std::chrono::steady_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::cout <<"PQ Build Time: " << elapsed_seconds.count()*pow(10,9) << " nanoseconds\n";
    return 0;
}
/*
1. Push all the characters in ch[] mapped to corresponding frequency freq[] in priority queue.
2. To create Huffman Tree, pop two nodes from priority queue.
3. Assign two popped node from priority queue as left and right child of new node.
4. Push the new node formed in priority queue.
5. Repeat all above steps until size of priority queue becomes 1.
6. Traverse the Huffman Tree (whose root is the only node left in the priority queue) to store the Huffman Code
7. Print all the stored Huffman Code for every character in ch[].*/

//instantiate huffTree in main