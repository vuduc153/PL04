#include "Point.h"
#include "Compare.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<Point> find_k_closest(int k, vector<Point> points) {
	priority_queue<Point, vector<Point>, Compare> sorted;
	vector<Point> result;
	
	Compare comparefunc;

	for(int i = 0; i < points.size(); ++i) {
		if(sorted.size() <= k)
			sorted.push(points[i]);
		else if(comparefunc(points[i], sorted.top())) {
			sorted.pop();
			sorted.push(points[i]);
		}
	}

	for(int i = 0; i < k; ++i) {
		result.push_back(sorted.top());
		sorted.pop();
	}

	return result;
}

int main(void) {

	vector<Point> points;
	points.push_back(Point(1.0,2.0,3.0));
	points.push_back(Point(5.0,5.0,5.0));
	points.push_back(Point(0.0,2.0,1.0));
	points.push_back(Point(9.0,2.0,1.0));
	points.push_back(Point(1.0,2.0,1.0));
	points.push_back(Point(2.0,2.0,1.0));

	vector<Point> closest = find_k_closest(3, points);
	for(size_t i = 0; i < 3; ++i) {
		cout << closest[i].x << "," << closest[i].y << "," 
		<< closest[i].z << endl;
	}
	return 0;
}