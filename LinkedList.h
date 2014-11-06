/*
 * LinkedList.h
 *
 *  Created on: Oct 29, 2014
 *      Author: jeromethai
 */




/**
 * A sample code of Creating C++ linked lists,
 * Including definitions the list node class and linked list class,
 * and how to create a blank linked list and a one-node linked list.
 *
 * Outline: understand the definition and structure of the linked
 * list and build a linked list based on it.
 */

#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

/*
 A linked list is a list constructed using pointers. It is not fixed in
 size and could grow and shrink while the program is running.

 A typical definition of list nodes contains at least two parts, both the
 content or date of each element and the pointer to the next element,
 which is shown in the figure below.

 +---------+
 |  Data   | -----> holds the data of this element in the list.
 +---------+
 | pointer | -----> is a pointer to the next element in the list.
 +---------+

 ***Attention***:
 The pointer holds the address of the next element, not the address of the
 data in the next element, even though they are the same in value sometimes.
 And It should be set to NULL while acting as the last node of the list.


 Implementation of the single linked list:
 +---------+    --->+---------+    --->+---------+
 |  Data   |    |   |  Data   |    |   |  Data   |
 +---------+    |   +---------+    |   +---------+
 | pointer |-----   | pointer |-----   | pointer |
 +---------+        +---------+        +---------+
 */


/* definition of the list node class */
//private members of a class are accessible only from within other members of the same class
//(or from their "friends").
//By default, all members of a class declared with the class keyword have private access
//for all its members. Therefore, any member that is declared before any other access specifier
//has private access automatically. For example:
class Node
{
	friend class LinkedList; /*A friend class in C++ can access the "private" and "protected" members
	 of the class in which it is declared as a friend.*/
	int _value; /* data, can be any data type, but use integer for easiness */
	Node *_pNext; /* pointer to the next node, pointer to a Node object */

public:
    /* Constructors with No Arguments */
    Node(void)
    : _pNext(NULL)
    { }

    /* Constructors with a given value */
    Node(int val)
    : _value(val), _pNext(NULL)
    { }

    /* Constructors with a given value and a link of the next node */
    Node(int val, Node* next)
    : _value(val), _pNext(next)
    {}

    /* Getters */
    int getValue(void)
    { return _value; }

    Node* getNext(void)
    { return _pNext; }
};


/* definition of the linked list class */
class LinkedList
{
    /* pointer of head node */
    Node *_pHead;
    /* pointer of tail node */
    Node *_pTail;

public:
    /* Constructors with No Arguments */
    LinkedList(void);
    /* Constructors with a given value of a list node */
    LinkedList(int val);
    /* Destructor */
    ~LinkedList(void);

    /* Traversing the list and printing the value of each node */
    void traverse_and_print();
};


LinkedList::LinkedList()
{
    /* Initialize the head and tail node */
    _pHead = _pTail = NULL;
}

LinkedList::LinkedList(int val)
{
    /* Create a new node, acting as both the head and tail node */
    _pHead = new Node(val);
    _pTail = _pHead;
}

LinkedList::~LinkedList()
{
    /*
     * Leave it empty temporarily.
     * It will be described in detail in the example "How to delete a linkedlist".
     */
}


void LinkedList::traverse_and_print()
{
    Node *p = _pHead;

    /* The list is empty? */
    if (_pHead == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    cout << "LinkedList: ";
    /* A basic way of traversing a linked list */
    while (p != NULL) { /* while there are some more nodes left */
        /* output the value */
        cout << p->_value;
        /* The pointer moves along to the next one */
        p = p->_pNext;
    }
    cout << endl;
}


int testLinkedList()
{
    /* Create an empty list */
    LinkedList list1;
    cout << "Created an empty list named list1." << endl;
    /* output the result */
    cout << "list1:" << endl;
    list1.traverse_and_print();

    /* Create a list with only one node */
    LinkedList list2(10);
    cout << "Created a list named list2 with only one node." << endl;
    /* output the result */
    cout << "list2:" << endl;
    list2.traverse_and_print();

    return 0;
}
