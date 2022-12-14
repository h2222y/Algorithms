#include <iostream>
#include <string>
using namespace std;

int board[70][70];

bool check(int sx,int sy,int z) {
	for (int x = sx; x < sx + z; x++) {
		for (int y = sy; y < sy + z; y++) {
			if (board[sx][sy] != board[x][y]) {
				cout << "(";
				return false;
			}
		}
	}
	return true;
}

void recur(int x,int y, int n) {
	if (check(x, y, n)) { 
		cout << board[x][y]; 
		return;
	}
	int z = n / 2;
	for(int i=0;i<2;i++)
		for (int j = 0; j < 2; j++) 
			recur(x + i * z, y + j * z, z);
	cout << ")";
}

int main() {
	int n;
	cin >> n;
	string str[70];
	for (int x = 0; x < n; x++) {
		cin >> str[x];
		for (int y = 0; y < n; y++) {
			board[x][y] = str[x][y] - '0';
		}
	}
	recur(0,0,n);
	return 0; 
}