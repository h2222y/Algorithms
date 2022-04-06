/*#include <iostream>
using namespace std;

int arr[19][19];
int win, win_x, win_y;

int Check();

int main() {
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> arr[i][j];
		}
	}
	Check();
	return 0;
}

int Check() {
	int a = 0;
	for (int y = 1; y <= 19; y++) {
		for (int x = 1; x <= 19; x++) {
			if (y >= 14 && x >= 14) break;
			else if (arr[y][x] != 0) {
				a = go(y, x);
				if (a != 0) {
					win = a;
					win_x = x;
					win_y = y;
					break;
				}
			}
		}
	}
}
int go(int y, int x) {
	int h = arr[y][x];
	int a = 0;
	for (int i = x; i < x + 5; i++) {
		if (arr[i][x] != h) break;
		a++;
	}

}*/