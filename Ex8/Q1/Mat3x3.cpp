#include "Mat3x3.h"

Mat3x3::Mat3x3() {
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		matrix[i][i] = 1;
	}
}

Mat3x3::Mat3x3(double matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
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

double& Mat3x3::operator()(int i, int j) {
	return matrix[i][j];
}

const double& Mat3x3::operator()(int i, int j) const {
 	return matrix[i][j];	
}

Mat3x3 operator+ (const Mat3x3& m1, const Mat3x3& m2) {
	double matrix[3][3];
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			matrix[i][j] = m1(i, j) + m2(i, j);
		}
	}
	return Mat3x3(matrix);
}

Mat3x3 operator- (const Mat3x3& m1, const Mat3x3& m2) {
	double matrix[3][3];
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			matrix[i][j] = m1(i, j) - m2(i, j);
		}
	}
	return Mat3x3(matrix);
}

Mat3x3 operator* (const Mat3x3& m1, const Mat3x3& m2){
	double matrix[3][3];
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			matrix[i][j] = m1(i, 0) * m2(0, j) + m1(i, 1) * m2(1, j) + m1(i, 2) * m2(2, j); 
		}
	}
	return Mat3x3(matrix);
}

bool operator== (const Mat3x3& m1, const Mat3x3& m2) {
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			if(m1(i, j) != m2(i, j))
				return false;
		}
	}
	return true;
}

Mat3x3 operator- (const Mat3x3& m) {
	double matrix[3][3];
	for (int i = 0; i < MATRIX_SIZE; i ++) {
		for (int j = 0; j < MATRIX_SIZE; j ++) {
			matrix[i][j] = - m(i, j);
		}
	}
	return Mat3x3(matrix);
}

std::ostream& operator<< (std::ostream& os, const Mat3x3 &m) {
	std::ostringstream s;
	for(int i = 0; i < MATRIX_SIZE; i ++) {
		s << '[';
		for(int j = 0; j < MATRIX_SIZE; j ++) {
			s << ' ' << m(i, j) << ' ';
		}
		s << ']' << std::endl;;
	} 
	s << std::endl;
	return os << s.str();
}