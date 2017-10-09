#ifndef DATE_H
#define DATE_H

#include <string>

/**
 *	Date class. This defines all of the date class' private member variables and public methods.
 *	@author	Giovanni Artavia
 *	@author Brandon Lammey
 *	@author	Dylan Herrig
 *	@author James Glass
 */

class date
{
	private:
		/**
		 *	Private member variable. Holds the date's year.
		 */
		int year;

		/**
		 *	Private member variable. Holds the date's month.
		 */
		int month;

		/**
		 *	Private member variable. Holds the date's day.
		 */
		int day;

		/**
		 *	Private member variable. Holds the date's time. startTime endTime = hourMinute hourMinute
		 */
		std::string time;

		/**
		 *	Private member variable. Holds the date's event name.
		 */
		std::string event;

		/**
		 *	Private member variable. Holds the date's list of people attending.
		 */
		std::string attendance;
		
		/**
		 *	Private member variable. Holds the tasks of the date and attendees assigned to those tasks.
		 */
		std::string tasks;

	public:

		/**
		 *	Constructor for the linkedList class.
		 */
		date();

		/**
		 *	Public method that takes one argument of type int and does not return.
		 *	Details: Sets the date's year.
		 *	@param y the first argument.
		 */
		void setYear(int y);

		/**
		 *	Public method that takes one argument of type int and does not return.
		 *	Details: Sets the date's month.
		 *	@param m the first argument.
		 */
		void setMonth(int m);

		/**
		 *	Public method that takes one argument of type int and does not return.
		 *	Details: Sets the date's day.
		 *	@param d the first argument.
		 */
		void setDay(int d);

		/**
		 *	Public method that takes one argument of type string and does not return.
		 *	Details: Sets the date's year.
		 *	@param t the first argument.
		 */
		void setTime(std::string t);

		/**
		 *	Public method that takes one argument of type string and does not return.
		 *	Details: Sets the date's event name.
		 *	@param e the first argument.
		 */
		void setEvent(std::string e);

		/**
		 *	Public method that takes one argument of type int and does not return.
		 *	Details: Sets the date's total amount of attendees.
		 *	@param a the first argument.
		 */
		void setAttendance(std::string a);
		
		/**
		 *	Public method that takes one argument of type string and does not return.
		 *	Details: Sets the date's task information.
		 *	@param t the first argument.
		void setTasks(std::string t);

		/**
		 *	Public method that takes no arguments and returns an int.
		 *	@returns the date's current year.
		 */
		int getYear();
		
		/**
		 *	Public method that takes no arguments and returns a string.
		 *	@returns the date's task information.
		 */
		std::string getTasks();

		/**
		 *	Public method that takes no arguments and returns an int.
		 *	@returns the date's current month.
		 */
		int getMonth();

		/**
		 *	Public method that takes no arguments and returns an int.
		 *	@returns the date's current day.
		 */
		int getDay();

		/**
		 *	Public method that takes no arguments and returns an string.
		 *	@returns the date's current time. Formatted as (startTime endTime = HourMinute HourMinute).
		 */
		std::string getTime();

		/**
		 *	Public method that takes no arguments and returns an string.
		 *	@returns the date's current event name.
		 */
		std::string getEvent();

		/**
		 *	Public method that takes no arguments and returns an int.
		 *	@returns the date's current total number of attendees.
		 */
		std::string getAttendance();
};
#include "date.hpp"
#endif

