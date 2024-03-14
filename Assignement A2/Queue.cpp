/*
	Queue.cpp

	Implementation file for the queue class
*/

#include "Queue.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>

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

	// do an initialization for each payload
	for (int i = 0; i < size; ++i)
	{
		queueFrame[i].payload = new char[BUFFERSIZE];
		if (queueFrame[i].payload != nullptr)
		{
			memset(queueFrame[i].payload, '~', BUFFERSIZE);
		}
		else
		{
			std::cerr << "Memory allocation fault- Fatal Err\n";
			exit(-1);
		}
	}
}

/*
	Destructor for Queue
	Removes the new initialized queueFrame array from memory
*/
Queue::~Queue()
{
	delete[] queueFrame; // Deallocate array memory
}

void Queue::resize()
{
	Frame* tempFrame = new Frame[size * 2];

	// do an initialization for each payload
	for (int i = 0; i < size; ++i)
	{
		tempFrame[i].payload = new char[BUFFERSIZE];
		if (tempFrame[i].payload != nullptr)
		{
			memset(tempFrame[i].payload, '~', BUFFERSIZE);
		}
		else
		{
			std::cerr << "Memory allocation fault- Fatal Err\n";
			exit(-1);
		}
	}

	int i(0), j(front);

	do
	{
		tempFrame[i++] = queueFrame[j];
		j = (j + 1) % size;
	} while (j != front);

	front = 0;
	rear = size - 1;
	queueFrame = tempFrame;
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
		resize();
		return -1; // error code for failure
	}
	else if (isEmpty())
	{
		++front;
	}

	char* enqueueInput = new char[BUFFERSIZE];
	strncpy_s(enqueueInput, BUFFERSIZE, userInput, BUFFERSIZE);

	rear = (rear + 1) % size;
	queueFrame[rear].payload = enqueueInput;
	
	std::cout << "Enqueued the value: " << queueFrame[rear].payload << '\n';

	return 0;
}

/*
	Dequeue the first most value in the Queue
	@param[out] queueOutput, the output of the dequeue
	@return int showing status of the dequeue
*/
int Queue::dequeue(char* userOutput)
{
	if (isEmpty())
	{
		userOutput = nullptr;
		return -1;
	}

	strncpy_s(userOutput, BUFFERSIZE, queueFrame[front].payload, BUFFERSIZE);

	// test to see if the front and rear point to the same node
	if (front == rear)
	{
		front = rear = -1;
	}
	else
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
	bool errorFound = false;

	for (int i = 0; i < size; ++i)
	{
		if (queueFrame[i].payload == nullptr)
		{
			errorFound = true;
			break;
		}
	}

	if (errorFound)
	{
		std::cerr << "Non fatal Err: Cant display table due to char* pointing to nullptr\n";
		return;
	}

	if (!isEmpty())
	{
		//header for the table
		std::cout << "The contents of the Queue include:\n\n";
		std::cout << "___________________________________________\n";

		//show the table legend with regard to the index and its payload
		std::cout << "    " << "Index" << std::setw(12) << std::setfill(' ') << '|' <<
			std::setw(16) << std::setfill(' ') << "Payload" << '\n';
		std::cout << "___________________________________________\n";

		if (rear >= front)
		{
			for (int i = front; i < size; ++i)
			{
				if (queueFrame[i].payload[0] != '~')
				{
					std::cout << "      " << i << std::setw(14) << std::setfill(' ') << '|' <<
					std::setw(13) << std::setfill(' '); 

					for (int j = 0; j < BUFFERSIZE; ++j)
					{
						if (queueFrame[i].payload[j] != '~')
							std::cout << queueFrame[i].payload[j];
					}
					std::cout << '\n';
				}
			}
		}
		else
		{
			for (int i = front; i < size; ++i)
			{
				if (queueFrame[i].payload[0] != '~')
				{
					std::cout << "      " << i << std::setw(14) << std::setfill(' ') << '|' <<
					std::setw(13) << std::setfill(' ');

					for (int j = 0; j < BUFFERSIZE; ++j)
					{
						if (queueFrame[i].payload[j] != '~')
							std::cout << queueFrame[i].payload[j];
					}
					std::cout << '\n';
				}

			}

			for (int i = 0; i <= rear; ++i)
			{
				if (queueFrame[i].payload[0] != '~')
				{
					std::cout << "      " << i << std::setw(14) << std::setfill(' ') << '|' <<
					std::setw(13) << std::setfill(' ');

					for (int j = 0; j < BUFFERSIZE; ++j)
					{
						if (queueFrame[i].payload[j] != '~')
							std::cout << queueFrame[i].payload[j];
					}
					std::cout << '\n';
				}
			}
		}
		
		std::cout << '\n';
	}
	else
	{
		//header for the table
		std::cout << "The contents of the Queue include:\n\n";
		std::cout << "___________________________________________\n";

		//show the table legend with regard to the index and its payload
		std::cout << "    " << "Index" << std::setw(12) << std::setfill(' ') << '|' <<
			std::setw(16) << std::setfill(' ') << "Payload" << '\n';
		std::cout << "___________________________________________\n";
	} 
}

/*
	check if any values exist within the Queue
	@return true if the Queue is empty, false otherwise
*/
bool Queue::isEmpty() const
{
	return front == -1;
}

/*
	check if the Queue is full and cannot take any more values
	@return true if the Queue is full, false otherwise
*/
bool Queue::isFull() const
{
	return (rear + 1) % size == front;
}

/*
	Process user input, convert the buffer into six char long payloads, until the buffer overflows
	@param[in] userInput, the char input from the user
	@param[in] size, the max size of the userInput
	@return char*, the processed user inputs
*/
char* Queue::processInput(const char* userInput, int size)
{
	char* testRtn = new char[size];
	
	for (int i = 0; i < size; i++)
	{
		if (userInput[i] != 0) // if a value is initialized
		{
			testRtn[i] = userInput[i];
		}
		else
		{
			testRtn[i] = ' ';
		}
	}
	return  testRtn;
}

/*
	Check the size is 6 or less
	@param[in] userinput, char* of the user input into the Queue
	@return true if the input is within the limit
*/
bool Queue::verifySize(const char* userInput)
{
	int size(0);
	for (int i = 0; i < 7; ++i)
	{
		if (userInput[i] != 0)
			++size;
	}
	return size < 7;
}

/*
	return the value of the Queue
	@return the value of the Queue
*/
Frame* Queue::getFrame()
{
	return queueFrame;
}

/*
	initialize all the payloads to '~' to check if they are initialized or not
*/
void Queue::implicitInitialization()
{
	for (int i = 0; i < size; ++i)
	{
		queueFrame[i].payload = new char[size];
		queueFrame[i].payload[0] = '~';
	}
}

int Queue::getFront()
{
	return front;
}

int Queue::getRear()
{
	return rear;
}

int Queue::getSize()
{
	return size;
}

bool Queue::queueStatus()
{
	if (isEmpty())
		return true;
	else
		return false;
}

void Queue::setDestination(int dest)
{
	queueFrame[0].destination = dest;
}

int Queue::getDestination()
{
	return queueFrame[0].destination;
}