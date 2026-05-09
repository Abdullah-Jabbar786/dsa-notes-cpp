#include <iostream>
using namespace std;

// Recursion - Time Complexity
// It depends on the number of function calls.


void fun(int n)
{
    if(n>0)
    {
        // Head Recursion
        // fun(n-1); output 1 2 3
        
        cout<<n<<endl;
        
        // Tail Recursion
        fun(n-1); // output 3 2 1
    }
}

int func(int n)
{
    if(n>0)
    {
        return func(n-1) + n;
    }
    return 0;
}

// Static Variables in Recursion.

int stat_func(int n)
{
    static int x = 0;
    if(n>0)
    {
        x++;
        return stat_func(n-1) + x;
    }
    return 0;
}

int main()
{
    int x = 3;
    fun(x);
    
    int a = 5;
    cout<<func(a)<<endl;

    // static variable function
    int r = 5;
    cout<<stat_func(5);
}

