#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// 애너그램 만들기
// 두 영어 단어의 철자의 순서를 뒤바꾸어 같아질 수 있으면 애너그램 관계
// ex) dared bread는 2개 제거하면 같아질 수 있음
// 같아지게 만들기 위해 제거해야하는 최소 문자의 개수 구하기

int main() {
	string a, b;
	cin >> a >> b; //문자열 두 개 입력받기
	int dat[100] = { 0 };
	for (int i = 0; i < a.length(); i++) {
		dat[a[i] - 'a']++;	// a 문자열의 값을 인덱스 값으로 받아 증가시키기
	}
	for (int i = 0; i < b.length(); i++) {
		dat[b[i] - 'a']--; // b 문자열의 값을 인덱스 값으로 받아 감소시키기
	}
	int cnt = 0; //제거해야하는 문자의 최소 개수
	for (int i = 0; i < 100; i++) {
		if (dat[i] != 0) { // 만약 0이면 두개의 문자가 모두 같은것이므로
			cnt += abs(dat[i]); //0이 아닌수들의 절대값을 합해준다
		}
	}
	cout << cnt;
	return 0;
}