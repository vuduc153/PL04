#ifndef SHAPE2D_H
#define SHAPE2D_H
#include <string>
using namespace std;

class Shape2D {
public:
	virtual string get_name() const = 0;

	virtual float compute_area() const = 0;

	virtual void translate(float tx, float ty) = 0; 

	virtual ~Shape2D() {}
};

#endif