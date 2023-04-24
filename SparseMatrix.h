#ifndef SPARSEMATRIX_H_INCLUDED
#define SPARSEMATRIX_H_INCLUDED
#include "Matrix.h"
using namespace std;
class SparseMatrix:public Matrix
{
    int nonzeros;
public:
    SparseMatrix()
    {
        nonzeros =0;
    }
    SparseMatrix(int r,int c):Matrix (r,c)
    {
         nonzeros=0;
    }
    friend istream &operator>>(istream& ,SparseMatrix& );
    friend ostream &operator<<(ostream& ,SparseMatrix& );
    void check_sparse();
    void tripletform();
};
#endif // SPARSEMATRIX_H_INCLUDED
