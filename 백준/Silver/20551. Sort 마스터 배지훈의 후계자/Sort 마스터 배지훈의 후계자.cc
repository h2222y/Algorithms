#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int A[200005];	
int n, m;

int find(int num) {
	int first = 0;
	int last = n - 1;
	int mid = 0;
	while(first<=last) {
		mid = (first + last) / 2;
		if (A[mid] > num) {
			last = mid - 1;
		}
		else if (A[mid] < num) {
			first = mid + 1;
		}
		else {
			if (last == mid)
				break;
			last = mid;
		}
	}
	if (A[mid] == num) {
		return mid;
	}
	else return -1;
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A, A + n);
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		cout << find(num)<<"\n";
	}
}
