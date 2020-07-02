/* 
 * File:   main.cpp
 * Author: Anthony Natale
 *
 * Created on 6/28/2020
 */

#include <iostream>
#include <fstream>
#include <string>
#include "SelfOrderedList.h"

using namespace std;

int main() {

	cout << "Anthony Natale -- CSIS 215 Programming Assignment 4 -- Self Organizing List" << "\n" << endl;

	//SelfOrderedList<char> charList = SelfOrderedList<char>();

	//// Add function
	//const char *it = "ABCDEFGH";
	//for (int i = 0; i < 8; i++) {
	//	charList.add(it[i]);
	//}

	//// Find function
	//const char *test = "FDFGEGFADFGEHI";
	//for (int i = 0; i < 14; i++) {
	//	if (charList.find(test[i])) {
	//		cout << test[i] << " is in the list" << endl;
	//	}
	//	else {
	//		cout << test[i] << " is NOT in the list" << endl;
	//	}
	//}

	SelfOrderedList<string> strList = SelfOrderedList<string>();

	// Open file stream
	ifstream input;
	input.open("test.txt");
	// Declare word variable
	string word;
	// separates words by whitespace
	while (input >> word) {
		strList.find(word);
	}

	//for (int i = 0; i < 8; i++) {
	//	strList.add(it2);
	//}

	//SelfOrderedList<string> fileList = SelfOrderedList<string>();


	// Close program
	cout << endl << endl;
	system("pause");
	return 0;
}
