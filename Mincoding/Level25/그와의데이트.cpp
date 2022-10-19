#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
vector<string> v;
int cnt[2] = {};
int main() {
	cin >> str;
	int a = 4;
	int b;
	//for (int i = 0; i < str.length(); i++) {
	//	if (str[i] == '.') {
	//		a = i;
	//	}
	b = str.find('.', a + 1);
	string temp_month = str.substr(a+1, b-a-1);
	if(temp_month.length()==1 && temp_month=="X") {
			cnt[0] += 9;
	}
	else if (temp_month.length() == 2) {
		for(int j=0;j<2;j++){
			if (temp_month[j] == 'X') {
				cnt[0] += 3;
				break;
			}
		}
	}
	// }
	string temp2 = str.substr(b+1, str.length()-b);
	if (temp2.length() == 1 && temp2=="X") {
		cnt[1] += 9;
	}
	else if (temp2.length() == 2) {
		if (temp2[0] == 'X') {
			if (temp2[1] == 'X') {
				cnt[1] += 22;
			}
			else if (temp2[1] >= '2' && temp2[1] <= '9') cnt[1] += 2;
			else cnt[1] += 3;
		}
		else if (temp2[1] == 'X') {
			if (temp2[0] == '3') {
				cnt[1] += 2;
			}
			else cnt[1] += 10;
		}
	}
	cout << cnt[0]*cnt[1];
	return 0; 
}