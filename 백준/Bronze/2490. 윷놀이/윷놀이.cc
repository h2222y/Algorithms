//윷놀이
#include <iostream>
using namespace std;

int main() {
	//배 0, 등 1
	// 도 -> 배 1개 등 3개
	int arr[3][4];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) cnt++;
		}
		if (cnt == 1) cout << "A\n";
		else if (cnt == 2) cout << "B\n";
		else if (cnt == 3)cout << "C\n";
		else if (cnt == 4) cout << "D\n";
		else cout << "E\n";
	}
	return 0;
}