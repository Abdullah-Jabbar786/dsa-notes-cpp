#include <iostream>
using namespace std;


// This file may contain some errors but focus on concepts.
class Array
{
public:
    int A[10];
    int size;
    int length;

    Array()
    {
        size = 10;
        length = 0;
    }

    void Display()
    {
        cout << "Elements: ";
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout<<endl;
    }

    // Findig Missing Elements in sorted array of first n natural number.
    void Missing()
    {
        int n = 12; // for exp : Array will have 1,2,3,4,5,6,8,9,10,11,12 so 7 is missing here. 
        int sum = 0;
        for (int i=0; i<n; i++)
        {
            sum = sum + A[i];
        }
        int S = n*(n+1)/2;
        
        cout<<"Missing number is: "<<S-sum<<endl;
    }

    // Findig Missing Elements in sorted array and the seuquence can start from anywhere andd anywhere for exp : 6,7,8,9,10,11,13,14,15,16,17. In this case 12 is missing.
    void random_missing()
    {
        int n = 11; //for exp : 6,7,8,9,10,11,13,14,15,16,17. In this case 12 is missing. 
        int l = 6; // In this case.
        int h = 17; // In this case.
        int diff = l - 0; // Difference of first Element at index zero l-i since i=0 initially so diff = l - 0;

        for (int i=0; i<n; i++)
        {
            if(A[i] - i != diff)
            {
                cout<<"Missing Element is: "<<i+diff<<endl;
                break;
            }
        }
    }

    // Findig Multiple Missing Elements in sorted array and the seuquence can start from anywhere andd anywhere for exp : 6,7,8,9,11,12,15,16,17,18,19. In this case 10,13,14 is missing.
    void Multiple_miss()
    {
        int n = 11; //for exp : 6,7,8,9,10,11,12,15,16,17,18,19. In this case 10,13,14 is missing.
        int l = 6; // In this case.
        int h = 19; // In this case.
        int diff = l - 0; // Difference of first Element at index zero l-i since i=0 initially so diff = l - 0;

        for (int i=0; i<n; i++)
        {
            if(A[i] - i != diff)
            {
                while (diff<A[i]-i)
                {
                    cout<<"Missing Elements: "<<diff+i;
                    diff++;
                }
            }
        }
    }

    // Finding Missing Element in an unsorted array;

    //Hash Tables takes constant time. Whenever using Hash table so you need an array space equal to the largest Element.'

    // Make one more array of size the largest element from first array for exp H[12] = {0} and then increment it's values on index which are equals to elements of first array
    
    void unsorted_missing(int n, int l, int h) // n is number of element, l is smallest element of first array, h is highest element of first array. First Array is main array in this code it is A[] but I am not running these functions cause these needs array values modifications.
    {
        int H[h] = {0};
        for (int i=0; i<n; i++)
        {
            H[A[i]]++; // incrementing as explained above.
        }

        for(int i=l; i<h; i++)
        {
            if(H[i] == 0)
            {
                cout<<"Missing Elements: "<<i<<endl;
            }
        }
        
    }

    // Finding Duplicate Elements. exp arr values 3,6,8,8,10,12,15,15,15,20 
    //you can use hash table concept to count duplicates then print i which tells the element and H[i] will tell the number of times it is repeated. Refer above for Hash Table explaination.
    void duplicate(int n)
    {
        int lastduplicate = 0;
        int count = 0;
        for (int i=0; i<n; i++)
        {
            if(A[i] == A[i+1] && A[i] != lastduplicate)
            {
                cout<<A[i];
                lastduplicate = A[i];
            }
        }
        
    }

    // Finding Duplicate Elements in Unsorted Array.
    
    void unsorted_Duplicate(int n)
    {
        int max = A[0];
        for (int i = 1; i < n; i++)
        {
            if (A[i] > max)
            {
                max = A[i];
            }
        }

        int *H = new int[max + 1](); // Initialize frequency array with 0s

        for (int i = 0; i < n; i++)
        {
            H[A[i]]++;
        }

        for (int i = 0; i <= max; i++)
        {
            if (H[i] > 1)
            {
                cout << i << " is repeated " << H[i] << " times" << endl;
            }
        }

        delete[] H;
    }


    // Finding a pair with sum k in an Unsorted Array, a+b = k. 
    void findsum(int n, int k) // O(n^2)
    {
        for(int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if(A[i] + A[j] == k)
                {
                    cout<<A[i]<<"+"<<A[j]<<" = "<<k<<endl;
                }
            }
            
        }
        
    }
    // Finding a pair with sum k in a Sorted Array, a+b = k. 
    void Sortfindsum(int n, int k) // O(n)
    {
        int i=0, j = n-1;
            while(i<j)
            {
                if(A[i] + A[j] == k)
                {
                    cout<<A[i]<<"+"<<A[j]<<" = "<<k<<endl;
                    i++;
                    j--;
                }
                else if(A[i] + A[j] < k)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
        
    }
    
    
    // Faster Method - Hash Table (Hashing).
    
    // Finding a pair with sum k in an Unsorted Array, a+b = k. 
    
    // h is highest element of main array, l is lowest element of main array and similarly n is number of elements
    
    void Hashfindsum(int n, int k, int h, int l) //O(n)
    {
        int H[h] = {0};
        for(int i=0; i<n; i++)
        {
            if(H[k-A[i]] != 0)
            {
                cout<<A[i]<<"+"<<k-A[i]<<" = "<<k<<endl;
            }
            H[A[i]]++;   
        }
        
    }

};





int main()
{
   Array arr;

    return 0;
}
