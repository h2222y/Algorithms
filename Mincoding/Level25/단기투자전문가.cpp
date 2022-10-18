#include <iostream>
#include <string>
using namespace std;
string str;

bool isValid(string temp) {
	if (temp.length() != 5) return false; // 길이 5아니라면 종료
	for (int i = 0; i < 5; i++) {
		if (!(temp[i] >= '0' && temp[i] <= '9'))return false; // 숫자 아니면 종료
	}
	return true; // 나머지 가능
}
void Parsing(string str) {
	int a = 0; // 인덱스 0번부터 탐색시작
	int b; 
	while(1){ // 계속 발견될때까지
	a = str.find('[', a); // 만약 [를 발견하면
	if (a == -1) return; // 종료조건
	b = str.find(']', a+1); // a+1인덱스부터 ] 나올 때까지
	if (b == -1) return; // 종료조건
	string temp = str.substr(a + 1, b - a - 1); // 숫자만 가져오기
	if (isValid(temp)) { // 만약 숫자가 5개라면 
		cout << "[" << temp << "]\n"; // 출력
	}
	a = b + 1; // a는 b+1부터 다시 탐색
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str; // 문자열 입력받기 
		Parsing(str); // 파싱하기 
	}
	
	return 0; 
}