/* 
1. Tail Recursion 
2. Head Recursion
3. Tree Recursion
4. Indirect Recursion
5. Nested Recursion
*/

// In case of tail recursion sometimes loop is more effiecient in terms of space, in intro there is tail recursion example in the start.

// In head recursion, the function does everything at the time of returning. 

// Linear/Tree Recursion
// In Linear Recursion the function calls itself only one time, where as in Tree Recursion the function call itself more than one time.  

// Linear --> 

/*
fun()
{
    if(n>0)
    {
        fun(n-1)
    }
}
*/

// Tree --> 

/*
fun()
{
    if(n>0)
    {
        ------
        fun(n-1)
        ------
        fun(n-1) // shows more than once function calls itself...

    }
}
*/

#include <iostream>
#include <vector>
using namespace std;


// void fun(int n)
// {
//     if(n>0)
//     {
//         cout<<n;

//         fun(n-1);
//         fun(n-1); // shows more than once function calls itself...

//     }
// }

// Indirect Recursion

// void funB(int n);
// void funA(int n)
// {
//     if(n>0)
//     {
//         cout<<n<<endl;
//         funB(n-1);
//     }
// }
// void funB(int n)
// {
//     if(n>1)
//     {
//         cout<<n;
//         funA(n/2);
//     }
// }

// Nested Recursion

// int Func(int n)
// {
//     if(n>100)
//     {
//         return n - 100;
//     }
//     else
//     {
//         return Func(Func(n+11));
//     }
// }


// int sum(int n)
// {
//     if(n==0)
//     {
//         return 0;
//     }
//     return sum(n-1) + n;
// }


// Factorial in Recursion

// int factorial(int n)
// {
//     if(n==0)
//     {
//         return 1;
//     }
//     else{
//         return factorial(n-1)*n;
//     }
// }

// Factorial in Loop
// int Iterate_Fact(int n)
// {
//     int f = 1;
//     for(int i = 1; i<=n; i++)
//     {
//         f = f*i;
//     }
//     return f;
// }

// Exponent Functions m^n

// int power(int m, int n)
// {
//     if(n==0)
//     {
//         return 1;
//     }

//     return power(m,n-1)*m;
// }


// // This one will do reduced number of multiplication.

// int power1(int m, int n)
// {
//     if(n==0)
//     {
//         return 1;
//     }
//     if(n%2 == 0)
//     {
//         return power1(m*m, n/2);
//     }

//     return m * power1(m*m,(n-1)/2);
// }


// Taylor Series
// 1st approach.


// double e(int x, int n)
// {
//     static double p = 1, f = 1;
//     double r;
    
//     if(n==0)
//     {
//         return 1;
//     }
//     r = e(x, n-1);
//     p = p*x;
//     f = f*n;
//     return r + p/f;
// }

// 2nd approach.
// n(n+1)    --> O(n^2), also there is linear approach too --> O(n)

// practice sin and cos series...

// double e(int x, int n)
// {
//     static double s;
//     if(n==0)
//     {
//         return s;
//     }

//     s = 1 + x*s/n;
//     return e(x, n-1);
// }

// In Loop

// double e(int x, int n)
// {
//     double s=1;
//     double num=1; //numerator
//     double den=1; //denominator

//     for(int i=1; i<=n; i++)
//     {
//         num*=x;
//         den*=i;
//         s+= num/den;
//     }
//     return s;
// }


// Fibonacci Series

// Excessive Recursion

// int fib(int n)
// {
//     if(n<=1)
//     {
//         return n;
//     }
//     return fib(n-2) + fib(n-1);
// }

//Preventing Excessive Recursion : Memoization approach --> storing the result to prevent same calls.

// int Fib(int n)
// {
//     int F[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
//     if(n<=1)
//     {
//         F[n] = n;
//         return n;
//     }
//     else
//     {
//         if(F[n-2]== -1)
//         {
//             F[n-2] = Fib(n-2);
//         }
//         if(F[n-1]== -1)
//         {
//             F[n-1] = Fib(n-1);
//         }
//     }
//     return F[n-2] + F[n-1];
// }



// Combination Formula, nCr --> Nfact/rFact(n-r)Fact


// int C(int n, int r)
// {
//     int t1, t2, t3;
//     t1 = factorial(n);
//     t2 = factorial(r);
//     t3 = factorial(n-r);
//     return t1/(t2*t3);
// }

// Recursive approach

// int C(int n, int r)
// {
//     if(r==0 || n==r)
//     {
//         return 1;
//     }
//     else
//     {
//         return C(n-1, r-1) + C(n-1, r);  // to understand this pascals traingle is imp which tells about n-1, r-1 and n-1, r.
//     }
// }


int main()
{
    // fun(3);  
    
    // funA(20);
    
    // Func(99);
    
    
    // cout<<sum(5);
    
    // cout<<factorial(5);
    
    // cout<<Iterate_Fact(5);
    
    
    // cout<<power(3,4);
    
    // cout<<power1(3,4);
    
    
    // Taylor Series
    // 1st approach.
    
    // cout<<e(3,10);
    
    // 2nd approach.
    // cout<<e(2,10);
    
    //with Loop
    // cout<<e(2,10);

    // Fibonacci Series
    // cout<<fib(4);

    // cout<<Fib(6);

    // cout<<C(5,3);

    return 0;
}


// Leetcode-78
//Subsets.   (back-tracking problem)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(0, nums, temp, res);
        return res;
    }

    void backtrack(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res) {
        if(i == nums.size()) {
            res.push_back(temp);
            return;
        }

        // Exclude nums[i]
        backtrack(i+1, nums, temp, res);

        // Include nums[i]
        temp.push_back(nums[i]);
        backtrack(i+1, nums, temp, res);
        temp.pop_back();
    }
};