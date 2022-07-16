#include <iostream>
#include <queue>
using namespace std;

const int LMT = 100001;
int board[LMT + 2];
int prePos[LMT + 2];
int subin, sister;
queue<int> Q;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> subin >> sister; // 수빈이와 동생의 좌표를 입력받는다
    board[subin] = 1; //수빈이의 좌표에 1표시, 시간을 잴 것
    prePos[subin] = subin;  // 수빈이의 좌표에 수빈이 숫자 표시
    Q.push(subin); //수빈이의 좌표 queue에 넣기
    while (!board[sister]) { // 동생의 좌표에 가기 전까지
        int v = Q.front(); Q.pop();
        for (int nv : { v + 1, v - 1, 2 * v }) {
            if (nv < 0 || LMT <= nv) continue;
            if (board[nv]) continue;
            board[nv] = board[v] + 1; // 숫자 재기
            prePos[nv] = v; // 다음 좌표에 현재 좌표 표시해두기
            Q.push(nv);
        }
    }
    cout << board[sister] - 1 << '\n'; // 초 출력하기
    deque<int> track = { sister }; // deque에 동생 좌표 넣기
    while (track.front() != subin) // deque의 좌표가 수빈의 좌표가 같지 않을 때까지
        track.push_front(prePos[track.front()]); // prePos 좌표에 deque의 값 넣기
    for (int p : track) cout << p << ' ';
}