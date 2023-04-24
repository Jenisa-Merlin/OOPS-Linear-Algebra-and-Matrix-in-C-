#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<fstream>

#include "Diagonal.h"
#include "Matrix.h"
#include "SquareMatrix.h"
#include "SparseMatrix.h"
#include "Matrix3x3.h"
#include "Basic_operations.h"

using namespace std;


Matrix::Matrix()
{
    rows =0;
    columns =0;
    mat = new int *[0];
}


Matrix::Matrix(int r,int c)
{
    rows = r;
    columns = c;
    mat = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        mat[i] = new int[columns];
    }
}


void Matrix :: swap(int **mat1, int row1, int row2,int col) //swapping function definition
{
    mat = new int*[rows];
        for(int i = 0; i < rows; ++i)
        {
         mat[i] = new int[columns];
        }
    for (int i = 0; i < col; i++)
    {
        int temp = mat1[row1][i];
        mat1[row1][i] = mat1[row2][i];
        mat1[row2][i] = temp;
    }
}


int Matrix :: rankofmatrix(int row,int col) //rank definition
{
    int rank1;
    rank1 = columns;
        for (int row = 0; row < rank1; row++)
    {
        if (mat[row][row])
        {
           for (int col = 0; col < rows; col++)
           {
               if (col != row)
               {
                 double mult = (double)mat[col][row] / mat[row][row];
                 for (int i = 0; i < rank1; i++)
                   mat[col][i] -= mult * (mat[row][i]);
              }
           }
        }
        else
        {
            bool reduce = true;
            for (int i = row + 1; i < rows;  i++)
            {
                if (mat[i][row])
                {
                    swap(mat, row, i, rank1);
                    reduce = false;
                    break ;
                }
            }
            if (reduce)
            {
                rank1--;
                for (int i = 0; i < rows; i ++)
                {
                    mat[i][row] = mat[i][rank1];
                }
            }
            row--;
        }
}
return rank1;
}


istream &operator>>(istream &in, Diagonal& M) //overloaded insertion operator function definition
{
    int i,j;
    cout<<"Enter the diagonal elements of the matrix:"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i != j)
            {
                M.mat[i][j]=0;
            }
            else
            {
                in>>M.mat[i][j];
            }
        }
    }
    return in;
}


ostream &operator<<(ostream &out,Diagonal& M) //overloaded extraction operator function definition
{
    int i,j;
    cout<<endl;
    for( i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<M.mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return out;
}


istream &operator>>(istream &in, Matrix3x3& M) //overloaded insertion operator function definition
{
    int i,j;
    cout<<"Enter the matrix:"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            in>>M.mat[i][j];
        }
    }
    return in;
}


ostream &operator<<(ostream &out,Matrix3x3& M) //overloaded extraction operator function definition
{
    int i,j;
    cout<<endl;
    for( i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<M.mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return out;
}


int Matrix3x3 ::eigvecsolve(int mat[3][3]) //eigenvecsolve function definition
{
	cout<<(mat[0][1]*mat[1][2]-mat[0][2]* mat[1][1])<<" ";
	cout<<(mat[0][2]*mat[1][0]-mat[1][2]*mat[0][0])<<" ";
	cout<<(mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0])<<" ]";
	return 0;
}


int *Matrix3x3 ::cubeq(int bu, int cu, int du) //cubeq function definition
{
	int au=1,p,q,ca,fi,cb;
	static int eig[3];
	p=(3*au*cu-bu*bu)/(3*au*au);
	q=(2*pow(bu,3)-9*au*bu*cu+27*au*au*du)/(27*pow(au,3));
	if(p>0)
    {
        cout<<"At least one root is complex!";
        return 0;
    }
	ca=2*pow((-p/3),0.5);
	fi=acos((3*q)/(ca*p));
	cb=-bu/(3*au);
	eig[0]=nearbyint(ca*cos(fi/3)+cb);
	eig[1]=nearbyint(ca*cos((fi+2*3.14)/3)+cb);
	eig[2]=nearbyint(ca*cos((fi+4*3.14)/3)+cb);
	cout<<"\nFirst eigen value: "<<-eig[0];
	cout<<"\nSecond eigen value: "<<-eig[1];
	cout<<"\nThird eigen value: "<<-eig[2];
	return eig;
}


int Matrix3x3 ::cofac(int a1,int b1,int c1,int d1) //cofac function definition
{
    int det2=0;
	int counter,count2;
	det2=a1*d1-b1*c1;
	return det2;
}


void Matrix3x3 ::Eigenvave() //eigenvave function definition
{
    int sum=0, mid;
	int a[3],eigena[3],mat2[3][3];
	int *temp;
	int i,j,chen;
	a[1]=cofac(mat[1][1],mat[1][2],mat[2][1],mat[2][2])+cofac(mat[0][0],mat[0][2],mat[2][0],mat[2][2])+cofac(mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
	a[0]=mat[0][0]+mat[1][1]+mat[2][2];
	a[2]=Determinant();
	temp=cubeq(a[0],a[1],a[2]);
	eigena[0]=*temp;
	eigena[1]=*(temp+1);
	eigena[2]=*(temp+2);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			{
				mat2[i][j]=mat[i][j];
			}
	}
	for(chen=0;chen<3;chen++)
	{
		for(i=0;i<3;i++)
	  {
		mat2[i][i]-=eigena[chen];
	  }
	  cout<<"\n\nEigen Vector "<<(chen+1)<<": [ ";
	  eigvecsolve(mat2);
	  for(i=0;i<3;i++)
	  {
		for(j=0;j<3;j++)
			{
				mat2[i][j]=mat[i][j];
			}
	  }
	}
	ofstream outfile;
        outfile.open("OOPS.txt",ios::app);
        if(!outfile)
        {
            cout<<endl;
            cout<<"Error"<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"File opened"<<endl;;
            outfile<<"Eigen values and vectors found"<<endl;
        }
        outfile.close();
}


int Matrix3x3 ::Determinant() //determinant function definition
{
    int sum=0;
	int i,j;
	for(i=0;i<3;i++)
	{
		if(i==0)
		{
			sum+=mat[i][0]*(mat[i+1][i+1]*mat[i+2][i+2]-mat[i+1][i+2]*mat[i+2][i+1]);
		}
		if(i==1)
		{
			sum-=mat[i][0]*(mat[i-1][i]*mat[i+1][i+1]-mat[i-1][i+1]*mat[i+1][i]);
		}
		if(i==2)
		{
			sum+=mat[i][0]*(mat[i-2][i-1]*mat[i-1][i]-mat[i-2][i]*mat[i-1][i-1]);
		}
	}
	cout<<"\nDeterminant is:"<<sum;
	return sum;
	ofstream outfile;
        outfile.open("OOPS.txt",ios::app);
        if(!outfile)
        {
            cout<<endl;
            cout<<"Error"<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"File opened"<<endl;;
            outfile<<"Determinant calculated"<<endl;
        }
        outfile.close();
}


void SparseMatrix::tripletform() //triplet form function definition
{
    int i,j,k=1;
    int size = 0;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            if(mat[i][j] != 0)
            {
                size++;
            }
        }
    }
    int b[size+1][3];
    b[0][0] = rows;
    b[0][1] = columns;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            if(mat[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = mat[i][j];
                k++;
            }
        }
    }
    b[0][2] = size;
    cout<<endl;
    cout<<"Elements of sparse matrix in triple notation :"<<endl;
    for(i=0; i<size+1; i++)
    {
        for(j=0; j<3; j++)
        {
            cout<<b[i][j]<<" ";
        }
       cout<<endl;
    }
    ofstream outfile;
        outfile.open("OOPS.txt",ios::app); //file open
        if(!outfile) //file condition
        {
            cout<<endl;
            cout<<"Error"<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"File opened"<<endl;
            outfile<<"Triplet form of sparse matrix is found";
        }
        outfile.close(); //file closing
}


void SparseMatrix::check_sparse() //check sparse function definition
{
    int zeros = 0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            if(mat[i][j] == 0)
            {
                zeros++;
            }
        }
    }
    nonzeros = (rows*columns)-zeros;
    cout<<"Number of non zero entries:"<<nonzeros<<endl;
    if(zeros > (rows*columns)/2)
    {
        cout<<"The matrix is a sparse matrix"<<endl;
    }
    else
    {
        cout<<"The matrix is not a sparse matrix"<<endl;
    }
    ofstream outfile;
        outfile.open("OOPS.txt",ios::app); //file open
        if(!outfile) //file condition
        {
            cout<<endl;
            cout<<"Error";
        }
        else
        {
            cout<<endl;
            cout<<"File opened";
            outfile<<"Checked whether sparse matrix or not";
        }
        outfile.close(); //file closing
}


istream &operator>>(istream &in, SparseMatrix& M) //overloaded insertion operator function definition
{
    int i,j;
    cout<<"Enter the matrix:"<<endl;;
    for(i=0;i<M.rows;i++)
    {
        for(j=0;j<M.columns;j++)
        {
            in>>M.mat[i][j];
        }
    }
    return in;
}


ostream &operator<<(ostream &out,SparseMatrix& M) //overloaded extraction operator function
{
    int i,j;
    cout<<endl;
    for( i=0;i<M.rows;i++)
    {
        for(j=0;j<M.columns;j++)
        {
            cout<<M.mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return out;
}


void Diagonal::Eigenvave() //eigenvave function definition
{
    int i;
    cout<<"Eigen values are:"<<endl;
    cout<<"[";
    for(i=0;i<rows;i++)
    {
        cout<<mat[i][i]<<",";
    }
    cout<<"]";
    ofstream outfile;
        outfile.open("OOPS.txt",ios::app); //opening file
        if(!outfile) //file condition
        {
            cout<<endl;
            cout<<"Error";
        }
        else
        {
            cout<<endl;
            cout<<"File opened";
            outfile<<"Eigen values of a diagonal matrix found";
        }
        outfile.close();
}


void Diagonal::Determinant() //determinant function call definition
{
    int i,sum=1;
    for(i=0;i<rows;i++)
    {
        sum *=mat[i][i];
    }
    cout<<"Determinant is:"<<sum<<endl;
    ofstream outfile;
        outfile.open("OOPS.txt",ios::app); //file open
        if(!outfile) //file condition
        {
            cout<<endl;
            cout<<"Error";
        }
        else
        {
            cout<<endl;
            cout<<"File opened";
            outfile<<"Determinant of Diagonal matrix is calculated";
        }
        outfile.close();
}


istream &operator>>(istream &in, Matrix &M) //overloaded insertion operator function call
{
    int i,j;
    cout<<"Enter the matrix:"<<endl;
    for(i=0;i<M.rows;i++)
    {
        for(j=0;j<M.columns;j++)
        {
            in>>M.mat[i][j];
        }
    }
}


ostream &operator<<(ostream &out,Matrix &M) //over loaded function for Extraction operator
{
    int i,j;
    cout<<endl;
    for( i=0;i<M.rows;i++)
    {
        for(j=0;j<M.columns;j++)
        {
            cout<<M.mat[i][j]<<" ";
        }
        cout<<endl;
    }
}


void Basic_operations::Addition(int r,int c) //definition of addition operation of basic operation matrix
{
    cout<<"First Matrix"<<endl;
    Matrix A(r,c);
    cin>>A;
    cout<<A;
    cout<<"Second Matrix"<<endl;
    Matrix B(r,c);
    cin>>B;
    cout<<B;
    Matrix C(r,c);
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            C.mat[i][j] = A.mat[i][j] + B.mat[i][j]; //performing operation
        }
    }
    cout<<"Addition of two Matrices is:"<<endl;
    cout<<C;
    ofstream outfile;
        outfile.open("OOPS.txt",ios::app);//opening a file
        if(!outfile)//checking file condition
        {
            cout<<endl;
            cout<<"Error";
        }
        else
        {
            cout<<endl;
            cout<<"File opened";
            outfile<<"Addition between the two given matrices is done"; //entering into file
        }
        outfile.close(); //closing file
}


void Basic_operations::Subtraction(int r,int c) //subtraction member function defination
{
    cout<<"First Matrix";
    Matrix A(r,c);
    cin>>A;
    cout<<A;
    cout<<"Second Matrix";
    Matrix B(r,c);
    cin>>B;
    cout<<B;
    Matrix C(r,c);
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            C.mat[i][j] = A.mat[i][j] - B.mat[i][j]; //performing operation
        }
    }
    cout<<"Subtraction of two Matrices is:"<<endl;
    cout<<C;
    ofstream outfile;
        outfile.open("OOPS.txt",ios::app); //file opened
        if(!outfile) //checking file condition
        {
            cout<<endl;
            cout<<"Error";
        }
        else
        {
            cout<<endl;
            cout<<"File opened";
            outfile<<"subtraction between the two given matrices is done"; //entering into file
        }
        outfile.close(); //closing file
}


void Basic_operations::ScalarMultiplication(int r,int c,int k) //defination of member function scalar multiplication under the class basic operations
{
    Matrix A(r,c);
    cin>>A;
    cout<<A;
    Matrix C(r,c);
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            C.mat[i][j] = k*(A.mat[i][j]); //performing operation
        }
    }
    cout<<"scalar multiplication of matrix with scalar"<<k<<" is:"<<endl;
    cout<<C;
    ofstream outfile;
        outfile.open("OOPS.txt",ios::app);//opening a file
        if(!outfile)//checking file condition
        {
            cout<<endl;
            cout<<"Error";
        }
        else
        {
            cout<<endl;
            cout<<"File opened";
            outfile<<"scalar multiplication of a matrix with given scalar  is done"; //entering into the file
        }
        outfile.close();  //closing the file
}
