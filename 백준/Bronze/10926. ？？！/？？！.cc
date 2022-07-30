#include <iostream>
using namespace std;

int main() {
	char id[55];
	cin >> id;
	int len = 0;
	for (int i = 0; i < 55; i++) {
		if (id[i] == '\0') {
			len = i;
			break;
		}
	}
	for (int i = 0; i<len; i++) {
		cout << id[i];
	}
	cout << "??!";

	return 0;
}