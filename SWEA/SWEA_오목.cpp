#include <Iostream>
#include <string>
using namespace std;
string str[30];
int n;

int Garo(int y, int x) {
	for (int i = 1; i <= 4; i++) {
		if (str[y][x] == '.') return 0;
		int dx = x + i;
		if (dx < 0 || dx >= n) return 0;
		if (str[y][x] != str[y][dx]) return 0;
	}
	return 1;
}
int Sero(int y, int x) {
	for (int i = 1; i <= 4; i++) {
		if (str[y][x] == '.') return 0;
		int dy = y + i;
		if (dy < 0 || dy >= n) return 0;
		if (str[y][x] != str[dy][x]) return 0;
	}
	return 1;
}
int Upper_diago(int y, int x) {
	for (int i = 1; i <= 4; i++) {
		if (str[y][x] == '.') return 0;
		int dy = y - i;
		int dx = x + i;
		if (dx < 0 || dx >= n || dy < 0 || dy >= n) return 0;
		if (str[y][x] != str[dy][dx]) return 0;
	}
	return 1;
}

int Lower_diago(int y, int x) {
	for (int i = 1; i <= 4; i++) {
		if (str[y][x] == '.') return 0;
		int dy = y + i;
		int dx = x + i;
		if (dx < 0 || dx >= n || dy < 0 || dy >= n) return 0;
		if (str[y][x] != str[dy][dx]) return 0;
	}
	return 1;
}
int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		int ret1 = 0, ret2 = 0, ret3 = 0, ret4 = 0;
		int flag = 0;
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				ret1= Garo(y, x);
				ret2= Sero(y, x);
				ret3= Upper_diago(y, x);
				ret4= Lower_diago(y, x);
				if (ret1 == 1 || ret2 == 1 || ret3 == 1 || ret4 == 1) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1) cout << "#" << tc << " YES" << endl;
		else cout << "#" << tc << " NO" << endl;
	}
	return 0;
}