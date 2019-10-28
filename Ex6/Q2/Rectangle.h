#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape2D.h"
#include "Point2D.h"

class Rectangle: public Shape2D {
private:
	Point2D left_corner;
	float width;
	float height;
public:
	Rectangle(Point2D left_corner, float width, float height);

	virtual string get_name() const override;

	virtual float compute_area() const override;

	virtual void translate(float tx, float ty) override;  
};

#endif