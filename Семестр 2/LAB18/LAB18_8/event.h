#pragma once

const int evNothing = 0;
const int evMessage = 100;
const int Add = 1;
const int Del = 2;
const int Show = 3;
const int Get = 4;
const int Make = 5;
const int Quit = 101;

struct TEvent {
int what;
union{
int command;

struct{
int message;
int a;
};
};
};
