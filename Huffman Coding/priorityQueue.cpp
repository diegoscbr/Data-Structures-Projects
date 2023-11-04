#include <iostream>

#include "priorityQueue.h"

void PriorityQueue::resize(int cap) 
{
    Node*arrayNew = new Node[cap];
    for (int i = 0; i <= size; i++) 
    {
        arrayNew[i] = arr[i];
    }
    delete[] arr;
    arr = arrayNew;
    capacity = cap;
}



void PriorityQueue::insert(Node num) //inserts a new node into the queue
{
    if (size == capacity - 1) 
    {
        resize(capacity * 2);
    }
    
    int newIdx = ++size;

    while (num.frequency < arr[newIdx / 2].frequency) 
    {
        arr[newIdx] = arr[newIdx / 2];
        newIdx = newIdx / 2;
    }

    arr[newIdx] = num;
}


void PriorityQueue::removeTop()
{
    arr[1] = arr[size];
    size = size - 1;
    removeHelper(1);
}

void PriorityQueue::removeHelper(int removed)
{
    Node temp = arr[removed]; //declaring temp array
    int child = 0;
    while (removed * 2 <= size)
    {
        child = removed * 2;
        if (child != size && arr[child + 1].frequency < arr[child].frequency)
        {
            child++;
        }
        if (arr[child].frequency < temp.frequency)
        {
            arr[removed] = arr[child];
            removed = child;
        }
        else
        {
            break;
        }
    }
    arr[removed] = temp;
}


Node* PriorityQueue::generateTree()
{
   

     Node* parent = new Node();
    while(size > 1)
    {
       
        Node* leftChild = new Node();
        *leftChild = *getTop();
        removeTop();

        Node* rightChild = new Node();
        *rightChild = *getTop();
        removeTop();

        parent->frequency = leftChild->frequency + rightChild->frequency;
        parent->left = leftChild;
        parent->right = rightChild;
        delete leftChild;
        delete rightChild;
        insert(*parent);
        size--;
    }
    removeTop();
    root = parent;
    delete parent;
    return root;
     
}

void PriorityQueue::assignCodes(Node* r) {
     if (r == nullptr) {
        return;
    }
    
    if (r->left == nullptr && r->right == nullptr) {
        // Leaf node found
        return;
    }
    
    // Traverse left subtree and append 0 to the code
    if (r->left != nullptr) {
        r->left->code = r->code + "0";
        assignCodes(r->left);
    }
    
    // Traverse right subtree and append 1 to the code
    if (r->right != nullptr) {
        r->right->code = r->code + "1";
        assignCodes(r->right);
    }
}

void PriorityQueue::printCodes(Node* r)
{
      if (r == nullptr) {
        return;
    }

    if (r->left == nullptr && r->right == nullptr) {
        cout << "ASCII code: " << r->asciiCode << ",Frequency: "<<r->frequency<<", Huffman code: " << r->code << endl;
    }

    printCodes(r->left);
    printCodes(r->right);
}
/*
int main()
{
	Node n1;
    Node n2;
    Node n3;
    Node n4;
    Node n5;
	n1.frequency = 10;
    n1.asciiCode = 93;
	n2.frequency = 13;
    n2.asciiCode = 25;
	n3.frequency = 5;
    n3.asciiCode = 44;
	n4.frequency = 8;
    n4.asciiCode =67;
	n5.frequency = 2;
    n5.asciiCode =88;

	PriorityQueue p1;
	p1.insert(n1);
	p1.insert(n2);
	p1.insert(n3);
	p1.insert(n4);
	p1.insert(n5);
    //p1.removeTop();
	//cout<<p1.getNodeatIndex(1).frequency<<endl;
    //cout<<p1.generateTree(hF).frequency<<endl;
    Node huffTree = p1.generateTree();
    cout<<"left: "<<huffTree.left->frequency<<" right: "<<huffTree.right->frequency<<" Frequency: " <<huffTree.frequency<<endl;
   // printCodes(root);
    //cout <<root->frequency;
    //cout<<root->right->asciiCode;

	return 0;
}
*/