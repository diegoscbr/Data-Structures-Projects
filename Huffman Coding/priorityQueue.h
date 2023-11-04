#ifndef priorityQueue_h
#define priorityQueue_h
#include <iostream>
#include <memory>
#include <algorithm>
#include <initializer_list>
#include <fstream>
#include<climits>
using namespace std;

struct Node
{
    int asciiCode;
    int frequency;
    Node * left;
    Node * right;
    Node * top;
    string code = ""; //assigns a code member to generate tree
};

class PriorityQueue 
{
private:
    Node* root;
    Node* arr;
    int capacity;
    int size;
public:
    Node* getRoot()
    {
        return root;
    }
    Node getNodeatIndex(int i)
    {
        return arr[i];
    }
    Node* getTop()
    {
        arr[1].top = &arr[1];
        return arr[1].top;
    }
    int getSize(){return size;}
    PriorityQueue()
    {
        capacity = 5; 
        size = 0;
        root = new Node();
        root->left = nullptr;
        root->right = nullptr;
        arr = new Node[capacity];
        arr[0].frequency = -1;
    }
    void resize(int newCapacity);
    ~PriorityQueue()
    {
        delete[] arr;
    }
    void insert(Node num);
    void removeTop();
    void removeHelper(int removed);
    void assignCodes(Node* tree);
    Node* generateTree();
    void printCodes(Node* r);
};
#endif
