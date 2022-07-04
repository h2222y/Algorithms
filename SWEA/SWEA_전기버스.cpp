#include <iostream>
using namespace std;
int stop[110] = { 0 };
int k, n, m;
int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> k >> n >> m;
		int cnt = 0;
		for (int i = 0; i <= n; i++) {
			stop[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int charge;
			cin >> charge;
			stop[charge] = 1;
		}
		int now = 0;
		while (1) {
			if (now+k >= n) {
				cout << "#" << tc << " " << cnt << endl;
				break;
			}
			int flag = 0;
			for (int i = now + k; i >= now + 1; i--) {
				if (stop[i] == 1) {
					now = i;
					cnt++;
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				cout <<"#"<<tc<<" "<<0<<endl;
				break; // while Á¾·á 
			}
		}
	}

	return 0;
}