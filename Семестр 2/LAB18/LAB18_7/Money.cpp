#include "Money.h"
Money::Money(void) {
ryb = 0;
cop = 0;
}

Money::Money(long R, int C) {
ryb = R;
cop = C;
}

Money::Money(const Money& t) {
ryb = t.ryb; 
cop = t.cop;
}

Money& Money::operator =(const Money& t) {
ryb = t.ryb; 
cop = t.cop;
return*this;
}

ostream& operator<<(ostream& out, const Money& t) {
out << t.ryb << " . " << t.cop << " ; "; return out;
}

istream& operator>>(istream& in, Money& t) {
cout << "\nryb?"; in >> t.ryb;
cout << "\ncop?"; in >> t.cop;
return in;
}

Money& operator+(Money& x, Money& y) {
Money p;
p.ryb = x.ryb + y.ryb;
int k = 0;
if ((x.cop + y.cop) / 100)>0){
k= (x.cop+y.cop)/ 100;    
}
p.ryb=p.ryb+k;
p.cop = (x.cop + y.cop)% 100;
return p;
}


