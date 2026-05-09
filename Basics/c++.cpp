#include <iostream>
using namespace std;


//Functions example (1)
// void swap(int *x, int *y)
// {
//     int temp;
//     temp = *x;
//     *x = *y;
//     *y = temp;
// }

//Functions example (2)
// void swap(int &x, int &y)
// {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }

// array as parameter
// void func(int B[], int size)
// {
//     B[0] = 25;
// }


// Templates
// template <class T>
// class Airthametic
// {
//     private:
//     T a;
//     T b;
    
//     public:
//     Airthametic(T a, T b);

//     T add();
//     T sub();

// };
// template <class T>
// Airthametic<T>::Airthametic(T a, T b)
// {
//     this->a = a;
//     this->b = b;
// }
// template <class T>
// T Airthametic<T>::add()
// {
//     T c;
//     c = a + b;
//     return c;
// }
// template <class T>
// T Airthametic<T>::sub()
// {
//     T c;
//     c = a - b;
//     return c;
// }



int main()
{
    int A[5];
    // int B[5] = {1,2,3,4,5}; //initialize
    // int i;

    // for(i=0;i<5;i++)
    // {
    //     cout<<B[i];
    // }


    // A[0] = 12;
    // A[1] = 15;
    // A[2] = 25;
    
    // cout<<sizeof(A)<<endl;
    // cout<<A[1]; 


    // POINTERS
    // int *p;
    // int a = 10;
    // p = &a;

    // cout<<p<<endl;
    // cout<<a<<endl;
    // cout<<*p+1<<endl; // derefrencing

    // p = new int[5]; // in C malloc in c++ new.
    // delete p;// free the memory.
     
    //Functions
    //Example of call by address (1)

    // int a, b;
    // a = 10;
    // b = 20;
    // swap(&a, &b);
    // cout<<a<<endl<<b;

    //Example of call by refrence (2)

    // int a, b;
    // a = 10;
    // b = 20;
    // swap(a, b);
    // cout<<a<<endl<<b;

    // array as parameter
    // int B[5] = {1,2,3,4,5};
    // func(B,5);


    // Templates
    // Airthametic<int> ar(10, 5);
    // cout<<ar.add()<<endl;
    // Airthametic<float> at(10.1, 5.1);
    // cout<<ar.sub();
    
}