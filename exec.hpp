
//ADMIN AND USER METHODS

exec :: exec()
	{

	}

exec :: ~exec()
	{

	}

void exec :: run()
    	{
		int choice;

		std::cout << "Please select a login in mode:\n";
		std::cout << "1) Admin\n";
		std::cout << "2) User\n";

		std::cin >> choice;

		if( choice == 1)
		{
			admin();
			//call to the admin method
		}
		else if (choice == 2)
		{
			user();
			//call to the user method
		}
		else //if the user gives something that isnt a vaild input it will tell them it is invalid and restart
		{
			if( std::cin.fail() )//checks for bad input, by checking that it is the correct type,then checking it was a option listed
	    		{
	      			std::cin.clear(); // unset failbit
	      			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
					std::cout << '\n';
	     			std::cout << "Sorry, your input was not a number, quitting now\n";
					std::cout << '\n';
	   			}
			else if((choice > 2) || (choice <= 0))//checks that it is a valid numerical input
				{
					std:: cout << "Invaid input, quitting now.\n";
					std::cout << '\n';
				}

				}
		
    	}


void exec :: admin()
	{
		/* 1. Name of event
		* 2. Year
		* 3. Month
		* 4. Day
		* 5. Time
		* 6. Number of people attending (1)*/

		int choice = 0;
		int eventYear = 0;
		int eventMonth = 0;
		int eventDay = 0;
		int eventBreak = 0;
		int peopleAttending = 1;
		int initialTime = 0;
		int endTime = 0;
		std::string eventName;
		std::string eventTime;
		bool repeat = true;

		std::cout << "Select an option:\n";
		std::cout << "1) Create new activity\n";
		std::cout << "2) View current activities\n";
		
		std::cin >> choice;

		if(choice == 1)
		{
			std::cout << "Please enter the name of the activity:\n";
			std::cin.ignore();
			std::getline (std::cin,eventName,'\n');

			std::cout << "What year will the event be on?\n";
			std::cin >> eventYear;

			std::cout << "What month will the event be on?:\n";
			std::cout << "1) January\n";
			std::cout << "2) February\n";
			std::cout << "3) March\n";
			std::cout << "4) April\n";
			std::cout << "5) May\n";
			std::cout << "6) June\n";
			std::cout << "7) July\n";
			std::cout << "8) August\n";
			std::cout << "9) September\n";
			std::cout << "10) October\n";
			std::cout << "11) November\n";
			std::cout << "12) December\n \n";
			std::cin >> eventMonth;

			std::cout << "What day will you event be on?\n";
			std::cin >> eventDay; //TODO: Check if valid day.

			std::cout << "At what time will your event start? (Time is meassured in half hour intervals)\n";
			std::cout << "Example times: 12:30 is 1230. 9:00 is either 0900 or 900.\n";
			
			do
			{
				std::cin >> initialTime;

				int i = initialTime;
				int len = 1;

				if (i > 0) { //Count number of digits in given time.
					for (len = 0; i > 0; len++) {
						i = i / 10;
					}
				}

				repeat = timeCheck(initialTime, len);
			}while(repeat);
			
			std::cout << "At what time will your event end? (If there are breaks in the event, input the end time before a break)\n";

			do
			{
				std::cin >> endTime;

				int i = endTime;
				int len = 1;

				if (i > 0) { //Count number of digits in given time.
					for (len = 0; i > 0; len++) {
						i = i / 10;
					}
				}

				repeat = timeCheck(endTime, len);
			}while(repeat);


			for(int i = initialTime; i < endTime-60; i+=30)
			{
				if((i/10)%10 == 6) //if third digit of time is 6, go to the closest next hour
				{
					i += 40;
				}
				if((endTime/10)%10 == 3) //Bunch of if's to remove space after final time
				{
					if(i == endTime-30)
					{
						eventTime = eventTime + std::to_string(i);
						break;
					}
				}
				else if((endTime/10)%10 == 0)
				{
					if(i == endTime-70)
					{
						eventTime = eventTime + std::to_string(i);
						break;
					}
				}
				eventTime = eventTime + std::to_string(i) + " ";
			}



			std::cout << "Are there breaks in your event?\n";
			std::cout << "1) Yes\n";
			std::cout << "2) No\n";
			std::cin >> eventBreak; //TODO check if valid time

			while(eventBreak == 1)
			{
				int initialTime = 0;
				int endTime = 0;

				eventTime = eventTime + " "; //Adds a space between times when event is added

				std::cout << "At what time will your event start again?\n";
				
				do
				{
					std::cin >> initialTime; //TODO: Check if time does not overlap when there is a break
					int i = initialTime;
					int len = 1;
	
					if (i > 0) { //Count number of digits in given time.
						for (len = 0; i > 0; len++) {
							i = i / 10;
						}
					}
	
					repeat = timeCheck(initialTime, len);
				}while(repeat);


				std::cout << "At what time will your event end? (If there are more breaks in the event, input the end time before a break)\n";

				do
				{
					std::cin >> endTime; //TODO: Check if time does not overlap when there is a break
					int i = endTime;
					int len = 1;
	
					if (i > 0) { //Count number of digits in given time.
						for (len = 0; i > 0; len++) {
							i = i / 10;
						}
					}
	
					repeat = timeCheck(endTime, len);
				}while(repeat);

			for(int i = initialTime; i < endTime-60; i+=30)
			{
				if((i/10)%10 == 6) //if third digit of time is 6, go to the closest next hour
				{
					i += 40;
				}
				if((endTime/10)%10 == 3) //Bunch of if's to remove space after final time
				{
					if(i == endTime-30)
					{
						eventTime = eventTime + std::to_string(i);
						break;
					}
				}
				else if((endTime/10)%10 == 0)
				{
					if(i == endTime-70)
					{
						eventTime = eventTime + std::to_string(i);
						break;
					}
				}
				eventTime = eventTime + std::to_string(i) + " ";
			}

				std::cout << "Are there any more breaks in your event?\n";
				std::cout << "1) Yes\n";
				std::cout << "2) No\n";
				std::cin >> eventBreak;
			}


			std::ifstream fileExists("eventFile.txt");
			if(fileExists) //If file exists, start at the end, add new line and add info
			{
				std::ofstream outFile;
				outFile.open("eventFile.txt", std::ios_base::app | std::ios_base::out);
				outFile << '\n' << eventYear << ":" << eventMonth << ":" << eventDay << ":" << eventTime << ":" << eventName << ":" << peopleAttending; 
				outFile.close();
			}
			else //If file does not exist, create it and add info
			{
				std::ofstream outFile;
				outFile.open("eventFile.txt", std::ios_base::app | std::ios_base::out);
				outFile << eventYear << ":" << eventMonth << ":" << eventDay << ":" << eventTime << ":" << eventName << ":" << peopleAttending;
				outFile.close();
			}

		}
	}

void exec :: user()
	{
		int choice;
		std::string eventName;
		//bool foundCheck;

		std::cout << "Would you like your times displayed on a 12 hour or 24 hour clock?\n";
		std::cout << "1) 12 hour clock\n";
		std::cout << "2) 24 hour clock\n";

		std::cin >> choice;

		if(choice == 1)
		{
			print(true);
		}
		else if(choice == 2)
		{
			print(false);
		}
		else //if the user gives something that isnt a vaild input it will tell them it is invalid and restart
		{
			if( std::cin.fail() )//checks for bad input, by checking that it is the correct type,then checking it was a option listed
	    		{
	      			std::cin.clear(); // unset failbit
	      			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
					std::cout << '\n';
	     			std::cout << "Sorry, your input was not a choice, quitting now\n";
					std::cout << '\n';
	   			}
			else if((choice > 2) || (choice <= 0))//checks that it is a valid numerical input
				{
					std::cout << "Sorry, your input was not a choice, quitting now\n";
					std::cout << '\n';
				}
				
			exit(0);

		}
    
		std::cout << "Please enter the name of the event you wish to attend: ";
		
		std::cin.ignore();
		std::getline (std::cin,eventName,'\n');
	   	
	   	bool foundCheck = updateEvent(eventName);
	   	
	   	if(foundCheck == true)
	   	{
	   		std::cout << "You are now signed up for the event, don't forget to go!\n";
	   	}
	   	else
	   	{
	   		std::cout << "The event name you entered was not found in the list of events.\n";
	   	}


	}

void exec :: print(bool time)
{
	/*
	TO DO:
	-Change linkedList.addFront() to .insertSorted()
	-Check TO DO portion pelow
	*/
	
	std::cout << "Made it to print.\n";

	linkedList<date> events;
		
	std::ifstream readFile; 
	readFile.open("eventFile.txt");
		
	int year = 0;
	int month = 0;
	int day = 0;
	std::string timeClock;
	std::string eventName;
	int attending = 0;

	std::string nameMonth;
	int startTime = 0;
	int endTime = 0;
	int timeKeeper [48];
		
	//read each value and assign to a date object
	//insert date object into the sorted linked list
	//output error if file is not open
	if(readFile.is_open())
	{
		
		while(!readFile.eof())
		{
			std::string entry;
		
			std::getline(readFile, entry, ':' ); //read line by ':' separated value
			
			if(entry != "") //check for case in which return is done after last line in text file
			{
		
				date eventDate;
		
				year = std::stoi(entry);
							
				std::getline(readFile, entry, ':');
				month = std::stoi(entry);
		
				std::getline(readFile, entry, ':');
				day = std::stoi(entry);
		
				std::getline(readFile, entry, ':');
				timeClock = entry;
		
				std::getline(readFile, entry, ':');
				eventName = entry;
		
				std::getline(readFile, entry);
				attending = std::stoi(entry);
		
		
				eventDate.setYear(year);
				eventDate.setMonth(month);
				eventDate.setDay(day);
				eventDate.setTime(timeClock);
				eventDate.setEvent(eventName);
				eventDate.setAttendance(attending);
		
				events.addFront(eventDate);


			}
		}
		readFile.close();//close file
	}
	else
	{
		std::cout << "Error Opening File!" << '\n'; 
		
	}
		
	/*
	===========
	TO DO: 
	-Print in 12Hr time
	-Edit to remove commas at end of time
	==========
	*/
		
	for(int pos = 1; pos <= events.size(); pos++)
	{
		
		year = events.getEntry(pos).getYear();
		month = events.getEntry(pos).getMonth();
		day = events.getEntry(pos).getDay();
		timeClock = events.getEntry(pos).getTime();
		eventName = events.getEntry(pos).getEvent();
		attending = events.getEntry(pos).getAttendance();
	
		//inputs blocks of time into an integer array timeKeeper
		std::istringstream sortedTime(timeClock);
		int lastPosition = 0;
		while (sortedTime)
		{
			int temp;
			std::string timeBlock;
			sortedTime >> timeBlock;
			if(timeBlock != "")//skip extra space at end
			{
			temp = std::stoi(timeBlock);
			timeKeeper[lastPosition]=temp; 
			lastPosition++;
			}
		
		}
		
		//parse array for start and end times of each block, append to end of string
		timeClock = ""; 
		int i = 0; //position in array
		int officialEndTime = 0; //end time to be printed for each block
		while(i <= lastPosition)
		{	
			if(i==0)
			{
				startTime = timeKeeper[i];
				i++;
			}
			else
			{
				//Check to determine whether time is on an hour or 30-minute interval
				//update officialTime to be used for appropriate output 
				if(endTime == 0)
				{
					if(startTime % 100 != 0)
					{
						officialEndTime = 70;
					}
					else
					{
						officialEndTime = 30;
					}
				}
				else
				{
					if(endTime % 100 != 0)
					{
						officialEndTime = 70;
					}
					else
					{
						officialEndTime = 30;
					}
				}
			
				//Check to determine if endTime should be updated 
				//or if time block complete and move to next time block 
				if(startTime == (timeKeeper[i] - officialEndTime))
				{
					endTime = timeKeeper[i];	
				}
				else if(endTime ==(timeKeeper[i] - officialEndTime))
				{
					endTime = timeKeeper[i];
				}
				else
				{
					if (endTime == 0)
					{
						timeClock.append(std::to_string(startTime));
						timeClock.append(" - ");
						timeClock.append(std::to_string(startTime+officialEndTime));
						timeClock.append(", ");
						startTime = timeKeeper[i];		
					}
					else
					{
						timeClock.append(std::to_string(startTime));
						timeClock.append(" - ");
						timeClock.append(std::to_string(endTime+officialEndTime));
						timeClock.append(", ");
			
						startTime = timeKeeper[i];
						endTime = 0;
					}
				}
				i++;
			}
		}
		
		//this will be moved to be used for printing (Currently testing)
		switch(month) 
		{
			case 1 : nameMonth = "January";  break;       
			case 2 : nameMonth = "February";  break;
			case 3 : nameMonth = "March";  break;       
			case 4 : nameMonth = "April";  break;
			case 5 : nameMonth = "May";  break;       
			case 6 : nameMonth = "June";  break;
			case 7 : nameMonth = "July";  break;       
			case 8 : nameMonth = "August";  break;
			case 9 : nameMonth = "September";  break;       
			case 10 : nameMonth = "October";  break;
			case 11 : nameMonth = "November";  break;       
			case 12 : nameMonth = "December";  break;
		}

		
		std::cout << "Event: " << eventName << "\n";
		std::cout << "Date: " << nameMonth << " " << day << ", " << year << "\n"; 
									
		std::cout << "Time: " << timeClock << '\n';
		std::cout << "Attending: " << attending << '\n' << '\n';
		
	}
		

		


}


void exec::test()
    {

		date eventDate;
		int year = 0;
		int month = 0;
		int day = 0;
		std::string timeClock;
		std::string eventName;
		int attending = 0;

		std::cout << '\n' << "Testing print, add to linked list, and print again." << '\n';
		std::cout << "///////////////////////////////////////////////////" << '\n' << '\n';

		print(true);

		std::cout << "Enter Year:";
		std::cin >> year;
		std::cout << "Enter Month:";
		std::cin >> month;
		std::cout << "Enter Day:";
		std::cin >> day;
		std::cout << "Enter Time:";
		std::cin.ignore(1, '\n');
		std::getline(std::cin, timeClock);
		std::cout << "Enter Event Name:";
		std::cin.ignore(0, '\n');
		std::getline(std::cin, eventName);

		eventDate.setYear(year);
		eventDate.setMonth(month);
		eventDate.setDay(day);
		eventDate.setTime(timeClock);
		eventDate.setEvent(eventName);
		eventDate.setAttendance(attending);

		//eventList.addInOrder(eventDate);

		std::cout << '\n';
		eventList.printList();
	
	}


bool exec::timeCheck (int time, int len)
{
	if (time != 0 && time != 30 && len != 3 && len != 4)
	{
		std::cout << "Invalid time. Example times: 12:30 is 1230. 9:00 is either 0900 or 900.\n";
		return true;
	}
	else if (time < 0 || time > 2330)
	{
		std::cout << "Invalid time. Time must be between 0000 and 2330.\n";
		return true;
	}
	else if ((len == 4 && (time/10)%10 != 0) && (len == 4 && (time/10)%10 != 3))
	{
		std::cout << "Invalid time. Times must be in thirty minute intervals i.e. End in 00 or 30.\n";
		return true;
	}
	else if ((len == 3 && (time%10) != 0) && (len == 3 && (time%10) !=3))
	{
		std::cout << "Invalid time. Times must be in thirty minute intervals i.e. End in 00 or 30.\n";
		return true;
	}
	else if ((time%10) != 0)
	{
		std::cout << "Invalid time. Times must be in thirty minute intervals i.e. End in 00 or 30.\n";
		return true;
	}
	else
	{
		return false;
	}
}


bool exec::updateEvent(std::string eventNameCheck)
	{
		//define used varibles
		int year = 0;
		int attending = 0;
		
		std::ifstream readFile;
		std::string temp;
		std::string yearString;
		std::string month;
		std::string day;
		std::string timeClock;
		std::string eventName;
		std::string attendingString;
		std::string inbuf;
		std::string replace_string;
		std::string search_string = eventNameCheck;
		
		char oldFileName[] ="update.txt";
		char newFileName[] ="eventFile.txt";
		
		bool removeCheck = false;


		//open the event file

		readFile.open("eventFile.txt");

		if(readFile.is_open())
		{
			//read through the whole list
			while(!readFile.eof())
			{
				//store each value of each event in temparary varibles
				std::string entry;

				std::getline(readFile, entry, ':');
				year = std::atoi(entry.c_str());
				yearString = entry;

				std::getline(readFile, entry, ':');
				month = entry;

				std::getline(readFile, entry, ':');
				day = entry;

				std::getline(readFile, entry, ':');
				timeClock = entry;

				std::getline(readFile, entry, ':');
				eventName = entry;

				std::getline(readFile, entry, '\n');
				attending = std::atoi(entry.c_str());
				
					//check that the line isnt blank, and that the temprary even name read in equals the one we are searching for
					if((year != 0) && (eventName == eventNameCheck))
					{
						//set the fact that we found the event to true
						removeCheck = true;
						
						//set the attending string to the number that is was found
						attendingString = std::to_string(attending);
						
						//assemble the string that includes the event name as one string that can be searched
						search_string = yearString + ":" + month + ":" + day + ":" + timeClock + ":" + eventName + ":" + attendingString;
						
						/* //was used to check that search_string was outputting correctly
						std::cout << "Find: ";
						std::cout << search_string ;
						std::cout << '\n';
						*/
						
						//increment the attendence
						attending++;
						
						//update the attending string to reflect the incremented attendence
						attendingString = std::to_string(attending);
						
						//set the replace string to the original string with the new incremented attendence
						replace_string  = yearString + ":" + month + ":" + day + ":" + timeClock + ":" + eventName + ":" + attendingString;
						
						/* //was used to check that replace_string was outputting correctly
						std::cout << "Replace with: ";
						std::cout << replace_string;
						*/
						
						
					}
				

			}
			readFile.close();//close file
		}
		else
		{
			//if file dint open for some reason output that.
			std::cout << "Error Opening File!" << '\n';

		}
		
		//open the input file
		std::fstream input_file("eventFile.txt", std::ios::in);
		//open the output file
		std::ofstream output_file("update.txt");
			
			  while (!input_file.eof())
			  {
			  	  //each line to a tempoary varible inbuf
			      std::getline(input_file, inbuf);
			
				  //search each tempoary string for the search string, and record location in spot
			      int spot = inbuf.find(search_string);
			      
			      if(spot >= 0)
			      {
			      	 //subtract search string from the file and record location in tmpstring
			         std::string tmpstring = inbuf.substr(0,spot);
			         //replace the subtracted string with the replace string in that place
			         tmpstring += replace_string;
			         tmpstring += inbuf.substr(spot + search_string.length(), inbuf.length());
			         inbuf = tmpstring;
			      }
			      
			      //doesnt print any empty lines
			      if ( ! inbuf.empty() ) 
			      {
			         output_file << inbuf << std::endl;
			      }
			  
			  

				}
			  
			//deletes the original textfile
			remove("eventFile.txt");
			
			//renames the newly created textfile to the old name
			rename(oldFileName, newFileName);
			
			//returns if the event was found
			return(removeCheck);
	}