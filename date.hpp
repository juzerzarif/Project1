
date::date()
{
  year = 0;
  month = 0;
  day = 0;
  time = "";
  event = "";
  attendance = "";
  tasks = "";
}

/*bool operator == (const date& date1, const date& date2)
{
  return(year == year && month == month && day == day)
}*/

void date::setYear(int y)
{
  year = y;
}

int date::getYear()
{
  return year;
}

void date::setMonth(int m)
{
  month = m;
}

int date::getMonth()
{
  return month;
}

void date::setDay(int d)
{
  day = d;
}

int date::getDay()
{
  return day;
}

void date::setTime(std::string t)
{
  time = t;
}

std::string date::getTime()
{
  return time;
}

void date::setEvent(std::string e)
{
  event = e;
}

std::string date::getEvent()
{
  return event;
}

void date::setAttendance(std::string a)
{
  attendance = a;
}

std::string date::getAttendance()
{
  return attendance;
}
