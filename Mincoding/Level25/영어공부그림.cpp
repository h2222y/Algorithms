#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string parse[100];

void push_temp(int cnt,string temp) {
	parse[cnt] = to_string(cnt) + "#" + temp;

}
int main() {
	string str;
	cin >> str;
	int a = 0;
	int b = 0;
	int cnt = 0;
	while (1) {
		a = str.find("_", b);
		if (a == -1) break;
		string temp;
		for (int i = b; i < a; i++) {
				temp += str[i];
			}
		if (temp != "") {

			cnt++;
			push_temp(cnt, temp);
		}
		b = a + 1;
	}
	string temp;
	for (int k = str.length() - 1; k >= b; k--) {
		temp += str[k];
	}
	reverse(temp.begin(), temp.end());
	parse[cnt+1] += to_string(cnt+1) + "#" + temp;

	for (int i = 1; i <= cnt + 1; i++) {
		cout << parse[i] << "\n";
	}


	return 0; 
}