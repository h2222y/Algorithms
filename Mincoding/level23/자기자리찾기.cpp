#include <iostream>
using namespace std;
int arr[8];
int main() {
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	int pivot = arr[0];
	int idx_a=1, idx_b=7;

	while (1) {
		for (idx_a = idx_a; idx_a < 8; idx_a++) {
			if (arr[idx_a] > pivot)break;
		}
		for (idx_b = idx_b; idx_a >=1 ; idx_b--) {
			if (arr[idx_b] < pivot)break;
		}
		if (idx_a > idx_b) break;
		swap(arr[idx_a], arr[idx_b]);
	}
	swap(arr[0], arr[idx_b]);
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}
	return 0; 
}