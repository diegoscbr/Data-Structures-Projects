#ifndef MovetoFront_h
#define MovetoFront_h

#include <iostream>
#include <memory>
#include <initializer_list>
#include <fstream>
struct Node{
    int data;
    Node* next;
    //default constructor
    Node(){
        next = NULL;
    }
    //parametized constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class MovetoFront{
 Node * head; 
 public:
 MovetoFront();
 //MovetoFront(std::initializer_list<int>);
 int query(int);
 //displays the contents of the list
 void PRINT();
 //adds elements to the front of the list 
 void ADD(int);
};
#endif