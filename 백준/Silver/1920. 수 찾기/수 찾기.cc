#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<int> arr1, arr2;
int BSearch(int val) {
	int first = 0;
	int last = n - 1;
	int mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (arr1[mid] == val) return 1;
		else if (arr1[mid] > val) last = mid - 1;
		else first = mid + 1;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr1.push_back(num);
	}
	sort(arr1.begin(), arr1.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		arr2.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		cout<<BSearch(arr2[i])<<"\n";
	}

	return 0;
}