#include "Money.h"
Money::Money()
{
	rub = 0; 
	cop = 0;
}
Money::Money(int R, int C)
{
	rub = R; 
	cop= C;
}
Money::Money(const Money& p)
{
	rub = p.rub; 
	cop = p.cop;
}
Money Money::operator =(const Money& p)
{
	if (&p == this) return *this;
	rub = p.rub;
	cop = p.cop; 
	return*this;
}
Money::~Money()
{
}

ostream& operator<<(ostream& out, const Money& p)
{
	out << "RUB: " << p.rub << " COP:" << p.cop << "\n"; 
	return out;
}

istream& operator>>(istream& in, Money& p)
{
	cout << "RUB?"; in >> p.rub;
	cout << "COP?"; in >> p.cop; 
	return in;
}

fstream& operator>>(fstream& fin, Money& p)
{
	fin >> p.rub; 
	fin >> p.cop; 
	return fin;
}

fstream& operator<<(fstream& fout, const Money& p)
{
	fout << p.rub << "\n" << p.cop << "\n";
	return fout;
}

