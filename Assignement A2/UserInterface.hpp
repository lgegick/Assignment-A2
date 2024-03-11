/*
	UserInterface.hpp

	handles the UI for the Queue assignment
*/

#ifndef INCLUDED_USERINTERFACE_HPP
#define INCLUDED_USERINTERFACE_HPP

#include <string>
#include "Queue.hpp"

std::string displayUserOptions();

void displayHead(Queue& userQueue, int size, int front, int rear);

void displayTail(Queue& userQueue, int size, int front, int rear);

void showHeadPosition();

void showTailPosition();

void displayWhitespaces(int amount);

int addressSize(const Frame& address);

int valueSize(const char* address);

#endif
