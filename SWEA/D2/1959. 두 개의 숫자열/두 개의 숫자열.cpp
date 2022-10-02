#include <iostream>
#include <vector>
using namespace std;

vector<int> ai, bi;
int n, m;

int ans = 0;
int max_val = -9999999;

void SumVal(int idx_small,int idx_large) {
	for (int i = 0; i < idx_large - idx_small+1; i++) {
		ans = 0;
		for (int j = 0; j < idx_small; j++) {
			ans += ai[j] * bi[j + i];
		}
		if (ans > max_val) max_val = ans;
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		cin >> n >> m;
		// ans = 0;
		max_val = 0;
		ai.clear();
		bi.clear();
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			ai.push_back(num);
		}
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			bi.push_back(num);
		}
		if (n < m) {
			for (int i = 0; i < m-n + 1; i++) {
				ans = 0;
				for (int j = 0; j < n; j++) 
					ans += ai[j] * bi[j + i];
				if (ans > max_val) max_val = ans;
			}
		}
		else if (m < n) {
			for (int i = 0; i <n - m + 1; i++) {
				ans = 0;
				for (int j = 0; j < m; j++) 
					ans += bi[j] * ai[j + i];
				if (ans > max_val) max_val = ans;
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				ans += ai[i] * bi[i];
				if (max_val < ans) max_val = ans;
			}
		}
		cout <<"#"<<T<<" "<< max_val << "\n";
	}
	return 0; 
}