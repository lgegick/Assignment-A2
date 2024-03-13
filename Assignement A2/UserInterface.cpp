/*
	UserInterface.cpp

	Implementation file, handles the UI for the Queue assignment
*/

#include "UserInterface.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstring>
#include <cmath>
#include <string_view>

const int BUFFERSIZE = 7;
constexpr std::string_view CLEAROUTPUT = "\033[2J\033[1; 1H";

using std::cout;
using std::setw;
using std::left;
using std::setfill;

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

void displayHead(Queue& userQueue, int size, int front, int rear)
{
	//NOTE:
	// there are 24 whitespaces in the address box
	// and 22 spaces in the value box

	// get the address of the Queue
	const Frame* queueFrame = new Frame[size];
	queueFrame = userQueue.getFrame();

	// declare the variable used to find the head node by index
	int headIndex;
	bool framesExist;

	// find if a head exists
	for (int i = 0; i < size; ++i)
	{
		if (queueFrame[i].payload == nullptr)
		{
			framesExist = false;
		}
		else
		{
			framesExist = true;
			break;
		}
	}

	// check if any Frames were initilized
	if (framesExist == false)
	{
		headIndex = -1;
		std::cout << "No head node exists\n";
		return;
	}

	// keeps track if a head node has been displayed
	int headCount(-1);
	bool isHeadNode = false;

	// get values of front to show when to start reading payloads
	char* frontPayload = queueFrame[front].payload;
	char* rearPayload = queueFrame[rear].payload;
	bool frontFound = false;
	bool atRear = false;

	//show the labels of the graph
	std::cout << setw(16) << setfill(' ') << "Address" << setw(23) << setfill(' ') << "Value" << '\n';
	std::cout << setw(50) << setfill('_') << '\n';

	// display the table
	for (int i = 0; i < size; ++i)
	{
		char* tempPayload = queueFrame[i].payload;
		char* tempRear = queueFrame[i].payload;

		if (tempPayload == frontPayload)
		{
			frontFound = true;
		}
		if (tempRear == rearPayload)
		{
			atRear = true;
		}
		if (front == rear)
		{
			frontFound = atRear = true;
		}

		if (tempPayload != nullptr)
		{
			if (frontFound && !atRear)
			{
				// if this is the first instance of a Frame, it must be the head node
				if (headCount == -1)
				{
					isHeadNode = true;
					headCount++;
				}
				else
				{
					isHeadNode = false;
				}

				int leftValueSpace = 10;
				int rightValueSpace = 12 - valueSize(queueFrame[i].payload);
				int addressSpace = (24 - addressSize(queueFrame[i])) / 2;
				addressSpace = (abs(addressSpace));

				// display table and its contents
				std::cout << "|";
				displayWhitespaces(addressSpace);
				std::cout << &queueFrame[i].payload;
				displayWhitespaces(addressSpace);
				std::cout << "|";
				displayWhitespaces(leftValueSpace);
				for (int j = 0; j < BUFFERSIZE; ++j)
				{
					if (queueFrame[i].payload[j] != '~')
					{
						std::cout << queueFrame[i].payload[j];
					}
					else
					{
						std::cout << ' ';
					}
				}
				displayWhitespaces(rightValueSpace);
				std::cout << "|";
			}
			else if (frontFound && atRear) //point to the same value
			{
				// if this is the first instance of a Frame, it must be the head node
				if (headCount == -1)
				{
					isHeadNode = true;
					headCount++;
				}
				else
				{
					isHeadNode = false;
				}

				int leftValueSpace = 10;
				int rightValueSpace = 12 - valueSize(queueFrame[i].payload);
				int addressSpace = (24 - addressSize(queueFrame[i])) / 2;
				addressSpace = (abs(addressSpace));

				// display table and its contents
				std::cout << "|";
				displayWhitespaces(addressSpace);
				std::cout << &queueFrame[i].payload;
				displayWhitespaces(addressSpace);
				std::cout << "|";
				displayWhitespaces(leftValueSpace);
				for (int j = 0; j < BUFFERSIZE; ++j)
				{
					if (queueFrame[i].payload[j] != '~')
					{
						std::cout << queueFrame[i].payload[j];
					}
					else
					{
						std::cout << ' ';
					}
				}
				displayWhitespaces(rightValueSpace);
				std::cout << "|";

				// reset the bool values
				frontFound = false;
				atRear = false;
			}
			else // display an empty table
			{
				std::cout << "|";
				displayWhitespaces(24);
				std::cout << "|";
				displayWhitespaces(22);
				std::cout << "|";
			}
		}

		//check if the value is of the head node
		if (isHeadNode)
		{
			showHeadPosition();
		}
		std::cout << '\n';
		std::cout << setw(50) << setfill('-') << '\n';
	}

	std::cout << '\n';
	delete[] queueFrame;
}

void showHeadPosition()
{
	std::cout << "<------ HEAD";
}

void displayWhitespaces(int amount)
{
	for (int i = 0; i < amount; ++i)
	{
		std::cout << ' ';
	}
}

int addressSize(const Frame& address)
{
	int charSize = sizeof(address);
	int numberCharacters = charSize * 2;
	return numberCharacters;
}

int valueSize(const char* address)
{
	int count = 0;
	if (address != nullptr)
	{
		count = strlen(address);
	}
	return count;
}

void displayTail(Queue& userQueue, int size, int front, int rear)
{

	//NOTE:
	// there are 24 whitespaces in the address box
	// and 22 spaces in the value box

	// get the address of the Queue
	const Frame* queueFrame = new Frame[size];
	queueFrame = userQueue.getFrame();

	// declare the variables to help find the rear node
	int tailIndex;
	bool framesExist;

	// find the count of nodes and if any payloads exist
	for (int i = 0; i < size; ++i)
	{
		if (queueFrame[i].payload == nullptr)
		{
			framesExist = false;
		}
		else
		{
			framesExist = true;
			break;
		}
	}

	// check if any Frames were initilized
	if (framesExist == false)
	{
		tailIndex = -1;
		std::cout << "No tail node exists\n";
		return;
	}

	// keeps track if a tail node
	bool isTailNode = false;

	// get values of front to show when to start reading payloads
	char* rearPayload = queueFrame[rear].payload;
	char* frontPayload = queueFrame[front].payload;
	bool rearFound = false;
	bool frontFound = true;

	//show the labels of the graph
	std::cout << setw(16) << setfill(' ') << "Address" << setw(23) << setfill(' ') << "Value" << '\n';
	std::cout << setw(50) << setfill('_') << '\n';

	// display the table
	for (int i = 0; i < size; ++i)
	{
		char* tempPayload = queueFrame[i].payload;
		char* tempRear = queueFrame[i].payload;

		if (tempPayload == frontPayload)
		{
			frontFound = true;
		}
		else if (tempRear == rearPayload)
		{
			rearFound = true;
		}
		else if (front == rear)
		{
			frontFound = rearFound = true;
		}
		else
		{
			rearFound = false;
		}

		if (queueFrame[i].payload != nullptr)
		{
			if (frontFound && !rearFound) // if the front and rear are at different positions
			{
				int leftValueSpace = 10;
				int rightValueSpace = 12 - valueSize(queueFrame[i].payload);
				int addressSpace = (24 - addressSize(queueFrame[i])) / 2;
				addressSpace = (abs(addressSpace));

				// display table and its contents
				std::cout << "|";
				displayWhitespaces(addressSpace);
				std::cout << &queueFrame[i].payload;
				displayWhitespaces(addressSpace);
				std::cout << "|";
				displayWhitespaces(leftValueSpace);
				std::cout << queueFrame[i].payload;
				for (int j = 0; j < BUFFERSIZE; ++j)
				{
					if (queueFrame[i].payload[j] != '~')
					{
						std::cout << queueFrame[i].payload[j];
					}
					else
					{
						std::cout << ' ';
					}
				}
				displayWhitespaces(rightValueSpace);
				std::cout << "|";
			}
			else if (frontFound && rearFound)
			{
				int leftValueSpace = 10;
				int rightValueSpace = 12 - valueSize(queueFrame[i].payload);
				int addressSpace = (24 - addressSize(queueFrame[i])) / 2;
				addressSpace = (abs(addressSpace));

				// display table and its contents
				std::cout << "|";
				displayWhitespaces(addressSpace);
				std::cout << &queueFrame[i].payload;
				displayWhitespaces(addressSpace);
				std::cout << "|";
				displayWhitespaces(leftValueSpace);
				for (int j = 0; j < BUFFERSIZE; ++j)
				{
					if (queueFrame[i].payload[j] != '~')
					{
						std::cout << queueFrame[i].payload[j];
					}
					else
					{
						std::cout << ' ';
					}
				}
				displayWhitespaces(rightValueSpace);
				std::cout << "|";
				
			}
			else
			{
				std::cout << "|";
				displayWhitespaces(24);
				std::cout << "|";
				displayWhitespaces(22);
				std::cout << "|";
			}
		}

		//check if the value is of the head node
		if (rearFound)
		{
			showTailPosition();
		}
		std::cout << '\n';
		std::cout << setw(50) << setfill('-') << '\n';
	}

	std::cout << '\n';
	std::cout << setw(50) << setfill('-') << '\n';

	std::cout << '\n';
}

void showTailPosition()
{
	std::cout << "<------ TAIL";
}
