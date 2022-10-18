#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string temp[40];
string ans[40];
int main() {
	string str;
	cin >> str; // 메일주소 이름@[도메인이름][최상위도메인]
	// ex bbq@mcdonald.co.kr
	// 이름과 도메인 이름만 추출해서 출력하기
	int a = 0;
	int b;
	int t = 0;
	while (1) {
		b = str.find("|", a);
		if (b == -1) break;
		for (int i = a; i < b; i++) {
			temp[t] += str[i];
		}
		t++;
		a = b+1;
	}
	int cnt = 0;
	for (int i = 0; i < 40; i++) {
		if (temp[i] == "")break;
		int a = 0;
		int b,c;
		while (1) {
			b = temp[i].find("@", a);
			if (b == -1)break;
			ans[i] += "[#" + temp[i].substr(a, b - a) + ']';
			c = temp[i].find(".", b);
			ans[i] += " " + temp[i].substr(b+1, c - b-1);
			a = c;
			cnt++;
		}
	}
	string temp2;
	for (int k = str.length() - 1; k >= a; k--) {
		temp2 += str[k];
	}
	reverse(temp2.begin(), temp2.end());
	int idx = 0;
	for (int i = 0; i < temp2.length(); i++) {
		if (temp2[i] == '@') {
			idx = i;
			ans[cnt] += "[#";
			for (int j = 0; j < i; j++) {
				ans[cnt] += temp2[j];
			}
			ans[cnt] += "]";
		}
		else if (temp2[i] == '.') {
			ans[cnt] += " ";
			for (int j = idx + 1; j < i; j++) {
				ans[cnt] += temp2[j];
			}
		}
	}

	for (int i = 0; i < 40; i++) {
		if (ans[i] == "")break;
		cout << ans[i];
		cout << "\n";
	}

	return 0; 
}