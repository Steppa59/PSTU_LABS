#include <iostream>
using namespace std;

struct Slovo {
char* data;
Slovo *next;
};

struct abc {
Slovo* start ;
Slovo* end;
};



abc* create_abc (char* n) {
Slovo *start = new Slovo;
Slovo *end = start;
start->data = n;
start->next = NULL;
abc *q = new abc;
q->start = start;
q->end = end;
return q;
}

void push (abc* s, char* n) {
Slovo *to_add = new Slovo;
to_add->data = s->start->data;
to_add->next = s->start->next;
s->start->data = n;
s->start->next = to_add;
} 
char* pop (abc* s) {
char* data = s->end->data;
Slovo *to_pop = new Slovo;
to_pop->data = s->end->data;
if (s->end->next != NULL) {
s->end->data = s->end->next->data;
s->end->next = s->end->next->next;
}
else {
s->end->data = NULL;
}
delete to_pop;
return data;
}

char* front(abc* s) {
return s->start->data;
}

char* back(abc* s) {
return s->end->data;
}

int main () {
srand (time (nullptr));
char* elem_to_add = new char[6];
for (int i = 0; i < 5; i++) {
elem_to_add[i] = rand() % 4 + 69;
}
elem_to_add[5] = '\0';
abc *s = create_abc(elem_to_add);
for (int i = 0; i < 10; i++) {
elem_to_add = new char[6];
for (int i = 0; i < 5; i++) {
elem_to_add[i] = rand() % 4 + 69;
}
elem_to_add[5] = '\0';
push (s, elem_to_add);
}
char* elem = pop(s);
cout << elem << ' ';
abc *tmp = create_abc (elem);
while (front (s) != NULL) {
push (tmp, pop(s));
}
while (front (tmp) != NULL) {
elem = pop(tmp);
cout << elem << ' ';
push (s, elem);
}
int index;
char *elem_to_add_second = new char[6];
cout << endl << "Введите слово, которое хотите добавить:  ";
cin >> elem_to_add_second;
cout << "После какого слова(индекса) вставить?  ";
cin >> index;
while (front (s) != NULL) {
push (tmp, pop(s));
}
int i = 0;
while (front (tmp) != NULL) {
if (i == index) {
push(s, elem_to_add_second);
}
else {
push(s, pop(tmp));
}
i++;
}
while (front (s) != NULL) {
push (tmp, pop(s));
}
while (front (tmp) != NULL) {
char *elem_to_print = pop(tmp);
cout << elem_to_print << ' ';
push (s, elem_to_print);
}
}
