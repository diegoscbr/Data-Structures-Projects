#ifndef O_List_h
#define O_List_h
#include <iostream>
#include <memory>
#include <initializer_list>
#include <fstream>
class O_List{
 public:
 O_List();
 O_List(int); 
 ~O_List(); 
 /*query method: iterate through each index of data structure. 
 each time you iterate through each index increase 
 traversal count then STOP once you have gotten 
 the number you want to query 
-----------------------------------------------------
Binary Search

 */
int Search(int); 
 //displays the contents of the list
 void PRINT();
 //adds elements to the front of the list 
 void ADD(int);
 void Sort();
 private:
 int * ptr; //pointer to the start of memory allocation
 int size; // length of the array we are passing the list to
 int end; //end of list, when it is end of full list it will equal size-1
 
};
#endif