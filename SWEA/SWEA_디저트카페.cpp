#include <iostream>
#include <cstring>
using namespace std;
int arr[21][21] = { 0 };
int n;
int direct_y[4] = { -1,-1,1,1 };
int direct_x[4] = { -1,1,-1,1 };

int run(int y, int x, int my, int mx) {
	int dat[101] = { 0 };

	int cnt = 0;
	int dy=y, dx = x;

	for (int i = 0; i < my; i++) {
		// dy = -1 , dx = +1
		dy = dy - 1;
		dx = dx + 1;
		cnt++;
		if (dy < 0 || dy >= n || dx < 0 || dx >= n) return 0;
		dat[arr[dy][dx]]++;
		if (dat[arr[dy][dx]] > 1) return 0;
	}
	for (int i = 0; i < mx; i++) {
		// dy = +1, dx = +1
		dy = dy + 1;
		dx = dx + 1;
		cnt++;
		if (dy < 0 || dy >= n || dx < 0 || dx >= n) return 0;
		dat[arr[dy][dx]]++;
		if (dat[arr[dy][dx]] > 1) return 0;
	}
	for (int i = 0; i < my; i++) {
		// dy = +1, dx = -1
		dy = dy + 1;
		dx = dx - 1;
		cnt++;
		if (dy < 0 || dy >= n || dx < 0 || dx >= n) return 0;
		dat[arr[dy][dx]]++;
		if (dat[arr[dy][dx]] > 1) return 0;
	}
	for (int i = 0; i < mx; i++) {
		//dy = -1 , dx = -1
		dy = dy - 1;
		dx = dx - 1;
		cnt++;
		if (dy < 0 || dy >= n || dx < 0 || dx >= n) return 0;
		dat[arr[dy][dx]]++;
		if (dat[arr[dy][dx]] > 1) return 0;
	}

	return cnt;
}

int go(int y, int x) {
	int max_val = -9999;
	for (int garo = 1; garo <= n; garo++) {
		for (int sero = 1; sero <= n; sero++) {
			int cnt = run(y, x, garo, sero);
			if (cnt > max_val) max_val = cnt;
		}
	}
	return max_val;
}


int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		int cnt = 0;
		int ret = 0;
		int max_val = -99999;
		
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> arr[y][x];
			}
		}

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				 ret = go(y, x);
				 if (ret > max_val) {
					 max_val = ret;
				 }
			}
		}

		if (max_val > 0) cout <<"#"<<tc<<" "<<max_val << endl;
		else cout <<"#"<<tc<<" "<< - 1 << endl;

	}
	return 0;
}