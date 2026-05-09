#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        A = new int[10];
        length = 0;
    }

    Array(int sz)
    {
        size = sz;
        A = new int[size];
        length = 0;
    }

    ~Array()
    {
        delete[] A;
    }

    // Display
    void Display()
    {
        int i;
        cout << "Elements: ";
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
    }

    // Insert
    void Insert(int index, int x)
    {
        if (index >= 0 && index <= length)
        {
            int i;
            for (int i = length; i > index; i--)
            {
                A[i] = A[i - 1];
            }
            A[index] = x;
            length++;
        }
    }

    // Append
    void Append(int x)
    {
        if (length < size)
        {
            A[length++] = x;
        }
    }

    // Delete
    int Delete(int index)
    {
        int x = 0;
        if (index >= 0 && index < length)
        {
            x = A[index];
            for (int i = index; i < length - 1; i++)
                A[i] = A[i + 1];
            length--;
        }
        return x;
    }

    // Search -> Linear / Binary

    // Linear Search

    // int LinearSearch(struct Array arr, int key)
    // {
    //     int i;
    //     for (i=0; i<arr.length; i++)
    //     {
    //         if(key==arr.A[i])
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    void swap(int *x, int *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    // // Improving Linear Search by Transposition
    // int LinearSearch(struct Array *arr, int key)
    // {
    //     int i;
    //     for (i=0; i<arr->length; i++)
    //     {
    //         if(key==arr->A[i])
    //         {
    //             swap(&arr->A[i], &arr->A[i-1]);
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    // Improving Linear Search by Move to Head
    int LinearSearch(int key)
    {
        int i;
        for (i = 0; i < length; i++)
        {
            if (key == A[i])
            {
                swap(&A[i], &A[0]);
                return i;
            }
        }
        return -1;
    }

    // Binary Search in Loop
    //  min O(1), max O(Logn), avg O(Logn)
    //  successive division results in Log, successive multiplication results in power.

    int BinarySearch(Array arr, int key)
    {
        int l = 0, m, h;
        h = arr.length - 1;
        while (l <= h)
        {
            m = (l + h) / 2;
            if (key == arr.A[m])
            {
                return m;
            }
            else if (key < arr.A[m])
            {
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return -1;
    }

    // Binary Search in Recursion
    int Rec_BinarySearch(int A[], int l, int h, int key)
    {
        int m;
        if (l <= h)
        {
            m = (l + h) / 2;
            if (key == A[m])
            {
                return m;
            }
            else if (key < A[m])
            {
                return Rec_BinarySearch(A, l, m - 1, key);
            }
            else
            {
                return Rec_BinarySearch(A, m + 1, h, key);
            }
        }
        return -1;
    }

    // Basic get, set, max, min, total, sum functions. Just writingg below the sum function with recursive approach.

    int Sum(int n)
    { // Can pass the whole structure obj or just pass int A[]
        if (n < 0)
            return 0;
        else
            return Sum(n - 1) + A[n];
    }

    // Reversing Array

    // 1. Create a new array, copy elements from the original array in reverse order into it, then copy the reversed array back into the original array.

    void Reverse_1()
    {
        int *B;
        int i, j;
        B = new int[length];
        for (i = length - 1, j = 0; i >= 0; i--, j++)
        {
            B[j] = A[i];
        }
        for (i = 0; i < length; i++)
        {
            A[i] = B[i];
        }
    }

    // 2. Swapping the elements

    void Reverse_2()
    {
        int i, j;
        for (i = 0, j = length - 1; i < j; i++, j--)
        {
            swap(&A[i], &A[j]);
        }
    }

    // Inserting a new element in a sorted array such that after insertion the array is sorted.

    void sort_insert(int x)
    {
        int i = length - 1;
        if (length == size)
        {
            return;
        }
        while (i >= 0 && A[i] > x)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
    }

    // Checking if array is sorted.
    bool is_sorted()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    // -ve on left side and +ve on right side
    void Rearrange()
    {
        int i = 0, j;
        j = length - 1;

        while (i < j)
        {
            while (A[i] < 0)
                i++;
            while (A[i] >= 0)
                j--;

            if (i < j)
            {
                swap(&A[i], &A[j]);
            }
        }
    }
};

int main()
{
    Array Arr(10);

    Arr.Append(1);
    Arr.Append(2);
    Arr.Append(3);
    Arr.Append(4);
    Arr.Append(5);

    cout << "Sum of first 5 elements: " << Arr.Sum(4) << endl;

    Arr.Append(10);
    Arr.Insert(3, 7);
    cout << Arr.Delete(0) << " Deleted." << endl;

    cout << "Index = " << Arr.LinearSearch(4) << endl;

    // Commented because sorted array is required so first sort then Binary search.
    // cout << "Binary search result = " << Arr.BinarySearch(Arr, 4) << endl;

    Arr.Reverse_2();

    cout << "Is sorted? " << (Arr.is_sorted() ? "Yes" : "No") << endl;

    Arr.Display();

    return 0;
}
