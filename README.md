# Data-Structures-Projects
* This repository contains projects I implemented for my Data Structures Class along with their project description. Below I have incorporated design documents for each of the projects.
* The projects include:
  1. List Data Structure Project
  2. Binary Tree Data Structure
  3. Splay Tree Data Structure
  4. Huffman Coding Project
 
  # List Project

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



Here's a README file for my BinTree project:

# BinTree Project

This project involves the implementation of two distinct binary tree data structures: Binary Search Tree (BST) and Splay Tree. The project is primarily focused on organizing and managing integer values using these tree structures, and it offers insights into their performance differences.

## Project Overview

### Data Structures

The project utilizes two primary classes for constructing and managing the binary tree structures:
- `treeNode`: This class represents the nodes of the tree, each containing attributes like `leftChild`, `rightChild`, and `parent`. Additionally, each `treeNode` object holds an integer key to store values read from input files.

### Tree Construction

Both the Binary Search Tree and Splay Tree are constructed by reading integer values from input files. The tree structures are built by organizing the values into the respective tree nodes.

### Tree Traversal and Printing

To visualize the trees, a Depth-First Traversal (DFT) method is used. This method prints out the integer key of each `treeNode` pointer at each level of the tree, allowing users to inspect the structure and content of the trees.

### Query and Deletion Operations

The project includes operations to query and delete specific numbers from each tree structure as indicated by the input files. These operations help assess the efficiency of each tree structure in terms of performance and adaptability.

## Performance Comparison

One of the key insights obtained from this project is the performance comparison between Binary Search Trees and Splay Trees. In general, Splay Trees exhibit greater efficiency than Binary Search Trees. This efficiency can be attributed to the self-adjusting property of Splay Trees, which brings recently accessed nodes closer to the root of the tree. As a result, Splay Trees require less time to traverse for queried items.

However, it's important to note that Splay Tree balancing operations can be computationally expensive, and there may be cases where Binary Search Trees outperform Splay Trees. This complexity arises due to the cost of maintaining the self-adjusting property in Splay Trees.

## Known Issues

It's worth mentioning that there is a known issue with the Splay Tree's remove method. At times, it may incorrectly delete the wrong node. This issue is believed to be related to problems in the join and split methods. Unfortunately, due to time constraints, debugging of this issue was not completed.

On a positive note, the project successfully addresses memory leak issues, ensuring that the allocated memory is properly managed.

## Conclusion

The BinTree project provides an opportunity to explore the differences in performance and behavior between Binary Search Trees and Splay Trees. The insights gained from this project can be valuable for understanding the trade-offs and benefits of each data structure in practical applications.

Please feel free to use this project code and documentation in your own work. If you have any questions or need further information, do not hesitate to contact me.

Thank you for exploring the BinTree project!


 Here's a README file for my Huffman Coding project:

# Huffman Coding Project

This project aimed to create a Huffman Coding implementation using a priority queue class as an underlying data structure. While a priority queue array was successfully implemented, the project faced challenges related to memory leaks in the Huffman encoding part, which could not be debugged within the given time frame.

## Project Overview

### Priority Queue Implementation

The project begins with the successful implementation of a priority queue using an array as the underlying data structure. This priority queue is essential for the construction of the Huffman Tree.

### Huffman Tree Construction

The plan for constructing the Huffman Tree is outlined as follows:
1. Push all the character codes in `asciiCode[]` mapped to their corresponding frequencies in `freq[]` into the priority queue.
2. Create the Huffman Tree by repeatedly popping two nodes from the priority queue and assigning them as the left and right children of the root attribute. This newly formed node is then assigned as the root.
3. Push the newly formed root node back into the priority queue.
4. Repeat the above steps until the size of the priority queue becomes 1.
5. Traverse the Huffman Tree, with the root node as the only remaining node in the priority queue, to store the Huffman Codes.
6. Print all the stored Huffman Codes for every character.

### Challenges Faced

While a priority queue was successfully created, full implementation of the Huffman Tree was not achieved due to issues related to pointers and memory allocation. The project acknowledges that more structured planning and implementation could have resolved these issues.

## Conclusion

The Huffman Coding project provides insights into the challenges and complexities of implementing data compression using Huffman Coding. While the priority queue part of the project was accomplished, further debugging and refinements are needed for the Huffman Tree construction.

Despite the encountered challenges, this project serves as a foundation for understanding the principles of Huffman Coding and its application in data compression. Future work on this project or a similar endeavor could lead to a more successful implementation.

Please feel free to use this project code and documentation in your own work. If you have any questions or require additional information, do not hesitate to contact me.

Thank you for exploring the Huffman Coding project!

---

@diegoscbr Diego Escobar
  
