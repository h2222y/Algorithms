#include <iostream>
using namespace std;
//최대값 구하기

int main() {
	int arr[9] = { 0 };
	int max_val = -9999, max_idx = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		if (arr[i] > max_val) {
			max_val = arr[i];
			max_idx = i;
		}
	}

	cout << max_val << "\n";
	cout << max_idx + 1;
	return 0;
}