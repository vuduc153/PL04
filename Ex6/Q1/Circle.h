#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape2D.h"
#include "Point2D.h"

class Circle: public Shape2D {
private:
	Point2D center;
	float radius;
public:
	Circle(Point2D center, float radius);
	
	virtual string get_name() const override;

	virtual float compute_area() const override;

	virtual void translate(float tx, float ty) override;  
};

#endif