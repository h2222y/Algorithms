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

    cin >> subin >> sister; // �����̿� ������ ��ǥ�� �Է¹޴´�
    board[subin] = 1; //�������� ��ǥ�� 1ǥ��, �ð��� �� ��
    prePos[subin] = subin;  // �������� ��ǥ�� ������ ���� ǥ��
    Q.push(subin); //�������� ��ǥ queue�� �ֱ�
    while (!board[sister]) { // ������ ��ǥ�� ���� ������
        int v = Q.front(); Q.pop();
        for (int nv : { v + 1, v - 1, 2 * v }) {
            if (nv < 0 || LMT <= nv) continue;
            if (board[nv]) continue;
            board[nv] = board[v] + 1; // ���� ���
            prePos[nv] = v; // ���� ��ǥ�� ���� ��ǥ ǥ���صα�
            Q.push(nv);
        }
    }
    cout << board[sister] - 1 << '\n'; // �� ����ϱ�
    deque<int> track = { sister }; // deque�� ���� ��ǥ �ֱ�
    while (track.front() != subin) // deque�� ��ǥ�� ������ ��ǥ�� ���� ���� ������
        track.push_front(prePos[track.front()]); // prePos ��ǥ�� deque�� �� �ֱ�
    for (int p : track) cout << p << ' ';
}