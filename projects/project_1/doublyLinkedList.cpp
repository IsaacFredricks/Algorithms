#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP
#include "doublylinkedlist.h"
DoublyLinkedList::DoublyLinkedList()//builds 2xly linked list object
{
	head = NULL;
	tail = NULL;
}


DoublyLinkedList::~DoublyLinkedList(){}//frees memory from heap

void DoublyLinkedList::addNewNodeToFront(Node* newNode)
{
	if (head == NULL && tail == NULL) {
		head = tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

void DoublyLinkedList::addNewNodeToBack(Node* newNode)
{
	if (head == NULL && tail == NULL) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

Node* DoublyLinkedList::removeNodeFromFront()
{
	Node* tempNode;
	tempNode = head;
	head = head->next;
	return tempNode;
}

void DoublyLinkedList::removeNodeFromBack()
{
	Node* tempNode;//like removeNodeFromFront() but no return
	tempNode = tail;
	tail = tail->prev;
}

void DoublyLinkedList::displayDoublyLinkedList()
{
	Node* tempNode;
	tempNode = head;
	while (tempNode != NULL){
		cout << tempNode->value << " ";
		tempNode = tempNode->next;
	}
}

void DoublyLinkedList::drawDoublyLinkedList(){
	// CODE in C/C++ TO BE ADDED for Project 1
	// Might reuse displayDoublyLinkedList()
	Node* tempNode;
	tempNode = head;
	while (tempNode != nullptr) {
		//format: [address: , prev: , value: , next: ]
		cout << "[address:" << tempNode << ", prev:" << tempNode->prev << ", value:"
		<< tempNode->value << ", next:" << tempNode->next << "]\n";
		tempNode = tempNode->next;
	}
}

bool DoublyLinkedList::isPalindrome(){
	// CODE in C/C++ TO BE ADDED for Project 1
	//make 2 temp nodes
	//see if each increment nodes to see if the first and last nodes' values are equal to eachother

	Node* frontNode;
	Node* backNode;
	frontNode = head;
	backNode = tail;

	while (frontNode != nullptr && backNode != nullptr) {
		if (frontNode->value != backNode->value) {
			return false;
		}

		if (frontNode == backNode) {//stops when frontNode and backNode are at same memory address
			break;//gets out of while loop
		}
		frontNode = frontNode->next;
		backNode = backNode->prev;
	}
	
	return true;
}

void DoublyLinkedList::split(int n){// n is the number of even partitions
	// CODE in C/C++ TO BE ADDED for Project 1
	//iterate through the 2xly linked list with a counter first for size
	//get # of sub 2xly linked lists by size / n
	//make sub lists
	//do all the if statements and printy stuff
	Node* tempNode;
	tempNode = head;
	int size{ 0 };
	while (tempNode != nullptr) {
		size++;
		tempNode = tempNode->next;
	}

	if (n < 1 || n > size || size % n > 0) {
		//size % n > 0 checks if there is a remainder
		std::cout << "cannot be processed\n";
	}
	
	else {
		int subListSize =  size / n;
		int numLists = size / subListSize;
		tempNode = head;
		std::cout << numLists << " evenly split subdoubly linked lists\n";
		
		for (int i{ 0 }; i < numLists; i++) {
			DoublyLinkedList* tempList = new DoublyLinkedList;
			for (int j{ 0 }; j < subListSize; j++) {
				tempList->addNewNodeToBack(new Node(tempNode->value));
				//makes new node but with tempNode's value. Avoids repeating values/nodes
				tempNode = tempNode->next;
			}
			tempList->displayDoublyLinkedList();
			std::cout << '\n';//newline for each sublist
		}
	}
}

#endif