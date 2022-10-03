#include <iostream>
using namespace std;

int puzzle[9][9] = {};
int cnt[10] = {};

int Hori() {
	for (int y = 0; y < 9; y++) {
		fill(cnt, cnt + 10, 0);
		for (int x = 0; x < 9; x++) {
			cnt[puzzle[y][x]]++;
		}
		for (int i = 1; i < 10; i++) {
			if (cnt[i] >= 2) return 0;
		}
	}
	return 1;
}
int Verti() {
	for (int x = 0; x < 9; x++) {
		fill(cnt, cnt + 10, 0);
		for (int y = 0; y < 9; y++) {
			cnt[puzzle[y][x]]++;
		}
		for (int i = 1; i < 10; i++) {
			if (cnt[i] >= 2) return 0;
		}
	}
	return 1;
}
int Box(int dy, int dx) {
	fill(cnt, cnt + 10, 0);

	for (int y = dy; y < dy + 3; y++) {
		for (int x = dx; x < dx + 3; x++) {
			cnt[puzzle[y][x]]++;
		}
	}
	for (int i = 1; i < 10; i++) {
		if (cnt[i] >= 2) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int tc;
	cin >> tc;

	for (int T = 1; T <= tc; T++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> puzzle[i][j];
			}
		}
		int ret1 = Hori();
		int ret2 = Verti();
		int ret3;
		for (int y = 0; y <= 6; y += 3) {
			for (int x = 0; x <= 6; x += 3) {
				ret3 = Box(y, x);
				if (ret3 == 0) break;
			}
			if (ret3 == 0) break;
		}
		cout << "#" << T <<" ";
		if (!ret1 || !ret2 || !ret3) cout << 0 << "\n";
		else cout << 1 << "\n";

	}
	return 0;
}