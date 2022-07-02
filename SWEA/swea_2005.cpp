#include <iostream>
using namespace std;

int map[11][11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int tc=1;tc<=T;tc++){
	int n;
	cin >> n;
	map[0][0] = 1;
	int y = 0;
	for (int x = 0; x < n; x++) {
		map[x][0] = 1;
		map[x][x] = 1;
		for(int y=1;y<n;y++){
		if (y != x) {
			if (x - 1 < 0 || y + 1 >= n) continue;
			map[x][y] = map[x - 1][y - 1] + map[x - 1][y];
		}
		}
	}
	cout <<"#"<<tc << "\n";
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (map[x][y] == 0) continue;
			cout << map[x][y] << " ";
		}
		cout << endl;
	}
	}

}