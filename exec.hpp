
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

	}

void exec :: user()
	{
		int choice;
		std::string eventName;

		std::cout << "Would you like your times displayed on a 12 hour or 24hour clock?\n";
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
		std::cout << "Please enter the number of the event you wish to attend.";
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
			         std::string tmpstring = inbuf.substr(0,spot);
			         tmpstring += replace_string;
			         tmpstring += inbuf.substr(spot+search_string.length(), inbuf.length());
			         inbuf = tmpstring;
			      }
			
			      output_file << inbuf << std::endl;
			      
			      return(true);
			  }
			
			  //TODO: delete demo.txt and rename result.txt to demo.txt
			  // to achieve the REPLACE effect.
			
			/*
					while((!readFile.eof()) && ())
			{
				
				std::getline(readFile, entry, ':');
				std::getline(readFile, entry, ':');
				std::getline(readFile, entry, ':');
				std::getline(readFile, entry, ':');
				std::getline(readFile, entry, ':');
				eventName = entry;

				std::getline(readFile, entry, '\n');
				attending = std::atoi(entry.c_str());
			}
			*/
	}