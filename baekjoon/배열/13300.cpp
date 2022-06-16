#include <iostream>
using namespace std;
//방 배정
//조건1. 같은 학년끼리만 방을 사용할 수 있다.
//조건2. 같은 성별끼리만 방을 사용할 수 있다.
//최소로 필요한 방의 개수를 구하자.

int main() {
	int n,k; //수학여행에 참가하는 인원수 n, 한 방에 가능한 인원수 k
	cin >> n >> k;
	
	int s, y; //성별 s, 학년 y
	int girls[7] = { 0 }; //학년을 인덱스로하는 여자 인원수
	int boys[7] = { 0 }; //학년을 인덱스로하는 남자 인원수

	for (int i = 0; i < n; i++) {
		cin >> s >> y;//성별과 학년 입력
		if (s == 0) girls[y]++; //여자일 경우 해당 학년의 여자 수 증가
		else boys[y]++; //남자일 경우 해당 학년의 남자 수 증가
	}

	int cnt = 0; //방 개수 세기

	for (int i = 1; i <= 6; i++) {
		if (girls[i] > 0) { // 해당 학년의 여자가 존재하면
			cnt += (girls[i]-1) / k + 1; //해당 인원수에서 1을 빼고 k로 나눈값에 1 더하기
		}
		if (boys[i] > 0) { //해당 학년의 남자가 존재하면
			cnt += (boys[i]-1) / k + 1; //해당 인원수에서 1을 빼고 k로 나눈값에 1 더하기
		}
	}
	cout << cnt;

	return 0;
}