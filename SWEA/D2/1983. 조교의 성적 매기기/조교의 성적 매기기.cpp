#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string score[10] = { "A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };
double average[102] = {};
//string give_score[102] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			double mid, last, hw;
			cin >> mid >> last >> hw;
			average[i] = mid * 0.35 + last * 0.45 + hw * 0.20;
		}
		double find_val = average[k - 1];

		// int same_score = n / 10;
		sort(average, average + n, greater<>());

		int k_rank = 0;

        for (int i = 0; i < n; i++) {
			if ( find_val == average[i]) {
				k_rank =i;
				break;
			}
		}
		cout << "#" << T << " " << score[(10 * k_rank) / n] << "\n";
	}

	return 0; 
}