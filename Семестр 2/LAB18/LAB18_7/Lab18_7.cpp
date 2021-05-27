#include "Money.h"
#include "Pair.h"
#include <iostream> 
using namespace std;
int main() {
Money<int>a(25, 40);
cin >> a;
cout << "А = 25 руб. 40 коп. :" << endl;
cout << a << endl;
Money <int>b(18, 25);
b = a;
cout << " B == A" << endl;
cout << b << endl;
cout << "Money b: " << b() << endl;
Money <int>c(11, 0);
c = a + b;
cout << "Значение A+B:" << c << endl;
cout << "A-2 элемент:" << a[2] << endl;
Pair c;
cin >> c;
Money<Pair>A(51, c);
cin >> A;
cout << "Инициализация  A:" << endl;
cout << A << endl;
Money<Pair>B(12, c);
cout << "Money b присвоить значение а "<< endl;
B = A;
cout << B << endl;
cout << "A-3 элемент: " << A[3] << endl;
Money<Pair>C(12, c);
C = A + B;
cout << "Сумма A и B:" << C << endl;
cout << "Money :"<< B() << endl;

return 0;
}