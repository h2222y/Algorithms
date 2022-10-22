#include <iostream>
using namespace std;

int main() {
	
	long long a, b, c;
	cin >> a >> b >> c; // a는 고정 비용, b는 가변비용, c는 판매비용
	if (b >= c) { // b가 c보다 크다면 애초에 바로 이익
		cout << -1;
		return 0; 
	}
	cout << a / (c - b) + 1; 
	// 고정 비용을 제외한 수익에서 가변비용을 빼면
	// ex) a==1000 b==70 c==170 이라면
	// c-b = 170-70 = 100
	// 고정비용 /100을 하면 몫이 10인데, 
	// 차익이 고정비용을 커버하기 위해서는 적어도 10이 필요
	// 따라서 최초로 고정 비용을 넘어가는 손익분기점은
	// 나눈값 +1

	return 0; 
}

