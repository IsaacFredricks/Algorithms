// University of Arkansas at Little Rock
// Department of Computer Science
// CPSI 28003 - 01 and 9S1: Algorithms
// Fall 2025
// Project 1: Doubly Linked List
// Due Date: September 30, 2025, 10:50 AM, Tuesday
// Name: Isaac Fredricks
// Student-ID (Last 4 Digits): 4922
// Description of the Program (2-3 sentences): This program has to do with doubly linked lists: making seperate classes for node and doublyLinkedList, 
// removing and adding node functions for the doubly linked list object, and specialized functions for organizing and checking the contents of a doubly linked list.
// Special functions include: drawDoublyLinkedList() show the contents of each of the nodes in an ordered fashion, isPalindrome() checks if the linked list is a palindrome,
// and function split() splits the doubly links list into n sub doubly linked lists.
// Date Written: 9/9/25
// Date Revised: 9/10/25

//comment out the main functions you aren't using and uncomment the main you will use:

//problem 1:
#include <iostream>
#include "doublyLinkedList.h"
int main()
{
	// test case 1
	// Create a doubly linked list
	DoublyLinkedList Dll_1;
	// Each node contains only one integer of a string
	Node n11(10);
	Node n12(20);
	Node n13(30);
	Node n14(40);
	Node n15(50);
	// a doubly linked list of integers by inserting nodes
	Dll_1.addNewNodeToFront(&n11);
	Dll_1.addNewNodeToBack(&n12);
	Dll_1.addNewNodeToFront(&n13);
	Dll_1.addNewNodeToBack(&n14);
	Dll_1.addNewNodeToFront(&n15);
	Dll_1.drawDoublyLinkedList();
	cout << endl;
	system("PAUSE");
	return 0;

	//output(the addresses will change, but the values won't):
	//[address:000000200E4FF978, prev:0000000000000000, value:50, next:000000200E4FF918]
	//[address:000000200E4FF918, prev:000000200E4FF978, value:30, next:000000200E4FF8B8]
	//[address:000000200E4FF8B8, prev:000000200E4FF918, value:10, next:000000200E4FF8E8]
	//[address:000000200E4FF8E8, prev:000000200E4FF8B8, value:20, next:000000200E4FF948]
	//[address:000000200E4FF948, prev:000000200E4FF8E8, value:40, next:0000000000000000]
	//Press any key to continue . . .
}

//problem 2:
/*#include <iostream>
#include "doublyLinkedList.h"
int main() {
	// test case 1
	// Create a doubly linked list
	DoublyLinkedList Dll_1;
	// Each node contains only one integer of a string
	Node n11(10);
	Node n12(20);
	Node n13(30);
	Node n14(40);
	Node n15(50);
	// a doubly linked list of integers by inserting nodes
	Dll_1.addNewNodeToFront(&n11);
	Dll_1.addNewNodeToFront(&n12);
	Dll_1.addNewNodeToFront(&n13);
	Dll_1.addNewNodeToFront(&n14);
	Dll_1.addNewNodeToFront(&n15);
	cout << Dll_1.isPalindrome() << endl;
	// test case 2
	// Create a doubly linked list
	DoublyLinkedList Dll_2;
	// Each node contains only one integer of a string
	Node n21(10);
	Node n22(20);
	Node n23(20);
	Node n24(10);
	// a doubly linked list of integers by inserting nodes
	Dll_2.addNewNodeToFront(&n21);
	Dll_2.addNewNodeToFront(&n22);
	Dll_2.addNewNodeToFront(&n23);
	Dll_2.addNewNodeToFront(&n24);
	cout << Dll_2.isPalindrome() << endl;
	system("PAUSE");
	return 0;

	//output:
	//0
	//1
	//Press any key to continue . . .
}*/

//problem 3(both test cases):
// The main.cpp
/*#include <iostream>
using namespace std;
#include "Node.h"
#include "doublylinkedlist.h"
int main(){
	// test case 1
	// Create a doubly linked list
	DoublyLinkedList *Dll_1;
	Dll_1 = new DoublyLinkedList;
	// Each node contains only one integer of a string
	Node n11(1);
	Node n12(2);
	Node n13(3);
	Node n14(4);
	Node n15(5);
	Node n16(6);
	// a doubly linked list of integers by inserting nodes
	Dll_1->addNewNodeToBack(&n11);
	Dll_1->addNewNodeToBack(&n12);
	Dll_1->addNewNodeToBack(&n13);
	Dll_1->addNewNodeToBack(&n14);
	Dll_1->addNewNodeToBack(&n15);
	Dll_1->addNewNodeToBack(&n16);
	Dll_1->split(3);

	delete Dll_1;//added by me. frees up memory in the heap
	system("PAUSE");
	return 0;

	//Output:
	//3 evenly split subdoubly linked lists
	//1 2
	//3 4
	//5 6
	//Press any key to continue . . .
}*/

/*#include <iostream>
#include "doublyLinkedList.h"
int main()
{
	// test case 2
	// Create a doubly linked list
	DoublyLinkedList *Dll_1;
	Dll_1 = new DoublyLinkedList;
	// Each node contains only one character of a string
	Node n11(1);
	Node n12(2);
	Node n13(3);
	Node n14(4);
	Node n15(5);
	Node n16(6);
	Node n17(7);
	// a doubly linked list of characters by inserting nodes
	Dll_1->addNewNodeToBack(&n11);
	Dll_1->addNewNodeToBack(&n12);
	Dll_1->addNewNodeToBack(&n13);
	Dll_1->addNewNodeToBack(&n14);
	Dll_1->addNewNodeToBack(&n15);
	Dll_1->addNewNodeToBack(&n16);
	Dll_1->addNewNodeToBack(&n17);
	Dll_1->split(3);
	system("PAUSE");
	return 0;

	//output:
	//cannot be processed
	//Press any key to continue . . .
}*/