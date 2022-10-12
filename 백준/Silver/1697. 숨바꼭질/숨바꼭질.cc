#include <iostream>
#include <queue>
using namespace std;

int vis[100001];
queue <int> Q;

int main() {
	int n, k;
	cin >> n >> k; // subin location, sister location
	fill(vis, vis + 100001, -1); // initialization visit array
	Q.push(n); // push subin's location
	vis[n] = 0; // start with 0 
	while (vis[k] == -1) { // when not visit sister's location
		int cur = Q.front(); // current location
		Q.pop();
		for (int nxt : {cur - 1, cur + 1, cur * 2}) { // move
			if (nxt < 0 || nxt>100000) continue; // out of range
			if (vis[nxt] != -1) continue; // already visit
			vis[nxt] = vis[cur] + 1; // count seconds
			Q.push(nxt);
		}
	}
	cout << vis[k]; 
	return 0;
}