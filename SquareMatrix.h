#ifndef SQUAREMATRIX_H_INCLUDED
#define SQUAREMATRIX_H_INCLUDED
#include "Matrix.h"
using namespace std;
class SquareMatrix:public Matrix
{
protected:
    int order;
public:
    SquareMatrix()
    {
        order = 0;
    }
    SquareMatrix(int r):Matrix(r,r)
    {
        order =r;
    }
};
#endif // SQUAREMATRIX_H_INCLUDED
