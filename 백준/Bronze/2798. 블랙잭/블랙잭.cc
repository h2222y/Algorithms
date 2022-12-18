#include <iostream>
#include <string>
#include <vector>
using namespace std;
int arr[100003];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int result = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] > result) {
					result = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}
	cout << result << "\n";
	return 0;
}