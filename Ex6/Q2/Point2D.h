#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
private:
	float x;
	float y;
public:
	Point2D(float x, float y): x{x}, y{y} {}

	// Default Constructor
	Point2D(): x{0}, y{0} {}
	
	// Assignment Operator
	Point2D& operator=(const Point2D& point) {
		if(this == &point) return *this;
		x = point.x;
		y = point.y;
		return *this;
	}

	void translate(float x, float y) {
		this->x += x;
		this->y += y;
	}

	float get_x() const {
		return this->x;
	}

	float get_y() const {
		return this->y;
	}
};

#endif