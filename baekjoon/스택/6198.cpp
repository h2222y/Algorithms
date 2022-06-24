#include <iostream>
#include <stack>
using namespace std;

#define ll long long

stack<int> s;
int n;
ll ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; // ����
    ll h; // ����

    while (n--) {
        cin >> h; //���� �Է¹���
        while (!s.empty() && s.top() <= h) //������ ������� �ʰ� ���ÿ� ����ִ� ���� ���̰� ���� ���̺��� ������
            s.pop(); //pop���ش�
        ans += s.size(); //�ڽź��� ū �� = �ڽ��� �ٶ� �� �ִ� �͵�
        // stack�� �ڽź��� ū ������ ���ܵױ� ������ �ڽ��� �ٶ� �� �ִ� ������ �����ִ� ���̴�. 
        s.push(h);
    }
    cout << ans;
    return 0;
}