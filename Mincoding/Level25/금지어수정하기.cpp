#include <iostream>
#include <string>
using namespace std;
string ori[5] = {
	"KFC",
	"MC",
	"BICMAC",
	"SHACK",
	"SONY"
};
string key[5] = {
	"#BBQ#",
	"#BBQ#",
	"#MACBOOK#",
	"#SHOCK#",
	"#NONY#"
};

string str;
string new_str;

void replace(string ori,string key) {
	int a = -1;
	int b;
	while (1) {
		a = str.find(ori, a+1);
		if (a == -1) return;
		str.erase(a, ori.length());
		str.insert(a, key);
		a += key.length();
	}
}

int main() {
	cin >> str;
	for (int i = 0; i < 5; i++) {
		replace(ori[i],key[i]);
	}
	cout << str;
	return 0; 
}