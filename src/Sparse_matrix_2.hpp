#ifndef TP1_METODOS_SPARSE_MATRIX_2_2_H
#define TP1_METODOS_SPARSE_MATRIX_2_2_H

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <tuple>
#include <map>
#include <math.h>

using namespace std;

typedef map<int, double>::const_iterator it_s_vec;
typedef map<int, double> s_vec;
typedef map<int, map<int, double> >::iterator it_s_matrix;
typedef map<int, map<int, double> > s_matrix;

class Sparse_matrix_2 {
public:
    // Constructor of Sparse_matrix_2 Class initallized with 0 on every position.
    Sparse_matrix_2(int rows, int cols) {
        _rows = rows;
        _cols = cols;
        s_matrix _matrix;
    }

    Sparse_matrix_2(const Sparse_matrix_2 & other) = default;

    int rows() const;
    int cols() const;
    double operator()(int row_idx, int col_idx) const;
    double operator()(int idx) const;
    void setIndex(int i, int j, double value);
    Sparse_matrix_2 operator+(const Sparse_matrix_2& m) const;
    Sparse_matrix_2 operator*(const double& scalar) const; //scalar multiplication
    bool operator==(const Sparse_matrix_2& other) const;
    void swapRows(int i1, int i2);
    Sparse_matrix_2 getRow(int index) const;
    Sparse_matrix_2 Sparse_mubMatrix(int i1, int i2, int j1, int j2) const;
    friend std::ostream& operator<<(std::ostream& o, const Sparse_matrix_2& a);
    Sparse_matrix_2 subMatrix(int i1, int i2, int j1, int j2) const;
    Sparse_matrix_2 multiply(const Sparse_matrix_2 b) const;
    Sparse_matrix_2 transpose() const;
    friend double dotProd(const Sparse_matrix_2 u, const Sparse_matrix_2 w);
    static Sparse_matrix_2 identity(int n);
    std::tuple<int, int> maxCoeff();
    Sparse_matrix_2 abs();
    bool isApproximate(const Sparse_matrix_2 b) const;

    /*
    std::tuple<int, int> shape() const;
    Sparse_matrix_2 multiply(const Sparse_matrix_2 b);
    static Sparse_matrix_2 identity(int n);

    std::tuple<int, int> maxCoeff();
    friend std::ostream& operator<<(std::ostream& o, const Sparse_matrix_2& a);
    bool isApproximate(const Sparse_matrix_2 b, double epsilon) const;
     */

private:
    int _rows;
    int _cols;
    s_matrix _matrix; //pointer of type int to the location of the Sparse_matrix_2.
    double _epsilon = 0.0000001;
};

;

#endif //TP1_METODOS_SPARSE_MATRIX_2_2_H
