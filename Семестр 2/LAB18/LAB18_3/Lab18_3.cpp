#include "money.h" 
#include <iostream> 
using namespace std;
int main() {
money a;
money b;
money c;
cin >> a;
cin >> b;
cout << "============================================" << endl;
cout << "Первая сумма денег: " << a <<" рублей" << endl;
cout << "Вторая сумма денег: " << b <<" рублей" << endl;
cout << "============================================" << endl;
c = a + b;
cout << "a= " << a << endl;
cout << "b= " << b << endl;
cout << "Сумма(1 и 2) = " << c << endl;
cout << "============================================" << endl;
cout << "a > b = " << (a > b) << endl;
cout << "a < b = " << (a < b) << endl;
}
