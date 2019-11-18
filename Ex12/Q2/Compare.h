#ifndef COMPARE_H
#define COMPARE_H
#include "Point.h"

class Compare {
public:
	bool operator() (const Point& first, const Point& second);
};

#endif