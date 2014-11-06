/*
 * reverseWords.cpp
 *
 *  Created on: Oct 30, 2014
 *      Author: jeromethai
 */

#include <iostream>  // to be able to use cout
#include <string>
using namespace std; // so that I don't have to use std::string



void reverseString( char str[], int start, int end) {
	char temp;
	while (end > start) {
		/* Exchange characters */
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		/* Mode indices towards middle */
		start++; end--;
	}
}


void reverseWords( char str[] ) {

	int start = 0, end = 0, length;
	length = strlen(str);
	/* Reverse entire string */
	reverseString(str, start, length - 1);

	while(end < length){
		if( str[end] !=  ' '){ /* Skip non-word characters */
			/* Save position of beginning of word */
			start = end;

			/* Scan to next non-word character */
			while ( end < length && str[end] != ' ' )
				end++;
			end--;
			reverseString(str,start,end);
		}
		end++;
	}
}


int testReverseWords() {
	string myString = "my String";
	//char[] s = myString.toCharArray();
	cout << myString << endl;
	char tab[myString.length()];
	strcpy (tab, myString.c_str());
	/* .c_str() returns a pointer to the c-string representation
	 to a string object and strcpy() copies the c-string pointed by left
	 to the array pointed by right
	 */
	cout << "Original string: " << tab << endl;
	reverseString(tab, 0, myString.length()-1);
	cout << "Reverse string: " << tab  << endl;
	reverseString(tab, 0, myString.length()-1);
	reverseWords( tab );
	cout << "Reverse words: " << tab  << endl;
	return 0;
}
