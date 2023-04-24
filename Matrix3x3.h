#ifndef MATRIX3X3_H_INCLUDED
#define MATRIX3X3_H_INCLUDED
#include "Matrix.h"
#include "SquareMatrix.h"
using namespace std;
class Matrix3x3 : public SquareMatrix
{
public:
    Matrix3x3():SquareMatrix(3)
    {
        rows = 3;
        columns = 3;
    }
    friend istream &operator>>(istream& ,Matrix3x3& );
    friend ostream &operator<<(ostream& ,Matrix3x3& );
    int Determinant();
    void Eigenvave();
    int cofac(int,int,int,int);
    int *cubeq(int , int, int );
    int eigvecsolve(int [3][3]);
};
#endif // MATRIX3X3_H_INCLUDED
