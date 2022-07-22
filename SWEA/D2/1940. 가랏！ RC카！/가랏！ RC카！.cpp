#include <iostream>
using namespace std;


int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int tc;
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n; //command 갯수
		int a; // 가속? 감속? 유지?
		int v = 0, dist[30] = { 0 },ans=0;

		for (int i = 0; i < n; i++) {
			cin >> a;
			int acc;
			if (a == 1 || a == 2) {
				cin >> acc;
			}
			if (a == 1) {
				v = v + acc;
				dist[i] = v;
			}
			else if (a == 2) {
				v = v - acc;
				if (v < 0) {
					v = 0;
				}
				dist[i] = v;
			}
			else {
				dist[i] = v;
			}
		}

		for (int i = 0; i < 30; i++) {
			ans += dist[i];
		}
		cout <<"#"<<tc<<" "<<ans << endl;

	}
		

	return 0;
}