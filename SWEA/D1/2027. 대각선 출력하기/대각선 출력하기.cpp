#include <iostream>
using namespace std;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	char arr[5][5];
	
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			if (y == x) {
				arr[y][x] = '#';
			}
			else arr[y][x] = '+';
		}
	}
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			cout << arr[y][x];
		}
		cout << endl;
	}
	return 0;
}