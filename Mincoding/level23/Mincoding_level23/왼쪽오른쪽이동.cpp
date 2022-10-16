#include <iostream>
using namespace std;
int arr[5] = { 3,5,1,9,7 };

int main() {
	for (int i = 0; i < 4; i++) {
		char ch;
		cin >> ch;
		if (ch == 'R') {
			int temp = arr[4];
			for (int i = 4; i >= 1; i--) {
				arr[i] = arr[i - 1];
			}
			arr[0] = temp;
		}
		else {
			int temp = arr[0];
			for (int i = 0; i < 4; i++) {
				arr[i] = arr[i + 1];
			}
			arr[4] = temp;
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	return 0; 
}