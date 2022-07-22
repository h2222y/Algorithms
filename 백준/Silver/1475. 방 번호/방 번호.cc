#include <iostream>
#include <string>
using namespace std;

int main() {
	string room_num;
	cin >> room_num;
	int num[10] = { 0 };
	int max_val = -9999;
	for (int i = 0; i < room_num.length(); i++) {
		num[room_num[i]-'0']++;
	}
	num[6] = (num[6] + num[9] + 1) / 2;
	num[9] = num[6];
	for (int i = 0; i < 10; i++) {
		if (num[i] > max_val) max_val = num[i];
	}
	cout << max_val;

	return 0;
}