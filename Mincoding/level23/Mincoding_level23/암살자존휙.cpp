#include <iostream>
using namespace std;
int map[3][4];

int main() {
	bool flag = false;
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}
	for (int x = 0; x < 3; x++) {
		int cnt = 0;
		for (int y = 0; y < 4; y++) {
			if (map[x][y] == 1) cnt++;
			if (cnt > 1) {
				flag = true;
				break;
			}
		}
	}
	if (flag == true) cout << "위험";
	else cout << "안전";
	return 0; 
}