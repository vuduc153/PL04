#include <iostream>
#include <unordered_set>
#include <fstream>
#include "Point.h"

using namespace std;
// ...
int main(void) {
	// define the hash set for storing the point
	unordered_set<Point, Point_hash, Point_equal> table;

	ifstream in("point_list.txt");
	cout << "Reading points from file" << endl;
	while (!in.eof()) {
		int x, y;
		in >> x >> y;

		Point p{x,y};
		table.insert(p);
	}
	cout << "Points read from file. Now enter some query point." << endl;

	while (cin) {
		int x, y;
		cin >> x >> y;
		Point p{x,y};

		// check if p is in the table, 
		// if it is print "point found"
		// otherwise print "not found"
		unordered_set<Point, Point_hash, Point_equal>::const_iterator result = table.find(p);

		if (result == table.end()) {
			cout << "Not found" << endl;
		}
		else {
			cout << "Point found" << endl;
		}
	}
	return 0;

}