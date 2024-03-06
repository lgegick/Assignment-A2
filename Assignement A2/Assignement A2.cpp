/*
	Assignment A2.cpp

	this is the main file for the project in Data Structures A2, made by Luke Gegick
*/

#include <iostream>
#include <string>
#include "Queue.hpp"
#include "Buffer.hpp"

int main()
{
	// handle user inputs using a char buffer
	const int BUFFERSIZE = 6;
	Buffer::Buffer userInput(BUFFERSIZE);
	
	std::string prompt = "Enter some values to enqueue\n";
	
	userInput.promptUser(prompt);

	// a function in the Queue class to handle user inputs and add them to the queue

	Queue userQueue(6);
	userQueue.enqueue(userInput.getUserInput());
	userQueue.displayQueue();

	char* test = new char[7];
	int temp = userQueue.dequeue(test);
	std::cout << test;

	// beginning of the UI

	delete[] test;

	return 0;
}
