/*
	Assignment A2.cpp

	this is the main file for the project in Data Structures A2, made by Luke Gegick
*/

#include <iostream>
#include <string>
#include <string_view>
#include <limits>
#include "Queue.hpp"
#include "Buffer.hpp"
#include "UserInterface.hpp"

constexpr std::string_view CLEAROUTPUT = "\033[2J\033[1;1H";

int main()
{
	// Initialize objects used to handle user Inputs
	const int BUFFERSIZE = 7;
	Buffer::Buffer userInput(BUFFERSIZE);
	Queue userQueue(BUFFERSIZE);

	/*char* test = new char[7];
	int temp = userQueue.dequeue(test);
	std::cout << test; 
	*/

	// beginning of the UI
	std::string userOption;
	std::string prompt;
	while (userOption != "quit" || userOption != "Quit")
	{
		// display the UI 
		userOption = displayUserOptions();

		if (userOption == "Enqueue" || userOption == "enqueue")
		{
			char enqueueAgain = 'y';

			while (enqueueAgain == 'y' || enqueueAgain == 'Y')
			{
				std::cout << CLEAROUTPUT;
				prompt = "Enter up to 6 characters to Enqueue: ";
				std::cin.clear(); //clear input stream
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				userInput.promptUser(prompt);

				//move the buffer into the Queue
				userQueue.enqueue(userInput.getUserInput());
				userQueue.displayQueue();

				std::cout << "Would you like to Enqueue another value? (Y/N): ";
				std::cin >> enqueueAgain;
				std::cout << CLEAROUTPUT;
			}

			std::cout << "Enter any value to continue...";
			std::cin >> prompt;
			std::cout << CLEAROUTPUT;
		}
		
	}
	
	//delete[] test; 

	return 0;
}
