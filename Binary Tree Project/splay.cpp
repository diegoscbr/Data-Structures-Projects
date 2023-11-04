#include "splay.h"
#include <memory>
#include <iostream>
using namespace std;
treeNode* splayTree::newNode(int key){
    treeNode* Node = new treeNode(key);
    return Node;
}

/********************************************************************************/
/********************************************************************************/
//rotate right method
void splayTree::rightRotate(treeNode* rotate)
{
    treeNode* y = rotate->leftChild;
		rotate->leftChild = y->rightChild;
		if (y->rightChild != nullptr) {
			y->rightChild->parent = rotate;
		}
		y->parent = rotate->parent;
		if (rotate->parent == nullptr) {
			this->root = y;
		} else if (rotate == rotate->parent->rightChild) {
			rotate->parent->rightChild = y;
		} else {
			rotate->parent->leftChild = y;
		}
		y->rightChild = rotate;
		rotate->parent = y;
}
/********************************************************************************/
/********************************************************************************/
//rotate left at node x
void splayTree::leftRotate(treeNode* rotate)
{
   treeNode* y = rotate->rightChild;
   rotate->rightChild = y->leftChild;
   if(y->leftChild != nullptr){
       y->leftChild->parent = rotate;
   }
   y->parent = rotate->parent;
   if(rotate->parent == nullptr){
       this->root = y;
   }
   else if (rotate == rotate->parent->leftChild) {
			rotate->parent->leftChild = y;
		}
   else {
			rotate->parent->rightChild = y;
		}
		y->leftChild = rotate;
		rotate->parent = y;
}
/********************************************************************************/
/********************************************************************************/
//splay method
void splayTree::splay(treeNode* x)
{
    while (x->parent) {
			if (!x->parent->parent) {
				if (x == x->parent->leftChild) {
					// zig rotation
					rightRotate(x->parent);
				} else {
					// zag rotation
					leftRotate(x->parent);
				}
			} else if (x == x->parent->leftChild && x->parent == x->parent->parent->leftChild) {
				// zig-zig rotation
				rightRotate(x->parent->parent);
				rightRotate(x->parent);
			} else if (x == x->parent->rightChild && x->parent == x->parent->parent->rightChild) {
				// zag-zag rotation
				leftRotate(x->parent->parent);
				leftRotate(x->parent);
			} else if (x == x->parent->rightChild && x->parent == x->parent->parent->leftChild) {
				// zig-zag rotation
				leftRotate(x->parent);
				rightRotate(x->parent);
			} else {
				// zag-zig rotation
				rightRotate(x->parent);
				leftRotate(x->parent);
			}
		}
}
/********************************************************************************/
/********************************************************************************/
//insert Method
void splayTree::insert(int key){
		// normal BST insert
		treeNode* newNode = new treeNode();
		newNode->parent = nullptr;
		newNode->leftChild = nullptr;
		newNode->rightChild = nullptr;
		newNode->key = key;
		treeNode* y = nullptr;
		treeNode* x = this->root;

		while (x != nullptr) {
			y = x;
			if (newNode->key < x->key) { //insert in left subtree
				x = x->leftChild;
			} else { //insert in right subtree
				x = x->rightChild;
			}
			traversalCount++;
		}

		// y is parent of x
		newNode->parent = y;
		if (y == nullptr) {
			root = newNode;
		} else if (newNode->key < y->key) {
			y->leftChild = newNode;
		} else {
			y->rightChild = newNode;
		}

		// splay the node
		splay(newNode);
		traversalCount++;
	}
/********************************************************************************/
/********************************************************************************/
    /* PRINT METHOD: DFS: */
void splayTree::printHelper(treeNode* node) {
    //base case and if nothing is found
    if (node == NULL) { 
        cout<<"[]"; //program should only print [] if one child has value AND one child is null
        return;
    }
    else
    {
        //base case: we print the key value
        cout << "["<< node->key;
        if (node->leftChild != NULL && node->rightChild == NULL) {//if there is a left child found, 
            //cout << "["; //print an open bracket when traversing down
            printHelper(node->leftChild); //recursivly call the base case
            //cout << "]"; //once that has terminated we close the bracket
                cout<<"[]";
        }
        if (node->rightChild != NULL && node->leftChild == NULL) {
            cout <<"[]";
            //cout <<"[";
            printHelper(node->rightChild);
            //cout << "]";
                
        }
        if (node->rightChild != NULL && node->leftChild != NULL)
        {
            printHelper(node->leftChild);
            printHelper(node->rightChild);
        }
        cout <<"]";
    }
        
}

void splayTree::print() {
    printHelper(root);
}
/********************************************************************************/
/********************************************************************************/
//search operations
treeNode* splayTree::searchTreeInterior(treeNode* node, int key) //implemented recursivly 
{
		if (node == nullptr || key == node->key) { //if node is null or the query == key of the node
			traversalCount++;
			return node;
		}
		if (key < node->key) { //in left subtree 
			traversalCount++;
			return searchTreeInterior(node->leftChild, key);
		} //otherwise in right subtree
		traversalCount++;
		return searchTreeInterior(node->rightChild, key);
}
treeNode* splayTree::search(int key)
{
    treeNode*  query = searchTreeInterior(this->root, key);
		if (query) {
			traversalCount++;
			splay(query);
		}
		traversalCount++;
		return query;
}
/********************************************************************************/
/********************************************************************************/
//remove and helper methods
treeNode* splayTree::findMax(treeNode* node){
    while (node->rightChild != nullptr) { //iterate through right children until leaf
			node = node->rightChild;
		}
		traversalCount++;
		return node;
}
treeNode* splayTree::findMin(treeNode* node){
    while(node->leftChild != nullptr){ //iterate through left children until leaf
        node = node->leftChild;
    }
	traversalCount++;
    return node;
}
treeNode* splayTree::join(treeNode* subtree1, treeNode* subtree2)
{
    if (!subtree1) {
			return subtree2;
		}

		if (!subtree2) {
			return subtree1;
		}
		treeNode* maxNode = findMax(subtree1);
		splay(maxNode);
		maxNode->rightChild = subtree2;
		subtree2->parent = maxNode;
		traversalCount++;
		return maxNode;
}

void splayTree::split(treeNode* &splayed,treeNode* &subtree1, treeNode* &subtree2){
   splay(splayed);
		if (splayed->rightChild) { //in right subtree
			subtree2 = splayed->rightChild;
			subtree2->parent = nullptr;
			traversalCount++;
		} else { //in left subtree
			subtree2 = nullptr;
			traversalCount++;
		}
		subtree1 = splayed;
		subtree1->rightChild = nullptr; //split it and null the child
		splayed= nullptr;
		traversalCount++;

}
void splayTree::removeNode(treeNode* node, int key){
		treeNode* x = nullptr; //instantiating a node pointer as null
		treeNode* t;
		treeNode* s;
		while (node != nullptr){ //while the node being passed is not null
			if (node->key == key) {// if the key within it is equal to the key desired to be deleted...
				x = node; //set it to the nullptr node
			}

			if (node->key < key) { 
				node = node->rightChild;
			} else {
				node = node->leftChild;
			}
			traversalCount++;
		}
		traversalCount++;
		if (x == nullptr) {
			traversalCount++;
			//cout<<"Couldn't find key in the tree"<<endl;
			return;
		}
		split(x, s, t); // split the tree
		if (s->leftChild){ // remove x
			s->leftChild->parent = nullptr;
		}
		root = join(s->leftChild, t);
		delete(s);
		s = nullptr;
}
   
/*
int main()
{
    splayTree s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);
	s1.print();
	cout<<endl;
    s1.search(1);
    s1.search(3);
    s1.search(2);
    s1.search(4);
    s1.search(6);
    s1.search(5);
    s1.search(6);
    s1.search(8);
    s1.print();
	s1.remove(4);
	s1.remove(2);
	s1.remove(3);
	s1.remove(4);
	cout<<endl;
	s1.print();
    return 0;
}
*/