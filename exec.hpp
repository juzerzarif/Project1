#include "exec.h"
#include<iostream>

//ADMIN AND USER METHODS

#include "exec.h"
#include "linkedList.h"
#include <iostream>


exec :: exec()
	{

	}

exec :: ~exec()
	{

	}

void exec :: admin()
	{
		
	}

void exec :: user()
	{
		int choice;
		bool hourclock = true;

		std::cout << "Would you like your times displayed on a 12 hour or 24hour clock?\n"
		std::cout << "1) 12 hour clock\n"
		std::cout << "2) 24 hour clock\n"

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
		
    }
    
void exec::run()
    {
        std::cout<<"test";
    }
