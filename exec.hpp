
//ADMIN AND USER METHODS

exec :: exec()
	{

	}

exec :: ~exec()
	{

	}

void exec :: run()
    {
		std::ifstream fileExists("eventFile.txt");

		std::string choice;
		bool choiceRepeat = true;
		//bool skipInterface = true;


		if(!fileExists)
		{
			while(choiceRepeat)
			{
				std::cout << "==============================\n";
				std::cout << "Please select a login in mode:\n";
				std::cout << "1) Admin\n";
				std::cout << "2) User\n";
				std::cout << "3) Quit\n";
				std::cout << "==============================\n";

				std::getline(std::cin, choice);
				if(choice == "1")
				{
					choiceRepeat = admin(choiceRepeat);

					/*if (choiceRepeat == false)
					{
						skipInterface = false;

					}*/
					//call to the admin method
				}
				else if (choice == "2")
				{
					std::cout << "Empty Calander, you must create an event through admin first.\n";
					//call to the user method
				}
				else if(choice == "3")
				{
					choiceRepeat = false;
					std::cout << "Bye!\n";
				}
				else //if the user gives something that isnt a vaild input it will tell them it is invalid and restart
				{

						std::cout << "Invalid input.\n\n";

				}
			}
		}

		choiceRepeat = true;
		std::ifstream newfileExists("eventFile.txt");

		if(newfileExists)
		{
			while(choiceRepeat)
			{
				std::cout << "==============================\n";
				std::cout << "Please select a login in mode:\n";
				std::cout << "1) Admin\n";
				std::cout << "2) User\n";
				std::cout << "3) Quit\n";
				std::cout << "==============================\n";

				std::getline(std::cin, choice);
				if(choice == "1")
				{
					admin(choiceRepeat);
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

						std::cout << "Invalid input.\n\n";

				}
			}
		}
	}

bool exec :: admin(bool ultimateEventCheck)
	{
		bool adminLoop = true; //Handles looping of the admin method
		bool superBool = false; //Handles looping of various while loops
		bool hoursChoiceBool = true; //Handles looping of the choice of 12 or 24 hours

		std::cout << "==============================\n";
		std::cout << "Would you like your times displayed on a 12 hour or 24 hour clock?\n";
		std::cout << "1) 12 hour clock\n";
		std::cout << "2) 24 hour clock\n";
		std::cout << "==============================\n";
		std::string hoursChoice = "";

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
		system("cls");
		while(adminLoop)
		{
			std::string stringChoice = ""; //Choice on creating event, looking at events, or quitting
			int eventYear = 0; //Takes year
			int eventMonth = 0; //Takes month
			int eventDay = 0; //Takes day
			std::string eventBreak = ""; //1 if user wants a break. 2 if not
			std::string peopleAttending = ""; //Event creator will be added first.
			std::string eventCreator = "";
			int initialTime = 0; //Gets initial time of event or initial time after break
			int endTime = 0; //Gets end time of event or end time after break
			std::string eventName = ""; //Takes name of event. Can't have colons (:)
			std::string eventTime = ""; //Contains all the event times. Adds initialTime and endTime every time they are given
			bool repeat = true; //Handles looping of various while loops
			bool eventDayCheck = true; //Handles looping of choosing day
			bool eventMonthCheck = true; //Handles looping of choosing month
			bool noMore = false; //If a time of 23:30 or 11:30 pm is given, noMore will turn true and skip any further asking for times.
			bool bogo = true; //Tells program whether or not to add a space after user gives breaks
			bool skipAll = false; //True if event goes until midnight.

			std::cout << "==============================\n";
			std::cout << "Select an option:\n";
			std::cout << "1) Create new event\n";
			std::cout << "2) View current activities\n";
			std::cout << "3) Back to Login selection\n";
			std::cout << "==============================\n";

			std::getline(std::cin, stringChoice);
			system("cls");
			//std::cin.ignore();

			//Choose Add Event or Show Events

			if(stringChoice == "1")
			{
				bool eventNameCheck = true; //Handles looping of event name

				std::cout << "Admin, please enter your name\n";
				std::getline(std::cin, eventCreator);
				system("cls");
				peopleAttending += (eventCreator + ", ");

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
					else if(eventCheck(eventName))
					{
						std::cout << "Event name already exists please pick a new one: \n";
						eventNameCheck = true;
					}
					else
					{
						eventNameCheck = false;
					}
				}while(eventNameCheck);
				system("cls");

				std::cout << "What year will the event be on? It can be from 2017 to 2021.\n";

				//Choose year of event
				do
				{
					superBool = true;


					std::cin >> eventYear;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
				system("cls");
				//Choose month of event
				do
				{
					std::cout << "==============================\n";
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
					std::cout << "==============================\n";
					std::cin >> eventMonth;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
				system("cls");
				std::cout << "==============================\n";
				std::cout << "What numerical day will your event be on?\n";
				std::cout << "==============================\n";

				//Choose day of event
				do
				{
					std::cin >> eventDay;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
				system("cls");
				if(hoursChoiceBool)
				{
					std::cout << "==============================\n";
					std::cout << "At what time will your event start? (Time is meassured in half hour intervals)\n";
					std::cout << "Example times: 14:30 is 1430. 9:00 is either 0900 or 900.\n";
					std::cout << "==============================\n";

					do
					{
						std::cin >> initialTime;
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
					system("cls");
				}
				else
				{
					std::cout << "==============================\n";
					std::cout << "At what time will your event start? (Time is meassured in half hour intervals)\n";
					std::cout << "Example times: 12:30 is 1230. 9:00 is either 0900 or 900.\n";
					std::cout << "a.m. or p.m. will be asked later. Just input the number.\n";
					std::cout << "==============================\n";

					do
					{
						bool shouldSkip = false; //Determines whether given time is valid by checking if its between 1 and 1230. True if invalid time is given

						std::cin >> initialTime;
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

						if(std::cin.fail())
						{
								std::cout << "Invalid input. Please enter a valid input:\n";
								std::cin.clear();
								std::cin.ignore(256,'\n');
								repeat = true;
						}
						else
						{
							int i = initialTime; //Tempotaty variable to check for int length
							int len = 1; //Temporary variable to check for int length

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
								superBool = true;

								std::string timeOfDay;
								//std::cin.ignore();
								while(superBool)
								{
									std::cout << "==============================\n";
									std::cout << "Do you want a.m. or p.m.?\n";
									std::cout << "1) a.m.\n";
									std::cout << "2) p.m.\n";
									std::cout << "==============================\n";

									std::getline(std::cin, timeOfDay);

									if(timeOfDay == "1" || timeOfDay == "2")
									{
										superBool = false;
									}
									else
									{
										std::cout << "Invalid input. Please enter a valid input.\n";
									}
								}

								if(timeOfDay == "2" && initialTime != 1200 && initialTime != 1230) //if time is pm, add 1200 to it to make it 24 hours
								{
									initialTime += 1200;
								}
								else if (timeOfDay == "1" && initialTime == 1200) //If time is 12am, change to 0
								{
									initialTime = 0;
								}
								else if (timeOfDay == "1" && initialTime == 1230) //If time is 12:30am, change to 30
								{
									initialTime = 30;
								}
								repeat = timeCheck(initialTime, len, hoursChoiceBool);
							}
						}

					}while(repeat);
					system("cls");
				}

				if (initialTime != 2330)
				{
					if(hoursChoiceBool)
					{
						std::cout << "==============================\n";
						std::cout << "At what time will your event end? \n(If there are breaks in the event, input the end time before a break). \nIf you want your event to go until 23:59 enter 2359  \n";
						std::cout << "==============================\n";

						do
						{
							std::cin >> endTime;
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

								if (endTime == 2359)
								{
									skipAll = true;
									repeat = false;
								}
								else
								{
									repeat = timeCheck(endTime, len, hoursChoiceBool);
									if (endTime <= initialTime)
									{
										std::cout << "Events can't go through multiple days. Please enter an end time that is after the initial time:\n";
										repeat = true;
									}
								}
							}
						}while(repeat);
					}
					else
					{
						std::cout << "==============================\n";
						std::cout << "At what time will your event end?\n(If there are breaks in the event, input the end time before a break).\nIf you want your event to go until 11:59 p.m. enter 1159 (then p.m.)\n";
						std::cout << "==============================\n";
						do
						{
							bool shouldSkip = false; //Determines whether given time is valid by checking if its between 1 and 1230. True if invalid time is given
							repeat = true;

							std::cin >> endTime;
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

									if (endTime == 1159)
									{
										//skipAll = true;
										//repeat = false;

									}
									else if(endTime > 1230 || endTime < 100)
									{
										shouldSkip = true;
									}

									if(shouldSkip)
									{
										std::cout << "Invalid time. Please input a time between 100 and 1230:\n";
									}
									else
									{
										superBool = true;
										std::string timeOfDay;
										//std::cin.ignore();

										while(superBool)
										{
											std::cout << "==============================\n";
											std::cout << "Do you want a.m. or p.m.?\n";
											std::cout << "1) a.m.\n";
											std::cout << "2) p.m.\n";
											std::cout << "==============================\n";

											std::getline(std::cin, timeOfDay);

											if(timeOfDay == "1" || timeOfDay == "2")
											{
												superBool = false;
											}
											else
											{
												std::cout << "Invalid input. Please enter a valid input.\n";
											}
										}
										if(endTime == 1159 && timeOfDay == "2")
										{
											skipAll = true;
											repeat = false;
										}

										if(!skipAll)
										{
											if(timeOfDay == "2" && endTime != 1200 && endTime != 1230) //if time is pm, add 1200 to it to make it 24 hours
											{
												endTime += 1200;
											}
											else if (timeOfDay == "1" && endTime == 1200) //If time is 12am, change to 0
											{
												endTime = 0;
											}
											else if (timeOfDay == "1" && initialTime == 1230) //If time is 12:30am, change to 30
											{
												initialTime = 30;
											}
											else if (timeOfDay == "1" && endTime == 1230)
											{
												endTime = 30;
											}
											repeat = timeCheck(endTime, len, hoursChoiceBool);
											if (endTime <= initialTime)
											{
												std::cout << "Events can't go through multiple days. Please enter an end time that is after the initial time:\n";
												repeat = true;
											}
										}
										else
										{
											repeat = false;
										}
									}
								}
						}while(repeat);
					}

				}
				else
				{
					noMore = true;
					if(!hoursChoiceBool)
					{
						std::cout << "Event started at 11:30 p.m. It will run until 11:59 p.m.\n";
					}
					else
					{
						std::cout << "Event started at 23:30. It will run until 23:59.\n";
					}
				}
				system("cls");
				if(!skipAll)
				{
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
				}
				else
				{
					if(endTime == 1159)
					{
						endTime = 2330;
					}
					for(int i = initialTime; i < endTime; i+=30)
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

					if(!hoursChoiceBool)
					{
						if(!hoursChoiceBool)
						{
							eventTime = eventTime + " " + "2330";
						}
						else
						{
							eventTime = eventTime + "2330";
						}

					}

					noMore = true;
				}
				system("cls");
				if(endTime == 2330) //Dont allow user to input breaks if end time is 11:30 pm
				{
					noMore = true;
				}
				if(initialTime == 2300 && endTime == 2330)
				{
					noMore = true;
					eventTime = std::to_string(initialTime);
				}
				else if(endTime == (initialTime + 30))
				{
					eventTime = std::to_string(initialTime);
				}
				system("cls");
				if(!noMore)
				{
					superBool = true;
					while(superBool)
					{
						std::cout << "==============================\n";
						std::cout << "Are there breaks in your event?\n";
						std::cout << "1) Yes\n";
						std::cout << "2) No\n";
						std::cout << "==============================\n";

						std::getline(std::cin, eventBreak);

						if(eventBreak == "1" || eventBreak == "2")
						{
							superBool = false;
						}
						else
						{
							std::cout << "Invalid input. Please enter a valid input.\n";
						}

					}

				}
				else
				{
					eventBreak = "2";
				}
				system("cls");
				//Choose if break
				while(eventBreak == "1")
				{
					if(bogo)
					{
						eventTime = eventTime + " "; //Adds a space between times when event is added
						std::cout << "==============================\n";
						std::cout << "At what time will your event start again?\n";
						std::cout << "==============================\n";
						bogo = false;
					}
					if(hoursChoiceBool)
					{
						do
						{
							repeat = true;

							std::cin >> initialTime;
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
								if(initialTime <= endTime)
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
							repeat = true;

							bool shouldSkip = false; //Determines whether given time is valid by checking if its between 1 and 1230. True if invalid time is given

							std::cin >> initialTime;
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

							if(std::cin.fail())
							{
									std::cout << "==============================\n";
									std::cout << "Invalid input. Please enter a valid input:\n";
									std::cout << "==============================\n";
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

								if (endTime == 1159)
								{
									//skipAll = true;
									//repeat = false;

								}
								else if(initialTime > 1230 || initialTime < 100)
								{
									shouldSkip = true;
								}

								if(shouldSkip)
								{
									std::cout << "Invalid time. Please input a time between 100 and 1230:\n";
								}
								else
								{
								superBool = true;
								std::string timeOfDay;

								while(superBool)
								{
									std::cout << "==============================\n";
									std::cout << "Do you want a.m. or p.m.?\n";
									std::cout << "1) a.m.\n";
									std::cout << "2) p.m.\n";
									std::cout << "==============================\n";

									std::getline(std::cin, timeOfDay);

									if(timeOfDay == "1" || timeOfDay == "2")
									{
										superBool = false;
									}
									else
									{
										std::cout << "Invalid input. Please enter a valid input.\n";
									}
									if(endTime == 1159 && timeOfDay == "2")
									{
										skipAll = true;
										repeat = false;
									}
								}
									if(!skipAll)
									{
										if(timeOfDay == "2" && initialTime != 1200 && initialTime != 1230) //if time is pm, add 1200 to it to make it 24 hours
										{
											initialTime += 1200;
										}
										else if (timeOfDay == "1" && initialTime == 1200) //If time is 12am, change to 0
										{
											initialTime = 0;
										}
										repeat = timeCheck(initialTime, len, hoursChoiceBool);

										if (initialTime <= endTime)
										{
											std::cout << "Events can't go through multiple days. Please enter an end time that is after the initial time:\n";
											repeat = true;
										}
									}
								}
							}

						}while(repeat);
					}

					if (initialTime != 2330)
					{
						if(hoursChoiceBool)
						{
							std::cout << "==============================\n";
							std::cout << "At what time will your event end?\n(If there are breaks in the event, input the end time before a break).\nIf you want your event to go until 23:59 enter 2359 \n";
							std::cout << "==============================\n";
							do
							{
								std::cin >> endTime;
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

									if (endTime == 2359)
									{
										skipAll = true;
										repeat = false;
									}
									else
									{
										repeat = timeCheck(endTime, len, hoursChoiceBool);
										if (endTime <= initialTime)
										{
											std::cout << "Events can't go through multiple days. Please enter an end time that is after the initial time:\n";
											repeat = true;
										}
									}
								}
							}while(repeat);
						}
						else
						{
							std::cout << "==============================\n";
							std::cout << "At what time will your event end? (If there are breaks in the event, input the end time before a break). If you want your event to go until 11:59 p.m. enter 1159 p.m. \n";
							std::cout << "==============================\n";
							do
							{
								bool shouldSkip = false; //Determines whether given time is valid by checking if its between 1 and 1230. True if invalid time is given
								repeat = true;

								std::cin >> endTime;
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
											superBool = true;
											std::string timeOfDay;
											//std::cin.ignore();

											while(superBool)
											{
												std::cout << "==============================\n";
												std::cout << "Do you want a.m. or p.m.?\n";
												std::cout << "1) a.m.\n";
												std::cout << "2) p.m.\n";
												std::cout << "==============================\n";

												std::getline(std::cin, timeOfDay);

												if(timeOfDay == "1" || timeOfDay == "2")
												{
													superBool = false;
												}
												else
												{
													std::cout << "Invalid input. Please enter a valid input.\n";
												}
											}

											if(!skipAll)
											{
												if(timeOfDay == "2" && endTime != 1200 && endTime != 1230) //if time is pm, add 1200 to it to make it 24 hours
												{
													endTime += 1200;
												}
												else if (timeOfDay == "1" && endTime == 1200) //If time is 12am, change to 0
												{
													endTime = 0;
												}
												if (timeOfDay == "2" && endTime == 2359)
												{
													skipAll = true;
													repeat = false;
												}
												if (!skipAll)
												{
													repeat = timeCheck(endTime, len, hoursChoiceBool);
												}
												if (endTime <= initialTime)
												{
													std::cout << "Events can't go through multiple days. Please enter an end time that is after the initial time:\n";
													repeat = true;
												}
											}

										}
								}
							}while(repeat);
						}
						if(initialTime == 2300 && endTime == 2330)
						{
							eventTime = eventTime + std::to_string(initialTime);
						}

					}
					else
					{
						noMore = true;

						if(initialTime == 2300 && endTime == 2330)
						{
							eventTime = eventTime + std::to_string(initialTime);
						}

						if(!hoursChoiceBool)
						{
							std::cout << "Break started at 11:30 p.m. It will run until 11:59 p.m.\n";
						}
						else
						{
							std::cout << "Break started at 23:30. It will run until 23:59.\n";
						}
						eventBreak = "2";
					}

					if(endTime == 2330 || endTime == 2359)
					{
						noMore = true;
						eventBreak = "2";
					}
					else if(endTime == (initialTime + 30))
					{
						eventTime = eventTime + std::to_string(initialTime);
					}

					if(!skipAll)
					{
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
					}
					else
					{
						if(endTime == 1159)
						{
							endTime = 2330;
						}
						for(int i = initialTime; i < endTime; i+=30)
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
						//eventTime = eventTime + "2330";
						noMore = true;
					}

					if(!noMore)
					{
						superBool = true;

						//std::cin.ignore();
						//std::cin.ignore();

						while(superBool)
						{
							std::cout << "==============================\n";
							std::cout << "Are there any more breaks in your event?\n";
							std::cout << "1) Yes\n";
							std::cout << "2) No\n";
							std::cout << "==============================\n";

							std::getline(std::cin, eventBreak);

							if(eventBreak == "1" || eventBreak == "2")
							{
								superBool = false;
							}
							else
							{
								std::cout << "Invalid input. Please enter a valid input.\n";
							}

						}
					}

					if(eventBreak == "1")
					{
						bogo = true;
					}
				}
				system("cls");
				if(initialTime == 2330)
				{
					eventTime = eventTime + "2330";
				}

				std::ifstream fileExists("eventFile.txt");
				if(fileExists) //If file exists, start at the end, add new line and add info
				{
					std::ofstream outFile;
					outFile.open("eventFile.txt", std::ios_base::app | std::ios_base::out);
					std::cout << peopleAttending;
					outFile << '\n' << eventYear << ":" << eventMonth << ":" << eventDay << ":" << eventTime << ":" << eventName << ":" << peopleAttending;
					outFile.close();

				}
				else //If file does not exist, create it and add info
				{
					std::ofstream outFile;
					outFile.open("eventFile.txt", std::ios_base::app | std::ios_base::out);
					std::cout << peopleAttending;
					outFile << eventYear << ":" << eventMonth << ":" << eventDay << ":" << eventTime << ":" << eventName << ":" << peopleAttending;
					outFile.close();
					ultimateEventCheck = false;
				}
				std::cout << "Event created!\n";
				eventBreak = "";
				//std::cin.ignore();
			}
			else if(stringChoice == "2")
			{
				system("cls");
				print(hoursChoiceBool);
			}
			else if(stringChoice == "3")
			{
				system("cls");
				std::cout << '\n';
				adminLoop = false;
			}
			else
			{
				std::cout << "Invalid Input.\n";
			}
		}
		return(ultimateEventCheck);
	}

void exec :: user()
	{
		int choice;
		std::string eventName;
		std::string userName;
		bool aproval = false;

		do
		{
				std::cout << "==============================\n";
				std::cout << "Would you like your times displayed on a 12 hour or 24 hour clock?\n";
				std::cout << "1) 12 hour clock\n";
				std::cout << "2) 24 hour clock\n";
				std::cout << "==============================\n";

				std::cin >> choice;

				if(choice == 1)
				{
					print(false);

					aproval = true;

				}
				else if(choice == 2)
				{
					print(true);

					aproval = true;

				}
				else //if the user gives something that isnt a vaild input it will tell them it is invalid and restart
				{
					if( std::cin.fail() )//checks for bad input, by checking that it is the correct type,then checking it was a option listed
			    		{
			      			std::cin.clear(); // unset failbit
			      			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
							std::cout << '\n';
			     			std::cout << "Sorry, your input was not a number choice, try again\n";
							std::cout << '\n';
			   			}
					else if((choice > 2) || (choice <= 0))//checks that it is a valid numerical input
						{
							std::cout << "Sorry, your number selection was not an option, try again.\n";
							std::cout << '\n';
						}

					aproval = false;

				}

		}while(!aproval);

			std::cout << "==============================" << '\n';
			std::cout << "Please enter the name of the event you wish to attend.\nEvent names lie between colons(:), don't include them! :D \n";
			std::cin.ignore();
			std::getline (std::cin,eventName,'\n');
			std::cout << "==============================" << '\n';

			std::cout << "User, what is your name?\n";
			//std::cin.ignore();
			std::getline(std::cin, userName);
	   	bool foundCheck = updateEvent(eventName, userName);


	   	if(foundCheck == true)
	   	{
	   		std::cout << "You are now signed up for the event, don't forget to go!\n";
	   	}
	   	else
	   	{
	   		std::cout << "The event name you entered was unfortunatly not found in the list of events.\n";
	   	}




	}

void exec :: print(bool time)
{

	std::cout << "==============================" << '\n' << "Events List (Furthest in the future at top)" << '\n' << "==============================" << '\n' <<'\n';

	linkedList<date> eventsList;

	std::ifstream readFile;
	readFile.open("eventFile.txt");

	//linkedList<date> eventList;

	int year = 0;
	int month = 0;
	int day = 0;
	std::string timeClock;
	std::string eventName;
	std::string attending = "";

	std::string nameMonth;
	int startTime = 0;
	int endTime = 0;

	//read each value and assign to a date object
	//insert date object into the sorted linked list
	//output error if file is not open
	if(readFile.is_open())
	{
		//std::cout << "1." << '\n';

		while(!readFile.eof())
		{
			//std::cout << "2." << '\n';
			std::string entry;

			std::getline(readFile, entry, ':' ); //read line by ':' separated value
			//std::cout << "3." << '\n';

			if(entry != "") //check for case in which return is done after last line in text file
			{
				//std::cout << "4." << '\n';

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
				attending = entry;

				//std::cout << "5." << '\n';

				eventDate.setYear(year);
				eventDate.setMonth(month);
				eventDate.setDay(day);
				eventDate.setTime(timeClock);
				eventDate.setEvent(eventName);
				eventDate.setAttendance(attending);

				//std::cout << "6." << '\n';
				eventsList.addBack(eventDate);//adds new date to back of the list
				//eventNum ++;
				//std::cout << "7." << '\n';

				//std::cout << "8." << '\n';
			}
		}

		readFile.close();//close file
	}
	else
	{
		std::cout << "Empty Calendar!" << '\n' << '\n';
	}

	if(eventsList.size() != 0)
	{
		eventsList.sortList();//sorts list
	}

	//std::cout << "END." << '\n';

	//Prints all objects in linkedList in readable format
	for(int pos = 1; pos <= eventsList.size(); pos++)
	{

		year = eventsList.getEntry(pos).getYear();
		month = eventsList.getEntry(pos).getMonth();
		day = eventsList.getEntry(pos).getDay();
		timeClock = eventsList.getEntry(pos).getTime();
		eventName = eventsList.getEntry(pos).getEvent();
		attending = eventsList.getEntry(pos).getAttendance();


		//inputs blocks of time into an integer array timeKeeper
		std::istringstream sortedTime(timeClock);
		int lastPosition = 0;
		int timeKeeper [48];
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


		//Prints in either 12 or 24 hour
		if(time == true) //24 hour
		{

			//parse array for start and end times of each block, append to end of string
			timeClock = "";
			int i = 0; //position in array
			int naturalTimeInterval = 0; //end time to be printed for each block

			while(i < lastPosition)
			{
				if(i==0)
				{
					startTime = timeKeeper[i];
					endTime = 0;
					i++;

					if(lastPosition == i)
					{

						if(startTime % 100 != 0)
						{
							naturalTimeInterval = 70;
						}
						else
						{
							naturalTimeInterval = 30;
						}

						if(startTime == 2330)
						{
							timeClock.append(format24Hr(startTime));
							timeClock.append(" - ");
							timeClock.append(format24Hr(2359));
						}
						else
						{

							timeClock.append(format24Hr(startTime));
							timeClock.append(" - ");
							timeClock.append(format24Hr(startTime+naturalTimeInterval));

						}
					}
				}
				else
				{
					//Check to determine whether time is on an hour or 30-minute interval
					//update officialTime to be used for appropriate output
					if(endTime == 0)
					{
						if(startTime % 100 != 0)
						{
							naturalTimeInterval = 70;
						}
						else
						{
							naturalTimeInterval = 30;
						}
					}
					else
					{
						if(endTime % 100 != 0)
						{
							naturalTimeInterval = 70;
						}
						else
						{
							naturalTimeInterval = 30;
						}
					}

					//Check to determine if endTime should be updated
					//or if time block complete and move to next time block
					//append completed time to string
					//2400 becomes 2359
					if(startTime == (timeKeeper[i]-naturalTimeInterval))
					{
						endTime = timeKeeper[i];

						if(i == lastPosition-1)
						{
							if(endTime % 100 != 0)
							{
								naturalTimeInterval = 70;
							}
							else
							{
								naturalTimeInterval = 30;
							}
							timeClock.append(format24Hr(startTime));
							timeClock.append(" - ");
							timeClock.append(format24Hr(endTime+naturalTimeInterval));
						}

					}
					else if(endTime == (timeKeeper[i] - naturalTimeInterval))
					{

						endTime = timeKeeper[i];

						if(i == lastPosition-1)
						{
							if(endTime % 100 != 0)
							{
								naturalTimeInterval = 70;
							}
							else
							{
								naturalTimeInterval = 30;
							}
							timeClock.append(format24Hr(startTime));
							timeClock.append(" - ");
							timeClock.append(format24Hr(endTime+naturalTimeInterval));
						}

					}
					else //complete time block
					{
						if (endTime == 0)
						{


							if(startTime % 100 != 0)
							{
								naturalTimeInterval = 70;
							}
							else
							{
								naturalTimeInterval = 30;
							}

							if(startTime == 2330)
							{
								timeClock.append(format24Hr(startTime));
								timeClock.append(" - ");
								timeClock.append(format24Hr(2359));
							}
							else if(i == lastPosition-1)
							{
								timeClock.append(format24Hr(startTime));
								timeClock.append(" - ");
								timeClock.append(format24Hr(startTime+naturalTimeInterval));
								timeClock.append(", ");

								//print last option
								startTime = timeKeeper[i];
								if(startTime % 100 != 0)
								{
									naturalTimeInterval = 70;
								}
								else
								{
									naturalTimeInterval = 30;
								}

								timeClock.append(format24Hr(startTime));
								timeClock.append(" - ");
								timeClock.append(format24Hr(startTime+naturalTimeInterval));
							}
							else
							{
								timeClock.append(format24Hr(startTime));
								timeClock.append(" - ");
								timeClock.append(format24Hr(startTime+naturalTimeInterval));
								timeClock.append(", ");
							}

							startTime = timeKeeper[i];

						}
						else
						{


							timeClock.append(format24Hr(startTime));
							timeClock.append(" - ");
							timeClock.append(format24Hr(endTime+naturalTimeInterval));
							timeClock.append(", ");

							startTime = timeKeeper[i];
							endTime = 0;


							if (i == lastPosition-1)
							{
								if(startTime % 100 != 0)
								{
									naturalTimeInterval = 70;
								}
								else
								{
									naturalTimeInterval = 30;
								}

								if(startTime == 2330)
								{
									timeClock.append(format24Hr(startTime));
									timeClock.append(" - ");
									timeClock.append(format24Hr(2359));
								}
								else
								{
									timeClock.append(format24Hr(startTime));
									timeClock.append(" - ");
									timeClock.append(format24Hr(startTime+naturalTimeInterval));
								}
							}

						}
					}

					i++;
				}

			}
		}
		else //12 hour
		{


			//parse array for start and end times of each block, append to end of string
			timeClock = "";
			int i = 0; //position in array
			int naturalTimeInterval = 0; //end time to be printed for each block

			while(i < lastPosition)
			{
				if(i==0)
				{
					startTime = timeKeeper[i];
					endTime = 0;
					i++;

					if(lastPosition == i)
					{

						if(startTime % 100 != 0)
						{
							naturalTimeInterval = 70;
						}
						else
						{
							naturalTimeInterval = 30;
						}

						if(startTime == 2330)
						{
							timeClock.append(make12Hr(startTime));
							timeClock.append(" - ");
							timeClock.append(make12Hr(2359));
						}
						else
						{

							timeClock.append(make12Hr(startTime));
							timeClock.append(" - ");
							timeClock.append(make12Hr(startTime+naturalTimeInterval));

						}
					}
				}
				else
				{
					//Check to determine whether time is on an hour or 30-minute interval
					//update officialTime to be used for appropriate output
					if(endTime == 0)
					{
						if(startTime % 100 != 0)
						{
							naturalTimeInterval = 70;
						}
						else
						{
							naturalTimeInterval = 30;
						}
					}
					else
					{
						if(endTime % 100 != 0)
						{
							naturalTimeInterval = 70;
						}
						else
						{
							naturalTimeInterval = 30;
						}
					}

					//Check to determine if endTime should be updated
					//or if time block complete and move to next time block
					//append completed time to string
					//2400 becomes 2359
					if(startTime == (timeKeeper[i]-naturalTimeInterval))
					{
						endTime = timeKeeper[i];

						if(i == lastPosition-1)
						{
							if(endTime % 100 != 0)
							{
								naturalTimeInterval = 70;
							}
							else
							{
								naturalTimeInterval = 30;
							}
							timeClock.append(make12Hr(startTime));
							timeClock.append(" - ");
							timeClock.append(make12Hr(endTime+naturalTimeInterval));
						}

					}
					else if(endTime == (timeKeeper[i] - naturalTimeInterval))
					{

						endTime = timeKeeper[i];

						if(i == lastPosition-1)
						{
							if(endTime % 100 != 0)
							{
								naturalTimeInterval = 70;
							}
							else
							{
								naturalTimeInterval = 30;
							}
							timeClock.append(make12Hr(startTime));
							timeClock.append(" - ");
							timeClock.append(make12Hr(endTime+naturalTimeInterval));
						}

					}
					else //complete time block
					{
						if (endTime == 0)
						{


							if(startTime % 100 != 0)
							{
								naturalTimeInterval = 70;
							}
							else
							{
								naturalTimeInterval = 30;
							}

							if(startTime == 2330)
							{
								timeClock.append(make12Hr(startTime));
								timeClock.append(" - ");
								timeClock.append(make12Hr(2359));
							}
							else if(i == lastPosition-1)
							{
								timeClock.append(make12Hr(startTime));
								timeClock.append(" - ");
								timeClock.append(make12Hr(startTime+naturalTimeInterval));
								timeClock.append(", ");

								//print last option
								startTime = timeKeeper[i];
								if(startTime % 100 != 0)
								{
									naturalTimeInterval = 70;
								}
								else
								{
									naturalTimeInterval = 30;
								}

								timeClock.append(make12Hr(startTime));
								timeClock.append(" - ");
								timeClock.append(make12Hr(startTime+naturalTimeInterval));
							}
							else
							{
								timeClock.append(make12Hr(startTime));
								timeClock.append(" - ");
								timeClock.append(make12Hr(startTime+naturalTimeInterval));
								timeClock.append(", ");
							}

							startTime = timeKeeper[i];

						}
						else
						{


							timeClock.append(make12Hr(startTime));
							timeClock.append(" - ");
							timeClock.append(make12Hr(endTime+naturalTimeInterval));
							timeClock.append(", ");

							startTime = timeKeeper[i];
							endTime = 0;


							if (i == lastPosition-1)
							{
								if(startTime % 100 != 0)
								{
									naturalTimeInterval = 70;
								}
								else
								{
									naturalTimeInterval = 30;
								}

								if(startTime == 2330)
								{
									timeClock.append(make12Hr(startTime));
									timeClock.append(" - ");
									timeClock.append(make12Hr(2359));
								}
								else
								{
									timeClock.append(make12Hr(startTime));
									timeClock.append(" - ");
									timeClock.append(make12Hr(startTime+naturalTimeInterval));
								}
							}
						}
					}
					i++;
				}
			}
		}


		//Puts month selection in readable format
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


		std::cout << "Event      => " << ':' <<eventName << ':' << "\n";
		std::cout << "Date       => " << nameMonth << " " << day << ", " << year << "\n";
		std::cout << "Time       => " << timeClock << '\n';
		std::cout << "Attending  => " << attending << '\n'<<'\n';

	}

	std::cout << "==============================" << '\n';
}


std::string exec::make12Hr(int num)
{
	std::string AmPmTime;
	if(num == 2400)
	{
		AmPmTime= "11:59 PM";
	}
	else if(num > 1230)
	{
		num = num - 1200;
		AmPmTime = std::to_string(num);

		if(AmPmTime.length() == 4)
		{
			AmPmTime.insert(2,":");
		}
		else
		{
			AmPmTime.insert(1,":");
		}

		AmPmTime.append(" PM");
	}
	else if(num < 100)
	{
		num = num + 1200;
		AmPmTime = std::to_string(num);

		if(AmPmTime.length() == 4)
		{
			AmPmTime.insert(2,":");
		}
		else
		{
			AmPmTime.insert(1,":");
		}

		AmPmTime.append(" AM");
	}
	else
	{
		AmPmTime = std::to_string(num);

		if(AmPmTime.length() == 4)
		{
			AmPmTime.insert(2,":");
		}
		else
		{
			AmPmTime.insert(1,":");
		}

		AmPmTime.append(" AM");
	}
	return(AmPmTime);
}

std::string exec::format24Hr(int num)
{
	std::string worldTime;
	if(num == 0)
	{
		worldTime = "00:00";
	}
	else if(num == 30)
	{
		worldTime = "00:30";
	}
	else if(num == 2400)
	{
		worldTime = "23:59";
	}
	else if(num < 1000)
	{
		worldTime = std::to_string(num);
		worldTime.insert(1,":");
		worldTime.insert(0,"0");
	}
	else
	{
		worldTime = std::to_string(num);
		worldTime.insert(2,":");

	}
	return(worldTime);
}

/*
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
		//eventList.printList();

	}
*/

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
		std::cout << "Pick a new time:\n";
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
		std::cout << "Pick a new time:\n";
		return true;
	}
	else if ((len == 3 && (time%10) != 0) && (len == 3 && (time%10) !=3))
	{
		std::cout << "Invalid time. Times must be in thirty minute intervals i.e. End in 00 or 30.\n";
		std::cout << "Pick a new time:\n";
		return true;
	}
	else if ((time%10) != 0)
	{
		std::cout << "Invalid time. Times must be in thirty minute intervals i.e. End in 00 or 30.\n";
		std::cout << "Pick a new time:\n";
		return true;
	}
	else
	{
		return false;
	}
}


bool exec::updateEvent(std::string eventNameCheck, std::string userName)
	{
		//define used varibles
		//int year = 0;
		std::string attending = "";
		//int i = 0;

		std::ifstream readFile;
		std::string temp;
		std::string yearString;
		std::string month;
		std::string day;
		std::string timeClock;
		std::string eventName;
		std::string attendingString;
		std::string inbuf;
		std::string initalLine;
		std::string replace_string;
		std::string search_string = eventNameCheck;

		char oldFileName[] ="update.txt";
		char newFileName[] ="eventFile.txt";
		
		

		bool removeCheck = false;

		//std::cout << eventNum;

		////open the event file
		//std::fstream input_file1("eventFile.txt", std::ios::in);
		////open the output file
		//std::ofstream output_file1("update.txt");
		

		//while(getline(input_file1, initalLine))
		//{
		//	if(!initalLine.empty())
		//	{
		//		   
		//      	//if(i == eventNum)
		//      //	{
		//        //	output_file1 << initalLine;
		//    //	}
		//    //	else
		//    //	{
		//			output_file1 << initalLine << std::endl;
		//    //	}
		//	//	i++;
		//				
		//	}
		//}

		//		//deletes the original textfile
		//		remove("eventFile.txt");

		//		//renames the newly created textfile to the old name
		//		rename("update.txt", "eventFile.txt");



		readFile.open("eventFile.txt");

		if(readFile.is_open())
		{
		//	std::ifstream in_file
			
			//read through the whole list
			while(!readFile.eof())
			{
				//store each value of each event in temparary varibles
				std::string entry;

				std::getline(readFile, entry, ':');
				//year = std::atoi(entry.c_str());
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
				attending = entry;

					//check that the line isnt blank, and that the temprary even name read in equals the one we are searching for
					if((eventName == eventNameCheck))
					{
						//set the fact that we found the event to true
						removeCheck = true;

						//set the attending string to the number that is was found
						attendingString = (attending);
						
						//std::cout << attendingString;

						//assemble the string that includes the event name as one string that can be searched
						search_string = yearString + ":" + month + ":" + day + ":" + timeClock + ":" + eventName + ":" + attendingString;

						/* //was used to check that search_string was outputting correctly
						std::cout << "Find: ";
						std::cout << search_string ;
						std::cout << '\n';
						*/

						//Add username to attending
						attending += (userName + ", ");

						//update the attending string to reflect the incremented attendence
						attendingString = (attending);

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
		
		if(removeCheck == true)
		{

			//open the input file
			std::fstream input_file("eventFile.txt", std::ios::in);
			
			//open the output file
			std::ofstream output_file("update.txt");
			//2017:1:31:800 830:Birthday Bash:Kaiser, 
				  while (!input_file.eof())
				  {
					  std::getline(input_file, inbuf);
					  std::string event_name;
					  
					  std::string delimiter = ":";
					  event_name = inbuf.substr(inbuf.find(delimiter)+1, std::string::npos);
					  event_name = event_name.substr(event_name.find(delimiter)+1, std::string::npos);
					  event_name = event_name.substr(event_name.find(delimiter)+1, std::string::npos);
					  event_name = event_name.substr(event_name.find(delimiter)+1, std::string::npos);
					  event_name = event_name.substr(0, event_name.find(delimiter));
					  if (event_name == eventNameCheck)
					  {
						  output_file << (replace_string);
						  if (!input_file.eof())
						  {
							  output_file << std::endl;
						  }
					  }
					  else
					  {
						  output_file << (inbuf);
						  if (!input_file.eof())
						  {
							  output_file << std::endl;
						  }
					  }
					  
					  
					  //  //each line to a tempoary varible inbuf
				   //   std::getline(input_file, inbuf);

					  ////search each tempoary string for the search string, and record location in spot
				   //   int spot = inbuf.find(search_string);

				   //   if(spot >= 0)
				   //   {
				   //   	 //subtract search string from the file and record location in tmpstring
				   //      std::string tmpstring = inbuf.substr(0,spot);
				   //      //replace the subtracted string with the replace string in that place
				   //      tmpstring += replace_string;
				   //      tmpstring += inbuf.substr(spot + search_string.length(), inbuf.length());
				   //      inbuf = tmpstring;
				   //   }

				   //   //doesnt print any empty lines
				   //   if ( ! inbuf.empty() )
				   //   {
				   //      output_file << inbuf << std::endl;
				   //   }

				}
				  input_file.close();
				  output_file.close();
				//deletes the original textfile
				if (remove("eventFile.txt") != 0)
					perror("Error deleting file");
				else
					puts("File successfully deleted");

				//renames the newly created textfile to the old name
				rename("update.txt", "eventFile.txt");
		}

			//returns if the event was found
			return(removeCheck);
	}

bool exec::eventCheck(std::string eventNameCheck)
	{
		//define used varibles
		int year = 0;

		std::ifstream readFile;
		std::string eventName = eventNameCheck;
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

				/*
				* ignore the info we dont care about
				*/
				std::getline(readFile, entry, ':');
				std::getline(readFile, entry, ':');
				std::getline(readFile, entry, ':');

				std::getline(readFile, entry, ':');
				eventName = entry;

				std::getline(readFile, entry, '\n');

					//check that the line isnt blank, and that the temprary event name read in equals the one we are searching for
					if((year != 0) && (eventName == eventNameCheck))
					{
						//set the fact that we found the event to true
						removeCheck = true;
					}


			}
			readFile.close();//close file
		}
		else
		{
			//if file didnt open for some reason output that.
			std::cout << "Error Opening File!" << '\n';

		}
		return(removeCheck);
	}
