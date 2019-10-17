#include <iostream>
#include "Date.h"

void Date::set(int m, int d, int y) { day = d, month = m, year = y; }
	
void Date::print() const { std::cout << year << "/" << month << "/" << day << std::endl; }

int Date::get_month() const { return month; }

int Date::get_year() const { return year; }

int Date::get_day() const { return day; }



