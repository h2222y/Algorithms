#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,x;
	cin >> n;
	int cnt = 0;
	int arr[100001] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;
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