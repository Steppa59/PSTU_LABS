#include <iostream>
#include "Header.h"
using namespace std;
int main() {
btree t;
double n;
cout << "Введите количество: ";
cin >> n;
for (int i = 0; i < n; i++) {
int a;
cin >> a;
t.insert(a);
}
t.print();
t.max();
}