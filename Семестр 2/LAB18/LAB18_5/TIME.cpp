#include "TIME.h"
TIME::TIME(void) :TRIAD() {}
TIME::~TIME(void) {}
TIME::TIME(int Hour, int Min, int Sec) : TRIAD(Hour, Min, Sec) {}
TIME::TIME(const TIME& D) {
first = D.first;
second = D.second;
third = D.third;
}

TIME TIME::operator++(int) {
first++;
second++;
third++;
int Sum = first*3600  + second * 60 + third;
TIME t(first, second, third);
first = Sum / 3600;
Sum = Sum % 3600;
second = Sum / 60;
Sum = Sum % 60;
third = Sum;
return t;
}

TIME TIME::operator+(int N) {
int Sum = first*3600 + second*60 + third + 60*N + N;

TIME t(first, second, third);
first = Sum / 3600;
Sum = Sum % 3600;
second = Sum / 60;
Sum = Sum % 60;
third = Sum;
return t;
}

void TIME::hour(int Hour) {
first = Hour;
}
void TIME::min(int Min) {
second = Min;
}
void TIME::sec(int Sec) {
third = Sec;
}

ostream& operator<<(ostream& out, const TIME& t) {
out << endl << "Часы: " << t.first;
out << endl << "Минуты: " << t.second;
out << endl << "Cекунды: " << t.third;
out << endl;
return out;
}
