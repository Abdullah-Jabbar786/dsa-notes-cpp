#include <iostream>
using namespace std;

// void dynamic_arr()
// {
//     // Dynamic Array

//     // Increasing array size 
//     int *p, i, *q;
//     p = new int[5];
//     p[0] = 3;
//     p[1] = 5;
//     p[2] = 7;
//     p[3] = 9;
//     p[4] = 11;

//     q = new int[10];

//     for(i=0; i<5; i++)
//     {
//         q[i] = p[i];
//     }

//     delete []p; 

//     p=q;
//     q=NULL;

//     for(i=0; i<5; i++)
//     {
//         cout<<p[i]<<" ";
//     }
// }

// void arr2d()
// {
//     int A[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    
//     int *B[3];
//     B[0] = new int[4];
//     B[1] = new int[4];
//     B[2] = new int[4];

//     int **C;
//     C = new int*[3]; // rows
//     C[0] = new int[4]; // columns
//     C[1] = new int[4]; // columns
//     C[2] = new int[4]; // columns

//     int i, j;

//     for(i=0; i<3; i++)
//     {
//         for(j=0; j<4; j++)
//         {
//             cout<<A[i][j]<<" ";
//         }
//         cout<<"\n";
//     }

//     // Same for loop can be used for both B and C but currently it will print garbage values.

// }

// Arrays in Compilers


// 1D
// Address of Array general formula
// A[i] = (Address of first Element) + i*(sizeof(data type used)) when i start from 1 then i-1 in formula.

// 2D

// 1. Row Major Mapping
// Address  A[i][j] = (Address of first Element) + (i*n + j)*(sizeof(data type used)), where n is number of columns and m is number of rows. In C/C++ , nut if a language is allowing indexes starting from 1 onwards then formula will be Address  A[i][j] = (Address of first Element) + ((i-1)*n + (j-1))*(sizeof(data type used)) same as above in 1D but this time both i and j we do -1. From Left to Right.
// O(n^2). By taking common the number of multiplications which will result as O(n), and the rule which is used here is Horner's Rule.

// 2. Column Major Mapping
// Address  A[i][j] = (Address of first Element) + (j*m+ i)*(sizeof(data type used)), where n is number of columns and m is number of rows. From Right to Left.



int main()
{
    // dynamic_arr();
    
    // arr2d();
    
    return 0;
}