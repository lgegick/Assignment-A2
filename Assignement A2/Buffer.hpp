/*
	Buffer.hpp

	Header file for the char buffer handling
*/

#ifndef INCLUDED_BUFFER_HPP
#define INCLUDED_BUFFER_HPP

#include <string>

namespace Buffer
{
	class Buffer
	{
		private:

			// the buffer for the user input
			char* userInput;

			// the size of the buffer
			int BUFFERSIZE;

		public:

			/*
				Constructor for the user buffer
				@param[in] size, the size of the input buffer
			*/
			Buffer(int size);

			/*
				Destructor for the user buffer
			*/
			~Buffer();

			/*
				return the userInput
			*/
			char* getUserInput();

			/*
				check for overflow from the userBuffer using the cin buffer
			*/
			bool checkBufferOverflow();

			/*
				Initialize all of the array elements to 0, this helps in checking for overflow
			*/
			void initializeBuffer();

			/*
				clears the user input buffer
			*/
			void clearBuffer();

			/*
				reads and input and automatically clears the buffer
				@param[in] prompt, the question you want to ask the user
				@return int, code for failure (-1), code for success (0)
			*/
			int promptUser(const std::string& prompt);
	};
}

#endif
