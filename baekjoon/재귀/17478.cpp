#include <iostream>
using namespace std;
int n;
void _bar(const char* str, int cnt) { //앞의 ____를 출력해주는 함수 
	for (int i = 0; i < cnt; ++i) cout << "____";
	cout << str;
}

void recur(int cnt) {
	_bar("\"재귀함수가 뭔가요?\"\n", cnt); // 카운트 만큼 출력 
	if (cnt == n) _bar("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", cnt); // 카운트가 입력받은 n과 일치할때만 출력
	else { //카운트가 n과 일치하지 않는 경우 출력하고, 카운트값 1증가 
		_bar("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n",cnt);
		_bar("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n",cnt);
		_bar("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n",cnt);
		recur(cnt + 1);
	}
	_bar("라고 답변하였지.\n", cnt);
	}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; //재귀 횟수 
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n"; // 첫 이야기는 한 번만 출력
	recur(0); //카운트는 0부터 시작 

}