#pragma once
#include <iostream> 
using namespace std;

template <class T>

class Money {
public:
Money(int s, T k);
Money(const Money<T>& a);
~Money();
Money& operator=(const Money<T>& a);
T& operator[](int index);
int operator() ();
friend Money& operator+(Money<T>& x, Money<T>& y);
friend ostream& operator<< <>(ostream& out, const Money<T>& a);
friend istream& operator>> <>(istream& in, Money<T>& a);

private:
int size;
T* data;
};

template <class T>
Money<T>::Money(int s, T k)
{
size = s;
data = new T[size];
for (int i = 0; i < size; i++)
data[i] = k;
}

template <class T>
Money<T>::Money(const Money& a) {
size = a.size;
data = new T[size];
for (int i = 0; i < size; i++)
data[i] = a.data[i];
}

template <class T>
Money<T>::~Money() {
delete[]data;
data = 0;
}

template <class T>
Money<T>& Money<T>::operator=(const Money<T>& a) {
if (this == &a)
return *this;
size = a.size;
if (data != 0)
delete[]data;
data = new T[size];
for (int i = 0; i < size; i++)
data[i] = a.data[i];
return *this;
}

template <class T>
T& Money<T>::operator[](int index) {
if (index < size)
return data[index];
else cout << "Ошибка! ";
}

template <class T>
int Money<T>:: operator()() {
return size;
}

template<class T>
Money<T>& operator+(Money<T>& x, Money<T>& y) {
for (int i = 0; i < x.size; i++)
y.data[i] = x.data[i] + y.data[i];
return y;
}

template <class T>
ostream& operator<< (ostream& out, const Money<T>& a) {
for (int i = 0; i < a.size; ++i)
out << a.data[i] << " ";
return out;
}

template <class T>
istream& operator>> (istream& in, Money<T>& a) {
for (int i = 0; i < a.size; ++i)
in >> a.data[i];
return in;
}