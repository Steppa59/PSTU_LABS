#include "dialog.h"
#include "person.h"
#include "student.h"
#include <iostream>

using namespace std;

dialog::dialog() : tree() {
EndState = 0;
}

dialog::~dialog() {}

void dialog::GetEvent(TEvent &event) {
string OpInt = "+-ms?q";
string s;
string param;
char code;
cout << '>';
cin >> s;
code = s[0];
if (OpInt.find(code) >= 0) {
event.what = evMessage;
switch (code) {
case 'm': event.command = Make; break;
case '+': event.command = Add; break;
case '-': event.command = Del; break;
case 's': event.command = Show; break;
case '?': event.command = Get; break;
case 'q': event.command = Quit; break;
}

if (s.length() > 1) {
param = s.substr(1, s.length() - 1);
int A = atoi(param.c_str());
event.a = A;
}
} else {
event.what = evNothing;
}
}


int dialog::execute() {
TEvent event;
do {
EndState = 0;
GetEvent(event);
HandleEvent(event);
} while (!valid());
    return EndState;
}


void dialog::HandleEvent(TEvent &event) {
if (event.what == evMessage) {
string name;
switch (event.command) {
case Make:
for (int i = 0; i < event.a; ++i) {
object *ptr;
int input;
                    
cout << "What object to Create?" << endl;
cout << "1: Person " << endl;
cout << "2: Student "<< endl;
cout << "Choice:  ";
cin >> input;
switch (input) {
case 1: ptr = new person; ptr->input(); break;
case 2: ptr = new student; ptr->input(); break;
}
add(ptr);
}
ClearEvent(event);
break;

case Add:
int input;
object *ptr;
cout << "What object to Add?" << endl;
cout << "1: Person " << endl;
cout << "2: Student "<< endl;
cout << "Choice:  ";
cin >> input;
switch (input) {
case 1: ptr = new person; ptr->input(); break;
case 2: ptr = new student; ptr->input(); break;
}

add(ptr);
ClearEvent(event);
break;
case Show:show(); ClearEvent(event); break;
case Del: 
cout << "What object to Delete?" << endl;
cout << "Name:  ";
cin >> name; del(name); ClearEvent(event); break;
case Quit: EndExec(); ClearEvent(event); break;
}
}
}


void dialog::ClearEvent(TEvent &event) {
event.what = evNothing;
}

int dialog::valid() {
if (EndState == 0) {
return 0;
} else {
return 1;
}
}

void dialog::EndExec() {
EndState = 1;
}
