
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
			//call to the admin method
		}
		else if (choice == 2)
		{
			//call to the user method
		}
		else
		{
			//error	
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
		int halfInterval = 0;
		int peopleAttending = 1;
		std::string activityName;
		std::string eventTime;

		std::cout << "Select an option:\n";
		std::cout << "1) Create new activity\n";
		std::cout << "2) View current activities\n";
		
		std::cin >> choice;

		if(choice == 1)
		{
			std::cout << "Please enter the name of the activity:\n";
			std::cin.ignore();
			std::getline (std::cin,activityName,'\n');

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

			std::cout << "At what time will your event take place? (Time is meassured in half hour intervals. If your event spans multiple half hours, please enter the initial half hour interval.)\n";
			std::cout << "Examples: 1100 indicates 11 a.m. 2130 indicates 9:30 p.m.\n";
			std::cin.ignore();
			std::getline (std::cin,eventTime,'\n');

			std::cout << "Does your event span another half hour interval?\n";
			std::cout << "1) Yes\n";
			std::cout << "2) No\n";
			std::cin >> halfInterval; //TODO check if valid time

			while(halfInterval == 1)
			{
				std::string additionalTime = "";
				std::cout << "What other interval of time will your event be taking? (Time is meassured in half hour intervals. If your event spans multiple half hours, please enter the initial half hour interval.)\n";
				std::cout << "Examples: 1100 indicates 11 a.m. 2130 indicates 9:30 p.m.\n";
				std::cin.ignore();
				std::getline (std::cin,additionalTime,'\n');
				eventTime = eventTime + " " + additionalTime;

				std::cout << "Does your event span another half hour interval?\n";
				std::cout << "1) Yes\n";
				std::cout << "2) No\n";
				std::cin >> halfInterval;
			}
			//std::cout << eventTime;
		}
	
	}

void exec :: user()
	{
		int choice;
		bool hourclock = true;

		std::cout << "Would you like your times displayed on a 12 hour or 24hour clock?\n";
		std::cout << "1) 12 hour clock\n";
		std::cout << "2) 24 hour clock\n";

		std::cin >> choice;

		if(choice == 1)
		{
			//print
		}
		else if(choice == 2)
		{

		}
		else
		{

		}

		//call to print method
		std::cout << "Please choose an event from the list above";

	}

void exec :: print(bool time)
	{
		//goals create linked list and print raw info

		//linkedList<date> events;
		date eventDate;

		std::ifstream readFile; 
		readFile.open("eventFile.txt");

		int year = 0;
		int month = 0;
		int day = 0;
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
				year = std::stoi(entry);

				std::getline(readFile, entry, ':');
				month = std::stoi(entry);

				std::getline(readFile, entry, ':');
				day = std::stoi(entry);

				std::getline(readFile, entry, ':');
				timeClock = entry;

				std::getline(readFile, entry, ':');
				eventName = entry;

				std::getline(readFile, entry, ':');
				attending = std::stoi(entry);

				std::cout << "Event Info: " << year << " " << month << " " << day << " " << timeClock << " " << eventName << " " << attending << '\n' << '\n';

				eventDate.setYear(year);
				eventDate.setMonth(month);
				eventDate.setDay(day);
				eventDate.setTime(timeClock);
				eventDate.setEvent(eventName);
				eventDate.setAttendance(attending);



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
		int choice;
		
			std::cout << "Please select a login in mode:\n";
			std::cout << "1) Admin\n";
			std::cout << "2) User\n";
		
			std::cin >> choice;
		
			if( choice == 1)
			{
				admin();
			}
			else if (choice == 2)
			{
				user();
			}
		
    }

