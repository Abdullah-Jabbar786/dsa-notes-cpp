#include <iostream>
using namespace std;

// Refer to note.png

class Diagonal 
{
    private:
    int *A, n;
    
    public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n](); // The () ensures all elements are 0.


    }
    
    void Create()
    {
        int x;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin>>x;
                if(i==j)
                {
                    A[i-1] = x; // change it if Lower triangular or Upper Triangular
                }
            }
        }
    }

    void Display()
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                {
                    cout<<A[i-1]<<" ";
                    // change it if Lower triangular or Upper Triangular and also change the if condition accordingly.
                }
                else
                {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }
    ~Diagonal()
    {
        delete []A;
    }
};

// Only diagonal elements are stored in a 1D array, and All off-diagonal elements are 0

int main()
{
   int size;
    cout << "Enter dimension of square matrix: ";
    cin>>size;

    Diagonal d(size);
    cout << "Enter elements row-wise:\n";
    d.Create();

    cout << "Diagonal Matrix:\n";
    d.Display();

    return 0;
}