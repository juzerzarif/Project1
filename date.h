#ifndef EXEC_H
#define EXEC_H

#include <string>

class date
{
	private:
		int year;
		int month;
		int day;
		int time;
		string event;
		int attendance;

	public:
		void setYear(int y);
		void setMonth(int m);
		void setDay(int d);
		void setTime(int t);
		void setEvent(int e);
		void setAttendance(int a);

		int getYear();
		int getMonth();
		int getDay();
		int getTime();
		int getEvent();
		int getAttendance();

};
#endif
