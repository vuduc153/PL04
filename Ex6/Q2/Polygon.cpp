#include "Polygon.h"
#include "Point2D.h"
#include <string>
using namespace std;

Polygon::Polygon(Point2D *vertices_list, int N) {
	this->N = N;
	this->vertices_list = new Point2D[this->N];
	for(int i = 0; i < this->N; i ++) 
		this->vertices_list[i] = vertices_list[i]; 
}

string Polygon::get_name() const {
	return "Polygon";
}

float Polygon::compute_area() const {
	float x_i, y_i, x_next, y_next;
	float sum = 0;
	for(int i = 0; i < this->N; i ++) {
		x_i = this->vertices_list[i].get_x();
		y_i = this->vertices_list[i].get_y();
		if(i+1 == N) {
			x_next = this->vertices_list[0].get_x();
			y_next = this->vertices_list[0].get_y();
		}
		else {
			x_next = this->vertices_list[i+1].get_x();
			y_next = this->vertices_list[i+1].get_y();
		}
		sum += x_i * y_next - x_next * y_i;
	}
	float area = 0.5 * sum;
	return area;
}

void Polygon::translate(float tx, float ty) {
	for(int i = 0; i < this->N; i ++) 
		this->vertices_list[i].translate(tx, ty);
}