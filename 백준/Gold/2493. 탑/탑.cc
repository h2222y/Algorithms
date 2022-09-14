#include <iostream>
#include <stack>
using namespace std;
#define X first
#define Y second

int n;
stack<pair<int, int>> S;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	S.push({ 100000001,0 });
	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height;
		while (S.top().X < height) 
			S.pop();
		cout << S.top().Y << " ";
		S.push({ height,i });
	}
		
	
	return 0; 
}