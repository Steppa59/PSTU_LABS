#pragma once

#include "person.h"

class student : public person {
protected:
double Rating;
string position;
public:
student(void);

public:
~student(void) override;
void show() override;
void input() override;
student(string, int, double, string);
student(const student &);
double get_Rating() { return Rating; }
void set_Rating(double s) { Rating = s; }
string get_position() { return position; }
void set_position(string p) { position = p; }
student &operator=(const student &);
};