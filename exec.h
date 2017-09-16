#ifndef EXEC_H
#define EXEC_H

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <math.h>

#include "date.h"
#include "linkedList.h"

/**
 *	Executive class. This defines all of the executive class' private member variables and public methods.
 *	@author	Giovanni Artavia
 *	@author Brandon Lammey
 *	@author	Dylan Herrig
 *	@author James Glass
 */
class exec
{
	private:

	public:
		/**
		 *	Constructor for the exec class.
		 */
		exec();
		/**
		 *	Destructor for the exec class.
		 */
		~exec();

		/**
		 *	Public method that takes in no arguments and does not return.
		 * 	Grants user to use admin options.
		 * 	Details: Able to create events (creates date object and prints to text file) and preview the current list of events.
		 */
		void admin();

		/**
		 *	Public method that takes in no arguments and does not return.
		 * 	Grants user to use user options.
		 * 	Details: Able preview the current list of events and then select which event they'd like to attend (Updates text file).
		 */
		void user();

		/**
		 *	Public method that takes in one argument as a bool and does not return.
		 * 	Details: Creates linked list, accesses text file, creates date objects, and places date objects into sorted linkedList. Prints linkedList in readable form to terminal (uses time parameter to determine 12/24 hr clock).
		 */
		void print(bool time);

		/**
		 *	Public method that takes in no arguments and does not return.
		 * 	Details: Runs the program and calls to admin or user based on user input.
		 */
		void run();

		/**
		 *	Public method that takes in no arguments and does not return.
		 * 	Details: Used for testing linkedList sort and early printing.
		 */
		void test();

		/**
		 *	Public method that takes in one argument as a string and returns a bool.
		 * 	Details: Searches the .txt file and updates attendence.
		 * 	@param eventNameCheck is the first parameter.
		 *	@return true if the event was found in the list, false otherwise.
		 */
		bool updateEvent(std::string eventNameCheck);

		/**
		 *	Public method that takes in one argument as a string and returns a bool.
		 * 	Details: Searches the .txt file for the event.
		 * 	@param eventNameCheck is the first parameter.
		 *	@return true if the event was found in the list, false otherwise.
		 */
		bool eventCheck(std::string eventNameCheck);

		/**
		 *	Public method that takes in two argument and returns a bool.
		 * 	Details: Checks to see if given time is valid.
		 * 	@param time is the first parameter.
		 *	@param len is the second parameter.
		 *	@return true if time is valid, false otherwise.
		 */
		bool timeCheck (int time, int len);

		/**
		 *	Public method that takes in two argument and returns a bool.
		 * 	Details: Checks to see if given time is valid. timeMode is true if in 24 hour mode, false is 12 hour.
		 * 	@param time is the first parameter.
		 *	@param len is the second parameter.
		 *	@param timeMode is the third parameter.
		 *	@return true if time is valid, false otherwise.
		 */
		bool timeCheck (int time, int len, bool timeMode);
};

#include "exec.hpp"

#endif
