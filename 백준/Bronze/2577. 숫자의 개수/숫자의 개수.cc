#include <iostream>
#include <string>
using namespace std;

int cnt[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	
	int multi = a * b * c;
	
	string str_multi;
	str_multi = to_string(multi);

	for (int i = 0; i < str_multi.length(); i++) {
		cnt[str_multi[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << "\n";
	}


	return 0;
}