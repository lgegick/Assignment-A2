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
	const int BUFFERSIZE = 256;
	char userInput[BUFFERSIZE];
	
	std::string prompt = "Enter some values to enqueue\n";
	
	Buffer::promptUser(userInput, BUFFERSIZE, prompt);

	// a function in the Queue class to handle user inputs and add them to the queue

	Queue userQueue(6);
	userQueue.enqueue(userInput);
	userQueue.displayQueue();

	char* test = new char[7];
	int temp = userQueue.dequeue(test);
	std::cout << test;

	// beginning of the UI, possibly GUI if I have the time

	delete[] test;

	return 0;
}
