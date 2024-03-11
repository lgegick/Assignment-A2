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

	// beginning of the UI
	std::string userOption;
	std::string prompt;
	

	while (userOption != "quit" && userOption != "Quit")
	{
		// display the UI 
		userOption = displayUserOptions();

		if (userOption == "Enqueue" || userOption == "enqueue")
		{
			char enqueueAgain = 'y';

			while (enqueueAgain == 'y' || enqueueAgain == 'Y')
			{
				bool flag = true;
				std::cout << CLEAROUTPUT;

				// check the user input is within range and valid
				do
				{
					prompt = "Enter up to 6 characters to Enqueue: ";
					std::cin.clear(); //clear input stream
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					int status = userInput.promptUser(prompt);

					if (status != -1 && userQueue.verifySize(userInput.getUserInput()))
					{
						flag = false;
					}
					else
					{
						if (status == -1)
						{
							std::cerr << "Non-fatal Err: Buffer processing error\n";
						}
						else
						{
							std::cerr << "Non-fatal Err: input is to long (try shortening your input)\n\n\n";
						}
					}

				} while (flag);

				//move the buffer into the Queue
				int status = userQueue.enqueue(userInput.getUserInput());
				if (status == -1)
				{
					std::cerr << "Non-fatal Err: Invalid user input\n";
					break;
				}
				
				// get the destination 
				/*
				int tempDest;
				std::cout << "Enter the destination (0-99): ";
				std::cin >> tempDest;
				userQueue.setDestination(tempDest); */

				//display the Queue contents
				userQueue.displayQueue();

				std::cout << "Would you like to Enqueue another value? (Y/N): ";
				std::cin >> enqueueAgain;
				std::cout << CLEAROUTPUT;
			}
		}
		else if (userOption == "Dequeue" || userOption == "dequeue")
		{
			char dequeueAgain = 'Y';
			while (dequeueAgain == 'Y' || dequeueAgain == 'y')
			{
				std::cout << CLEAROUTPUT;
				char* dequeueOutput = new char[BUFFERSIZE];
				int status = userQueue.dequeue(dequeueOutput);

				if (status == -1)
					break;

				// if the dequeue works as intended, output the value and show the updated table
				std::cout << dequeueOutput;
				std::cout << "\n\n";
				userQueue.displayQueue();

				// deallocate the new char made to show output
				delete[] dequeueOutput;

				// check if user wants to dequeue again
				std::cout << "Would you like to Dequeue another value? (Y/N): ";
				std::cin >> dequeueAgain;
				std::cout << CLEAROUTPUT;
			}
		}
		else if (userOption == "Display" || userOption == "display")
		{
			std::cout << CLEAROUTPUT;
			userQueue.displayQueue();
			std::cout << "When you are done viewing, enter any value to continue...\n";
			std::cin.clear(); //clear input stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(std::cin, userOption);
		}
		else if (userOption == "Head" || userOption == "head")
		{
			std::cout << CLEAROUTPUT;
			displayHead(userQueue, BUFFERSIZE, userQueue.getFront(), userQueue.getRear());
			std::cout << "When you are done viewing, enter any value to continue...\n";
			std::cin.clear(); //clear input stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(std::cin, userOption);
		}
		else if (userOption == "Tail" || userOption == "tail")
		{
			std::cout << CLEAROUTPUT;
			displayTail(userQueue, BUFFERSIZE, userQueue.getFront(), userQueue.getRear());
			std::cout << "When you are done viewing, enter any value to continue...\n";
			std::cin.clear(); //clear input stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(std::cin, userOption);
		} 
		else if (userOption == "Size" || userOption == "size")
		{
			std::cout << CLEAROUTPUT;
			std::cout << "The Queue has a size of: " << userQueue.getSize() << '\n';
			std::cout << "When you are done viewing, enter any value to continue...\n";
			std::cin.clear(); //clear input stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(std::cin, userOption);
		}
		else if (userOption == "Empty" || userOption == "empty")
		{
			bool status = userQueue.queueStatus();
			if (status)
				std::cout << "The queue is empty" << '\n';
			else
				std::cout << "The queue is not empty" << '\n';
			std::cout << "When you are done viewing, enter any value to continue...\n";
			std::cin.clear(); //clear input stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(std::cin, userOption);
		}
		

		//once user finishes an above function, or enters function incorrectly
		std::cout << CLEAROUTPUT;
		std::cout << "Enter 'quit' to exit program, and 'enter' to continue: ";
		std::cin >> userOption;
		std::cout << CLEAROUTPUT;
	}


	return 0;
}
