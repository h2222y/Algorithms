#include <iostream>
#include <queue>
using namespace std;

int vis[100002]; // �����̰� �̵��ϴ� �迭

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k; //�������� ��ǥ�� ������ ��ǥ �Է�
	queue<int> Q;
	Q.push(n); // �������� ó�� ��ǥ�� ť�� �ִ´�
	fill(vis, vis + 100001, -1); // �̵� �迭�� -1�� �ʱ�ȭ
	vis[n] = 0; // �������� ù �̵���ǥ�� 0�� �־��ش�. 
	while (vis[k] == -1) { // -1�ϵ���
		int cur = Q.front();
		Q.pop();
		for (int nxt : {cur - 1, cur + 1, 2 * cur}) { //�̵��� cur-1,cur+1,cur*2 ����
			if (nxt < 0 || nxt>100000)continue; // nxt�� ���� ������ �����
			if (vis[nxt] != -1) continue; // �̹� �湮������
			vis[nxt] = vis[cur] + 1; // ������ǥ +1�� �־��ش�
			Q.push(nxt);
		}
	}
	cout << vis[k]; //������ ��ǥ�� �ִ� �̵� ��ǥ�� ������ش�.
	return 0;
}