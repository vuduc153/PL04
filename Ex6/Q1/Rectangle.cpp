#include "Rectangle.h"
#include "Point2D.h"
#include <string>
using namespace std;

Rectangle::Rectangle(Point2D left_corner, float width, float height): left_corner{left_corner}, width{width}, height{height} {}

string Rectangle::get_name() const {
	return "Rectangle";
}

float Rectangle::compute_area() const {
	return this->width * this-> height;
}

void Rectangle::translate(float tx, float ty) {
	this->left_corner.translate(tx, ty);
}