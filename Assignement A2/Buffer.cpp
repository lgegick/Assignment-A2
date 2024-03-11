/*
	Buffer.cpp

	Buffer Implementation file
*/

#include "Buffer.hpp"
#include <iostream>

namespace Buffer
{
	/*
		Constructor for the user buffer
		@param[in] size, the size of the input buffer
	*/
	Buffer::Buffer(int size)
	{
		BUFFERSIZE = size;
		userInput = new char[size];

	}

	/*
		Destructor for the user buffer
	*/
	Buffer::~Buffer()
	{
		delete[] userInput;
	}

	/*
		return the userInput
	*/
	char* Buffer::getUserInput()
	{
		return userInput;
	}

	/*
		check for overflow from the userBuffer
		@return true if the buffer overflowed, false otherwise
	*/
	bool Buffer::checkBufferOverflow()
	{
		if (std::cin.fail() && !std::cin.eof())
			return true;
		else
			return false;
	}

	/*
		Initialize all of the array elements to 0, this helps in checking for overflow
	*/
	void Buffer::initializeBuffer()
	{
		memset(userInput, '~', sizeof(userInput));
	}

	/*
		clears the user input buffer by writing '~' to all possible inputs
		@param[in, out] userInput, the char buffer for the users inputs
		@param[in] size, the size of the buffer
	*/
	void Buffer::clearBuffer()
	{
		initializeBuffer();
	}

	/*
		reads and input and automatically clears the buffer
		@param[in] prompt, the question you want to ask the user
		@return int, code for failure (-1), code for success (0)
	*/
	int Buffer::promptUser(const std::string& prompt)
	{
		//set up the buffer to handle inputs
		initializeBuffer();

		//prompt the user with the string prompt
		std::cout << prompt;

		//process the users inputs
		std::cin.getline(userInput, BUFFERSIZE);

		int length = strlen(userInput);

		// pad the values
		for (int i = length; i < BUFFERSIZE - 1; ++i)
		{
			userInput[i] = '~';
		}

		// add back null terminator
		userInput[BUFFERSIZE - 1] = '\0';

		//check the buffer doesnt overflow
		if (checkBufferOverflow() == true)
		{
			std::cout << "Non-fatal Overflow Err: user input is too long, try shortening your input\n";
			return (-1);
		}

		//return code for success
		return(0);
	}
}