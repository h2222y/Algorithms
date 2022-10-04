#include <iostream>
using namespace std;
int n, m;
int map[20][20] = {};

int KillFly(int dy,int dx) {
	int sum = 0;
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < m; x++) {
			if (dx+x<0 || dy+y<0 || dx + x >= n || dy + y >= n) return 0;
			sum += map[dy+y][dx+x];
		}
	}
	return sum;

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		cin >> n>>m;

		int max_val = -999999999;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cin >> map[y][x];
			}
		}

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				max_val = max(max_val, KillFly(y,x));
			}
		}
		cout << "#" << T << " " << max_val<<"\n";
	}
	
	return 0; 
}