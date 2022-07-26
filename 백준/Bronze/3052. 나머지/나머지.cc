#include <iostream>
using namespace std;

int main() {
	int num[10] = { 0 };
	int ans[10] = { 0 };
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 10; i++) {
		ans[i] = num[i] % 42;
	}
	for (int i = 0; i < 10; i++) {
		int flag = 0;
		for (int j = i + 1; j < 10; j++) {
			if (ans[i] == ans[j]) flag = 1;
			else continue;
		}
		if (flag == 0) cnt++;
	}
	cout << cnt;
	return 0;
}