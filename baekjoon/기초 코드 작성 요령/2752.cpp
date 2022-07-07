//세수 정렬
#include <iostream>
using namespace std;

int main() {
	int arr[3];
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			int temp;
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << arr[i]<<" ";
	}
	return 0;
}