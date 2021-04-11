#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int size = 100;

struct info {
string FIO;
string NUMBER;
string PASS;
};

info* astr = new info[size];

void make() {
string key;
ifstream str("F.txt");
for (int i = 0; i < size; i++) {
if (str.is_open()) {
if (getline(str, key)) {
astr[i].FIO = key;
}
if (getline(str, key)) {
astr[i].NUMBER = key;
}
if (getline(str, key)) {
astr[i].PASS = key;
}
}
}
str.close();
}

void LIN() {
string key;
bool n = true;
cout << "Введите ключ(паспорт): ";
getline(cin, key);
getline(cin, key);
for (int i = 0; i < size; i++) {
if (astr[i].PASS == key) {
cout << "Номер элемента: " << i + 1 << endl;
cout << "Данные о человеке: " << endl;
cout << "=====================================================" << endl;
cout << "Имя           :  " << astr[i].FIO << endl;
cout << "Номер телефона:  " << astr[i].NUMBER << endl;
cout << "Номер паспорта:  " << astr[i].PASS << endl;
cout << "=====================================================" << endl;
n = false;
}
}
if (n == true) {
cout << "Элемент по такому ключу не найден !" << endl;
}
}


void PodStr() {
string substr;
cout << "Введите подстроку(паспорт): ";
getline(cin, substr);
getline(cin, substr);
string str;
bool x = true, n = true;
for (int i = 0; i < size; i++) {
str = astr[i].PASS;
for (int j = 0; j < str.size(); j++) {
x = true;
for (int k = 0; k < substr.size(); k++) {
if (substr[k] != str[j + k]) {
x = false;
}
}
if (x == true) {
cout << "Номер элемента: " << i + 1 << endl;
cout << "Данные о человеке: " << endl;
cout << "=====================================================" << endl;
cout << "Имя           :  " << astr[i].FIO << endl;
cout << "Номер телефона:  " << astr[i].NUMBER << endl;
cout << "Номер паспорта:  " << astr[i].PASS << endl;
cout << "=====================================================" << endl;
n = false;
}
}
}
if (n == true) {
cout << "Элемент по заданному ключу не найден !" << endl;
}
}


void INTER() {
int* arr = new int[size];
int sum;
string str;
for (int i = 0; i < size; i++) {
str = astr[i].PASS;
sum = 0;
for (int j = 0; j < str.size(); j++) {
sum += str[j];
}
arr[i] = sum;
}
int min, temp;
	
for (int i = 0; i < size - 1; i++) {
min = i;
for (int j = i + 1; j < size; j++) {
if (arr[j] < arr[min]) {
min = j;
}
}
temp = arr[i];
arr[i] = arr[min];
arr[min] = temp;
}
string key;
int sumkey = 0;
cout << "Введите ключ(паспорт): ";
getline(cin, key);
getline(cin, key);
for (int i = 0; i < key.size(); i++) {
sumkey = sumkey + key[i];
}
int mid, left = 0, right = size - 1;
int answer;
bool z = true;
while (arr[left] <= sumkey && arr[right] >= sumkey && z) {
    
mid = left + ((sumkey - arr[left]) * (right - left)) / (arr[right] - arr[left]);

if (arr[mid] < sumkey) {
left = mid + 1;
}
else {
if (arr[mid] > sumkey) {
right = mid - 1;
}
else {
answer = mid;
z = false;
}
}
}
sum = 0;
int l = 0;
if (z == true) {
if (arr[left] == sumkey) {
answer = left;
}
else {
answer = -1;
}
}
if (answer > -1) {
for (int i = 0; i < size; i++) {
str = astr[i].PASS;
sum = 0;
for (int j = 0; j < str.size(); j++) {
sum += str[j];
}
if (sum == arr[answer]) {
cout << "Номер элемента: " << i + 1 << endl;
cout << "Данные о человеке: " << endl;
cout << "=====================================================" << endl;
cout << "Имя           :  " << astr[i].FIO << endl;
cout << "Номер телефона:  " << astr[i].NUMBER << endl;
cout << "Номер паспорта:  " << astr[i].PASS << endl;
cout << "=====================================================" << endl;
}
}
}
	
else {
cout << "Элемент по заданному ключу не найден" << endl;
}
}

void print() {
cout << "База данных: " << endl;
for (int i = 0; i < size; i++) {
cout << "=====================================================" << endl;
cout << i + 1 << " элемент: " << endl;
cout << "Имя           :  " << astr[i].FIO << endl;
cout << "Номер телефона:  " << astr[i].NUMBER << endl;
cout << "Номер паспорта:  " << astr[i].PASS << endl;
}
cout << "=====================================================" << endl;
}


void save() {
string key;
ofstream str;
str.open("F.txt");
for (int i = 0; i < size; i++) {
str << astr[i].FIO << endl;
str << astr[i].NUMBER << endl;
str << astr[i].PASS << endl;
}
str.close();
}

int main() {
setlocale(LC_ALL, "Rus");
bool x = true;
int i;
while (x) {
cout << "Нажмите 1: Взять информацию из файла F.txt" << endl;
cout << "Нажмите 2: Сохранить структуру в файл F.txt" << endl;
cout << "Нажмите 3: Вывести структуру на экран" << endl;
cout << "Нажмите 4: Найти элемент в структуре" << endl;
cout << "Нажмите 0: Выйти из программы" << endl;
cin >> i;
switch (i) {
case 1: make();  break;
case 2: save();  break;
case 3: print(); break;
case 4: int Vs; 
cout << "Нажмите 1: Метод линейного поиска" << endl; 
cout << "Нажмите 2: Метод поиска подстроки в строке" << endl;
cout << "Нажмите 3: Метод интерполяционного поиска" << endl;
cout << "Нажмите 0: Выбрать другое действие" << endl;
cin >> Vs;
switch (Vs) {
case 1: LIN(); break;
case 2: PodStr(); break;
case 3: INTER(); break;
case 0: break;
default: cout << "Неизвестный выбор, попробуйте ещё раз !" << endl; break;
}
break;
case 0:
x = 0;
break;
default:
cout << "Неизвестный выбор, попробуйте ещё раз !" << endl;
break;
}
}
	return 0;
}
