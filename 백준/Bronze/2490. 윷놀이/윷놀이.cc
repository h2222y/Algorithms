#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 배 0, 등 1
	for(int j=0;j<3;j++){
		int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		if (num == 0) cnt++;
		}
	if (cnt == 0) cout << "E\n";
	else if (cnt == 1) cout << "A\n";
	else if (cnt == 2) cout << "B\n";
	else if (cnt == 3) cout << "C\n";
	else if (cnt == 4) cout << "D\n";
	}

	return 0; 
}