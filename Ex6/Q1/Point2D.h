#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
private:
	float x;
	float y;
public:
	Point2D(float x, float y): x{x}, y{y} {}
	
	void translate(float x, float y) {
		this->x += x;
		this->y += y;
	}
};

#endif