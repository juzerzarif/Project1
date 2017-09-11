
date::date()
{
  year = 0;
  month = 0;
  day = 0;
  time = "";
  event = "";
  attendance = 0;
}

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

void date::setAttendance(int a)
{
  attendance = a;
}

int date::getAttendance()
{
  return attendance;
}
