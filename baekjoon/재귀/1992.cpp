#include <iostream>
#include <string>
using namespace std;

int board[70][70];

bool check(int sx,int sy,int z) {
	for (int x = sx; x < sx + z; x++) {
		for (int y = sy; y < sy + z; y++) {
			if (board[sx][sy] != board[x][y]) {
				cout << "("; // 다르면 나눠야함 나눌때마다 여는 괄호 출력
				return false;
			}
		}
	}
	return true;
}

void recur(int x,int y, int n) {
	if (check(x, y, n)) { 
		cout << board[x][y];  // board의 값이 모두 같으면 종료
		return;
	}
	int z = n / 2;
	for(int i=0;i<2;i++)
		for (int j = 0; j < 2; j++) 
			recur(x + i * z, y + j * z, z); //나눴을때 값이 같은지 확인하기 위함
	cout << ")"; // 범위를 나누고 모두 압축했을때 괄호 닫기
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