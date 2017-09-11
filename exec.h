//ADMIN AND USER METHODS
#ifndef EXEC_H
#define EXEC_H

#include <iostream>
#include <fstream>
#include <istream>
#include <string>

#include "date.h"

class exec
{
	private:

	
	public:
		//constructor and destructor
		exec();
		~exec();

		/* admin method controls admin options
		* Option 1: Creates event (creates date object and prints to text file)
		* Option 2: Look at event
		*/
		void admin();

		/* user method controls user options
		* Option 1: Check Active Events
		* 	- Select Available Event (Update text file)
		*/
		void user();

		/* print method creates linked list, accesses text file, creates date objects,
		* and places date objects into sorted linked list
		* Output: Print list in readable form to terminal (uses time parameter to determine 12/24 hr clock)
		*/
		void print(bool time);

		void run();

};

#include "exec.hpp"


#endif