#include "List.h"
#include "Error.h"
#include <iostream>
List::List(int s, int k) {
if (size > MAX_SIZE) throw MaxSizeError();
size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
	beg.elem = &data[0];
	end.elem = &data[size];
}
List::List(const List& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
}
List::~List()
{
	delete[]data;
	data = 0;
}
List& List::operator=(const List& a)
{
	if (this == &a)
		return *this;
	size = a.size;
	if (data != 0)
		delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
	return *this;
}

int List::operator() ()
{
	return size;
}

int& List::operator[](int index)
{
	if (index < 0) throw IndexError1();
	if (index >= size) throw IndexError2();
	else
		return data[index];
}
List& operator+(List& x, List& y) {
	for (int i = 0; i < x.size; i++)
		y.data[i] = x.data[i] + y.data[i];
	return y;
}
List List::operator+(const int k)
{
	if (size+1 == MAX_SIZE) throw MaxSizeError();
	List temp(size+1);
	for (int i = 0; i < size; ++i)
		temp.data[i] += data[i] + k;
	return temp;
}
ostream& operator<<(ostream& out, const List& a)
{
	if (a.size == 0) out << "Empty\n";
	for (int i = 0; i < a.size; i++)
		out << a.data[i] << " ";
	return out;
}

istream& operator>>(istream& in, List& a)
{
	for (int i = 0; i < a.size; i++)
	{
		in >> a.data[i];
	}
	return in;
}