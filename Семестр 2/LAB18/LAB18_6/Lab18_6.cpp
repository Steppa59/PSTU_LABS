#include <iostream>
#include "List.h"
using namespace std;

int main() {
List a(5);

cout << "Создание списка a: " << endl;
cout << a <<endl;
cin >> a;

cout << "Список a: " << endl;
cout << a <<endl; 

a[2] = 100;
cout << "Список после изменение элемента[2]: " << endl;
cout << a << endl;

cout << "Значение первого элемента в списке: " << endl;
cout << *(a.first()) << endl;

Iterator i = a.first();
int n;
cout << "Введите индекс: ";
cin >> n;
i+n;
cout << "Значение элемента под индексом: " << endl;
cout << *i << endl;
cout << "Cписок а после всех операций" << endl;
for (i = a.first(); i != a.last(); ++i)
cout << *i << " ";
cout << endl;
List b(10);
cout << "Создание списка b"<< endl;
cout << b <<endl;

b = a;
cout << "Присваиваем списку b значения списка a" << endl;
cout << b <<endl;
cout << "Определение размера списка: " << b() << endl;
List c(10);
c = a + b;
cout << "Сложение элементов списков a[i] + b[i]:" << endl;
cout << c <<endl;
return 0;
}
