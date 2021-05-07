#include <iostream>
#include "TRIAD.h"
#include "TIME.h"
using namespace std; 
int main() {
TRIAD a; 
cin >> a;
a++;
cout << endl << "First + 1; Second + 1; Third +1: ";
cout << a;

cout << endl << "TIME b(10, 04, 15)";
TIME b(10, 04, 15);
cout << b << endl;

cout << "Set 4 Hours, 9 Minutes, 20 Seconds";
b.set_first(4);
b.set_second(9);
b.set_third(20);
cout << b;

b++;
cout << endl << "Hours + 1; Minutes + 1; Seconds +1: ";
cout << b << endl;

int N=0;
cout << "Увеличить на N минут и секунд. Введите N: ";
cin >> N;
b + N;
cout << b;

}
