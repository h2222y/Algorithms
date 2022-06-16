#include <iostream>
#include <string>
using namespace std;
//Strfry
// 주어진 문자열 두개 중 뒤 문자열의 문자들을 무작위로 뽑아 재정렬하여
// 첫 번째 문자열을 만들 수 있는 경우 Possible
// 만들 수 없는 경우 impossible

int main() {
	int n;
	cin >> n; //tc의 개수
	string arr1, arr2; //문자열 2개
	for (int i = 0; i < n; i++) { //테케의 개수만큼
		cin >> arr1 >> arr2; //문자열 2개 입력받음
		int bucket[100] = { 0 }; //문자를 저장할 dat 배열
		int flag = 0; //possible impossible 구분
		for (int j = 0; j < arr1.length(); j++) {
			bucket[arr1[j] - 'a']++; // arr1에 있는 문자들을 dat에 저장
			bucket[arr2[j] - 'a']--; //arr1에 있는 문자 -1을 하면 0이된다.
		}
		for (int j = 0; j < 100; j++) {
			if (bucket[j] != 0) { //0이 아니면 다른 문자 존재
				flag = 1;
				break;
			}
		}
		if(flag==0) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	return 0;
}