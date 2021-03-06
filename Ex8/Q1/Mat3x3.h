#ifndef MAT3x3_H
#define MAT3x3_H
#define MATRIX_SIZE 3
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

class Mat3x3 {
private:
	double matrix[MATRIX_SIZE][MATRIX_SIZE];
public:
	Mat3x3();

	Mat3x3(double matrix[MATRIX_SIZE][MATRIX_SIZE]);
    // Copy Constructor
	Mat3x3(const Mat3x3& m);

    Mat3x3& operator+= (const Mat3x3& m);

	Mat3x3& operator-= (const Mat3x3& m);

    Mat3x3& operator*= (const Mat3x3& m);

    double& operator()(int i, int j);

 	const double& operator()(int i, int j) const;

};

Mat3x3 operator+ (const Mat3x3& m1, const Mat3x3& m2);

Mat3x3 operator- (const Mat3x3& m1, const Mat3x3& m2);

Mat3x3 operator* (const Mat3x3& m1, const Mat3x3& m2);

bool operator== (const Mat3x3& m1, const Mat3x3& m2);

Mat3x3 operator- (const Mat3x3& m);

std::ostream& operator<< (std::ostream& os, const Mat3x3 &m);

#endif