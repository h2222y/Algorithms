#include <iostream>
#include <string>
using namespace std;

int arr[11][11];
string str[11];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[i][j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

	return 0; 
}