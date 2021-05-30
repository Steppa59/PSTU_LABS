#include <iostream>
#include "List.h"
#include "Error.h"
using namespace std;
int main()
{
try {
List a(5);
cout << "Создание списка а из 5 элементов" << endl;
cin >> a;
cout << a << "\n";
a[2] = 100;
cout << "Обращение по индексу + присваивание a[2]=100"<< endl;
cout << a << "\n";

cout << "Пример попытки обращения к элементу с индексом[6] больше текущего размера списка: " << endl;
cout << "a[6] = 100" << endl; 
a[6] = 100;

cout << "Разыменовывание указателя на 1 элемент" << endl;
cout << *(a.first()) << endl;
Iterator i = a.first();
int n;
cout << "Номер элемента списка: ";
cin >> n;
i + n;
cout << "Переход к n-ому элементу списка а" << endl;
cout << *i << endl;

cout << "Пример попытки перехода к -1-ому элементу списка а: "<< endl;
cout << "Номер элемента списка не может быть отрицательным!";
n = -1;

cout << "Вывод значений списка а с помощью итератора и разыменовывания указателя" << endl;
for (i = a.first(); i != a.last(); ++i)
cout << *i << " ";
cout << endl;
		
List b(10);
cout << "Присваивание списку b списка а" << endl;
cout << b << "\n";
cout << "Определение размера списка b: " << b() << endl;
List c(10);
c = a + b;
cout << "Сумма a и b" << endl;
cout << c << "\n";

}
catch (Error &e) {
e.what();
}
	return 0;
}

