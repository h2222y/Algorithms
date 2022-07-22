#include <iostream>
using namespace std;

using ll = long long;

ll POW(ll a, ll b, ll m) {
	if (b == 1) return a % m; //base condition a가 1보다 클 수 있기 때문에 m으로 나눈 나머지 반환
	ll val = POW(a,b/2,m); // 제곱승을 2로 나눈다
	val = val * val % m; //val에는 2로나누어서 구한 a를 다시 제곱해준다.
	if (b % 2 == 0) return val; // 만약 짝수이면 그대로 val를 출력해주면 된다.
	return val * a % m; // 홀수이면 val에 a를 한 번 더 곱해줘야 한다 (2b+1)
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a, b, c;
	cin >> a >> b >> c; 
	cout<< POW(a, b, c); // 답 출력
}