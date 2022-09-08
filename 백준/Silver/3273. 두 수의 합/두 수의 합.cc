#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[100003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;
	int cnt = 0;
	sort(arr, arr + n);

	int i = 0, j = n - 1;
	while (1) {
		int sum = arr[i] + arr[j];

		if (i >= j) break;

		if (sum == x) {
			cnt++;
			i++;
			j--;
		}

		else if (sum < x) {
			i++;
		}
		else j--;
	}
	cout << cnt;


	return 0;
}