#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int vis[1000001];
int main() {
	// �ǹ� �� F��, ��ŸƮ��ũ�� G��
	// ��ȣ�� ���� �ִ� �� S��
	// ���������� up��ư down��ư �ΰ� ����
	int f, g, s, u, d;
	cin >> f >> s >> g >> u >> d;
	// ��ȣ�� s������ g�� ���� ���� �������ϴ� ��ư�� ���� �ּڰ� ���
	// �̵��� �� ���� ���� use the stairs ���


	fill(vis, vis + 1000001, -1); //vis �迭 -1�� �ʱ�ȭ 

	queue<int> Q;
	Q.push(s);
	vis[s] = 0; // ��ȣ�� ���� �ִ� ������ ���� 

	while(!Q.empty()){
	int cur = Q.front(); 
	Q.pop();
	for (int nxt : {cur + u, cur - d}) { // up��ŭ �ö󰡰� d��ŭ �������� 
		if (nxt < 1 || nxt > f) continue; // ���� ������� Ȯ��
		if (vis[nxt] != -1) continue; // �湮���� �ʾҴ� ���� �湮�ϱ� ����
		vis[nxt] = vis[cur] + 1;  // ������ǥ +1���� �� ��° Ŭ������ üũ
		Q.push(nxt);
	}
	}
	if (vis[g] == -1) // vis[g]�� �湮�ϴµ� �����ߴٸ�
		cout << "use the stairs"; // ����̿� ��� 
	else cout << vis[g]; // �����ߴٸ� �ش� �� ���
	return 0; 
}