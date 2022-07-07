//´ëÇ¥°ª2
#include <iostream>
using namespace std;

int main() {
	int arr[5];
	double sum=0, avg;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}
	avg = sum / 5.0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			int temp;
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << (int)avg << "\n";
	cout << arr[2];
	return 0; 
}