#include <Iostream>
#include <string>
using namespace std;
int n; //수열의 길이
string str; // 수열 입력받기

int isSame(int sublen, int sPos) {
	for (int i = sPos; i < sPos + sublen; i++) { // 현재 위치부터 현재위치 + 부분수열의 길이
		if (i + sublen >= n) return 0; //현재 위치 + 부분수열의 길이가 n초과하면 안된다.
		if (str[i] != str[i + sublen]) return 0; //현재 위치 옆에 인접한 부분수열 존재하지 않으면 0보내기
	}
	return 1; // 현재 위치 옆에 인접한 부분수열 존재시 1전송
}

int main() {
	int flag = 0; // 수열에 인접하고 같은 부분수열이 존재하는지 확인
	cin >> n; // 수열의 길이 입력
	cin >> str; //전체 수열 입력
	for (int sublen = 1; sublen <= n; sublen++) { //1~n까지 1칸, 2칸 ... n칸까지 부분수열 구하기
		for (int sPos = 0; sPos < n; sPos++) { // 0부터 n-1까지 현재 위치 보내주기
			if (isSame(sublen, sPos))flag = 1; // 인접한 부분수열 존재시 flag를 1로
		}
	}
	if (flag == 1) cout << "NO";// 인접한 부분수열 존재하면 NO 출력
	else cout << "YES"; //인접한 부분수열 존재하지 않으면 YES 출력
	return 0;
}