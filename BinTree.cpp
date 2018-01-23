// ------------------------------------------------ binarytree.cpp -------------------------------------------------------
//- 
// Programmer Name: Ahmed Nada
// Course Section Number: CSS 502
// Creation Date: 02/03/2019
// Date of Last Modification: 02/03/2019
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function:
// source file for the BinTree class. Has all the methods used in main class as per the instructions in the assignment file
// as well as the supporting documents
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// #include "pch.h" must remain in the file for proper compilation
// --------------------------------------------------------------------------------------------------------------------
#include "pch.h"
#include "bintree.h"

// ------------------------------------BinTree()-----------------------------------------------
// Description: empty constructor
// ---------------------------------------------------------------------------------------------------
BinTree::BinTree() 
{
	this->root = nullptr; // set root to nullptr
}

// ------------------------------------BinTree(Node * root)-----------------------------------------------
// Description: non-empty constructor, take a Node as root
// ---------------------------------------------------------------------------------------------------

BinTree::BinTree(Node * root) 
{
	this->root = root; // set input node to root
}

// ------------------------------------Node * BinTree::getRoot() const-----------------------------------------------
// Description: function to return root, i used it main method to access bintree root
// ---------------------------------------------------------------------------------------------------

BinTree::Node * BinTree::getRoot() const 
{
	return this->root; // returns root
}

// ------------------------------------void BinTree::setRoot(Node * n)-----------------------------------------------
// Description: function to set root
// ---------------------------------------------------------------------------------------------------

void BinTree::setRoot(Node * n) 
{
	this->root = n; // set node n as root
}

// ------------------------------------BinTree::BinTree(const BinTree &t)-----------------------------
// Description: copy constructor
// ---------------------------------------------------------------------------------------------------

BinTree::BinTree(const BinTree &t) 
{
	if (t.getRoot() == nullptr) 
	{
		this->root = nullptr; // if bintree root is nullptr then set root to nullptr
	}
	else 
	{
		this->root = copyTree(t.root); // if root is not nullptr then call the method to CopyTree()
	}
}

// ------------------------------------~BinTree()-----------------------------
// Description: destructor, it calls makeEmpty() method which deletes the bintree
// ---------------------------------------------------------------------------------------------------

BinTree::~BinTree() 
{
	this->makeEmpty(); // destructor calls makeEmpty() method
}

// --------------------BinTree::Node * BinTree::copyTree(Node * originalnode)-----------------------------
// Description: method to copy tree that takes recursively tree nodes
// ---------------------------------------------------------------------------------------------------

BinTree::Node * BinTree::copyTree(Node * originalnode) 
{
	if (originalnode == nullptr) 
	{
		return nullptr;
	}
	else 
	{
		Node * newnode = new Node();	// create new node	
		newnode->data = new NodeData(*originalnode->data); // create new nodedata as well otherwise if one 
		//tree that uses same nodedata pointer deletes the nodedata then other tree sharing same nodedata will have an error
		newnode->left=(copyTree(originalnode->left)); // recurisvely to the left and copy tree
		newnode->right=(copyTree(originalnode->right)); // recursively to the right to copy tree
		return newnode; //return newnode which should be root to a new tree
	}	
}

// --------------------operator=(const BinTree &b)-----------------------------
// Description: assignemnt operator overload
// ---------------------------------------------------------------------------------------------------

BinTree& BinTree::operator=(const BinTree &b)
{
	if (this == &b) // self assignemnt check
	{
		return *this;
	}
	if (this->root != nullptr) 
	{
		this->makeEmpty(); // if the tree will have previous data then make it empty before 
		//assigning new nodes and new nodedata to it otherwise old data will get lost and create memory leak
	}
	this->root = copyTree(b.getRoot()); // then you can start copying the tree 
	return *this;
}

// --------------------operator==(const BinTree& b) const-----------------------------
// Description: equality operator overload
// ---------------------------------------------------------------------------------------------------

bool BinTree::operator==(const BinTree& b) const 
{
	if (this->getRoot() != nullptr && b.getRoot() != nullptr) 
	{
		return identicalTrees(this->root, b.root); //if both trees roots are not nullptr then run the 
		//identicallTree function to iterate over a tree node by node
	}
	return false;
}

// --------------------BinTree::identicalTrees(Node* a, Node* b) const-----------------------------
// Description: function to check if two tree are identical by going over the trees nodes
// ---------------------------------------------------------------------------------------------------

bool BinTree::identicalTrees(Node* a, Node* b) const
{
	if (a == nullptr && b == nullptr)
		return true;
	if (a != nullptr && b != nullptr)
	{
		return (*a->data == *b->data && identicalTrees(a->left, b->left) && identicalTrees(a->right, b->right)); // recursively 
		//iterate over all nodes and check if nodes' nodedata is same
	}
	return false;
}

// --------------------bool BinTree::operator!=(const BinTree& b) const ------------------------------
// Description: inequality operator overload, same as euality check uses the helper method identicalTrees
// ---------------------------------------------------------------------------------------------------

bool BinTree::operator!=(const BinTree& b) const 
{
	if (this->getRoot() != nullptr && b.getRoot() != nullptr) 
	{
		return !identicalTrees(this->root, b.root);
	}
	return true;
}

// --------------------int BinTree::getHeight(const NodeData& b) const ------------------------------
// Description: function to getHeight of a certain node using its NodeData
// ---------------------------------------------------------------------------------------------------

int BinTree::getHeight(const NodeData& b) const 
{
	int result = 0;
	if (this->getRoot() == nullptr) {
		return -1; // if tree is empty height is -1
	}
	Node * temp = retrieveNode(this->getRoot(), b); // retrieve node * that contains the node data 
	if (temp == nullptr)
		return 0; // if temp is nullptr so node with the given nodedata is not existing and so return 0
	else 
	{
		result = getHeightHelper(temp); // if it is not nullptr so call getHeightHelper that takes a node * of the node that has the node data
	}
	return result;
}

// --------------------int BinTree::max(int a, int b) const ------------------------------
// Description: function to get max of two int numbers
// ---------------------------------------------------------------------------------------------------

int BinTree::max(int a, int b) const 
{
	if (a >= b) 
	{
		return a;
	}
	else
		return b;
}

// --------------------int BinTree::getHeightHelper(Node * b) const------------------------------
// Description: helper function to return the height of a node
// ---------------------------------------------------------------------------------------------------

int BinTree::getHeightHelper(Node * b) const 
{
	int depthVal, depthRight, depthLeft;
	if (b == nullptr) 
	{
		return 0; // no height if node is null
	}
	else 
	{
		depthRight = getHeightHelper(b->right); // go all the way right to get right path
		depthLeft = getHeightHelper(b->left); // go all the way left to get left path
	}
	depthVal = 1 + max(depthLeft, depthRight); // depth of node as per definition is 1+ max of the right or left path
	return depthVal;
}

// --------------------BinTree::Node * BinTree::retrieveNode(Node * n, const NodeData& d) const------------------------------
// Description: function to retun a node * of a node that contains given nodedata or else nullptr
// ---------------------------------------------------------------------------------------------------

BinTree::Node * BinTree::retrieveNode(Node * n, const NodeData& d) const 
{
	bool found = false;
	Node * result = nullptr;
	if (*n->data == d) 
	{
		found = true;
		return n;
	}
	else 
	{
		if (n->left != nullptr && !found && result == nullptr) // if left is not null and not found and result is nullptr
		{
			result = retrieveNode(n->left, d); // go left
			if (result != nullptr) // if result is no longer null then return the result, no need to continue
				return result;
		}
		if (n->right != nullptr && !found && result == nullptr)  // same as for left side
		{
			result = retrieveNode(n->right, d);
			if (result != nullptr)
				return result;
		}
		if (!found) // if tree has been itirated over and still not found then retun nullptr
		{
			result = nullptr;
		}
	}
	return result;
}

// --------------------bool BinTree::retrieve(const NodeData& d, NodeData* &b)------------------------------
// Description: function to retun a bool true of a node that contains given nodedata or else false and the pointer should be pointing ti the nodedata
// ---------------------------------------------------------------------------------------------------

bool BinTree::retrieve(const NodeData& d, NodeData* &b) // same steps as for the previous retruive function, this one return bool instead of node *
{
	bool found = false;
	if (d == *this->getRoot()->data && !found && b == nullptr) 
	{
		b = this->getRoot()->data;
		found = true;
		return true;
	}
	else 
	{
		if (((this->getRoot()->left != nullptr) || (this->getRoot()->right != nullptr)) && !found) 
		{
			b = retrieveHelper(this->getRoot(), d);
			if (b != nullptr) {
				found = true;
				return true;
			}
		}
	}
	return found;
}

// --------------------NodeData * BinTree::retrieveHelper(Node * n, const NodeData& d)------------------------------
// Description: helper function to retun a nodedata * of a node and a given nodedata
// ---------------------------------------------------------------------------------------------------

NodeData * BinTree::retrieveHelper(Node * n, const NodeData& d) // same steps as for the previous retrieve function
{
	bool found = false;
	NodeData * result = nullptr;
	if (*n->data == d) 
	{
		found = true;
		return n->data;
	}
	else {
		if (n->left != nullptr && !found && result == nullptr) 
		{
			result = retrieveHelper(n->left, d);
			if (result != nullptr)
				return result;
		}
		if (n->right != nullptr && !found && result == nullptr) 
		{
			result = retrieveHelper(n->right, d);
			if (result != nullptr)
				return result;
		}

		if (!found) 
		{
			result = nullptr;
		}
	}
	return result;
}

// --------------------bool BinTree::find(Node * n, NodeData * ptr)------------------------------
// Description: function to traverse a tree and see if a node pointer has been inserted in the tree before
// Note: this function might be doing same thing as retrieve function, however, i created it before knowing retrieve will do same thing
// ---------------------------------------------------------------------------------------------------

bool BinTree::find(Node * n, NodeData * ptr) 
{
	bool found = false;
	if (*n->data == *ptr) 
	{
		return true;
	}
	else 
	{
		if (n->left != nullptr && !found)
			found = find(n->left, ptr);
		if (n->right != nullptr && !found)
			found = find(n->right, ptr);
	}
	return found;
}

// --------------------bool BinTree::insert(NodeData* ptr) ------------------------------
// Description: function to insert a nodedata pointer in a bintree and retunr true if success or false is unsuccessful
// ---------------------------------------------------------------------------------------------------

bool BinTree::insert(NodeData* ptr) 
{
	if (this->root == nullptr) 
	{
		this->root = new Node(); // create new node
		this->root->data = ptr; // assign data as pointer passed from buildtree function
		this->root->left = nullptr;
		this->root->right = nullptr;
		return true;
	}
	else if (*ptr > *(root->data) && find(this->root, ptr) == false)  // if nodedata is greater than root go right
	{
		this->root->right=(insert(ptr, this->root->right));
		return true;
	}
	else if (*ptr < *(root->data) && find(this->root, ptr) == false) // if nodedata is less than root go left
	{
		this->root->left=(insert(ptr, this->root->left));
		return true;
	}
	return false;
}

// --------------------BinTree::Node * BinTree::insert(NodeData* ptr, Node * node)------------------------------
// Description: helper function to insert a nodedata pointer in a bintree aand return the node *
// ---------------------------------------------------------------------------------------------------

BinTree::Node * BinTree::insert(NodeData* ptr, Node * node) 
{
	if (node == nullptr) 
	{
		node = new Node();
		node->data = ptr;
		node->left = nullptr;
		node->right = nullptr;
	}
	else if (*ptr > *(node->data)) 
	{
		node->right=(insert(ptr, node->right));
	}
	else 
	{
		node->left=(insert(ptr, node->left));
	}
	return node;
}

// --------------------void BinTree::inorderHelper(ostream &out, Node * n) const------------------------------
// Description: helper function for cout function, returns outstream with the tree nodedata strings
// ---------------------------------------------------------------------------------------------------


void BinTree::inorderHelper(ostream &out, Node * n) const 
{
	if (n == nullptr) 
	{
		return;
	}
	if (n->left != nullptr) {
		inorderHelper(out, n->left);
	}

	out << *n->data << " ";

	if (n->right != nullptr) 
	{
		inorderHelper(out, n->right);
	}
}

// --------------------ostream& operator<<(ostream &os, const BinTree& n)------------------------------
// Description: cout operator overload, provides outstream for the helper function to return the outstream filled to return it
// ---------------------------------------------------------------------------------------------------

ostream& operator<<(ostream &os, const BinTree& n) 
{
	 n.inorderHelper(os, n.getRoot());
	 return os; 
}

// --------------------void BinTree::makeEmptyHelper(Node * n)------------------------------
// Description: helper function for makeEmpty function, it does post order traversal to remove nodes and nodedata left, right, node
// ---------------------------------------------------------------------------------------------------


void BinTree::makeEmptyHelper(Node * n) 
{
	if (n == nullptr) 
	{
		return;
	}
	else 
	{
		if (n->left != nullptr) 
		{
			makeEmptyHelper(n->left); // recursive deletion to left
		}
		if (n->right != nullptr) 
		{
			makeEmptyHelper(n->right); // recurise deletion to right
		}

		delete n->left; // delete left pointer
		n->left = nullptr; // set to null
		delete n->right; // delete right pointer
		n->right = nullptr; // set to null
		if (n->data != nullptr) // if nodedata is not null then remove it
		{
			delete (n->data); // delete nodedata object
			n->data = nullptr; // set it to null
		}
	}
}

// --------------------void BinTree::makeEmpty()------------------------------
// Description: function to empty a tree
// ---------------------------------------------------------------------------------------------------


void BinTree::makeEmpty()
{ 
	if (this->root != nullptr) 
	{
		makeEmptyHelper(this->getRoot());		// calls helper function starting root
		delete root->data; // deelte root nodeData
		root->data = nullptr; // set root data to null
		delete this->root; // delete root
		this->root = nullptr; // set it to null
	}
	else 
	{
		return;
	}
}

// --------------------bool BinTree::isEmpty() const------------------------------
// Description: function to retun true if tree is empty or false otherwise
// ---------------------------------------------------------------------------------------------------


bool BinTree::isEmpty() const 
{
	if (this->getRoot() == nullptr)
		return true;
	else
		return false;
}

// --------------------void BinTree::bstreeToArray(NodeData* arr[])------------------------------
// Description: function to import tree nodedata into an arraoy of node data
// ---------------------------------------------------------------------------------------------------

void BinTree::bstreeToArray(NodeData* arr[]) 
{
	int i = 0;
	if (this->root != nullptr) // if root is not null or if tree is existing
	{
		i = bstreeToArrayHelper(arr, i, this->root); // call the bstreetoArray helper method
		this->makeEmpty();
	}
}

// --------------------int BinTree::bstreeToArrayHelper(NodeData* arr[], int index, Node * n)------------------------------
// Description: helper function to import tree nodedata into an array of node data
// ---------------------------------------------------------------------------------------------------

int BinTree::bstreeToArrayHelper(NodeData* arr[], int index, Node * n) 
{
	int newindex = index; // record a new index to be returned for the tree nodedata array not get overwritten 
	int originalindex = index; // orgiianl index
	if (n == nullptr) 
	{
		return originalindex; // if n is null index will be same
	}
	if (n->left != nullptr)  // traverse left, as you go left always the original index will remain the same, 
	{
		newindex = bstreeToArrayHelper(arr, originalindex, n->left); // call the method recursively using the original index 
		//and the result should be the new index of the new element
	}
	arr[newindex] = new NodeData(*n->data); //in order addition of the nodedata in the array
	newindex++; // increment array index

	if (n->right != nullptr) // call the method recurseively going to the right
	{
		newindex = bstreeToArrayHelper(arr, newindex, n->right); // as you go to the right, we will alwyas use the new index since we add left, node, right
	}
	return newindex;
}

// --------------------void BinTree::arrayToBSTree(NodeData* arr[]) ------------------------------
// Description: function to reconstruct tree from nodedata array
// ---------------------------------------------------------------------------------------------------

void BinTree::arrayToBSTree(NodeData* arr[]) 
{
	if (arr != nullptr) 
	{
		int size = 0;
		int highest_index = 0;
		while (arr[size] != nullptr)  
		{
			size++; // calculating array size
		}
		highest_index = size - 1; // highest index is size -1
		Node * temp = new Node(); // create new node
		temp->data = new NodeData(*arr[(highest_index) / 2]); // nodedata is a new nodedta
		delete arr[(highest_index) / 2]; // delete array index
		this->setRoot(temp); // set root to middle node
		this->root->left = arrayToBSTree(arr, 0, ((size - 1) / 2) - 1); // 0 5 // split the array 
		//into 2 and recursively assign root as the equation in the assignment document, first half is to reconstruct left subtree
		this->root->right = arrayToBSTree(arr, ((size - 1) / 2) + 1, ((size - 1))); //7 13 // second half of the array should reconstruct right part of the tree
	}
}

// --------------------BinTree::Node * BinTree::arrayToBSTree(NodeData* arr[], int start, int end)------------------------------
// Description: helper function to reconstruct tree from nodedata array
// ---------------------------------------------------------------------------------------------------

BinTree::Node * BinTree::arrayToBSTree(NodeData* arr[], int start, int end) // function takes two indexes of the start and end of the subarray 
{
	if  (start <= end) 
	{
		Node * temp = new Node();
		temp->data = arr[(start + end) / 2]; // every time assign node data to middle nodedata
		temp->left = arrayToBSTree(arr, start, ((start + end) / 2) - 1); // recursively resplit the array left
		temp->right = arrayToBSTree(arr, ((start + end) / 2) + 1, (end)); // recursively resplit the array right
		return temp;
	}
	else 
	{
		return nullptr;
	}
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}