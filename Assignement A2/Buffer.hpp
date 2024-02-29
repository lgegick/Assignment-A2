/*
	Buffer.hpp

	Header file for the char buffer handling
*/

#ifndef INCLUDED_BUFFER_HPP
#define INCLUDED_BUFFER_HPP

#include <string>

namespace Buffer
{
	/*
		check for overflow from the userBuffer using the cin buffer
	*/
	bool checkBufferOverflow();

	/*
		Initialize all of the array elements to 0, this helps in checking for overflow
		@param[in, out] userInput, user input for strings
		@param[in] size, the size of the buffer
	*/
	void initializeBuffer(char* userInput, const int size);

	/*
		clears the user input buffer
		@param[in, out] userInput, the char buffer for the users inputs
		@param[in] size, the size of the buffer
	*/
	void clearBuffer(char* userInput, const int size);

	/*
		reads and input and automatically clears the buffer
		@param[in,out] userInput, the char buffer of the users inputs
		@param[in] size, the size of the buffer for the users
		@param[in] prompt, the question you want to ask the user
		@return int, code for failure (-1), code for success (0)
	*/
	int promptUser(char* userInput, const int size, const std::string& prompt);
}

#endif
