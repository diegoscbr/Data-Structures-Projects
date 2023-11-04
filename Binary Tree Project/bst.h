#ifndef bst_h
#define bst_h
#include "treeNode.h"

class BST {
public:
    treeNode* root;  // a pointer to the root node
    int traversalCount;  // attribute to be updated each time a node is accessed during traversal

    // Constructors and destructor
    BST();
    BST(int key);
    ~BST();

    // Public methods
    bool isTreeEmpty(); //check if empty
    //void insert(treeNode* newNode); //primitive, requires external instantiation of nodes
    void insertVal(int data);
    treeNode* search(int key);
    void printHelper(treeNode* root);//depthFirstTrraversal approach
    void print(); 
    void destroyRecursive(treeNode* node); //helper method for destructor
  // Getters and setters
    treeNode* getRoot();
    void setRoot(treeNode* root);
    int getTraversalCount();
/*-----------------------------------------*/
/*-----------------------------------------*/
/*-----------------------------------------*/
    treeNode * minValueNode(treeNode* node) {
        treeNode * current = node;
    /* loop down to find the leftmost leaf */
    
     while (current->leftChild != NULL) {
      current = current->leftChild;
    }
    traversalCount++;
    return current;
  }
/*-----------------------------------------*/
/*-----------------------------------------*/
/*-----------------------------------------*/
treeNode * deleteNode(treeNode *  & r , int v) {
    // base case 
     // cout<< "Traversing Node: "<< r->key<<endl;
    if (r == NULL) {
      //traversalCount++;
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (v < r -> key) {
       // cout << "Node is in left subtree"<<endl;
       // traversalCount++;
      r -> leftChild = deleteNode(r -> leftChild, v);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v > r -> key) {
       // cout<<"Node is in right subtree"<<endl;
       // traversalCount++;
      r->rightChild = deleteNode(r -> rightChild, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else  {
      // node with only one child or no child 
      if (r->leftChild == NULL) {
        //cout<<"CASE 0 or 1 determined"<<endl;
        treeNode * temp = r->rightChild;
        delete r;
        //traversalCount++;
        return temp;
      } else if (r -> rightChild == NULL) {
        treeNode * temp = r->leftChild;
        delete r;
        //traversalCount++;
        return temp;
      } else {
         // cout<<"CASE 2 detemined"<<endl;
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        treeNode * temp = minValueNode(r->rightChild);
        // Copy the inorder successor's content to this node 
        r->key = temp->key;
        // Delete the inorder successor 
        //traversalCount++;
        r->rightChild = deleteNode(r->rightChild, temp->key);
        //deleteNode(r->right, temp->value); 
      }
      traversalCount++;
    }
   traversalCount++;
    return r;
  }

/*----------------------------------------------*/
/*----------------------------------------------*/
/*----------------------------------------------*/
/*----------------------------------------------*/

};

#endif
