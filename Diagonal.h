#ifndef DIAGONAL_H_INCLUDED
#define DIAGONAL_H_INCLUDED
#include "Matrix.h"
#include "SquareMatrix.h"
using namespace std;
class Diagonal :public SquareMatrix
{
public:
    Diagonal():SquareMatrix()
    {
        cout<<"Default";
    }
    Diagonal(int r):SquareMatrix(r)
    {
        order = r;
    }
    friend istream &operator>>(istream& ,Diagonal& );
    friend ostream &operator<<(ostream& ,Diagonal& );
    void Determinant();
    void Eigenvave();
};
#endif // DIAGONAL_H_INCLUDED
