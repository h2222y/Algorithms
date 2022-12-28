#include <iostream>
#include <deque>
#include <utility>
using namespace std;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, l;
	cin >> n >> l; // 숫자의 개수 n과 뺄 값 l이 주어진다.
	deque<pair<int,int>> DQ; // deque<index,number>
	for (int i = 1; i <= n; i++) { //idx는 1부터 n까지
		int num;
		cin >> num; // 숫자 입력
		while (!DQ.empty() && DQ.back().Y >= num) { //만약 DQ가 비어있지 않고, DQ의 맨 뒤 값의 num가 현재 num보다 크거나 같다면 
			DQ.pop_back(); // 해당 값을 뺀다 (최솟값을 위해)
		}
		DQ.push_back({ i,num }); // DQ에 현재 값과 인덱스를 담는다.
		if (DQ.front().X <= i - l) DQ.pop_front(); // A(i-L+1)~Ai까지의 최솟값을 구해야 하므로
		// 해당 범위에서 벗어나는 값을 DQ에서 제거해준다.
		cout << DQ.front().Y << " "; // DQ의 front의 number 값을 출력해준다.
	}
	return 0;
}