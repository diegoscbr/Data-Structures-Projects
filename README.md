# Data-Structures-Projects
* This repository contains projects I implemented for my Data Structures Class along with their project description. Below I have incorporated design documents for each of the projects.
* The projects include:
  1. List Data Structure Project
  2. Binary Tree Data Structure
  3. Splay Tree Data Structure
  4. Heap Data Structure
 
  # List Project Report by Diego Escobar

This project is an implementation of two data structures for handling ordered lists and Move-to-Front (MTF) lists from input files.

## Ordered List (O_List)

The ordered list data structure, known as O_List, functions like an array and reads input files into its indices. The O_List class offers three essential methods:

1. `O_List::O_List(int length)`: The constructor with an integer argument is used to determine the length of the array by reading the first line of the input file.

2. `void O_List::ADD(int num)`: The ADD method appends values to the end of the list. It increments the index of the last element every time a new value is added.

3. `int O_List::Search(int num)`: The Search method is implemented as a binary search. It returns a traversal count that is incremented at each layer of binary parsing of the array. Binary search is much more efficient than linear search when querying because it operates in O(logN) time complexity as opposed to O(N) for linear search.

## Move-to-Front List (MTF)

The MTF list data structure, called Move-to-Front, is implemented as a singly linked list. It utilizes a dummy head and has `head->next` as the first element in the list. The internal Node struct is used to create the structure of the list. The Move-to-Front class provides two key methods:

1. `void MTF::ADD(int num)`: The ADD method inserts a new node at the front of the list by having `head` point to the newly instantiated Node (newNode), and `newNode` then points to the first item in the list (`head->next`).

2. Query method (not explicitly mentioned): The query method iterates through the list and, when it finds values requested to be queried, it moves them to the front of the list. This method returns a traversal count that is incremented each time it parses the list for the queries of the input file.

These data structures offer efficient ways to manage lists and are especially useful when dealing with large datasets.

Feel free to use this code and documentation in your own projects. If you have any questions or need further information, please don't hesitate to contact me.

Thank you for using this project!


 
  
