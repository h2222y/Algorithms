// X 보다 작은 수
#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n;
	cin >> x;
	int arr[10000] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] < x) cout << arr[i]<<" ";
	}

}