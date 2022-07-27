#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	int arr[10000001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int max = -257000000;
	int min = 257000000;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	cout << min << "\n" << max;
	return 0;
}