#include "car.h"
#include <iostream>
#include <string>
using namespace std;

car::car()
{
	brand = "";
	model = "";
	price = 0;
	cout << "Конструктор без параметров для объекта " << this << endl;
}

car::car(string A, string C, int S)
{
	brand = A;
	model = C;
	price = S;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}

car::car(const car& t) {
	brand = t.brand;
	model = t.model;
	price = t.price;
	cout << "Конструктор копирования для объекта " << this << endl;
}

car::~car() {
	cout << "Деструктор для объекта " << this << endl;
}

string car::get_brand() {
	return brand;
}
string car::get_model() {
	return model;
}
int car::get_price() {
	return price;
}
void car::set_brand(string A) {
	brand = A;
}
void car::set_model(string C)
{
	model = C;
}
void car::set_price(int S)
{
	price = S;
}
void car::show()
{
	cout << "Марка машины: " << brand << endl;
	cout << "Модель: " << model << endl;
	cout << "Цена: " << price << endl;
}
