#include <cmath>
#include "Compare.h"

double distance(const Point& p) {
	return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}

bool Compare::operator() (const Point& first, const Point& second) {
	return distance(first) < distance(second);
}