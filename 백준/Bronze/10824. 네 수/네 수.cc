#include <iostream>
#include <string>
using namespace std;
string a, b, c, d;

int main() {

	cin >> a >> b >> c >> d;
	string first = a + b;
	string second = c + d;
	long long ans = stoll(first) + stoll(second);
	cout << ans;
	return 0; 
}
