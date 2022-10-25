#include <iostream>
using namespace std;
int arr1[101][101];
int arr2[101][101];
int sum[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int  x= 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> arr1[x][y];
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> arr2[x][y];
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			sum[x][y] = arr1[x][y] + arr2[x][y];
			cout << sum[x][y]<<" ";
		}
		cout << "\n";
	}
	return 0; 
}