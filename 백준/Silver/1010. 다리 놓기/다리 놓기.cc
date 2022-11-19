#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        double n_fac = 1;
        double m_fac = 1;
        double mn_fac = 1;
        int ans;
        for (int i = n; i >= 1; i--) {
            n_fac *= i;
        }
        for (int i = m; i >= 1; i--) {
            m_fac *= i;
        }
        for (int i = m - n; i >= 1; i--) {
            mn_fac *= i;
        }
        ans = round(m_fac / (n_fac * mn_fac));
        cout << ans << "\n";

    }
        return 0;
 }
