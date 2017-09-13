
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
		std::ifstream readFile;
		readFile.open("eventFileInOrder.txt");

		//read each value and assign to a date object
		if(readFile.is_open())
		{
			while(!readFile.eof())
			{

				//linkedList<date> events;
				date eventDate;
				int year = 0;
				int month = 0;
				int day = 0;
				std::string timeClock;
				std::string eventName;
				int attending = 0;

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
					std::cout << "Event Info: " << year << " " << month << " " << day << " " << timeClock << " " << eventName << " " << attending << '\n' << '\n';

					eventDate.setYear(year);
					eventDate.setMonth(month);
					eventDate.setDay(day);
					eventDate.setTime(timeClock);
					eventDate.setEvent(eventName);
					eventDate.setAttendance(attending);

					eventList.addBack(eventDate);
					//eventList.addInOrder(eventDate);
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

		eventList.addBack(eventDate);
		eventList.sortList();
		//eventList.addInOrder(eventDate);

		std::cout << '\n';
		eventList.printList();

    }
