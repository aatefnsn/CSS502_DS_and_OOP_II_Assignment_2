// I will test your BinTree class using either this main or
// a very similar one, and this buildTree.  
// You will want to do thorough testing on your own, 
// which is done by altering the data.

// Windows and unix store files slightly differently. Windows does not
// always store an end-of-line char on the last line, where unix does.
// On windows, always make sure the cursor is on the line after
// the last line of data so it acts like unix/linux.

// presumably bintree.h includes nodedata.h so the include is not needed here
#include "pch.h"
#include "bintree.h"
#include <fstream>
#include <iostream>
using namespace std;

const int ARRAYSIZE = 100;

//global function prototypes
void buildTree(BinTree&, ifstream&);      // 
void initArray(NodeData*[]);             // initialize array to NULL

int main() {
	// create file object infile and open it
	// for testing, call your data file something appropriate, e.g., data2.txt
	ifstream infile("data2.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	// the NodeData class must have a constructor that takes a string
	NodeData iiiND("iii");
	NodeData eeeND("eee");
	NodeData notND("not");
	NodeData andND("and");
	NodeData ffND("ff");
	NodeData jjND("jj");
	NodeData ttttND("tttt");
	NodeData mND("m");
	NodeData rND("r");
	NodeData yND("y");
	NodeData ppND("pp");
	NodeData sssssND("sssss");
	NodeData zND("z");
	NodeData oooND("ooo");
	NodeData eND("e");
	NodeData tND("t");
	NodeData tttND("ttt");
	NodeData sssND("sss");
	
	BinTree T,dup,T2,T3,T4,T5;
	NodeData* ndArray[ARRAYSIZE];
	initArray(ndArray);
	cout << "Initial data:" << endl << "  ";
	buildTree(T, infile);              // builds and displays initial data
	cout << endl;


	cout << "Printing T" << endl;
	cout << T << endl;
	
	cout << "Initial data:" << endl << "  ";
	buildTree(T2, infile);
	cout << endl;
	cout << "Printing T2" << endl;
	cout << T2 << endl;
	

	cout << "Testing copy constructor" << endl;
	BinTree first(T);                  // test copy constructor
	cout << endl;
	cout << "Printing first (copy constructor of T)" << endl;
	cout << first << endl;
	cout << endl;



cout << "Comparing BinTree T and first (T copy)" << endl;
	if (T == first) {
		cout << "Trees are identical" << endl;
	}
	else {
		cout << "Trees are not identical" << endl;
	}

cout << "Initial data:" << endl << "  ";
	buildTree(first, infile);              // builds and displays initial data
	cout << endl;	
	cout << "Printing first after the change" << endl;
	cout << first << endl;
	cout << endl;
	cout << "Printing T again" << endl;
	cout << T << endl;
	cout << endl;

cout << "Printing dup before self assignment" << endl;
        cout << dup << endl;
        cout << endl;

	cout << "test operator=, self-assignment" << endl;
 	dup = dup = T; 


	cout << "Printing dup operator= after self assignment" << endl;
	cout << dup << endl;
	cout << endl;

	cout << "Printing first again after operator=" << endl;
	cout << first << endl;
	cout << endl;


	dup = dup = T;                     // test operator=, self-assignment


	cout << "Comparing BinTree dup and first == overload" << endl;

	if (dup == first) {
		cout << "Trees are identical" << endl;
	}
	else {
		cout << "Trees are not identical" << endl;
	}

	cout << "Comparing BinTree dup and first != overload" << endl;

	if (dup != first) {
		cout << "Trees are not identical" << endl;
	}
	else {
		cout << "Trees are identical" << endl;
	}



cout << "Comparing BinTree dup and T == overload" << endl;

	if (dup == T) {
		cout << "Trees are identical" << endl;
	}
	else {
		cout << "Trees are not identical" << endl;
	}

	cout << "Comparing BinTree dup and T != overload" << endl;

	if (dup != T) {
		cout << "Trees are not identical" << endl;
	}
	else {
		cout << "Trees are identical" << endl;
	}

cout << "Comparing BinTree T and T2" << endl;
	if (T == T2) {
		cout << "Trees are identical" << endl;
	}
	else {
		cout << "Trees are not identical" << endl;
	}



first.makeEmpty();

	cout << "Printing first again after makeEmpty()" << endl;
	cout << first << endl;
	cout << endl;

cout << "Initial data:" << endl << "  ";
	buildTree(T3, infile);              // builds and displays initial data
	cout << endl;
	cout << "Printing T3" << endl;
	cout << T3 << endl;
	cout << endl;
cout << "Initial data:" << endl << "  ";
buildTree(T4, infile);              // builds and displays initial data
	cout << endl;
	cout << "Printing T4" << endl;
	cout << T4 << endl;
	cout << endl;
cout << "Comparing BinTree T4 and T == overload" << endl;
	
	if (T4 == T) {
		cout << "Trees are identical" << endl;
	}
	else {
		cout << "Trees are not identical" << endl;
	}


	NodeData* p;                    // pointer of retrieved object
	bool found;                     // whether or not object was found in tree
	cout << endl;
	cout << "Printing T" << endl;
	cout << T << endl;
	cout << endl;
cout << "Testing Retrieve" << endl;
	found = T.retrieve(iiiND, p);
	cout << "Retrieve --> iii:  " << (found ? "found" : "not found") << endl;
	cout << *p << endl; // verify that pointer p now points to the correct NodeData
	found = T.retrieve(eeeND, p);
	cout << "Retrieve --> eee:  " << (found ? "found" : "not found") << endl;
	cout << *p << endl; // verify that pointer p now points to the correct NodeData
	found = T.retrieve(notND, p);
	cout << "Retrieve --> not:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(andND, p);
	cout << "Retrieve --> and:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(ffND, p);
	cout << "Retrieve --> ff:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(jjND, p);
	cout << "Retrieve --> jj:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(ttttND, p);
	cout << "Retrieve --> tttt:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(mND, p);
	cout << "Retrieve --> m:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(rND, p);
	cout << "Retrieve --> r:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(yND, p);
	cout << "Retrieve --> y:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(ppND, p);
	cout << "Retrieve --> pp:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(sssssND, p);
	cout << "Retrieve --> sssss:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(zND, p);
	cout << "Retrieve --> z:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(oooND, p);
	cout << "Retrieve --> ooo:  " << (found ? "found" : "not found") << endl;

	cout << "-----------------------------------------------------" << endl;
	found = T.retrieve(iiiND, p);
	cout << "Retrieve --> iii:  " << (found ? "found" : "not found") << endl;
	cout << *p << endl; // verify that pointer p now points to the correct NodeData
	found = T.retrieve(sssND, p);
	cout << "Retrieve --> sss:  " << (found ? "found" : "not found") << endl;
	cout << p << endl; // verify that pointer p is a nullptr for a nodeData that was not found
	found = T.retrieve(tND, p);
	cout << "Retrieve --> t:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(tttND, p);
	cout << "Retrieve --> ttt:  " << (found ? "found" : "not found") << endl;
	found = T.retrieve(andND, p);
	cout << "Retrieve --> and:  " << (found ? "found" : "not found") << endl;


	// test getHeight 
	cout << "Testing getHeight()"  << endl;
	cout << "Height    --> and:  " << T.getHeight(andND) << endl;
	cout << "Height    --> not:  " << T.getHeight(notND) << endl;
	cout << "Height    --> sss:  " << T.getHeight(sssND) << endl;
	cout << "Height    --> tttt:  " << T.getHeight(ttttND) << endl;
	cout << "Height    --> ooo:  " << T.getHeight(oooND) << endl;
	cout << "Height    --> y:  " << T.getHeight(yND) << endl;

	 cout << "the array is for bstreeToArray function" << endl;
	BinTree T10 = T2;
	initArray(ndArray);
cout << endl;
	cout << "Printing T" << endl;
	cout << T << endl;
	cout << endl;
T.bstreeToArray(ndArray);

//	while (!infile.eof()) {
//		cout << "Tree Inorder:" << endl << T;             // operator<< does endl
//		T.displaySideways();

		// test retrieve 
//		NodeData* p;                    // pointer of retrieved object
//		bool found;                     // whether or not object was found in tree
//		found = T.retrieve(andND, p);
//		cout << "Retrieve --> and:  " << (found ? "found" : "not found") << endl;
//		found = T.retrieve(notND, p);
//		cout << "Retrieve --> not:  " << (found ? "found" : "not found") << endl;
//		found = T.retrieve(sssND, p);
//		cout << "Retrieve --> sss:  " << (found ? "found" : "not found") << endl;

		// test getHeight 
//		cout << "Height    --> and:  " << T.getHeight(andND) << endl;
//		cout << "Height    --> not:  " << T.getHeight(notND) << endl;
//		cout << "Height    --> sss:  " << T.getHeight(sssND) << endl;
//		cout << "Height    --> tttt:  " << T.getHeight(ttttND) << endl;
//		cout << "Height    --> ooo:  " << T.getHeight(oooND) << endl;
//		cout << "Height    --> y:  " << T.getHeight(yND) << endl;

		// test ==, and != 
//		T2 = T;
//		cout << "T == T2?     " << (T == T2 ? "equal" : "not equal") << endl;
//		cout << "T != first?  " << (T != first ? "not equal" : "equal") << endl;
//		cout << "T == dup?    " << (T == dup ? "equal" : "not equal") << endl;
//		dup = T;

		// somewhat test bstreeToArray and arrayToBSTree
//		T.bstreeToArray(ndArray);
		int j = 0;
		while (j < ARRAYSIZE) {
			if (ndArray[j] != nullptr) {
				cout << *ndArray[j] << ",";
				j++;
			}
			else {
				break;
			}
		}
		T.arrayToBSTree(ndArray);

	cout << "Testing getHeight() after reconstructing tree"  << endl;

       cout << "Height    --> not:  " << T.getHeight(notND) << endl;		
		cout << "Height    --> ff:  " << T.getHeight(ffND) << endl;
        cout << "Height    --> sssss:  " << T.getHeight(sssssND) << endl;
		cout << "Height    --> and:  " << T.getHeight(andND) << endl;
        cout << "Height    --> jj:  " << T.getHeight(jjND) << endl;		
		cout << "Height    --> pp:  " << T.getHeight(ppND) << endl;
		cout << "Height    --> y:  " << T.getHeight(yND) << endl;
		cout << "Height    --> eee:  " << T.getHeight(eeeND) << endl;
		cout << "Height    --> iii:  " << T.getHeight(iiiND) << endl;
		cout << "Height    --> m:  " << T.getHeight(mND) << endl;
		cout << "Height    --> ooo:  " << T.getHeight(oooND) << endl;
		cout << "Height    --> r:  " << T.getHeight(rND) << endl;
        cout << "Height    --> tttt:  " << T.getHeight(ttttND) << endl;        		
        cout << "Height    --> z:  " << T.getHeight(zND) << endl;                               
        cout << "Height    --> sss:  " << T.getHeight(sssND) << endl; 


		T.displaySideways();

		T.makeEmpty();                  // empty out the tree
		initArray(ndArray);             // empty out the array

	cout << "Testing the isEmpty() method" << endl;
	bool empty = T3.isEmpty();
	cout << "Tree T3 is " << (empty ? "empty" : "not empty") << endl;
	BinTree T6;
	empty = T6.isEmpty();
	cout << "Tree T6 is " << (empty ? "empty" : "not empty") << endl;


	T3.makeEmpty();
	cout << "checking if T3 is empty after makeEmpty()" << endl;
	empty = T3.isEmpty();
	cout << "Tree T3 is " << (empty ? "empty" : "not empty") << endl;

	
	NodeData aND("a");
	NodeData lND("l");
	NodeData nND("n");


	BinTree T9;
	buildTree(T9, infile);
	cout << endl;
	cout << "T9 Tree" << endl;
	cout << T9 << endl;
	cout << "Height    --> a:  " << T9.getHeight(aND) << endl;
	cout << "Height    --> z:  " << T9.getHeight(zND) << endl;
	cout << "Height    --> l:  " << T9.getHeight(lND) << endl;
	cout << "Height    --> m:  " << T9.getHeight(mND) << endl;
	cout << "Height    --> n:  " << T9.getHeight(nND) << endl;
	cout << "Height    --> root:  " << T9.getHeight(*T9.getRoot()->data) << endl;
	

	initArray(ndArray);
	T9.bstreeToArray(ndArray);
	T9.arrayToBSTree(ndArray);

	cout << "T9 Tree after re-construction to balanced tree" << endl;
	cout << T9 << endl;
	cout << "Height    --> a:  " << T9.getHeight(aND) << endl;
	cout << "Height    --> z:  " << T9.getHeight(zND) << endl;
	cout << "Height    --> l:  " << T9.getHeight(lND) << endl;
	cout << "Height    --> m:  " << T9.getHeight(mND) << endl;
	cout << "Height    --> n:  " << T9.getHeight(nND) << endl;
	cout << "Height    --> root:  " << T9.getHeight(*T9.getRoot()->data) << endl;
	cout << "Height    --> and:  " << T9.getHeight(andND) << endl; // no existing node hight is 0
	

	//cout << "---------------------------------------------------------------"
		//	<< endl;
		//cout << "Initial data:" << endl << "  ";
		//buildTree(T, infile);
		//cout << endl;
	//}
	return 0;
}


//#include "pch.h"
//#include "bintree.h"
//#include <iostream>
//#include <string>
//using namespace std;
//
//const int ARRAYSIZE = 100;
//
////global function prototypes
//void buildTree(BinTree&, ifstream&);      // 
//void initArray(NodeData*[]);             // initialize array to NULL
//
//
//int main()
//{
//
//	// create file object infile and open it
//	// for testing, call your data file something appropriate, e.g., data2.txt
//	ifstream infile("data2_Ahmed.txt");
//	if (!infile) {
//		cout << "File could not be opened." << endl;
//		return 1;
//	}
//
//	// the NodeData class must have a constructor that takes a string
//	NodeData iiiND("iii");
//	NodeData eeeND("eee");
//	NodeData notND("not");
//	NodeData andND("and");
//	NodeData ffND("ff");
//	NodeData jjND("jj");
//	NodeData ttttND("tttt");
//	NodeData mND("m");
//	NodeData rND("r");
//	NodeData yND("y");
//	NodeData ppND("pp");
//	NodeData sssssND("sssss");
//	NodeData zND("z");
//	NodeData oooND("ooo");
//	NodeData eND("e");
//	NodeData tND("t");
//	NodeData tttND("ttt");
//	NodeData sssND("sss");
//
//	BinTree T, T2, T3, T4, T5, dup;
//	NodeData* ndArray[ARRAYSIZE];
//	initArray(ndArray);
//	cout << "Initial data:" << endl << "  ";
//	buildTree(T, infile);              // builds and displays initial data
//	cout << endl;
//	cout << "Printing T" << endl;
//	cout << T << endl;
//	
//	cout << "Initial data:" << endl << "  ";
//	buildTree(T2, infile);
//	cout << endl;
//	cout << "Printing T2" << endl;
//	cout << T2 << endl;
//
//
//	cout << "Testing copy constructor" << endl;
//	BinTree first(T);                  // test copy constructor
//	cout << endl;
//	cout << "Printing first (copy constructor of T)" << endl;
//	cout << first << endl;
//	cout << endl;
//	
//
//	cout << "Comparing BinTree T and first (T copy)" << endl;
//	if (T == first) {
//		cout << "Trees are identical" << endl;
//	}
//	else {
//		cout << "Trees are not identical" << endl;
//	}
//
//
//	
//	buildTree(first, infile);              // builds and displays initial data
//	cout << endl;	
//	cout << "Printing first after the change" << endl;
//	cout << first << endl;
//	cout << endl;
//	cout << "Printing T again" << endl;
//	cout << T << endl;
//	cout << endl;
//
//	dup = dup = first;                     // test operator=, self-assignment
//
//	cout << endl;
//	cout << "Printing dup operator=" << endl;
//	cout << dup << endl;
//	cout << endl;
//
//	cout << "Printing first again after operator=" << endl;
//	cout << first << endl;
//	cout << endl;
//
//
//	cout << "Comparing BinTree dup and first == overload" << endl;
//
//	if (dup == first) {
//		cout << "Trees are identical" << endl;
//	}
//	else {
//		cout << "Trees are not identical" << endl;
//	}
//
//	cout << "Comparing BinTree dup and first != overload" << endl;
//
//	if (dup != first) {
//		cout << "Trees are not identical" << endl;
//	}
//	else {
//		cout << "Trees are identical" << endl;
//	}
//
//
//	first.makeEmpty();
//
//	cout << "Printing first again after makeEmpty()" << endl;
//	cout << first << endl;
//	cout << endl;
//
//	cout << "Printing T again after operator=" << endl;
//	cout << T << endl;
//	cout << endl;
//
//
//	cout << "Comparing BinTree T and T2" << endl;
//	if (T == T2) {
//		cout << "Trees are identical" << endl;
//	}
//	else {
//		cout << "Trees are not identical" << endl;
//	}
//
//
//	cout << "Comparing BinTree T and first" << endl;
//	if (T == first) {
//		cout << "Trees are identical" << endl;
//	}
//	else {
//		cout << "Trees are not identical" << endl;
//	}
//
//	cout << "Comparing BinTree T and dup" << endl;
//
//	if (T == dup) {
//		cout << "Trees are identical" << endl;
//	}
//	else {
//		cout << "Trees are not identical" << endl;
//	}
//
//
//	cout << "Comparing BinTree dup and first" << endl;
//	if (dup == first) {
//		cout << "Trees are identical" << endl;
//	}
//	else {
//		cout << "Trees are not identical" << endl;
//	}
//
//
//	cout << "Comparing BinTree T and dup" << endl;
//
//	if (T == dup) {
//		cout << "Trees are identical" << endl;
//	}
//	else {
//		cout << "Trees are not identical" << endl;
//	}
//
//	cout << endl;
//	buildTree(T3, infile);              // builds and displays initial data
//	cout << endl;
//	cout << "Printing T3" << endl;
//	cout << T3 << endl;
//	cout << endl;
//
//	buildTree(T4, infile);              // builds and displays initial data
//	cout << endl;
//	cout << "Printing T4" << endl;
//	cout << T4 << endl;
//	cout << endl;
//
//	cout << "Comparing BinTree T2 and T3" << endl;
//	
//	if (T3 == T2) {
//		cout << "Trees are identical" << endl;
//	}
//	else {
//		cout << "Trees are not identical" << endl;
//	}
//
//	cout << "Comparing BinTree T4 and first == overload" << endl;
//	
//	if (T4 == first) {
//		cout << "Trees are identical" << endl;
//	}
//	else {
//		cout << "Trees are not identical" << endl;
//	}
//	
//	cout << "Comparing BinTree T4 and first != overload" << endl;
//	
//	if (T4 != first) {
//		cout << "Trees are not identical" << endl;
//	}
//	else {
//		cout << "Trees are identical" << endl;
//	}
//
//	cout << endl;
//	buildTree(T5, infile);              // builds and displays initial data
//	cout << endl;
//	cout << "Printing T5" << endl;
//	cout << T5 << endl;
//
//	cout << "Comparing BinTree T5 and first == overload" << endl;
//
//	if (T5 == first) {
//		cout << "Trees are identical" << endl;
//	}
//	else {
//		cout << "Trees are not identical" << endl;
//	}
//
//	cout << "Comparing BinTree T5 and first != overload" << endl;
//	
//	if (T5 != first) {
//		cout << "Trees are not identical" << endl;
//	}
//	else {
//		cout << "Trees are identical" << endl;
//	}
//
//	//while (!infile.eof()) {
//	//	cout << "Tree Inorder:" << endl << T;             // operator<< does endl
//	//	T.displaySideways();
//
//		// test retrieve 
//	NodeData* p;                    // pointer of retrieved object
//	bool found;                     // whether or not object was found in tree
//	cout << endl;
//	cout << "Printing T" << endl;
//	cout << T << endl;
//	cout << endl;
//
//	found = T.retrieve(iiiND, p);
//	cout << "Retrieve --> iii:  " << (found ? "found" : "not found") << endl;
//	cout << *p << endl; // verify that pointer p now points to the correct NodeData
//	found = T.retrieve(eeeND, p);
//	cout << "Retrieve --> eee:  " << (found ? "found" : "not found") << endl;
//	cout << *p << endl; // verify that pointer p now points to the correct NodeData
//	found = T.retrieve(notND, p);
//	cout << "Retrieve --> not:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(andND, p);
//	cout << "Retrieve --> and:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(ffND, p);
//	cout << "Retrieve --> ff:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(jjND, p);
//	cout << "Retrieve --> jj:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(ttttND, p);
//	cout << "Retrieve --> tttt:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(mND, p);
//	cout << "Retrieve --> m:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(rND, p);
//	cout << "Retrieve --> r:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(yND, p);
//	cout << "Retrieve --> y:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(ppND, p);
//	cout << "Retrieve --> pp:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(sssssND, p);
//	cout << "Retrieve --> sssss:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(zND, p);
//	cout << "Retrieve --> z:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(oooND, p);
//	cout << "Retrieve --> ooo:  " << (found ? "found" : "not found") << endl;
//
//	cout << "-----------------------------------------------------" << endl;
//	found = T.retrieve(iiiND, p);
//	cout << "Retrieve --> iii:  " << (found ? "found" : "not found") << endl;
//	cout << *p << endl; // verify that pointer p now points to the correct NodeData
//	found = T.retrieve(sssND, p);
//	cout << "Retrieve --> sss:  " << (found ? "found" : "not found") << endl;
//	cout << p << endl; // verify that pointer p is a nullptr for a nodeData that was not found
//	found = T.retrieve(tND, p);
//	cout << "Retrieve --> t:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(tttND, p);
//	cout << "Retrieve --> ttt:  " << (found ? "found" : "not found") << endl;
//	found = T.retrieve(andND, p);
//	cout << "Retrieve --> and:  " << (found ? "found" : "not found") << endl;
//
//
//	// test getHeight 
//	cout << "Height    --> and:  " << T.getHeight(andND) << endl;
//	cout << "Height    --> not:  " << T.getHeight(notND) << endl;
//	cout << "Height    --> sss:  " << T.getHeight(sssND) << endl;
//	cout << "Height    --> tttt:  " << T.getHeight(ttttND) << endl;
//	cout << "Height    --> ooo:  " << T.getHeight(oooND) << endl;
//	cout << "Height    --> y:  " << T.getHeight(yND) << endl;
//
//		// test ==, and != 
//		/*T2 = T;
//		cout << "T == T2?     " << (T == T2 ? "equal" : "not equal") << endl;
//		cout << "T != first?  " << (T != first ? "not equal" : "equal") << endl;
//		cout << "T == dup?    " << (T == dup ? "equal" : "not equal") << endl;
//		dup = T;*/
//
//		// somewhat test bstreeToArray and arrayToBSTree
//	cout << "the array is for bstreeToArray function" << endl;
//	BinTree T10 = T2;
//	initArray(ndArray);
//	//cout << "1" << endl;
//	
//	T2.bstreeToArray(ndArray);
//	//cout << "2" << endl;
//	
//	int j = 0;
//	//cout << "3" << endl;
//	while (j < ARRAYSIZE) {
//		if (ndArray[j] != nullptr) {
//			//cout << "4" << endl;
//			cout << *ndArray[j] << ",";
//			//cout << "5" << endl;
//			j++;
//		}
//		else {
//			break;
//		}
//	}
//	cout << endl;
	//cout << "6" << endl;

	//
	//

	////T.bstreeToArray(ndArray);

	// j = 0;
	//while (j < ARRAYSIZE) {
	//	if (ndArray[j] != nullptr) {
	//		cout << *ndArray[j] << ",";
	//		j++;
	//	}
	//	else {
	//		break;
	//	}
	//}

	//cout << endl;
	//
	//cout << "Testing the isEmpty() method" << endl;
	//bool empty = T3.isEmpty();
	//cout << "Tree T3 is " << (empty ? "empty" : "not empty") << endl;
	//BinTree T6;
	//empty = T6.isEmpty();
	//cout << "Tree T6 is " << (empty ? "empty" : "not empty") << endl;

	//cout << endl;
	//cout << "Printing T3" << endl;
	//cout << T3 << endl;

	//T3.makeEmpty();
	//cout << "checking if T3 is empty after makeEmpty()" << endl;
	//empty = T3.isEmpty();
	//cout << "Tree T3 is " << (empty ? "empty" : "not empty") << endl;

	//cout << endl;
	//cout << "Printing T3" << endl;
	//cout << T3 << endl;
	//cout << endl;


	//cout << "current ndArray contents" << endl;
	//int i = 0;
	//while (ndArray[i] != nullptr) {
	//	cout << *ndArray[i] << ",";
	//	i++;
	//}
	//cout << endl;

	//BinTree T7;
	//T7.arrayToBSTree(ndArray);

	//cout << endl;
	//cout << "Printing T7, after re-construction from Array" << endl;
	//cout << T7 << endl;
	//cout << endl;

	//BinTree T8; 
	//buildTree(T8, infile);
	//cout << endl;
	//cout << "T8 Tree" << endl;
	//cout << T8 << endl; 

	//NodeData aND("a");
	//NodeData lND("l");
	//NodeData nND("n");

	//BinTree T9;
	//buildTree(T9, infile);
	//cout << endl;
	//cout << "T9 Tree" << endl;
	//cout << T9 << endl;
	//cout << "Height    --> a:  " << T9.getHeight(aND) << endl;
	//cout << "Height    --> z:  " << T9.getHeight(zND) << endl;
	//cout << "Height    --> l:  " << T9.getHeight(lND) << endl;
	//cout << "Height    --> m:  " << T9.getHeight(mND) << endl;
	//cout << "Height    --> n:  " << T9.getHeight(nND) << endl;
	//cout << "Height    --> root:  " << T9.getHeight(*T9.getRoot()->data) << endl;
	////initArray(ndArray);
	////T9.bstreeToArray(ndArray);
	//T9.arrayToBSTree(ndArray);
	//cout << "T9 Tree after re-construction to balanced tree" << endl;
	//cout << T9 << endl;
	//cout << "Height    --> a:  " << T9.getHeight(aND) << endl;
	//cout << "Height    --> z:  " << T9.getHeight(zND) << endl;
	//cout << "Height    --> l:  " << T9.getHeight(lND) << endl;
	//cout << "Height    --> m:  " << T9.getHeight(mND) << endl;
	//cout << "Height    --> n:  " << T9.getHeight(nND) << endl;
	//cout << "Height    --> root:  " << T9.getHeight(*T9.getRoot()->data) << endl;
	//cout << "Height    --> and:  " << T9.getHeight(andND) << endl; // no existing node hight is 0
	//
	//initArray(ndArray);
	//cout << endl;
	//cout << "T8 Tree" << endl;
	//cout << T8 << endl;
	////T8.bstreeToArray(ndArray);
	////T8.arrayToBSTree(ndArray);
	//cout << "T8 Tree after re-construction to balanced tree" << endl;
	//cout << "T8 Tree" << endl;
	//cout << T8 << endl;
	//cout << "Height    --> and:  " << T8.getHeight(andND) << endl;
	//cout << "Height    --> not:  " << T8.getHeight(notND) << endl;
	//cout << "Height    --> sss:  " << T8.getHeight(sssND) << endl;
	//cout << "Height    --> tttt:  " << T8.getHeight(ttttND) << endl;
	//cout << "Height    --> ooo:  " << T8.getHeight(oooND) << endl;
	//cout << "Height    --> y:  " << T8.getHeight(yND) << endl;

	//cout << "T10 Tree" << endl;
	//cout << T10 << endl;
	//cout << "Testing bsTreeToArray version 2" << endl;
	//cout << endl;
	//initArray(ndArray);
	//cout << endl;
	////T10.bstreeToArray(ndArray);
	//cout << "current ndArray contents" << endl;
	//i = 0;
	//while (ndArray[i] != nullptr) {
	//	cout << *ndArray[i] << ",";
	//	i++;
	//}
	//cout << endl;

	//cout << "T8 Tree" << endl;
	//cout << T8 << endl;
	//cout << "Testing bsTreeToArray version 2" << endl;
	//cout << endl;
	////initArray(ndArray);
	//cout << endl;
	////T8.bstreeToArray(ndArray);
	//cout << "current ndArray contents" << endl;
	//i = 0;
	//while (ndArray[i] != nullptr) {
	//	cout << *ndArray[i] << ",";
	//	i++;
	//}
	//cout << endl;
	//delete ndArray;
	//ndArray == nullptr;
	//return 0;
//}

//------------------------------- buildTree ----------------------------------
// YOU COMMENT

// To build a tree, read strings from a line, terminating when "$$" is
// encountered. Since there is some work to do before the actual insert that is
// specific to the client problem, it's best that building a tree is not a 
// member function. It's a global function. 

void buildTree(BinTree& T, ifstream& infile) {
	string s;
	for (;;) {
		infile >> s;
		cout << s << ' ';
		if (s == "$$") break;                // at end of one line
		if (infile.eof()) break;             // no more lines of data
		NodeData* ptr = new NodeData(s);     // NodeData constructor takes string
		// would do a setData if there were more than a string

		bool success = T.insert(ptr);
		if (!success)
			delete ptr;                       // duplicate case, not inserted 
	}
}

//------------------------------- initArray ----------------------------------
// initialize the array of NodeData* to NULL pointers

void initArray(NodeData* ndArray[]) {
	for (int i = 0; i < ARRAYSIZE; i++)
		ndArray[i] = nullptr;
}


//#include "pch.h"
//#include "bintree.h"
//#include <fstream>
//#include <iostream>
//using namespace std;
//
//const int ARRAYSIZE = 100;
//
////global function prototypes
//void buildTree(BinTree&, ifstream&);      // 
//void initArray(NodeData*[]);             // initialize array to NULL
//
//int main() {
//	// create file object infile and open it
//	// for testing, call your data file something appropriate, e.g., data2.txt
//	ifstream infile("data2.txt");
//	if (!infile) {
//		cout << "File could not be opened." << endl;
//		return 1;
//	}
//
//	// the NodeData class must have a constructor that takes a string
//	NodeData notND("not");
//	NodeData andND("and");
//	NodeData sssND("sss");
//	NodeData ttttND("tttt");
//	NodeData oooND("ooo");
//	NodeData yND("y");
//	NodeData eND("e");
//	NodeData mND("m");
//	NodeData tND("t");
//
//	BinTree T, T2, dup;
//	NodeData* ndArray[ARRAYSIZE];
//	initArray(ndArray);
//	cout << "Initial data:" << endl << "  ";
//	buildTree(T, infile);              // builds and displays initial data
//	cout << endl;
//	cout << " testing copy constructor" << endl;
//	BinTree first(T);                  // test copy constructor
//	dup = dup = T;                     // test operator=, self-assignment /////////////////////////////////////////////////////////
//	while (!infile.eof()) {
//		cout << "Tree Inorder:" << endl << T;             // operator<< does endl
//		cout << "\n1" << endl;
//		T.displaySideways();
//		cout << "2" << endl;
//		// test retrieve 
//		NodeData* p;                    // pointer of retrieved object
//		bool found;                     // whether or not object was found in tree
//		cout << "3" << endl;
//		found = T.retrieve(andND, p);
//		cout << "4" << endl;
//		cout << "Retrieve --> and:  " << (found ? "found" : "not found") << endl;
//		found = T.retrieve(notND, p);
//		cout << "Retrieve --> not:  " << (found ? "found" : "not found") << endl;
//		found = T.retrieve(sssND, p);
//		cout << "Retrieve --> sss:  " << (found ? "found" : "not found") << endl;
//		cout << "5" << endl;
//		// test getHeight 
//		cout << "Height    --> and:  " << T.getHeight(andND) << endl;
//		cout << "Height    --> not:  " << T.getHeight(notND) << endl;
//		cout << "Height    --> sss:  " << T.getHeight(sssND) << endl;
//		cout << "Height    --> tttt:  " << T.getHeight(ttttND) << endl;
//		cout << "Height    --> ooo:  " << T.getHeight(oooND) << endl;
//		cout << "Height    --> y:  " << T.getHeight(yND) << endl;
//		cout << "6" << endl;
//		// test ==, and != 
//		T2 = T;//////////////////////////////////////////////////////////////////////////////////////////////////////
//		cout << "T == T2?     " << (T == T2 ? "equal" : "not equal") << endl;
//		cout << "T != first?  " << (T != first ? "not equal" : "equal") << endl;
//		cout << "T == dup?    " << (T == dup ? "equal" : "not equal") << endl;
//		//dup = T;
//		cout << "7" << endl;
//		// somewhat test bstreeToArray and arrayToBSTree
//		//T.bstreeToArray(ndArray);
//		int j = 0;
//			while (j < ARRAYSIZE) {
//				if (ndArray[j] != nullptr) {
//					//cout << "4" << endl;
//					cout << *ndArray[j] << ",";
//					//cout << "5" << endl;
//					j++;
//				}
//				else {
//					break;
//				}
//			}
//			cout << endl;
//		cout << "8" << endl;
//		T.arrayToBSTree(ndArray);
//		cout << "9" << endl;
//		T.displaySideways();
//		cout << "10" << endl;
//		T.makeEmpty();                  // empty out the tree
//		cout << "11" << endl;
//		initArray(ndArray);             // empty out the array
//
//		cout << "---------------------------------------------------------------"
//			<< endl;
//		cout << "Initial data:" << endl << "  ";
//		buildTree(T, infile);
//		cout << endl;
//	}
//
//	return 0;
//}
