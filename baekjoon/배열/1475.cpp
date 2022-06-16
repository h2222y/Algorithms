#include <iostream>
#include <string>
using namespace std;
//방번호
// 0~9까지 적힘 플라스틱 카드가 한 세트
// 방 번호가 주어질때 최소로 필요한 세트의 개수는?
// 6은 뒤집어서 9로 이용가능 만약,6이 2개면 세트 1개만 있으면 된다.

int main() {
	string room_num;
	cin >> room_num; //방번호 입력
	int num[10] = { 0 }; //플라스틱 1세트
	int max_val = -9999; // 최소로 필요한 개수 
	for (int i = 0; i < room_num.length(); i++) {
		num[room_num[i]-'0']++; //길이만큼 카드 개수 카운팅
	}
	num[6] = (num[6] + num[9] + 1) / 2; // 숫자 6이랑 9개수 +1을 2로 나누면 필요한 세트값
	num[9] = num[6]; // 9랑 6이랑 같은 값 넣으면 둘 중 하나만 세어질 수 있음
	for (int i = 0; i < 10; i++) {
		if (num[i] > max_val) max_val = num[i]; //최대 카드 개수 찾기
	}
	cout << max_val; //출력 

	return 0;
}