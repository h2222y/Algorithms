#include <iostream>
using namespace std;
int arr[3000][3000];
int cnt[3];

bool check(int r, int c,int n) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (arr[r][c] != arr[i][j]) return false;
		}
	}
	return true;
}

void recur(int x,int y,int z) {
	if (check(x,y,z)) {
		cnt[arr[x][y] + 1] += 1;
		return;
	}
	int n = z / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			recur(x + i * n, y + j * n,n);
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> arr[x][y];
		}
	}
	recur(0,0,n);
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << "\n";
	}
}