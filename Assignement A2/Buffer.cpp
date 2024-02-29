/*
	Buffer.cpp

	Buffer Implementation file
*/

#include "Buffer.hpp"
#include <iostream>

namespace Buffer
{
	/*
		check for overflow from the userBuffer
		@param[in] userChar, char* buffer to process user inputs
		@return true if the buffer overflowed, false otherwise
	*/
	bool checkBufferOverflow()
	{
		if (std::cin.fail() && !std::cin.eof())
			return true;
		else
			return false;
	}

	/*
		Initialize all of the array elements to 0, this helps in checking for overflow
		@param[in, out] userInput, user input for strings
		@param[in] size, the size of the buffer
	*/
	void initializeBuffer(char* userInput, const int size)
	{
		for (int i = 0; i < size; ++i)
		{
			userInput[i] = '~';
		}
	}

	/*
		clears the user input buffer
		@param[in, out] userInput, the char buffer for the users inputs
		@param[in] size, the size of the buffer
	*/
	void clearBuffer(char* userInput, const int size)
	{
		initializeBuffer(userInput, size);
	}

	/*
		reads and input and automatically clears the buffer
		@param[in,out] userInput, the char buffer of the users inputs
		@param[in] size, the size of the buffer for the users
		@param[in] prompt, the question you want to ask the user
		@return int, code for failure (-1), code for success (0)
	*/
	int promptUser(char* userInput, const int size, const std::string& prompt)
	{
		//set up the buffer to handle inputs
		initializeBuffer(userInput, size);

		//prompt the user with the string prompt
		std::cout << prompt;

		//process the users inputs
		std::cin.getline(userInput, size);

		//check the buffer doesnt overflow
		if (checkBufferOverflow() == true)
		{
			std::cout << "Non-fatal Overflow Err: user input is too long, try shortening your input\n";
			return (-1);
		}
	}
}