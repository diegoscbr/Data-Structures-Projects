#ifndef splay_h
#define splay_h
#include "treeNode.h"
#include "bst.h"

class splayTree{
 public: 
    treeNode * root;
    int traversalCount;
    /*Constructors & Destructors*/
    splayTree(){
        root = nullptr;
        traversalCount = 0;
    }
    splayTree(int rootval){
        root = new treeNode(rootval);//this looks more like good shit
        root->leftChild = nullptr;
        root->rightChild = nullptr;
        root->parent = nullptr;
    }
     void destroyRecursive(treeNode* node)
     {
          if(node)
    {
        destroyRecursive(node->leftChild);
        destroyRecursive(node->rightChild);
        delete node;
    }
     }
     ~splayTree(){
         destroyRecursive(root);
     }
/********************************************************************************/
/********************************************************************************/
/********************************************************************************/
//Print methods
 void printHelper(treeNode* root);//depthFirstTrraversal approach
 void print(); 
/********************************************************************************/
/********************************************************************************/
//splaying and rotate methods
treeNode * newNode(int key);
void rightRotate(treeNode* x);
void leftRotate(treeNode* x);
void splay(treeNode* x);
 void insert(int key);
/********************************************************************************/
/********************************************************************************/
//search tree operations
treeNode* searchTreeInterior(treeNode* node, int key);
treeNode* search(int key);

/********************************************************************************/
/********************************************************************************/
    //remove and helper methods
    treeNode* findMax(treeNode* node);
    treeNode* findMin(treeNode* node);
    treeNode* join(treeNode* sub1, treeNode* sub2); //joins two trees
    void split(treeNode* &splayed, treeNode* &sub1, treeNode* &sub2); //splits tree into two subtrees
    void removeNode(treeNode* node, int key);
    void remove(int data) {
		removeNode(this->root, data);
	}
   

};

#endif
