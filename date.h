#ifndef DATE_H
#define DATE_H

#include <string>

class date
{
	private:
		int year;
		int month;
		int day;
		std::string time;
		std::string event;
		int attendance;

	public:
		date();

		void setYear(int y);
		void setMonth(int m);
		void setDay(int d);
		void setTime(std::string t);
		void setEvent(std::string e);
		void setAttendance(int a);

		int getYear();
		int getMonth();
		int getDay();
		std::string getTime();
		std::string getEvent();
		int getAttendance();

};

#include "date.hpp" 
#endif
