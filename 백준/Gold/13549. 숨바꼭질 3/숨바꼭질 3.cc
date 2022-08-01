#include <iostream>
#include <queue>
using namespace std;
int n, k;
int dist[200005];

int main() {
	cin >> n >> k;
	deque<int> DQ;
	fill(dist, dist + 200000, -1);
	DQ.push_back(n);
	dist[n] = 0;
	while(!DQ.empty()) {
		int cur = DQ.front();
		DQ.pop_front();
		if (2 * cur < 200000 && dist[2 * cur] == -1) {
			dist[2 * cur] = dist[cur];
			DQ.push_front(2 * cur);
		}
		for (auto nxt : { cur + 1,cur - 1}) {
			if (nxt < 0 || nxt >= 200000)continue;
			if (dist[nxt] != -1)continue;
			else dist[nxt] = dist[cur] + 1;
			DQ.push_back(nxt);
		}
	}
	cout << dist[k];
}