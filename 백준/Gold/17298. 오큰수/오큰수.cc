#include <iostream>
#include <stack>
using namespace std;

int arr[1000000];
int ans[1000000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= arr[i]) s.pop();
		if (s.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = s.top();
		}
		s.push(arr[i]);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0; 
}