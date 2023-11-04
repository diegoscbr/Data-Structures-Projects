#ifndef treeNode_h
#define treeNode_h
#include <iostream>
using namespace std;
//this is a interior node class to my binary search tree data structure
class treeNode{
  public:
   int key; //data that is stored at each branching 
    treeNode * leftChild; //values less than parent
    treeNode * rightChild; //values greater than parent
    treeNode * parent;
    treeNode()//default constructor 
    {
        key = 0;
        leftChild = NULL;
        rightChild = NULL;
    }
    treeNode(int value)//parametized constructor
    {
        key = value;
        leftChild = NULL;
        rightChild = NULL;
    }  
};

#endif