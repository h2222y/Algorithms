#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	string str;
	while(tc--){
		cin >> str;
		int idx = str.find(',');
		int a = stoi(str.substr(0, idx));
		int b = stoi(str.substr(idx + 1, str.length()));
		cout << a + b << "\n";
	}
	return 0;
}