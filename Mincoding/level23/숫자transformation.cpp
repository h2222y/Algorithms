#include <iostream>
using namespace std;

int arr[3][4] = {
	3,5,4,1,
	1,1,2,3,
	6,7,1,2
};
int numbers[4];

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> numbers[i];
	}
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 4; y++) {
			for(int i=0;i<4;i++){
				if (arr[x][y] == numbers[i]) {
					if (i + 1 == 4) {
						i = 0;
						arr[x][y] = numbers[i];
						break;
					}
					else {
						arr[x][y] = numbers[i + 1];
						break;
					}
			}
		}
		}
	}
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 4; y++) {
			cout << arr[x][y] << " ";
		}
		cout << endl;
	}
	return 0;
}