#include "Mat3x3.h"

// TODO

Mat3x3::Mat3x3() {
	for(int i = 0; i < 3; i ++) {
		matrix[i][i] = 1;
	}
}

Mat3x3::Mat3x3(double **matrix) {
	for(int i; i < MATRIX_SIZE; i ++) {
		for(int j; j < 3; j ++) {
			this->matrix[i][j] = matrix[i][j];
		}
	}
}

// Copy Constructor
Mat3x3::Mat3x3(const Mat3x3& m) {
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			this->matrix[i][j] = m.matrix[i][j];
		}
	} 
}

Mat3x3 Mat3x3::operator+ (const Mat3x3& m1, const Mat3x3& m2) {
	double matrix[3][3];
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
		}
	}
	return Mat3x3(matrix);
}

Mat3x3 Mat3x3::operator- (const Mat3x3& m1, const Mat3x3& m2) {
	double matrix[3][3];
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
		}
	}
	return Mat3x3(matrix);
}

Mat3x3 Mat3x3::operator* (const Mat3x3& m1, const Mat3x3& m2){
	double matrix[3][3];
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			matrix[i][j] = m1.matrix[i][0] * m2.matrix[0][j] + m1.matrix[i][1] * m2.matrix[1][j] + m1.matrix[i][2] * m2.matrix[2][j]; 
		}
	}
	return Mat3x3(matrix);
}

Mat3x3& Mat3x3::operator+= (const Mat3x3& m) {
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			matrix[i][j] += m.matrix[i][j];
		}
	}
	return *this;
}

Mat3x3& Mat3x3::operator-= (const Mat3x3& m) {
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			matrix[i][j] -= m.matrix[i][j];
		}
	}
	return *this;	
}

Mat3x3& Mat3x3::operator*= (const Mat3x3& m) {
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			matrix[i][j] = matrix[i][0] * m.matrix[0][j] + matrix[i][1] * m.matrix[1][j] + matrix[i][2] * m.matrix[2][j]; 
		}
	}
	return *this;
}

Mat3x3& Mat3x3::operator- (const Mat3x3& m) {

}