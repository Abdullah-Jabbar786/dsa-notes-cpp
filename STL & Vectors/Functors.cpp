#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

// Function Objects: Function wrapped in a class so that it is available like an object.

int main()
{
    int arr[] = {11,23,37,4,15,6};
    sort(arr, arr+5); // will sort only first 5 elements.
    for (int i=0; i<6; i++)
    {
        cout<<arr[i]<<endl;
    }

    sort(arr, arr+5, greater<int>()); //descending order sorting
    for (int i=0; i<6; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}