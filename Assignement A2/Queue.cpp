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
	else if (front == 1) //insert the first element in the array
	{

		front = 0; 
		rear = 0;
		queueFrame[rear].payLoad = userInput;
	}
	else if (rear == size - 1 && front != 0) //if towards the end of the array
	{
		rear = 0;
		queueFrame[rear].payLoad = userInput;
	}
	else
	{
		rear++;
		queueFrame[rear].payLoad = userInput;
	}
}

/*
	Dequeue the first most value in the Queue
	@param[in, out] queueOutput, the output of the dequeue
	@return int showing status of the dequeue
*/
int Queue::dequeue(char* queueOutput)
{
	if (isEmpty())
	{
		return -1;
	}

	//initialze the data to send back
	queueOutput = queueFrame[rear].payLoad;

	if (front = rear) //if they are indexing the same value (ie. empty queue)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size - 1)
	{
		front = 0;
	}
	else
	{
		front++;
	}

	return 0;
}

/*
	Display the contents of the Queue, show each payload beginning at the first most index
*/
void Queue::displayQueue()
{
	if (!isEmpty())
	{
		std::cout << "The contents of the Queue include:\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << "Index" << std::setw(10) << std::left << "Payload" << '\n';
		}
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
bool Queue::isEmpty()
{
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

/*
	check if the Queue is full and cannot take any more values
	@return true if the Queue is full, false otherwise
*/
bool Queue::isFull()
{
	if (front + 1 == size - 1)
		return true;
	else
		return false;
}