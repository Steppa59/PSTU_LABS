#include<iostream>
#include<time.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

int** Create(int row, int col) {
int** arr;
arr = new int* [row];
for (int i = 0; i < row; i++){
arr[i] = new int[col];
}
return arr;
}

void Fill(int** arr, int height, int width)
{
for (int i = 0; i < height; i++) {
for (int j = 0; j < width; j++)  {
arr[i][j] =10+ rand() % 89;
}
}
}

//================================
int** Add_Column(int** arr, int height, int& width)
{
int** arr_22;
int pos2;
cout << "Введите номер cтолбца, который нужно добавить: ";
cin >> pos2;
pos2=pos2 - 1;
if (pos2 > width - 1)
{
cout << "Недопустимое значение\n";
return 0;
}
else {
arr_22 = Create(height , width + 1);
for (int i = 0; i < height; i++) {
for (int j = 0; j < pos2; j++) {
arr_22[i][j] = arr[i][j];
}
for (int j = width+1; j > pos2; j--){
arr_22[i][j] = arr[i][j-1];
}
for (int j = pos2; j <= pos2; j++)   {
arr_22[i][j] =10 + rand() % 89;
}
}
arr = arr_22;
return arr;
}
}
//================================

int width, height;
int choice;
int pos;

int main() {
setlocale(LC_ALL, "rus");
cout << "Введите количество строк: ";
cin >> width;
cout << "Введите количество столбцов: "; 
cin >> height;
int** arr;
arr = Create(height, width);
Fill(arr, height, width);
for (int i = 0; i < height; i++) {
for (int j = 0; j < width; j++)  {
cout << arr[i][j] << " ";
}
cout << endl;
}
cout << "\n";

//================================
arr = Add_Column(arr, height, width);
for (int i = 0; i < height; i++) {
for (int j = 0; j < width+1; j++)  {
cout  << arr[i][j] << " ";
}
cout << "\n";
}
cout << "\n";


}
