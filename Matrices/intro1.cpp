#include <iostream>
using namespace std;


class DiagonalMatrix
{
    private:
    int n;
    int *A;

    public: 
    DiagonalMatrix()
    {
        n = 2;
        A = new int[2];
    }
    DiagonalMatrix(int N)
    {
        n = N;
        A = new int[n];
    }

    // Diagonal Matrix

    void set(int i, int j, int x)
    {
        if(i==j)
        {
            A[i-1] = x;
        }
    }
    
    int get(int i, int j)
    {
        if(i==j)
        {
            return A[i-1];
        }
        else
        {
            return 0;
        }
    }

    void display()
    {
        int i, j;
        for(i=1; i<n; i++)
        {
            for(j=1; j<n; j++)
            {
                if(i==j)
                {
                    cout<<A[i]<<" ";
                }
                else
                {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }

    ~DiagonalMatrix()
    {
        delete []A;
    }

};

// Lower Traingular Matrix
// 1 0 0 0 0
// 2 3 0 0 0
// 4 5 6 0 0
// 7 8 9 1 0
// 2 3 4 5 6

// To excess:

// Row Major Mapping
// Non-Zero = n(n+1)/2  
// Zero = n(n-1)/2
// Index(A[i][j]) = [i(i-1)/2] + j - 1

// Column Major Mapping
// Index(A[i][j]) = [n(j-1) - (j-2)(j-1)/2] + (i-j)


// In Upper Triangular Matrix i will become j and j will become i.

// Zero - if i>j
// Non-Zero - if i<=j
// Row Major Mapping
// Index(A[i][j]) = [(i-1)n - (i-2)(i-1)/2)] + (j-i)
// Column Major Mapping
// Index(A[i][j]) = [j(j-1)/2)] + (i-1)


// Symmetric Matrix
// if M[i,j] = M[j,i]
// Both Lower and Upper Triangular Matrix can be used.

// Tridiagonal Matrix
// Main Diagonal i-j = 0
// Lower Diagonal i-j = 1
// Upper Diagonal i-j = -1

// M[i,j] = Non-Zero if i-j<1
// M[i,j] = Zero if i-j>1

// A 1d array is used to store all non zero values for all upper concepts and after that row major or column major mapping is used to locate a certain element.
// All non zero values Tridiagonal Matrix are store in a array first all Lower Diagonal and then followed by main and upper diagonal.
// Index(A[i][j]) 
// case 1 if i-j = 1, index = i-1  // Lower Diagonal
// case 2 if i-j = 0, index = n-1+i-1 // Main Diagonal
// case 3 if i-j = -1, index = 2n-1+i-1 // Upper Diagonal

// Square Band Matrix
// When there are more than 1 diagonals below Main Diagonal and we have equal number of Diagonals on both side then it is a Square Band Matrix.

// Toeplitz Matrix
// When elements in a Diagonal are same
// M[i,j] = M[i-1,j-1]
// Element = n+n-1 -> size of 1d array too.
// Index(A[i][j])
// case 1  if i<=j, means Upper Triangular part, Index = j-i
// case 2  if i>j, means Lower Triangular, Index = n+i-j-1



int main()
{
    DiagonalMatrix m(4);
    
    m.set(1, 1, 5);
    m.set(2, 2, 8);
    m.set(3, 3, 3);
    m.set(4, 4, 6);

    cout << "Matrix is:" << endl;
    m.display();

    cout << "Element at (2,2): " << m.get(2, 2) << endl;
    cout << "Element at (2,3): " << m.get(2, 3) << endl;

    return 0;
}