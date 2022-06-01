#include <iostream>
using namespace std;
int map[110][110] = { 0 };
int n,k;

int isMax(int y, int x) {
	int direct_y[4] = { -1,1,-1,1 };
	int direct_x[4] = { 1,-1,-1,1 };
	int dx=0, dy=0;
	int sum = 0;
	for (int t = 0; t < 4; t++) {
		for (int range = 1; range <= k; range++) {
		dy = y + direct_y[t]*range;
		dx = x + direct_x[t]*range;
		if (dy < 0 || dy >= n || dx < 0 || dx >= n) continue;
		sum += map[dy][dx];
		}
	}
	return sum;
}

int main() {
	cin >> n;
	int max = -9999;
	int ret = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
	cin >> k;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			ret = isMax(y, x);
			if (ret > max) max = ret;
		}
	}
	cout << max;

	return 0;
}