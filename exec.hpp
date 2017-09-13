
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
		bool eventDayCheck = true;
		bool eventMonthCheck = true;

		std::cout << "Select an option:\n";
		std::cout << "1) Create new event\n";
		std::cout << "2) View current activities\n";
		
		std::cin >> choice;

		if(choice == 1)
		{
			bool eventNameCheck = true;
			std::cin.ignore();
			std::cout << "Enter the name of the activity. Please no colons (:).\n";
			do
			{
				std::getline (std::cin,eventName,'\n');

				if(eventName.find(':') != std::string::npos || eventName[0] == ':')
				{
					std::cout << "Invalid event name. Please no colons (:) in the name of the event: \n";
					eventNameCheck = true;
				}
				else
				{
					eventNameCheck = false;
				}
			}while(eventNameCheck);


			std::cout << "What year will the event be on?\n";
			std::cin >> eventYear;
			
			do
			{
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
				std::cout << "12) December\n";
				std::cin >> eventMonth;

				if(eventMonth < 1 || eventMonth > 12)
				{
					std::cout << "\nINVALID INPUT. Please choose a valid option: \n \n";
				}
				else
				{
					eventMonthCheck = false;
				}
			}while(eventMonthCheck);

			std::cout << "What day will you event be on?\n";

			do
			{
				std::cin >> eventDay;
				if (eventMonth == 1 || eventMonth == 3 || eventMonth == 5 || eventMonth == 7 || eventMonth == 8 || eventMonth == 10 || eventMonth == 12)
				{
					if(eventDay < 0 || eventDay > 31)
					{
						std::cout << "Invalid day for the chosen month. Please enter a valid day:\n";
						eventDayCheck = true;
					}
					else
					{
						eventDayCheck = false;
					}
				}
				else if (eventMonth == 4 || eventMonth == 6 || eventMonth == 9 || eventMonth == 11)
				{
					if(eventDay < 0 || eventDay > 30)
					{
						std::cout << "Invalid day for the chosen month. Please enter a valid day:\n";
						eventDayCheck = true;
					}
					else
					{
						eventDayCheck = false;
					}
				}
				else if (eventMonth == 2)
				{
					if(eventDay < 0 || eventDay > 28)
					{
						std::cout << "Invalid day for the chosen month. Please enter a valid day:\n";
						eventDayCheck = true;
					}
					else
					{
						eventDayCheck = false;
					}
				}
				else
				{
					std::cout << "This should never print";
				}
			}while(eventDayCheck);

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
			
			if (initialTime != 2330)
			{

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
					if (endTime < initialTime)
					{
						std::cout << "Events can't go through multiple days. Please enter an end time that is after the initial time\n";
						repeat = true;
					}
				}while(repeat);
			}
			else
			{
				std::cout << "Event started at 23:30. It will run until 23:59.\n";
			}

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
			std::cin >> eventBreak;

			while(eventBreak == 1)
			{
				eventTime = eventTime + " "; //Adds a space between times when event is added

				std::cout << "At what time will your event start again?\n";
				
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
					if(initialTime < endTime)
					{
						std::cout << "Can't continue from break after previous end time. Please input a valid time: \n";
						repeat = true;
					}
				}while(repeat);

				if (initialTime != 2330)
				{	
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
						if (endTime < initialTime)
						{
							std::cout << "Events can't go through multiple days. Please enter an end time that is after the initial time\n";
							repeat = true;
						}
					}while(repeat);
				}

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
			std::cout << "Event created!\n";
		}
	}

void exec :: user()
	{
		int choice;
		std::string eventName;

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
	     			std::cout << "Sorry, your input was not a number, quitting now\n";
					std::cout << '\n';
	   			}
			else if((choice > 2) || (choice <= 0))//checks that it is a valid numerical input
				{
					std:: cout << "Invaid input, quitting now.\n";
					std::cout << '\n';
				}
				
			exit(0);

		}
    

		//call to print method
		std::cout << "Please enter the name of the event you wish to attend.";
		std::cin >> eventName;
		
		if( std::cin.fail() )//checks for bad input, by checking that it is the correct type,then checking it was a option listed
	    		{
	      			std::cin.clear(); // unset failbit
	      			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
					std::cout << '\n';
	     			std::cout << "Sorry, your input was not a number, quitting now\n";
					std::cout << '\n';
					exit(0);
	   			}
	   	
	   	//eventList.search()//need function to go x number of nodes into the linked list
	   	
	   	update(eventName);
	   	
	   	
	   	
	   	
	   	//use same function to access the given node from the list
	   	
	   	
		
		
		
		
		
		
		
		

	}

void exec :: print(bool time)
	{
		//goals create linked list and print raw info

		//linkedList<date> events;
		date eventDate;

		std::ifstream readFile;
		readFile.open("eventFileInOrder.txt");

		int year = 0;
		int month = 0;
		int day = 0;
		int count = 1;
		std::string timeClock;
		std::string eventName;
		int attending = 0;


		//read each value and assign to a date object

		if(readFile.is_open())
		{
			while(!readFile.eof())
			{
				std::string entry;

				std::getline(readFile, entry, ':');
				year = std::atoi(entry.c_str());

				std::getline(readFile, entry, ':');
				month = std::atoi(entry.c_str());

				std::getline(readFile, entry, ':');
				day = std::atoi(entry.c_str());

				std::getline(readFile, entry, ':');
				timeClock = entry;

				std::getline(readFile, entry, ':');
				eventName = entry;

				std::getline(readFile, entry, '\n');
				attending = std::atoi(entry.c_str());

				if(year != 0)
				{
					std::cout << "Event " << count << " details: " << year << " " << month << " " << day << " " << timeClock << " " << eventName << " " << attending << '\n' << '\n';

					eventDate.setYear(year);
					eventDate.setMonth(month);
					eventDate.setDay(day);
					eventDate.setTime(timeClock);
					eventDate.setEvent(eventName);
					eventDate.setAttendance(attending);

					eventList.addInOrder(eventDate);
					
					count ++;
				}

			}
			readFile.close();//close file
		}
		else
		{
			std::cout << "Error Opening File!" << '\n';

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

		eventList.addInOrder(eventDate);

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


bool exec::update(std::string eventNameCheck)
	{
		std::ifstream readFile;
		readFile.open("eventFile.txt");
		std::string entry;
		
		std::string search_string = eventNameCheck;
		std::string replace_string = "oranges";
		std::string inbuf;
		std::fstream input_file("eventFile.txt", std::ios::in);
		std::ofstream output_file("result.txt");
			
			  while (!input_file.eof())
			  {
			      std::getline(input_file, inbuf);
			
			      int spot = inbuf.find(search_string);
			      if(spot >= 0)
			      {
			         std::string tmpstring = inbuf.substr(0,spot + search_string.length() + 1);
			         
			         tmpstring += replace_string;
			         tmpstring += inbuf.substr(spot + search_string.length(), inbuf.length());
			         inbuf = tmpstring;
			      }
			         output_file << inbuf << std::endl;
			

			      
			      
			  }
			
			  //TODO: delete demo.txt and rename result.txt to demo.txt
			  // to achieve the REPLACE effect.
			  
			return(true);
	}