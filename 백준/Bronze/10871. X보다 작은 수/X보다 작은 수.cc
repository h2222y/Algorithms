#include <iostream>
using namespace std;
int arr[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] < x) {
			cout << arr[i] << " ";
		}
	}

	return 0;
}