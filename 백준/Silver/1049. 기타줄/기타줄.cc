#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m;
int ans1 = 0;
int ans2 = 0;
int ans3 = 0; 
int min_val = 999999999;
vector<int> set_sum;
vector<int> piece_sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int set, piece;
		cin >> set >> piece;
		set_sum.push_back(set);
		piece_sum.push_back(piece);
	}
	sort(set_sum.begin(), set_sum.end());
	sort(piece_sum.begin(), piece_sum.end());

	if (n <= 6) {
		ans1 = set_sum[0];
		ans2 = piece_sum[0] * n;
		if (ans1 >= ans2) cout << ans2;
		else cout << ans1;
		return 0; 
	}
	
	else {
		ans1 = set_sum[0] * ((n/6)+1);
		ans2 += set_sum[0] * (n / 6);
		ans2 += piece_sum[0] * (n % 6);
		ans3 += piece_sum[0] * n;
		if (ans1 <= ans2 && ans1 <= ans3) cout << ans1;
		else if (ans2 < ans1 && ans2 <= ans3) cout << ans2;
		else if(ans3<ans1 && ans3<ans2) cout << ans3;

	
	}

	return 0; 

}