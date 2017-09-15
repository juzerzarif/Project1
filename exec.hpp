
//ADMIN AND USER METHODS

exec :: exec()
	{

	}

exec :: ~exec()
	{

	}

void exec :: run()
    {
		std::string choice;
		int choiceRepeat = true;

		while(choiceRepeat)
		{
			std::cout << "Please select a login in mode:\n";
			std::cout << "1) Admin\n";
			std::cout << "2) User\n";
			std::cout << "3) Quit\n";
	
			std::getline(std::cin, choice);

			if(choice == "1")
			{
				admin();
				//call to the admin method
			}
			else if (choice == "2")
			{
				user();
				//call to the user method
			}
			else if(choice == "3")
			{
				choiceRepeat = false;
				std::cout << "Bye!\n";
			}
			else //if the user gives something that isnt a vaild input it will tell them it is invalid and restart
			{
				/*if( std::cin.fail() )//checks for bad input, by checking that it is the correct type,then checking it was a option listed
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
	
					}*/

					std::cout << "Invalid input.\n\n";
			
			}
		}
	}

void exec :: admin()
	{
		bool adminLoop = true;
		
		//int choice = 0;
		std::string stringChoice;
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
		std::string hoursChoice;
		bool hoursChoiceBool = true;
		bool superBool = false;

		std::cout << "Would you like your times displayed on a 12 hour or 24 hour clock?\n";
		std::cout << "1) 12 hour clock\n";
		std::cout << "2) 24 hour clock\n";

		//std::cin.ignore();

		//Choose 12 or 24 hours
		do
		{
			superBool = false;

			std::getline(std::cin, hoursChoice);

			if(hoursChoice == "2") //24 hours
			{
				hoursChoiceBool = true;
				superBool = true;
			}
			else if (hoursChoice == "1") //12 hours
			{
				hoursChoiceBool = false;
				superBool = true;
			}
			else
			{
				std::cout << "Invalid input. Please enter a valid input:\n";
				superBool = false;
			}
		}while(!superBool);

		while(adminLoop)
		{
			std::cout << "Select an option:\n";
			std::cout << "1) Create new event\n";
			std::cout << "2) View current activities\n";
			std::cout << "3) Back to Login selection\n";

			std::getline(std::cin, stringChoice);
			
			//std::cin.ignore();	
	
			//Choose Add Event or Show Events
	
			if(stringChoice == "1")
			{
				bool eventNameCheck = true;
	
				std::cout << "Enter the name of the event. Please no colons (:).\n";
	
				//Choose name of event
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
	
	
				std::cout << "What year will the event be on? It can be from 2017 to 2021.\n";
	
				//Choose year of event
				do
				{
					superBool = true;
	
					std::cin >> eventYear;	
					if(std::cin.fail())
					{
						while(std::cin.fail()) {
							std::cout << "Invalid input. Please enter a valid input:\n";
							std::cin.clear();
							std::cin.ignore(256,'\n');
							superBool = false;
						}
					}
					else if(eventYear < 2017 || eventYear > 2021)
					{
						std::cout << "Invalid year. Years have to be between 2017 and 2021.\n";
						superBool = false;
					}
				}while(!superBool);
	
				//Choose month of event
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
	
					if(std::cin.fail()) {
						//std::cout << "Invalid input. Please enter a valid input:\n";
						std::cin.clear();
						std::cin.ignore(256,'\n');
						eventMonthCheck = true;
					}
	
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
	
				//Choose day of event
				do
				{
					std::cin >> eventDay;
	
					if(std::cin.fail()) {
						//std::cout << "Invalid input. Please enter a valid input:\n";
						std::cin.clear();
						std::cin.ignore(256,'\n');
						eventDayCheck = true;
					}
	
					if(eventDay < 1)
					{
						std::cout << "Invalid day.\n";
						eventDayCheck = true;
					}
					else if (eventMonth == 1 || eventMonth == 3 || eventMonth == 5 || eventMonth == 7 || eventMonth == 8 || eventMonth == 10 || eventMonth == 12)
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
						if(eventYear != 2020 && (eventDay < 0 || eventDay > 28))
						{
							std::cout << "Invalid day for the chosen month. Please enter a valid day:\n";
							eventDayCheck = true;
						}
						else if(eventYear == 2020 && (eventDay < 0 || eventDay > 29))
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
	
				if(hoursChoiceBool)
				{
					std::cout << "At what time will your event start? (Time is meassured in half hour intervals)\n";
					std::cout << "Example times: 14:30 is 1430. 9:00 is either 0900 or 900.\n";
	
					do
					{
						std::cin >> initialTime;
	
						if(std::cin.fail())
						{
								std::cout << "Invalid input. Please enter a valid input:\n";
								std::cin.clear();
								std::cin.ignore(256,'\n');
								repeat = true;
						}
						else
						{
							int i = initialTime;
							int len = 1;
		
							if (i > 0) { //Count number of digits in given time.
								for (len = 0; i > 0; len++) {
									i = i / 10;
								}
							}
		
							repeat = timeCheck(initialTime, len, hoursChoiceBool);
						}
					}while(repeat);
				}
				else
				{
					std::cout << "At what time will your event start? (Time is meassured in half hour intervals)\n";
					std::cout << "Example times: 12:30 is 1230. 9:00 is either 0900 or 900.\n";
					std::cout << "a.m. or p.m. will be asked later. Just input the number.\n";
	
					do
					{
						bool shouldSkip = false;
	
						std::cin >> initialTime;
	
						if(std::cin.fail())
						{
								std::cout << "Invalid input. Please enter a valid input:\n";
								std::cin.clear();
								std::cin.ignore(256,'\n');
								repeat = true;
						}
						else
						{
							int i = initialTime;
							int len = 1;
		
							if (i > 0) { //Count number of digits in given time.
								for (len = 0; i > 0; len++) {
									i = i / 10;
								}
							}
		
							if(initialTime > 1230 || initialTime < 100)
							{
								shouldSkip = true;
							}
		
							if(shouldSkip)
							{
								std::cout << "Invalid time. Please input a time between 100 and 1230:\n";
							}
							else
							{
								int timeOfDay = 0;
								std::cout << "Do you want a.m. or p.m.?\n";
								std::cout << "1) a.m.\n";
								std::cout << "2) p.m.\n";
		
								std::cin >> timeOfDay;
		
								if(timeOfDay == 2 && initialTime != 1200 && initialTime != 1230) //if time is pm, add 1200 to it to make it 24 hours
								{
									initialTime += 1200;
								}
								else if (timeOfDay == 1 && initialTime == 1200) //If time is 12am, change to 0
								{
									initialTime = 0;
								}
								repeat = timeCheck(initialTime, len, hoursChoiceBool);
							}
						}
	
					}while(repeat);
				}
				
				if (initialTime != 2330)
				{
					if(hoursChoiceBool)
					{
						std::cout << "At what time will your event end? (If there are breaks in the event, input the end time before a break)\n";
						
						do
						{
							std::cin >> endTime;
						
							if(std::cin.fail())
							{
									std::cout << "Invalid input. Please enter a valid input:\n";
									std::cin.clear();
									std::cin.ignore(256,'\n');
									repeat = true;
							}
							else
							{
								int i = endTime;
								int len = 1;
							
								if (i > 0) { //Count number of digits in given time.
									for (len = 0; i > 0; len++) {
										i = i / 10;
									}
								}
							
								repeat = timeCheck(endTime, len, hoursChoiceBool);
								if (endTime <= initialTime)
								{
									std::cout << "Events can't go through multiple days. Please enter an end time that is after the initial time\n";
									repeat = true;
								}
							}
						}while(repeat);
					}
					else
					{
						std::cout << "At what time will your event end? (If there are breaks in the event, input the end time before a break)\n";
						do
						{
							bool shouldSkip = false;
							repeat = true;
	
							std::cin >> endTime;
	
							if(std::cin.fail())
							{
									std::cout << "Invalid input. Please enter a valid input:\n";
									std::cin.clear();
									std::cin.ignore(256,'\n');
									repeat = true;
							}
							else
							{
								int i = endTime;
								int len = 1;
				
								if (i > 0) { //Count number of digits in given time.
									for (len = 0; i > 0; len++) {
										i = i / 10;
									}
								}
		
								if(endTime > 1230 || endTime < 100)
								{
									shouldSkip = true;
								}
				
								if(shouldSkip)
								{
									std::cout << "Invalid time. Please input a time between 100 and 1230:\n";
								}
								else
								{
									int timeOfDay = 0;
									std::cout << "Do you want a.m. or p.m.?\n";
									std::cout << "1) a.m.\n";
									std::cout << "2) p.m.\n";
		
									std::cin >> timeOfDay;
		
									if(timeOfDay == 2 && endTime != 1200 && endTime != 1230) //if time is pm, add 1200 to it to make it 24 hours
									{
										endTime += 1200;
									}
									else if (timeOfDay == 1 && endTime == 1200) //If time is 12am, change to 0
									{
										endTime = 0;
									}
									repeat = timeCheck(endTime, len, hoursChoiceBool);
									if (endTime <= initialTime)
									{
										std::cout << "Events can't go through multiple days. Please enter an end time that is after the initial time\n";
										repeat = true;
									}
								}
							}
						}while(repeat);
					}
	
				}
				else
				{
					if(hoursChoiceBool)
					{
						std::cout << "Event started at 11:30 p.m. It will run until 11:59 p.m.\n";
					}
					else
					{
						std::cout << "Event started at 23:30. It will run until 23:59.\n";
					}
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
	
				//Choose if break
				while(eventBreak == 1) //TODO: Change this to string
				{
					eventTime = eventTime + " "; //Adds a space between times when event is added
	
					std::cout << "At what time will your event start again?\n";
					
					if(hoursChoiceBool)
					{
						do
						{
							std::cin >> initialTime;
	
							if(std::cin.fail())
							{
									std::cout << "Invalid input. Please enter a valid input:\n";
									std::cin.clear();
									std::cin.ignore(256,'\n');
									repeat = true;
							}
							else
							{
								int i = initialTime;
								int len = 1;
				
								if (i > 0) { //Count number of digits in given time.
									for (len = 0; i > 0; len++) {
										i = i / 10;
									}
								}
				
								repeat = timeCheck(initialTime, len, hoursChoiceBool);
								if(initialTime < endTime)
								{
									std::cout << "Can't continue from break after previous end time. Please input a valid time: \n";
									repeat = true;
								}
							}
						}while(repeat);
					}
					else
					{
						do
						{
							bool shouldSkip = false;
	
							std::cin >> initialTime;
	
							if(std::cin.fail())
							{
									std::cout << "Invalid input. Please enter a valid input:\n";
									std::cin.clear();
									std::cin.ignore(256,'\n');
									repeat = true;
							}
							else
							{
								int i = initialTime;
								int len = 1;
				
								if (i > 0) { //Count number of digits in given time.
									for (len = 0; i > 0; len++) {
										i = i / 10;
									}
								}
		
								if(initialTime > 1300 || initialTime < 100)
								{
									shouldSkip = true;
								}
				
								if(shouldSkip)
								{
									std::cout << "Invalid time. Please input a time between 100 and 1230:\n";
								}
								else
								{
									int timeOfDay = 0;
									std::cout << "Do you want a.m. or p.m.?\n";
									std::cout << "1) a.m.\n";
									std::cout << "2) p.m.\n";
		
									std::cin >> timeOfDay;
		
									if(timeOfDay == 2 && initialTime != 1200 && initialTime != 1230) //if time is pm, add 1200 to it to make it 24 hours
									{
										initialTime += 1200;
									}
									else if (timeOfDay == 1 && initialTime == 1200) //If time is 12am, change to 0
									{
										initialTime = 0;
									}
									std::cout << initialTime << '\n';
									repeat = timeCheck(initialTime, len, hoursChoiceBool);
								}
							}
			
						}while(repeat);
					}
					
					if (initialTime != 2330)
					{	
						std::cout << "At what time will your event end? (If there are more breaks in the event, input the end time before a break)\n";
	
						do
						{
							std::cin >> endTime; 
	
							if(std::cin.fail())
							{
									std::cout << "Invalid input. Please enter a valid input:\n";
									std::cin.clear();
									std::cin.ignore(256,'\n');
									repeat = true;
							}
							else
							{
								int i = endTime;
								int len = 1;
				
								if (i > 0) { //Count number of digits in given time.
									for (len = 0; i > 0; len++) {
										i = i / 10;
									}
								}
				
								repeat = timeCheck(endTime, len, hoursChoiceBool);
								if (endTime <= initialTime)
								{
									std::cout << "Events can't go through multiple days. Please enter an end time that is after the initial time\n";
									repeat = true;
								}
							}
						}while(repeat);
					}
					else
					{
						if(hoursChoiceBool)
						{
							std::cout << "Break started at 11:30 p.m. It will run until 11:59 p.m.\n";
						}
						else
						{
							std::cout << "Break started at 23:30. It will run until 23:59.\n";
						}
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
	
				if(initialTime == 2330)
				{
					eventTime = eventTime + "2330";
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
				std::cin.ignore();
			}
			else if(stringChoice == "2")
			{
				print(hoursChoiceBool);
			}
			else if(stringChoice == "3")
			{
				std::cout << '\n';
				adminLoop = false;
			}
			else
			{
				std::cout << "Invalid Input.\n";
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

	//linkedList<date> events;
		
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
		
				date eventDate = date();
		
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
			
				eventList.addBack(eventDate);//adds new date to back of the list
				eventList.sortList();//sorts list
			}
		}
		//eventList.printList();//prints list
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
		
	for(int pos = 1; pos <= eventList.size(); pos++)
	{
		
		year = eventList.getEntry(pos).getYear();
		month = eventList.getEntry(pos).getMonth();
		day = eventList.getEntry(pos).getDay();
		timeClock = eventList.getEntry(pos).getTime();
		eventName = eventList.getEntry(pos).getEvent();
		attending = eventList.getEntry(pos).getAttendance();
	
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

		//print(true);

		/*std::cout << "Enter Year:";
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
		std::getline(std::cin, eventName);*/

		eventDate.setYear(year);
		eventDate.setMonth(month);
		eventDate.setDay(day);
		eventDate.setTime(timeClock);
		eventDate.setEvent(eventName);
		eventDate.setAttendance(attending);


		//eventList.addInOrder(eventDate);

		std::cout << '\n';
		//eventList.printList();
	
	}


bool exec::timeCheck (int time, int len, bool timeMode)
{
	if (time != 0 && time != 30 && len != 3 && len != 4)
	{
		std::cout << "Invalid time. Example times: 12:30 is 1230. 9:00 is either 0900 or 900.\n";
		return true;
	}
	if(len == 3 && (time/10)%10 != 3 && (time/10)%10 != 0)
	{
		std::cout << "Invalid time. Times must be in thirty minute intervals i.e. End in 00 or 30.\n";
		return true;
	}
	else if (time < 0 || time > 2330)
	{
		if(timeMode)
		{
			std::cout << "Invalid time. Time must be between 0000 and 2330.\n";
		}
		else
		{
			std::cout << "Invalid time. Time must be between 100 and 1230.\n";
		}
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