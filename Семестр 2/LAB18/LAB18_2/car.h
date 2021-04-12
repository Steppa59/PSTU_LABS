#pragma once
#include <iostream>
#include <string>
using namespace std;

class car {
string brand;
string model;
int price;

public:
car();
car(string, string, int);
car(const car&);
~car();
string get_brand();
void set_brand(string);

string get_model();
void set_model(string);

int get_price();
void set_price(int);

void show();
};
