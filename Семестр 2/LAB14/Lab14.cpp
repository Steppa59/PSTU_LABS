#include <iostream>
#include <string>
using namespace std;

struct info {
string FIO;
string NUMBER;
string PASS;
};

bool knut_morris_pratt(string str, string pod) {
int i, j, k;
bool res = 0;
int d = str.size();
int e = pod.size();
if (d == 0){
cout << "Неверно задана строка\n";
}
else {
if (e == 0){
cout << "Неверно задана подстрока\n";
}
else {
j = 0;
k = -1;
}
}
int* pf = new int[1000];
pf[0] = -1;
while (j < e - 1) {
while (k >= 0 && pod[j] != pod[k])
k = pf[k];
j++;
k++;
if (pod[j] == pod[k])
pf[j] = pf[k];
else
pf[j] = k;
}
i = 0;
j = 0;
while (j < e && i < d) {
while (j >= 0 && str[i] != pod[j])
j = pf[j];
i++;
j++;
}
delete[] pf;
if (j == e)
res = 1;
return res;
}


bool boyer_moor(string str, string pod) {
int d = str.size();
int e = pod.size();
if (d == 0)
cout << "Неверно задана строка\n";
else if (e == 0)
cout << "Неверно задана подстрока\n";
else
int  i, Pos;
int  bmt[256];
for (int i = 0; i < 256; i++)
bmt[i] = e;
for (int i = e - 1; i >= 0; i--)
if (bmt[(short)(pod[i])] == e)
bmt[(short)(pod[i])] = e - i - 1;
int pos = e - 1;
while (pos < d)
if (pod[e - 1] != str[pos])
pos += bmt[(short)(str[pos])];
else
for (int i = e - 2; i >= 0; i--) {
if (pod[i] != str[pos - e + i + 1]) {
pos += bmt[(short)(str[pos - e + i + 1])] - 1;
break;
}
else
if (i == 0) {
return true;
}
}
	return false;
}






void boyer(info* st, string key, int n) {
bool l;
bool p = 0;
for (int i = 0; i < n; i++) {
l = boyer_moor(st[i].PASS, key);
if (l != 0) {
cout << "Элемент найден под номером: " << i << endl;
cout << "ФИО: " << st[i].FIO << endl;
cout << "Номер телефона: " << st[i].NUMBER << endl;
cout << "Номер паспорта: " << st[i].PASS << endl;
p = 1;
}
}
if (p == 0) {
cout << "Элемент не найден" << endl;
}
}
void knut(info* st, string key, int n) {
bool l;
bool p = 0;
for (int i = 0; i < n; i++) {
l = knut_morris_pratt(st[i].PASS, key);
if (l != 0) {
cout << "Элемент найден под номером: " << i << endl;
cout << "ФИО: " << st[i].FIO << endl;
cout << "Номер телефона: " << st[i].NUMBER << endl;
cout << "Номер паспорта: " << st[i].PASS << endl;
p = 1;
}
}
if (p == 0) {
cout << "Элемент не найден" << endl;
}
}


int main() {

int n;
string key;
cout << "Кол-во элементов: ";
cin >> n;
cin.ignore();
cout << "Ключ для поиска (паспорт) : ";
getline(cin, key);
info* st = new info[n];
for (int i = 0; i < n; i++) {
cout << "ФИО: ";
getline(cin, st[i].FIO);
cout << "Номер телефона: ";
getline(cin, st[i].NUMBER);
cout << "Номер паспорта: ";
getline(cin, st[i].PASS);
}

bool a;
cout << "Введите 0, если хотите произвести поиск алгоритмом Бойера-Мура " << endl; 
cout << "Введите 1, если хотите произвести поиск алгоритмом Кнута-Морриса-Пратта " << endl;
cin >> a;

switch (a) {
case 0: boyer(st, key, n); break;
case 1: knut(st, key, n); break;
default: cout << "Ошибка! " << endl;
}

	return 0;
}
