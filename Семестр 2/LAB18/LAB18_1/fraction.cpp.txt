#include<iostream>
#include"fraction.h"
using namespace std;

void fraction::Init(double F, int S)
{
	first = F;
	second = S;
}

void fraction::Read()
{
	cout << "Введите first (Оклад)";
	cin >> first;
	cout << "Введите second (Количество отработанных дней)";
	cin >> second;
}

void fraction::Show()
{
        cout << "============================================"<< endl;
	cout << "Оклад: " << first << endl;
	cout << "Количество отработанных дней: " << second << endl;
}

double fraction::summa()
{
	return ((first/30)*second);
}
