#include <iostream>
#include <queue>
using namespace std;
int subin, sister;
int dist[200005];

int main() {
	cin >> subin >> sister; // �����̿� ������ ��ġ�� �Է¹޴´�
	deque<int> DQ; //deque ���
	fill(dist, dist + 200000, -1); // ������ 2�踦 ����ؼ� ��Ҵ�/
	DQ.push_back(subin); // dq�� �������� ��ǥ�� �ִ´�
	dist[subin] = 0; // �������� ��ǥ�� 0���� �ΰ� �Ÿ��� �����Ѵ�. 
	while(!DQ.empty()) { // dq�� ��� ��������
		int cur = DQ.front(); // dq�� ���� ���� �����´�
		DQ.pop_front(); // �� ����
		if (2 * cur < 200000 && dist[2 * cur] == -1) { //2���̸鼭, ���� �湮���� ���� ���
			dist[2 * cur] = dist[cur]; // 0�ʰ� �ɸ��� ������ �״�� ���� �����Ѵ�.
			DQ.push_front(2 * cur); // ���� ���� ���ش� 
		}
		for (auto nxt : { cur + 1,cur - 1}) { //+1,-1�� �̵��Ҷ�
			if (nxt < 0 || nxt >= 200000)continue; // �������� ����� ���
			if (dist[nxt] != -1)continue; // �̹� �湮�� ���
			else dist[nxt] = dist[cur] + 1; // 1�ʰ� �ҿ�ȴ�
			DQ.push_back(nxt); //�ڿ� �־��ش�.
		}
	}
	cout << dist[sister]; // ������ ��ǥ�� dist�� ����ϱ�
}