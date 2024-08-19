#include <iostream>
using namespace std;
int main()
{
    int x = 10;
    int *p = &x;
    int **pp = &p;

    cout << "Value of x: " << x << endl;
    cout << "Value pointed to by p: " << *p << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of p: " << p << endl;
    cout << "Address of p: " << &p << endl;
    cout << "Value pointed to by pp: " << *pp << endl;
    cout << "Address of pp: " << &pp << endl;

    return 0;
}