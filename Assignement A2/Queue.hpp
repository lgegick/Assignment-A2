/*
	Queue.hpp

	This is the header file for the Queue class and associated struct
*/	

#ifndef INCLUDED_QUEUE_HPP
#define INCLUDED_QUEUE_HPP

#include <string>

struct Frame
{
	char* payLoad;
	Frame* next;
};

class Queue
{
	private:

		// index of the front of the queue
		int front;

		// index of the rear of the queue
		int rear;

		// size of the queue (number of frames)
		int size;

		// points to the front most Frame
		Frame* head;

	public:
		/*
			Constructor for Queue
			@param[in] size, the number of frames needed for the Queue
		*/
		Queue(int size);

		/*
			Destructor for Queue
			Removes all new declarations of the Frame from memory
		*/
		~Queue();

		/*
			Enqueue the next value into the Queue
			@param[in] userInput, char buffer with user input
			@return int status code for showing enqueue status
		*/
		int enqueue(char* userInput);

		/*
			Dequeue the first most value in the Queue
			@param[in, out] queueOutput, the output of the dequeue
			@return int showing status of the dequeue
		*/
		int dequeue(char* queueOutput);

		/*
			Display the contents of the Queue, show each payload beginning at the first most index
		*/
		void displayQueue();

		/*
			check if any values exist within the Queue
			@return true if the Queue is empty, false otherwise
		*/
		bool isEmpty();

		/*
			check if the Queue is full and cannot take any more values
			@return true if the Queue is full, false otherwise
		*/
		bool isFull();
};

#endif