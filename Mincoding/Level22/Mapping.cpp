#include <iostream>
#include <string>
using namespace std;
int MAP[3][6] = {
	3,5,4,2,2,3,
	1,3,3,3,4,2,
	5,4,4,2,3,5,
};
string price = "TPGKC";

int main() {
	char ch1;
	int n;
	cin >> ch1 >> n;
	int idx = MAP[ch1 - 'A'][n - 1];
	/*if (ch1 == 'A') {
		idx = MAP[0][n - 1];
	}
	else if (ch1 == 'B') {
		idx = MAP[1][n - 1];
	}
	else {
		idx = MAP[2][n - 1];
	}*/
	cout << price[idx-1];
}