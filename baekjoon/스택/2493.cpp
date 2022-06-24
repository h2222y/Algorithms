#include <iostream>
#include <stack>
using namespace std;
#define X first // pair의 first 와 second를 편하게 사용하기 위해 정의
#define Y second // 위와 같음

int n; // 타워의 개수 
stack<pair<int, int>> S; // 타워의 높이를 입력받을 스택

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; //타워의 개수 입력
	S.push({ 100000001,0 }); //pair 쌍을 최대 높이보다 1큰 높이와 현재 좌표 
	for (int i = 1; i <= n; i++) {
		int height;
		cin >> height; //높이 입력받음
		while (S.top().X < height)  // 스택의 현재 값이 입력받은 height 보다 작다면 pop
			S.pop(); // 큰 값을 발견할때까지 pop을 해준다 
		cout << S.top().Y << " "; // 가장 위의 현재 좌표보다 높은 타워의 개수 출력
		S.push({ height,i }); // 입력 받은 높이와 타워의 좌표
	}

	return 0;
}