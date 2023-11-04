#include "bst.h"
#include <memory>
#include <iostream>
using namespace std;
bool BST::isTreeEmpty()
{
    if(root == NULL)
        return true;
    else 
        return false;
}
//CONSTRUCTORS 
BST::BST() {
    root = NULL;
    traversalCount = 0;
}

BST::BST(int r_value) {
    root = new treeNode(r_value);//this looks more like good shit
    root->leftChild = NULL;
    root->rightChild = NULL;
}
void BST::destroyRecursive(treeNode* node)
{
    if(node)
    {
        destroyRecursive(node->leftChild);
        destroyRecursive(node->rightChild);
        delete node;
    }
}
BST::~BST() {
    destroyRecursive(root);
}

void BST::setRoot(treeNode* r)
{
    root = r;
}
treeNode* BST::getRoot()
{
    return root;
}
int BST::getTraversalCount()
{
    return traversalCount;
}
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
void BST::insertVal(int key) {
    if (root == NULL) {
        root = new treeNode(key);
        traversalCount++;
        return;
    }
    treeNode *temp = root;
    while (temp != NULL) { //the root exists
        if (key == temp->key) {
            cout << endl;
            //traversalCount++;
            cout<<"Count: "<<traversalCount<<endl;
            return;
        } 
        else if (key < temp->key) {//if the value to be inserted is less than the root
    
            if (temp->leftChild == NULL) { //check if the lesser child aka LEFT child is empty
                temp->leftChild = new treeNode(key);// instantiate a new node and link it to the parent 
                //traversalCount++;
                
                return;
            }
            else{
            temp = temp->leftChild;//if its full, then we reassign the temp to root.left, which is now the root
            }
        }
         else if (key > temp->key)
         {
            if (temp->rightChild == NULL) {
                temp->rightChild = new treeNode(key);
               // traversalCount++; 
                return;
            }
            else{
                //traversalCount++;
               temp = temp->rightChild; 
            }
           
        }
        traversalCount++;
    }
}
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
treeNode* BST::search(int query) //iterative
{
    treeNode* temp = root;
    while (temp != nullptr)
    {

        if(query > temp->key)
        {
           
            temp = temp->rightChild;
            //cout<<"value in right subtree!"<<endl;
        }
        else if(query < temp->key)
        {
            
             temp = temp->leftChild;
             //cout<<"value in left subtree!"<<endl;
        }
        else{
            //cout<<"value found!"<<endl;
            
           // cout<<"traversal Count: "<<traversalCount<<endl;
            return temp;
            
        }
        traversalCount++;
     }
     traversalCount++;
    return nullptr;
}
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
/* PRINT METHOD: DFS: */
void BST::printHelper(treeNode* node) {
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
    /* else if (node->leftChild != NULL && node->rightChild == NULL)
        {
            //cout << "["; //print an open bracket when traversing down
            printHelper(node->leftChild); //recursivly call the base case
            //cout << "]"; 
            cout <<"[]";
        }
        */
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
    /* else if (node->rightChild != NULL && node->leftChild == NULL)
        {
            //cout << "[";
            printHelper(node->rightChild);
            //cout << "]";
            cout <<"[]";
        }
        */
        cout <<"]";
    }
        
}

void BST::print() {
    printHelper(root);
}
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/

         