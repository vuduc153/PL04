#include "Circle.h"
#include "Point2D.h"
#include <string>
using namespace std;

const float PI = 3.141593f;

Circle::Circle(Point2D center, float radius) : center{center}, radius{radius} {}

string Circle::get_name() const {
	return "Circle";
}

float Circle::compute_area() const {
	return this->radius * this->radius * PI;
}

void Circle::translate(float tx, float ty) {
	this->center.translate(tx, ty);
}