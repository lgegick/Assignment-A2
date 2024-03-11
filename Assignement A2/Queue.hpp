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
	int destination;
};

class Queue
{
	private:

		// size of the char* array within the Frame
		const int BUFFERSIZE = 7;

		// index of the front of the queue
		int front;

		// index of the rear of the queue
		int rear;

		// size of the queue (number of frames)
		int size;

		// points to the front most Frame
		Frame* queueFrame;

		void resize();

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
			@return char* of the dequeued value
		*/
		int dequeue(char* userOutput);

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
			@param[in] size, the max size of the userInput
			@return char*, the processed user inputs
		*/
		char* processInput(const char* userInput, int size);

		/*
			Check the size is 6 or less
			@param[in] userinput, char* of the user input into the Queue
			@return true if the input is within the limit
		*/
		bool verifySize(const char* userInput);

		/*
			return the value of the Queue
			@return the value of the Queue
		*/
		Frame* getFrame();

		/*
			initialize all the payloads to '~' to check if they are initialized or not
		*/
		void implicitInitialization();

		int getFront();

		int getRear();

		int getSize();

		bool queueStatus();

		void setDestination(int dest);

		int getDestination();
};

#endif