#include<iostream>
#include"fraction.h"
using namespace std;

fraction make_fraction(double F, double S)
{
fraction t;
t.Init(F, S);
return t;
}

int main() {
double y; int z;
cout << "Введите first(оклад): ";
cin >> y;
cout << "Введите second(Количество отработанных дней): ";
cin >> z;
cout << endl;

fraction F = make_fraction(y,z);
F.Show();
cout << "summa(" << F.first << ";" << F.second << ") = " << F.summa() << endl;
	return 0;
}
