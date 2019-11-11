#ifndef POINT_H
#define POINT_H

using namespace std;

struct Point {
 int x, y;
};

struct Point_hash {
	size_t operator() (const Point& p) const {
		size_t h = 0;
		hash<int> hs;
		h = hs(p.x) ^ hs(p.y);
		return h;
	}
};

struct Point_equal {
	bool operator() (const Point& p1, const Point& p2) const {
		return (p1.x == p2.x) && (p1.y) == (p2.y);
	}
};

#endif