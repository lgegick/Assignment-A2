/*
	Queue.cpp

	Implementation file for the queue class
*/

#include "Queue.hpp"
#include <iostream>
#include <iomanip>

/*
	Constructor for Queue
	@param[in] size, the number of frames needed for the Queue
*/
Queue::Queue(int size)
{
	this->size = size;
	rear = -1;
	front = -1;
	queueFrame = new Frame[size];
}

/*
	Destructor for Queue
	Removes the new initialized queueFrame array from memory
*/
Queue::~Queue()
{
	delete[] queueFrame;
}

/*
	Enqueue the next value into the Queue
	@param[in] userInput, char buffer with user input
	@return int status code for showing enqueue status
*/ 
int Queue::enqueue(char* userInput)
{
	if (isFull())
	{
		return -1; //error code for failure
	}
	else if (isEmpty()) // if empty, offset the array
	{
		front++;
	}

	//increase the rear. ensuring it doesnt go above the total size
	rear = (rear + 1) % size;

	//initialize the payload struct
	queueFrame[rear].payload = new char[7];
	queueFrame[rear].payload = userInput;

	return 0;
}

/*
	Dequeue the first most value in the Queue
	@param[in, out] queueOutput, the output of the dequeue
	@return int showing status of the dequeue
*/
int Queue::dequeue(char* queueOutput)
{
	
	if (isEmpty()) //return an error code since no more values to dequeue
	{
		return -1;
	}

	//copy the payload to the queueOutput
	copy(queueOutput, queueFrame[rear].payload, 7);

	if (front == rear) //exactly one element in the array ex. front = rear = 0
	{
		front = -1;
		rear = -1;
	}
	else //move front one forward one index
	{
		front = (front + 1) % size;
	}
	
	return 0;
}

/*
	Display the contents of the Queue, show each payload beginning at the first most index
*/
void Queue::displayQueue() const
{
	if (!isEmpty())
	{
		//header for the table
		std::cout << "The contents of the Queue include:\n\n";
		std::cout << "___________________________________________\n";

		//show the table legend with regard to the index and its payload
		std::cout << "    " << "Index" << std::setw(12) << std::setfill(' ') << '|' <<
		std::setw(16) << std::setfill(' ') << "Payload" << '\n';
		std::cout << "___________________________________________\n";

		for (int i = front; i <= rear; i++)
		{
			std::cout << "      " << i << std::setw(14) << std::setfill(' ') << '|' <<
			std::setw(13) << std::setfill(' ') << queueFrame[i].payload << '\n';
		}
		std::cout << '\n';
	}
	else
	{
		std::cout << "The queue is currently empty...\n";
	}
}

/*
	check if any values exist within the Queue
	@return true if the Queue is empty, false otherwise
*/
bool Queue::isEmpty() const
{
	if (front == -1) //front is set to -1 meaning no values
		return true;
	else
		return false;
}

/*
	check if the Queue is full and cannot take any more values
	@return true if the Queue is full, false otherwise
*/
bool Queue::isFull() const
{
	if ((rear + 1) % size == front) //queue has fully wrapped around the circle
		return true;
	else
		return false;
}

/*
	Process user input, convert the buffer into six char long payloads, until the buffer overflows
	@param[in] userInput, the char input from the user
	@return char*, the processed user inputs
*/
char* Queue::processInput(const char* userInput)
{
	char* testRtn = new char[7];
	return  testRtn;
}

/*
	copy the contents from one char* to another char*
	@param[in, out] char1, char* is the operand on the left
	@param[in, out] char2, char* is the operand on the right'
	@param[in] size, the size of the array (assumed to be six for a Frame)
*/
void Queue::copy(char* char1, char* char2, const int size)
{
	for (int i = 0; i < size; ++i)
		char1[i] = char2[i];
}
