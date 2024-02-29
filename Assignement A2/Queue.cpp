/*
	Queue.cpp

	Implementation file for the queue class
*/

#include "Queue.hpp"

/*
	Constructor for Queue
	@param[in] size, the number of frames needed for the Queue
*/
Queue::Queue(int size)
{
	this->size = size;
	rear = -1;
	front = -1;
	head = nullptr;
}

/*
	Destructor for Queue
	Removes all new declarations of the Frame from memory
*/
Queue::~Queue()
{

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

	}

}

/*
	Dequeue the first most value in the Queue
	@param[in, out] queueOutput, the output of the dequeue
	@return int showing status of the dequeue
*/
int Queue::dequeue(char* queueOutput)
{

}

/*
	Display the contents of the Queue, show each payload beginning at the first most index
*/
void Queue::displayQueue()
{

}

/*
	check if any values exist within the Queue
	@return true if the Queue is empty, false otherwise
*/
bool Queue::isEmpty()
{
	if (head == nullptr)
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