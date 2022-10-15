#include <iostream>
using namespace std;
int arr[3][2][3];

int main() {
	int a, b;
	cin >> a >> b;
	for (int z = 0; z < 3; z++) {
			for (int y = 0; y < 3; y++) {
				arr[z][0][y] = a;
				arr[z][1][y] = b;
			}
	}
	for (int z = 0; z < 3; z++) {
		for(int x=0;x<2;x++){
			for (int y = 0; y < 3; y++) {
				cout << arr[z][x][y]<<" ";
			}
			cout << "\n";
		}
		cout << "\n";
	}

	return 0; 
}