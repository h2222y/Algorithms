#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int memoi[52][52][52];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	else if (memoi[a][b][c] != 0) return memoi[a][b][c];
	else if (a < b && b < c)
		return memoi[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		return memoi[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			return 0;
		else {
			cout<<"w("<<a<<", "<<b<< ", "<<c<<") = "<< w(a, b, c)<<"\n";
		}
	}
	return 0;
}
