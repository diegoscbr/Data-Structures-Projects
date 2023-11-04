#ifndef node_h
#define node_h
#include <iostream>
using namespace std;

  const int size = 256;
class node{ //minheap node that allows us to create a frequency table 
  public:

    //node* frequencies[size];
    int asciiKey; //data stored at each node
    int frequency; //priority ranking
    node * left; //values less than parent
    node * right; //values greater than parent
    node * parent;
    node()//default constructor 
    {
        asciiKey = 0;
        frequency = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
/*
    node(int asciiCode, int freq)//parametized constructor with freq and asciiCode
    {
        frequency = freq;
        asciiKey = asciiCode;
        left = nullptr;
        right = nullptr;
    }  
*/
    node(int asciiCode, int freq)
    {
        asciiKey = asciiCode;
        frequency = freq;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

};

#endif