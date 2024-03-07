/*
	UserInterface.cpp

	Implementation file, handles the UI for the Queue assignment
*/

#include "UserInterface.hpp"
#include <iostream>
#include <limits>

const std::string CLEAROUTPUT = "\033[2J\033[1; 1H";

using std::cout;

std::string displayUserOptions()
{
	std::string userOption;

	cout << "Here are the options for this Queue:\n";
	cout << "     Enqueue: Read a value into the Queue\n";
	cout << "     Dequeue: remove and print a value from the Queue\n";
	cout << "     Display: displays the current values within the Queue\n";
	cout << "     Head: displays the location of the head and its value\n";
	cout << "     Tail: displays the location of the tail and its value\n";
	cout << "     Size: displays the size of the Queue\n";
	cout << "     Empty: displays if the Queue is empty\n\n\n";

	cout << "Enter your choice: ";
	std::cin >> userOption;

	return userOption;
}

