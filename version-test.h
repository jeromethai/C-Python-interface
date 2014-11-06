/*
 * version-test.h
 *
 *  Created on: Oct 29, 2014
 *      Author: jeromethai
 */


#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int version() {
	stringstream version;
	version << "GCC VERSION: "
//			<< __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC PATCHLEVEL__
			<< "\nVersion string: " << __VERSION__;

	cout << version.str() << endl;

	return 0;
}

