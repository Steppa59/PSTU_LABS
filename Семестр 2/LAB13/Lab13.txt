#include <iostream>
using namespace std;

int board[8][8];

void set_ferz(int i, int j) { 
for (int x = 0; x < 8; ++x) {
++board[x][j]; 
++board[i][x]; 
int FK;
FK = j - i + x; 
if (FK >= 0 && FK < 8)
++board[x][FK];
FK = j + i - x;

if (FK >= 0 && FK < 8)
++board[x][FK];

board[i][j] = -1; 
}
}


void reset_ferz(int i, int j) {
for (int x = 0; x < 8; ++x) {
--board[x][j];  
--board[i][x]; 
int FK; 
FK = j - i + x;
if (FK >= 0 && FK < 8)
--board[x][FK];
FK = j + i - x;

if (FK >= 0 && FK < 8)
--board[x][FK];

board[i][j] = 0; 
}
}

bool try_queen(int i) { 
bool result = false; 
for (int j = 0; j < 8; ++j){
if (board[i][j] == 0)  {
set_ferz(i, j); 
			
if (i == 7) 
result = true; 
			
else if (!(result = try_queen(i + 1))) reset_ferz(i, j); 
}
if (result) break; 
}
	
return result; 
}

int main()
{
cout << "===== Доска с восьмью ♛ ======" << endl;
for (int i = 0; i < 8; ++i) 
for (int j = 0; j < 8; ++j) 
board[i][j] = 0; 
try_queen(0); 

for (int i = 0; i < 8; ++i) { 
for (int j = 0; j < 8; ++j) {
if (board[i][j] == -1) cout << "[Ф] "; 
else cout <<"[ ] "; 
} 
cout << endl;
} 
}
