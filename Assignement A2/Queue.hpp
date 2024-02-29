/*
	Queue.hpp

	This is the header file for the Queue class and associated struct
*/	

#ifndef INCLUDED_QUEUE_HPP
#define INCLUDED_QUEUE_HPP

#include <string>

struct Frame
{
	char* payload;
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
		Frame* queueFrame;

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
		void displayQueue() const;

		/*
			check if any values exist within the Queue
			@return true if the Queue is empty, false otherwise
		*/
		bool isEmpty() const;

		/*
			check if the Queue is full and cannot take any more values
			@return true if the Queue is full, false otherwise
		*/
		bool isFull() const;

		/*
			Process user input, convert the buffer into six char long payloads, until the buffer overflows
			@param[in] userInput, the char input from the user
			@return char*, the processed user inputs
		*/
		char* processInput(const char* userInput);

		/*
			copy the contents from one char* to another char*
			@param[in] char1, char* is the operand on the left
			@param[in] char2, char* is the operand on the right
			@param[in] size, the size of the array (assumed to be six for a Frame)
		*/
		void copy(char* char1, char* char2,	const int size);
};

#endif