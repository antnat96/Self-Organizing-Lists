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

	SelfOrderedList<char> charList = SelfOrderedList<char>();

	// Add function
	const char *characters = "ABCDEFGH";
	for (int i = 0; i < 8; i++) {
		charList.add(characters[i]);
	}

	// Find function
	const char *toFind = "FDFGEGFADFGEHI";
	for (int i = 0; i <= 13; i++) {
		charList.find(toFind[i]);
	}

	charList.printlist();

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

	strList.printlist(10);

	// Close program
	cout << endl << endl;
	system("pause");
	return 0;
}
