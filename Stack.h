/*
 * Stack.h
 *
 *  Created on: Oct 29, 2014
 *      Author: jeromethai
 */

/**
 * A sample code of Creating C++ linked stacks
 */

#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

class Stack {
public:
	Stack(); // Constructor for the class
	~Stack(); // Destructor for the class
	void push( int data ); /* Push elements in the list
	 void * are pointers to data of an unspecified type*/
	int pop(); /*Pop element at the top of the stack out of the list*/
	void print(); // Print the stack
protected:
	/*accessible in the class that defines them and
	in other classes which inherit from that class.
	Here, we only need the element internally*/
    struct Element { // Struct is same as class but used for simple classes in practice
    	struct Element *next; //point to a object Element
    	int data;
    };
    Element *head; // The stack is just a pointer to the head of the stack

};

Stack::Stack() {
	// Initialize the head element
	head = NULL;
	return;
}

Stack::~Stack() {
	while( head ){
		Element *next = head->next; // next is the pointer to the next element
		delete head;
		head = next;
	}
	return;
}

void Stack::push( int data ) {
	//Allocation error will throw exception
	Element *element = new Element;
	element->data = data;
	element->next = head;
	head = element;
	return;
}


int Stack::pop() {
	Element *popElement = head;
	int data;

	/* Assume StackError exception class is defined elsewhere */
	if ( head == NULL )
		cout << "Stack is empty." << endl;

	data = head-> data;
	head = head->next;
	delete popElement;
	return data;
}


void Stack::print() {
	Element *element = head;
	if ( head == NULL ) {
		cout << "Stack is empty." << endl;
		return;
	}
	cout << "Stack: ";
	    /* A basic way of traversing a linked list */
	    while (element != NULL) { /* while there are some more nodes left */
	        /* output the value */
	        cout << element->data;
	        cout << " ";
	        /* The pointer moves along to the next one */
	        element = element->next;
	    }
	    cout << endl;

}


int testStack() {
	Stack stack;
	stack.push(10); // Explicitly passed as a pointer
	stack.push(5);
	stack.print();
    stack.pop();
    stack.pop();
    stack.print();
    return 0;
}

