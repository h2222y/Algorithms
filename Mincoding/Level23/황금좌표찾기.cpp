#include <iostream>
#include <string>
using namespace std;

char left_arr[4][4];
char right_arr[5][5] = {
	"ABCD",
	"BBAB",
	"CBAC",
	"BAAA"
};
int dat[100];

int main() {
	int max_val=-999;
	int max_idx = 0;
	for (int x = 0; x < 4; x++) {
		cin >> left_arr[x];
	}

	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (left_arr[x][y] == right_arr[x][y]) {
				dat[left_arr[x][y]]++;
			}
		}
	}
	for (int x = 0; x < 100; x++) {
		if (dat[x] > max_val) {
			max_val = dat[x];
			max_idx = x;
		}
	}
	cout << char(max_idx);
	
	return 0; 
}