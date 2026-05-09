#include <iostream>
using namespace std;

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
    }
};

Array* Merge(Array *Arr1, Array *Arr2)
{
    int k = 0;
    Array *Arr3 = new Array;

    for (int i = 0; i < Arr1->length; i++)
        Arr3->A[k++] = Arr1->A[i];

    for (int j = 0; j < Arr2->length; j++)
        Arr3->A[k++] = Arr2->A[j];

    Arr3->length = k;
    Arr3->size = 10;

    for (int i = 0; i < Arr3->length - 1; i++)
    {
        for (int j = 0; j < Arr3->length - i - 1; j++)
        {
            if (Arr3->A[j] > Arr3->A[j + 1])
            {
                int temp = Arr3->A[j];
                Arr3->A[j] = Arr3->A[j + 1];
                Arr3->A[j + 1] = temp;
            }
        }
    }

    return Arr3;
}

Array* Union(Array *Arr1, Array *Arr2)
{
    Array *Arr3 = new Array;
    int k = 0;

    for (int i = 0; i < Arr1->length; i++)
        Arr3->A[k++] = Arr1->A[i];

    for (int j = 0; j < Arr2->length; j++)
    {
        bool found = false;
        for (int i = 0; i < Arr1->length; i++)
        {
            if (Arr2->A[j] == Arr1->A[i])
            {
                found = true;
                break;
            }
        }
        if (!found)
            Arr3->A[k++] = Arr2->A[j];
    }

    Arr3->length = k;
    Arr3->size = 10;

    for (int i = 0; i < Arr3->length - 1; i++)
    {
        for (int j = 0; j < Arr3->length - i - 1; j++)
        {
            if (Arr3->A[j] > Arr3->A[j + 1])
            {
                int temp = Arr3->A[j];
                Arr3->A[j] = Arr3->A[j + 1];
                Arr3->A[j + 1] = temp;
            }
        }
    }

    return Arr3;
}

Array* Intersection(Array *Arr1, Array *Arr2)
{
    Array *Arr3 = new Array;
    int k = 0;

    for (int i = 0; i < Arr1->length; i++)
    {
        for (int j = 0; j < Arr2->length; j++)
        {
            if (Arr1->A[i] == Arr2->A[j])
            {
                Arr3->A[k++] = Arr1->A[i];
                break;
            }
        }
    }

    Arr3->length = k;
    Arr3->size = 10;
    return Arr3;
}

Array* Difference(Array *Arr1, Array *Arr2)
{
    Array *Arr3 = new Array;
    int k = 0;

    for (int i = 0; i < Arr1->length; i++)
    {
        bool found = false;
        for (int j = 0; j < Arr2->length; j++)
        {
            if (Arr1->A[i] == Arr2->A[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
            Arr3->A[k++] = Arr1->A[i];
    }

    Arr3->length = k;
    Arr3->size = 10;
    return Arr3;
}

int main()
{
    Array *Arr1 = new Array;
    Array *Arr2 = new Array;
    Array *Arr3;

    int a1[] = {2,6,10,15,25};
    int a2[] = {3,6,7,15,20};

    for (int i = 0; i < 5; i++) Arr1->A[i] = a1[i];
    Arr1->length = 5;

    for (int i = 0; i < 5; i++) Arr2->A[i] = a2[i];
    Arr2->length = 5;

    Arr3 = Merge(Arr1,Arr2);
    Arr3->Display();

    return 0;
}
