// ------------------------------------------------ binarytree.h -------------------------------------------------------
//- 
// Programmer Name: Ahmed Nada
// Course Section Number: CSS 502
// Creation Date: 02/03/2019
// Date of Last Modification: 02/03/2019
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function:
// Header file for the BinTree class
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// created getRoot() method as public to use it in main to get height of rootNode of a tree
// --------------------------------------------------------------------------------------------------------------------
#pragma once
#include "nodedata.h"
#include <stdio.h>
#include <iostream>
using namespace std;

class BinTree {
public:
	BinTree();								// constructor
	BinTree(const BinTree &);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	
	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty() returns true
	BinTree& operator=(const BinTree &);    // assignemnt operator overload
	bool operator==(const BinTree &) const; // equality operator == overload
	bool operator!=(const BinTree &) const; // inequality operator != overload
	bool insert(NodeData*);                 // method to insert NodeData into tree
	bool retrieve(const NodeData &, NodeData* &) /*const*/; // method to return true if NodeData is found or false otherwise, also retrieve a pointer to the NodeData if found
	void displaySideways() const;			// provided below, displays the tree sideways
	int getHeight(const NodeData &) const;  // method to get height of a given NodeData
	void bstreeToArray(NodeData*[]);         // method to traverse a tree and input the NodeData of the tree into an array
	void arrayToBSTree(NodeData*[]);         // method to reconstruct a tree from an array of nodedata

private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};	
	Node * root;							// root node of tree
	
public:
	Node * getRoot() const;                 // created this method as public to use it in main to get height of rootNode of a tree

	//Private helper functions

private: 
	void setRoot(Node * n);                   // set root method
	BinTree(Node * root);                     // BinTree constructor
	Node * insert(NodeData* ptr, Node * node);			// insert helper method				
	Node * copyTree(Node * originalnode);	      //method to Copy tree by traversing the nodes copying each node
	void makeEmptyHelper(Node * n);	             // makeEmptyHelper method	
	bool identicalTrees(Node* a, Node* b) const;  //method to compare two trees by comparing the nodes of each tree
	void inorderHelper(ostream &out, Node * n) const; // helper method for the cout << operatoer overload
	friend ostream& operator<<(ostream &out, const BinTree&); //cout << operatoer overload
	void sideways(Node*, int) const;			// provided below, helper for displaySideways()
	bool find(Node * node, NodeData * ptr);		//method to check if a Node with Node data is preexisting in a tree
	NodeData * retrieveHelper(Node * n, const NodeData& d) /*const*/;	// retrieve method to retrieve Node * to a node given NodeData
	int getHeightHelper(Node * b) const;                      // get height helper that takes a node * and returns the height
	Node * retrieveNode(Node * n, const NodeData& d) const; // used for the getHight() method to return the address of a node
	int max(int a, int b) const; // method to return the max of 2 numbers
	int bstreeToArrayHelper(NodeData*[], int index, Node * n);		//helper method for bintree to array 
	Node * arrayToBSTree(NodeData* arr[], int start, int end);		// helper method to return a node * from array to bintree
};

