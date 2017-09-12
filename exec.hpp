
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

		/*
		TO DO: 2 portions below to complete
		*/

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

		std::string nameMonth;
		int startTime = 0;
		int endTime = 0;


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

					
					/*
					TO DO: PUT ON LINKED LIST TO SORT 
					*/

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

					std::istringstream sortedTime(timeClock);
					int tempTime = 0;
					while (sortedTime) 
					{
						std::string timeBlock;
						sortedTime >> timeBlock;
						tempTime = std::stoi(timeBlock);
					}


					std::cout << "Event: " << eventName << "\n";
					std::cout << "Date: " << nameMonth << " " << day << ", " << year << "\n"; 
					
					std::cout << "Time: " << timeClock << '\n';
					std::cout << "Attending: " << attending << '\n' << '\n';


				}
			}
			//std::cout << '\n' << "reached end of file" << '\n';
			readFile.close();//close file
		}
		else
		{
			std::cout << "Error Opening File!" << '\n'; 

		}

		/*
		TO DO: Print out each node in sorted array in readable format
		*/



    }
    

void exec::test()
    {
		std::cout<<"test" << '\n' << '\n';
		print(true);
    }

