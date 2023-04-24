#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
using namespace std;
class Matrix
{
    protected:
    int rows;
    int columns;
public:
    int **mat;
    Matrix();
    Matrix(int ,int );
    friend istream &operator>>(istream& ,Matrix& );
    friend ostream &operator<<(ostream& ,Matrix& );
    int rankofmatrix(int ,int );
    void swap(int **,int ,int ,int );

};
#endif // MATRIX_H_INCLUDED
