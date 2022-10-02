#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for(int T=1;T<=tc;T++){
		int n;
		cin >> n;
		v.clear();
		for(int i=0;i<n;i++){
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		cout<<"#" << T << " ";
		for (auto i : v) {
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0; 
}