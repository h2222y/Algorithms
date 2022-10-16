#include <iostream>
using namespace std;
int map[4][4];

int main() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			cin >> map[x][y];
		}
	}
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			map[x][3] += map[x][y];
		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			map[3][y] += map[x][y];
		}
	}
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			if (x == y) {
				map[3][3] += map[x][y];
			}
		}
	}
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			cout<< map[x][y]<< " ";
		}
		cout << "\n";
	}
	return 0; 
}