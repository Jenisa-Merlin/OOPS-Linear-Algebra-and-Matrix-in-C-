#ifndef BASIC_OPERATIONS_H_INCLUDED
#define BASIC_OPERATIONS_H_INCLUDED
#include "matrix.h"
using namespace std;
class Basic_operations
{
    Matrix A;
    Matrix B;
    Matrix C;
public:
    Basic_operations()
    {
        Matrix A;
        Matrix B;
        Matrix C;
    }
    Basic_operations(int r,int c)
    {
        Matrix A(r,c);
        Matrix B(r,c);
        Matrix C(r,c);
    }
    void Addition(int ,int );
    void Subtraction(int ,int );
    void ScalarMultiplication(int ,int ,int );
};
#endif // BASIC_OPERATIONS_H_INCLUDED
