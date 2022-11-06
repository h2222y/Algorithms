#include <iostream>
#include <string>
using namespace std;

int main() {
	while (1) {
		string str;
		int cnt = 0;
		getline(cin, str);
		if (str == "#") return 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') cnt++;
			if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') cnt++;
		}
		cout << cnt<<"\n";
	}
	return 0; 
}