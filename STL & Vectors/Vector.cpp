#include <iostream>
#include <vector>
using namespace std;


// Can also make this display function a template function.

void display(vector<int> &v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
        // cout<<v.at(i)<<" "; gives position. 
    }
    cout<<endl;
}

// For vector methods you can refer to c++.com or geeks for geeks.

int main()
{

    vector<int> vec1;
    int size,element;
    cout<<"Enter the size of your vector? ";
    cin>>size;

    vector<int> vec2(5, 10); //creates a vector of 5 elements of integer 10
    display(vec2);

    for(int i=0; i<size; i++)
    {
        cout<<"Enter an Element: ";
        cin>>element;
        vec1.push_back(element);
    }

    vec1.pop_back(); // removes last element. Similarly to remove from front there is .pop_front too.

    display(vec1);
    vector<int> :: iterator iter = vec1.begin();
    vec1.insert(iter, 566); // iterator is like a pointer. By default inserts the element 566 before first element 

    // Using  vec1.begin() because Because each insert changes the vector and may invalidate the previous iterator.

    vec1.insert(vec1.begin()+1, 566); //By default inserts the element 566 after first element 
    vec1.insert(vec1.begin()+2, 566); //By default inserts the element 566 after second element 
    vec1.insert(vec1.begin()+3, 5,700); // By default inserts the element 700 after second element and the number 5 after vec1.begin() represents the number of copies.
    display(vec1);
    return 0;
}