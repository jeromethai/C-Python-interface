/*
 * main.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: jeromethai
 */

#include <iostream>
//using namespace std;
#include"version-test.h"
#include"LinkedList.h"
#include"Stack.h"
#include"reverseWords.h"
#include"hello_world.h"

int main( int argc, char ** argv ) {
    version();
    testLinkedList();
    testStack();
    testReverseWords();
    print_hw();
	return 0;
}

