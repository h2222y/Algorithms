#include <iostream>
using namespace std;

char arr[3][3][3];

int main() {
	char ch;
	cin >> ch;
	for (int z = 0; z < 3; z++) {
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				arr[z][x][y] = ch;
			}
		}
		ch++;
	}
	
	for (int z = 0; z < 3; z++) {
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				cout << arr[z][x][y];
			}
			cout << "\n";
		}
		cout << "\n"
			;
	}

	return 0;
}