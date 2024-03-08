/*
	UserInterface.hpp

	handles the UI for the Queue assignment
*/

#ifndef INCLUDED_USERINTERFACE_HPP
#define INCLUDED_USERINTERFACE_HPP

#include <string>
#include "Queue.hpp"

std::string displayUserOptions();

void displayHead(const Queue& userQueue, int size);

#endif