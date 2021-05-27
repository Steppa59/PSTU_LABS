#include "Plenty.h"
#include "Money.h"
#include <iostream> 
using namespace std;
int main() {
Plenty<int>a(11, 20);
cin >> a;
cout << "Initialization a:" << endl;
cout << a << endl;
Plenty <int>b(11, 25);
b = a;
cout << "Plenty b == а" << endl;
cout << b << endl;
cout << "Size Plenty b: " << b() << endl;
Plenty <int>c(11, 0);
c = a + b;
cout << "Summa a+b:" << c << endl;
cout << "a-2 element:" << a[2] << endl;
Money c;
cin >> c;
Plenty<Money>A(5, c);
cin >> A;
cout << "Init Plenty a:" << endl;
cout << A << endl;
Plenty<Money>B(12, c);
cout << "Plenty b == а"<< endl;
B = A;
cout << B << endl;
cout << "a-3 element: " << A[3] << endl;
Plenty<Money>C(12, c);
C = B + A;
cout << "Summa b+a:" << C << endl;
cout << "Size Plenty b:"<< B() << endl;
}