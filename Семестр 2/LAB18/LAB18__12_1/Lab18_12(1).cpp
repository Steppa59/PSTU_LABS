#include <iostream> 
#include <set>
#include <iterator>
using namespace std;
typedef multiset<float>Mset;
typedef Mset::iterator it;

Mset make_Mset(int n) {
Mset m;
for (int i = 0; i < n; i++) {
float a = (float)(rand())/10000000 - 80;
m.insert(a);
}
return m;
}

Mset print_Mset(Mset m) {
copy(m.begin(), m.end(), ostream_iterator<float>(cout, " \t "));
cout << endl;
return m;
}

void addSRED(Mset &m){
float s = 0;
multiset<float>::iterator it;
for (it = m.begin(); it != m.end(); ++it){
s += *it;    
}

int n = m.size();
m.insert(s / n);
} 

Mset AddMin(Mset m) {
Mset tmp;
multiset<float>::iterator it;
float min = *m.begin();
for (it = m.begin(); it != m.end(); ++it){
if (min > *it) min = *it;
}
for (it = m.begin(); it != m.end(); ++it){
tmp.insert(min + *it );
}
return tmp;
}

Mset del_key(Mset m, int key) {
Mset tmp;
multiset<float>::iterator it;
for (it = m.begin(); it != m.end(); ++it) {
if (!(key < *it)) {
tmp.insert(*it);
}
}
	return tmp;
}

int main() {
int n;
cout << "Введите количество значений: ";
cin >> n;
Mset m = make_Mset(n);
cout << "Созданный список: " << endl;
print_Mset(m);
addSRED(m);
cout << "Список после добавления среднего арифметического: " << endl;
print_Mset(m);
m = AddMin(m);
cout << "Список после прибавления к элементам минимального: " << endl;
print_Mset(m);
cout << "Введите ключ для удаления: " << endl;
int key;
cin >> key;

m = del_key(m, key);
cout << "Список после удаления: " << endl;
print_Mset(m);
}
