
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
			bool eventNameCheck = true;
			std::cout << "Enter the name of the activity. Please no colons (:).\n";
			do
			{
				std::cin.ignore();
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
					std::cin >> initialTime; //TODO: Check if time does not overlap when there is a break
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

