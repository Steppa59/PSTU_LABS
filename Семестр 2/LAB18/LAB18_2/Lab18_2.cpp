#include <iostream>
#include"car.h"
#include <string>
using namespace std;

car make_car() {
string a;
string c;
int s;
cout << "Введите марку машины: " << endl;
cin.ignore();
getline(cin, a);
cout << "Введите модель: " << endl;
cin.ignore();
getline(cin, c);
cout << "Введите цену: " << endl;
cin >> s;
car t(a, c, s);
	return t;
}

void print_car(car t) {
	t.show();
}



int main() {
setlocale(LC_ALL, "Rus");
car t1;
t1.show();
car t2("Lexus", "Rx200", 1500);
t2.show();
car t3 = t2;
t3.set_brand("Ford");
t3.set_model("Focus");
t3.set_price(4000);
print_car(t3);
t1 = make_car();
t1.show();
return 0;
}
