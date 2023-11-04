#include <iostream>
#include "MovetoFront.h"
#include<initializer_list>
MovetoFront::MovetoFront(){
    head = new Node();
    head->next = head;
}

void MovetoFront::ADD(int num)
{
    if (head->next == head)
    {
       Node * newNode = new Node(num);
       //list head points to the new added num
       head->next = newNode;
    }
    else
    {
        Node * newNode = new Node(num);
       
        newNode->next =  head->next;
        head->next = newNode;
        
    }
    
}
int MovetoFront::query(int num)
{
    int traversal = 0;
    Node* current = head;//dummy head
    while (current->next != NULL) {
        traversal++;
        if (current->next->data == num) {
            Node* query = current->next;
            current->next = query->next; //if the argument is in the node we will move to front
            query->next = head->next; //we will put the node at the front of the list
            head->next = query;
            
        return traversal;
        }
    current = current->next; 
    }
    return traversal;
}

void MovetoFront::PRINT()
{
    Node* iter = head->next;
    while (iter == NULL)
    {
        std::cout <<"The list is empty";

    }
    while (iter != NULL){
    std::cout << iter->data << " ";
    iter = iter->next;
}
   
}