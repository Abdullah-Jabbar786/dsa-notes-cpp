#include <iostream>
using namespace std;

void tower(int n, char s, char h, char d) 
{
    if (n == 0) return;
    tower(n - 1, s, d, h);
    cout<<s<<" --> "<<d<<endl;
    tower(n - 1, h, s, d);
}

// O(2^n)

int main() 
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    tower(n, 'A', 'B', 'C');
    return 0;
}
