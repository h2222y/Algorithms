#include <iostream>
#include <algorithm>
using namespace std;

int numbers[200];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	sort(numbers, numbers + n);
	int mid = n / 2;
	cout << numbers[mid];
	return 0;
}