#pragma once
#include <iostream> 
using namespace std;
class Pair {
    
public:
Pair();
Pair(long, int);
Pair(const Pair&);
Pair& operator=(const Pair&);
friend Pair& operator+(Pair& x, Pair& y);
friend ostream& operator<< (ostream& out, const Pair&);
friend istream& operator>> (istream& in, Pair&);

public:
virtual ~Pair() {};
private:
long first;
int second;