#include <iostream>
using namespace std;
int price[10000000];

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> price[i];
		}
		int max_val = -9999;
		long long profit = 0;
		int cnt = 0;

		for (int now = n - 1; now >= 0; now--) {
			if (price[now] > max_val) { // max_val : now 이후로 가장 비싼 가격 
				max_val = price[now];
			} //vs max_val
			profit += max_val - price[now];
		}
		cout << "#"<<tc<<" "<< profit<<endl;
		/*
		for (int now = 0; now < 5; now ++) {
			// 1.
		max_val = -9999;

			for(int next=now;next<5;next++){
				if (price[next] > max_val) {
					max_val = price[next];
				}
			}
		// 2. 이익 누적
			profit += max_val - price[now];
		}
		cout << profit;
		*/
	}
	return 0;
}