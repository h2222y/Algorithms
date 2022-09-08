#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n; //테케수
	string str1, str2;

	for (int tc = 0; tc < n;tc++) 
	{

		cin >> str1 >> str2;

		bool flag = true;
		int dat[100] = {0};

		for (int i = 0; i < str1.length(); i++) {
			dat[str1[i] - 'a']++;
			dat[str2[i] - 'a']--;
		}

		for (int i = 0; i < 100; i++) {
			if (dat[i] != 0) {
				flag = false;
				break;
			}
		}
		
		if(flag== true) cout << "Possible\n";
		else cout << "Impossible\n";
	}


	return 0;
}