#include <iostream>
#include <string>

using namespace std;

int main() {
	int T, N;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		string s = "";
		int n = 0;
		for (int j = 1; j <= N; j++) {
			char Ci; int Ki;
			cin >> Ci >> Ki;
			for (int k = 1; k <= Ki; k++) {
				s += Ci;
				n++;
				if (n % 10 == 0)
					s += '\n';
			}
		}
		cout << "#" << tc << "\n" << s << endl;
	}
	return 0;
}