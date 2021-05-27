#pragma once
#include <iostream> 
#include <string>
using namespace std;
class Money {
public:
Money(void);
Money(long, int);
Money(const Money&);


Money& operator=(const Money&);
friend Money& operator+(Pair& x, Pair& y);
friend ostream& operator<< (ostream& out, const Money&);
friend istream& operator>> (istream& in, Money&);

public:
virtual ~Money(void) {};
private:
long R;
int K;
};

