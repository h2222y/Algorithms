#include <iostream>
using namespace std;


int main() {
	int a, b;
	int i = 0;
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		cout << a + b<<"\n";
		i++;

	}
	return 0;
}