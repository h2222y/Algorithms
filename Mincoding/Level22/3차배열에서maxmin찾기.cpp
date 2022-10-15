#include <iostream>
using namespace std;

int arr[3][2][2] = {
	{2,4,1,5 },
	{2,3,3,6,},
	{7,3,1,5,},
};

int main() {
	int n;
	cin >> n;
	int max_val=-99999, min_val = 999999;
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			if (arr[n][x][y] > max_val) {
				max_val = arr[n][x][y];
				}
			if (arr[n][x][y] < min_val) {
				min_val = arr[n][x][y];
			}
		}
	}
	cout << "MAX=" << max_val << "\n";
	cout << "MIN=" << min_val << "\n";


	return 0; 
}