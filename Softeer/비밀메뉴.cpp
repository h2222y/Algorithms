#include <iostream>
using namespace std;
int m, n, k;
int button[102];
int user[102];
int isSame(int index) {
	int i = index;
	for (int j = 0; j < m; j++) {
		if (button[j] != user[i]) return 0;
		else i++;
	}
	return 1;
}

int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++) {
		cin >> button[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> user[i];
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret= isSame(i);
		if (ret == 1) break;
	}
	if (ret == 0) cout << "normal";
	else cout << "secret";
	return 0; 
}