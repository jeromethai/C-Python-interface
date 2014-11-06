/*
 * main.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: jeromethai
 */

#include <iostream>
using namespace std;
#include"version-test.h"
#include"LinkedList.h"
#include"Stack.h"
#include"reverseWords.h"

int main( int argc, char ** argv ) {
    version();
    testLinkedList();
    testStack();
    testReverseWords();
	return 0;
}

