/*
	Assignment A2.cpp

	this is the main file for the project in Data Structures A2
*/

#include <iostream>

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

int main()
{
	const int bufferSize = 256;

	//buffer for user inputs to go into, holds 256 char values
	char userInput[bufferSize];

	initializeBuffer(userInput, bufferSize);
	
	std::cout << "Enter some values\n";
	std::cin.getline(userInput, bufferSize);
	if (checkBufferOverflow() == true)
		std::cout << "Overflow works\n";

	//beginning of the UI, possibly GUI if I have the time


	return 0;
}

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