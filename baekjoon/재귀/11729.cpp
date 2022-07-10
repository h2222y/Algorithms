#include <iostream>
using namespace std;

void Hanoi(int a, int b, int n) {
	if (n == 1) { // base condition n이 1일때, a와 b의 값을 출력하면 된다. 
		cout << a << ' ' << b << ' ' << '\n';
		return;
	}
	Hanoi(a, 6 - a - b, n-1); //a에서 시작해서 기둥이 1,2,3번이 존재하기 때문에,
	// 기둥 6-a-b를 하면 a도 b도 아닌 기둥의 위치를 구할 수 있다.
	// a,b가 아닌 위치에 n-1개의 원판을 모두 옮긴다. 
	cout << a << ' ' << b << ' ' << '\n'; // 옮기는 원판 출력
	Hanoi(6 - a - b, b, n - 1);
	// 옮긴 n-1개의 원판을 모두 b로 옮기고 마지막 base condition에서 n을 옮겨준다. 

}

int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n"; //1<<n은 left shift로 2^n을 구하는 것
	// 2^n-1이 이동 개수의 일반항
	// 예를 들어 k를 옮길때 a번이 필요하다면
	// k+1을 옮길때는 k개를 옮길때 a번, k+1을 옮길때 1번, k-1를 k+1로 다시 옮길때 a번으로
	// 총 2a+1번의 이동이 필요하다고 하자
	// 초항이 1이기 때문에, 이 수열의 일반항은 2^k-1이 된다. 
	Hanoi(1, 3, n); // 기둥 1,2,3이 존재 전체 원판을 1에서 3으로 옮기는 것이 목표
	return 0;
}