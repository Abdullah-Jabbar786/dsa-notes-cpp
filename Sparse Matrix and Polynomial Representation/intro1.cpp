#include <iostream>
using namespace std;

// Sparse Matrix
// Example:
// [ 0   0   3   0   4 ]
// [ 0   0   5   7   0 ]
// [ 0   0   0   0   0 ]
// [ 0   2   6   0   0 ]

// 1. Cordinate List / 3-column representation.

// row | column | element
// Now in this first row is about information like total row numbers are stored in row and similarly total column numbers in column and also total number of non-zero elements are stored in element. Then from 2nd row onwards the non zero element will be stored. Below is the example for 1 element and also the info of above matrix.
// row | column | element
//  4       5        6    // info
//  1       3        3    // element 3 is stored on row 1 and column 3.


// 2. Compressed Sparse Matrix
// CSR(Compressed Sparse Row) uses three arrays:
// 1. Values array (val) → stores all non-zero elements row-wise.
// 2. Column indices array (col_ind) → stores the column index of each value.
// 3. Row pointer array (row_ptr) → tells where each row starts in val and col_ind.


// For adding two matrixes the dimensions must be same.

// Incomplete will study later...

int main()
{

    return 0;
}
