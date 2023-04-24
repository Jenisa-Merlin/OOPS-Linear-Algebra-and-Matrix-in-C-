///IMPLEMENTATION OF LINEAR ALGEBRA AND MATRICES IN C++
//BY 21PW02-AKEPATI JYOSHNA REDDY AND 21PW08-JENISA MERLIN
///header files

#include<iostream>
#include<stdlib.h>
#include<fstream>

#include "Diagonal.h"
#include "Matrix.h"
#include "SquareMatrix.h"
#include "SparseMatrix.h"
#include "Matrix3x3.h"
#include "Basic_operations.h"

using namespace std;
//main function begins
int main()
{
    int rows,columns,i,j,choice,choice1,k;
    do
    {
       cout<<"\nKIND OF MATRICES AVAILABLE"<<endl;
       cout<<"\n 1.Normal Matrix \n 2.Sparse Matrix \n 3.Square Matrix of order 3 \n 4.Diagonal Matrix\n";
       cout<<"Choose the matrix you want to perform operations on :";
       cin>>choice;
       system("CLS");
       if(choice ==1 )
       {
                  cout<<"Enter the number of rows:";
                  cin>>rows;
                  cout<<"Enter the number of columns:";
                  cin>>columns;
                  Matrix M1(rows,columns); //creates an object of type matrix
                  cin>>M1;                  //takes input from overloaded function
                  cout<<M1;                  //prints output from overloaded function
                  cout<<"Rank of the matrix is:"<<M1.rankofmatrix(rows,columns)<<endl; //calls the member function rank of the matrix
       }
       else if(choice == 2)
       {
                  cout<<"Enter the number of rows:";
                  cin>>rows;
                  cout<<"Enter the number of columns:";
                  cin>>columns;
                  SparseMatrix M2(rows,columns); //creates an object of type Matrix
                  cin>>M2;
                  cout<<M2;
                  M2.check_sparse(); //call the function to check whether it is sparse or not
                  M2.tripletform(); //making the sparse matrix to triplet form
       }
       else if(choice ==3)
       {
            Matrix3x3 M3;
                  cin>>M3;
                  cout<<M3;
                  M3.Determinant(); //returning the determinant of the matrix
                  M3.Eigenvave(); //call the function to find the eigen values
       }
       else if(choice == 4) //This case under exception handling normal diagonal matrix eigen values cannot be found by previous method this method gives us answers
       {
                  cout<<"Enter the number of rows:";
                  cin>>rows;
                  Diagonal M4(rows);
                  cin>>M4;
                  cout<<M4;
                  M4.Determinant();  //calling the member function determinant of the matrix
                  M4.Eigenvave();    //calling function to calculate eigen values eigen vectors
       }
        cout<<endl;
        cout<<"Do you want to perform any Basic operation on Matrix:(5 for yes and 6 for no)";
        cin>>choice;
        system("CLS");
        if(choice == 5)
        {
            cout<<"What operation do you want to perform(1.Addition 2.Subtraction 3.ScalarMultiplication)";
            cin>>choice1;
            if(choice1 == 1)
            {
                cout<<"Enter the number of rows:";
                cin>>rows;
                cout<<"Enter the number of columns:";
                cin>>columns;
                Basic_operations B1(rows,columns); //creating an object of class basic operations
                B1.Addition(rows,columns);   //performing addition
            }
            else if(choice1 ==2)
            {
                cout<<"Enter the number of rows:";
                cin>>rows;
                cout<<"Enter the number of columns:";
                cin>>columns;
                Basic_operations B2(rows,columns);
                B2.Subtraction(rows,columns);  //calling a memberfunction to perform subtraction
            }
            else if(choice1 == 3)
            {
                cout<<"Enter the number of rows:";
                cin>>rows;
                cout<<"Enter the number of columns:";
                cin>>columns;
                Basic_operations B3(rows,columns);
                cout<<"Enter the scalar value you want to multiply:";
                cin>>k;
                B3.ScalarMultiplication(rows,columns,k);  //calling a function to perform scalar multiplication
            }
        }
    }while(choice <7);
    return 0;
}

