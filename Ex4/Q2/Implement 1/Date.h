#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date {
public:
  Date() {}
  void set(int m, int d, int y) {
  	day = d, month = m, year = y;
  }

  void print() const {
  	std::cout << year << "/" << month << "/" << day << std::endl;
  }
  
  int get_month() const {
  	return month;
  }

  int get_day() const {
  	return day;
  }

  int get_year() const {
  	return year;
  }
private:
  int month, day, year;

};

#endif

