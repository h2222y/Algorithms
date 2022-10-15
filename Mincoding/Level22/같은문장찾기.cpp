#include <iostream>
#include <cstring>
#include <string>
using namespace std;


int main() {
	char s1[10];
	char s2[10];
	char s3[10];
	cin >> s1 >> s2 >> s3;
	if (!strcmp(s1, s2)) {
		if (!strcmp(s1, s3)) {
			cout << "WOW";
		}
		else cout << "GOOD";
	}
	else if (!strcmp(s1, s3)) {
		if (!strcmp(s1, s2)) {
			cout << "WOW";
		}
		else cout << "GOOD";
	}
	else if (!strcmp(s2, s3)) {
		if (!strcmp(s1, s3)) {
			cout << "WOW";
		}
		else cout << "GOOD";
	}
	else cout << "BAD";
	return 0;
}