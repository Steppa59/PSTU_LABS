#include "Money.h"
#include <iostream> 
#include <fstream>
#include <string> 
#include "file_work.h"
using namespace std;
int main() {	
Money p, p1, p2;
int k, c;
char file_name[30]; 
do {	
cout << "\nВведите: 1 - Создать файл"; 
cout << "\nВведите: 2 - Распечатать файл";
cout << "\nВведите: 3 - Удалить запись из файла";
cout << "\nВведите: 4 - Добавить запись в файл";
cout << "\nВведите: 5 - Изменить запись в файле";
cout << "\nВведите: 0 - Выход из программы\n";
cin >> c;
switch (c) {
case 1: cout << "Введите имя файла: "; cin >> file_name; k = make_file(file_name);
if (k < 0)cout << "Невозможно создать файл"; break;

case 2: cout << "Введите имя файла: "; cin >> file_name; k = print_file(file_name);
if (k == 0)cout << "Файл пуст.\n"; 
if (k < 0)cout << "Невозможно прочитать файл\n"; break;

case 3: cout << "Введите имя файла: ";  cin >> file_name; int nom; cout << "Количество значений: ";
cin >> nom; k = del_file(file_name, nom);
if (k < 0)cout << "Невозможно прочитать файл"; break;

case 4: cout << "Введите имя файла: ";  cin >> file_name;  cout << "Количество значений: ";
cin >> nom; cout << "Новое значение: ";
cin>>p1;
k = add_file(file_name, nom, p1);
if (k < 0) cout << "Невозможно прочитать файл"; 
if (k == 0) k = add_end(file_name, p1); break;

case 5: cout << "Введите имя файла: ";  cin >> file_name; cout << "Количество значений: ";
cin >> nom; cout << "Новое значение: "; 
cin>>p2; k = change_file(file_name, nom, p2);
if (k < 0) cout << "\nНевозможно прочитать файл: ";
if (k == 0) cout << "\nНеверное значение"; 
break;
}
} 
	while (c != 0);
}