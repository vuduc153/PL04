#ifndef MATNxN_H
#define MATNxN_H
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

template <typename T, int N>
class MatNxN {
private:
    T matrix[N][N];
public:
    MatNxN();

    MatNxN(T matrix[N][N]);
    // Copy Constructor
    MatNxN(const MatNxN<T, N>& m);

    MatNxN<T, N>& operator+= (const MatNxN<T, N>& m);

    MatNxN<T, N>& operator-= (const MatNxN<T, N>& m);

    MatNxN<T, N>& operator*= (const MatNxN<T, N>& m);

    T& operator()(int i, int j);

    const T& operator()(int i, int j) const;

};

template <typename T, int N>
MatNxN<T, N>::MatNxN() {
    for(int i = 0; i < N; i ++) {
        matrix[i][i] = 1;
    }
}

template <typename T, int N>
MatNxN<T, N>::MatNxN(T matrix[N][N]) {
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            this->matrix[i][j] = matrix[i][j];
        }
    }
}

// Copy Constructor
template <typename T, int N>
MatNxN<T, N>::MatNxN(const MatNxN<T, N>& m) {
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            this->matrix[i][j] = m.matrix[i][j];
        }
    } 
}

template <typename T, int N>
MatNxN<T, N>& MatNxN<T, N>::operator+= (const MatNxN<T, N>& m) {
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            matrix[i][j] += m.matrix[i][j];
        }
    }
    return *this;
}

template <typename T, int N>
MatNxN<T, N>& MatNxN<T, N>::operator-= (const MatNxN<T, N>& m) {
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            matrix[i][j] -= m.matrix[i][j];
        }
    }
    return *this;   
}

template <typename T, int N>
MatNxN<T, N>& MatNxN<T, N>::operator*= (const MatNxN<T, N>& m) {
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            matrix[i][j] = matrix[i][0] * m.matrix[0][j] + matrix[i][1] * m.matrix[1][j] + matrix[i][2] * m.matrix[2][j]; 
        }
    }
    return *this;
}

template <typename T, int N>
T& MatNxN<T, N>::operator()(int i, int j) {
    return matrix[i][j];
}

template <typename T, int N>
const T& MatNxN<T, N>::operator()(int i, int j) const {
    return matrix[i][j];    
}

template <typename T, int N>
MatNxN<T, N> operator+ (const MatNxN<T, N>& m1, const MatNxN<T, N>& m2) {
    T matrix[N][N];
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            matrix[i][j] = m1(i, j) + m2(i, j);
        }
    }
    return MatNxN<T, N>(matrix);
}

template <typename T, int N>
MatNxN<T, N> operator- (const MatNxN<T, N>& m1, const MatNxN<T, N>& m2) {
    T matrix[N][N];
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            matrix[i][j] = m1(i, j) - m2(i, j);
        }
    }
    return MatNxN<T, N>(matrix);
}

template <typename T, int N>
MatNxN<T, N> operator* (const MatNxN<T, N>& m1, const MatNxN<T, N>& m2){
    T matrix[N][N];
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            matrix[i][j] = m1(i, 0) * m2(0, j) + m1(i, 1) * m2(1, j) + m1(i, 2) * m2(2, j); 
        }
    }
    return MatNxN<T, N>(matrix);
}

template <typename T, int N>
bool operator== (const MatNxN<T, N>& m1, const MatNxN<T, N>& m2) {
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            if(m1(i, j) != m2(i, j))
                return false;
        }
    }
    return true;
}

template <typename T, int N>
MatNxN<T, N> operator- (const MatNxN<T, N>& m) {
    T matrix[N][N];
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            matrix[i][j] = - m(i, j);
        }
    }
    return MatNxN<T, N>(matrix);
}

template <typename T, int N>
std::ostream& operator<< (std::ostream& os, const MatNxN<T, N> &m) {
    std::ostringstream s;
    for(int i = 0; i < N; i ++) {
        s << '[';
        for(int j = 0; j < N; j ++) {
            s << ' ' << m(i, j) << ' ';
        }
        s << ']' << std::endl;
    } 
    s << std::endl;
    return os << s.str();
}


#endif