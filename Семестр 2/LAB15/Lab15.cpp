#include <iostream>
#include<string>
using namespace std;

struct Cities {
string name;
int distance;
};

void METOD_Shella(Cities* arr, int n) {
int b = n / 2;
while (b > 0) {
for (int i = 0; i < n - b; i++) {
int j = i;
while (j >= 0) {
if (arr[j].distance > arr[j + b].distance) {
int d = arr[j].distance;
arr[j].distance = arr[j + b].distance;
arr[j + b].distance = d;
string f = arr[j].name;
arr[j].name = arr[j + b].name;
arr[j + b].name = f;
j = j - b;
}
else
j = -1;
}
}
b = b / 2;
}
}

void METOD_Hoara(Cities* arr, int left, int right) {
int d;
string f;
int i = left;
int j = right;
while (i <= j) {
while (arr[i].distance < arr[(left + right) / 2].distance && i < right)
i++;
while (arr[j].distance > arr[(left + right) / 2].distance && j > left)
j--;
if (i <= j) {
d = arr[i].distance;
arr[i].distance = arr[j].distance;
arr[j].distance = d;
f = arr[i].name;
arr[i].name = arr[j].name;
arr[j].name = f;
i++;
j--;
}
if (i < right) {
METOD_Hoara(arr, i, right);
}
if (j > left) {
METOD_Hoara(arr, left, j);
}
}
}

int main() {
setlocale(LC_ALL, "Rus");
int n;
cout << "Введите количество городов: ";
cin >> n;
cout << "Заполняйте массив: " << endl;
cin.ignore();
Cities* string = new Cities[n];
for (int i = 0; i < n; i++) {
cout << "Название города: ";

getline(cin, string[i].name);
cout << "Расстояние до Москвы: ";
cin >> string[i].distance;
cout << endl;
cin.ignore();
}
int a;
cout << "Введите 0, если хотите произвести сортировка методом Шелла." << endl;
cout << "Введите 1, если хотите произвести сортировку методом Хоара." << endl << "Значение: ";
cin >> a;

switch (a) {
case 0: METOD_Shella(string, n); break;
case 1: METOD_Hoara(string, 0, n - 1);; break;
default: cout << "Неизвестная операция. Сортировка не выполнена." << endl;
}
cout << "=============================================================="<< endl;
cout << "После сортировки города расположены следующим образом: " << endl;
cout << "==============================================================" << endl << endl;
for (int i = 0; i < n; i++) {
cout << "Название города: " << string[i].name << endl;
cout << "Расстояние до Москвы: " << string[i].distance << endl << endl;
}
cout << "=============================================================="<< endl;

	return 0;
	
}
