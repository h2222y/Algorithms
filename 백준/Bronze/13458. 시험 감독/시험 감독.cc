#include <iostream>
#include <vector>
using namespace std;

vector<int> Ai;
int main() {
	int n;
	int viewer1, viewer2;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		Ai.push_back(num);
	}

	cin >> viewer1 >> viewer2;

	int rest = 0;
	long long cnt_viewer = 0;
	for (int i = 0; i < Ai.size(); i++) {
		rest = Ai[i] - viewer1;
		cnt_viewer++;
		if (rest > 0) {
			if (rest % viewer2 == 0) cnt_viewer += rest/viewer2;
			else cnt_viewer += rest / viewer2 + 1;
		}
	}
	cout << cnt_viewer;
	return 0; 
}