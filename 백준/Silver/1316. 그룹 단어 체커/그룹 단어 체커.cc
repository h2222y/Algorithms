#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int used[500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	for (int tc = 0; tc < n;tc++) 
	{
		string str;
		cin >> str;
		bool flag = true;
		fill(used, used + 500, 0);
		for (int i = 0; i < str.length(); i++) {
			if (i - 1 >= 0 && str[i] != str[i - 1]) {
				if (used[str[i]] > 0) flag = false;
			}
			used[str[i]]++;
		}
		if (flag == true) cnt++;
	}
	cout << cnt;

	return 0;
}
