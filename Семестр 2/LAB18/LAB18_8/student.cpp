#include "student.h"

student::student(void) : person() {
    Rating = 0.0;
    position = "";
}

student::~student(void) {
}

void student::show() {
cout << "Name: " << name << endl;
cout << "Age: " << age << endl;
cout << "Rating: " << Rating << endl;
cout << "Position: " << position << endl;
cout << endl;
}

void student::input() {
cout << "Name? "; cin >> name;
cout << "Age? "; cin >> age;
cout << "Rating? "; cin >> Rating;
cout << "Position? "; cin >> position;
}

student::student(string n, int a, double s, string p) : person(n, a) {
Rating = s;
position = p;
}

student::student(const student & e) {
name = e.name;
age = e.age;
Rating = e.Rating;
position = e.position;
}

student &student::operator=(const student &e) {
if (&e == this){
return *this;
}
    
name = e.name;
age = e.age;
Rating = e.Rating;
position = e.position;
return *this;
}
