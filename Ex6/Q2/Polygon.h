#ifndef POLYGON_H
#define POLYGON_H
#include "Shape2D.h"
#include "Point2D.h"

class Polygon: public Shape2D {
private:
	Point2D *vertices_list;
	int N;
public:
	Polygon(Point2D* vertices_list, int N);

	virtual string get_name() const;

	virtual float compute_area() const;

	virtual void translate(float tx, float ty);
};

#endif