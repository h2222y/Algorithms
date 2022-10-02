#include <iostream>
#include <cstring>
using namespace std;
int arr[7][7];
int n;

void rotate() {
   int backup[7][7];
   // 90도 회전 
   for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
         backup[x][n - 1 - y] = arr[y][x];
      }
   }
   for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
         arr[y][x] = backup[y][x];
      }
   }

}
int main() {
   // freopen_s(new FILE*, "input.txt", "r", stdin);
   int tc, T;
   cin >> T;
   for (int tc = 1; tc <= T; tc++) {
      cin >> n;
      for (int y = 0; y < n; y++) {
         for (int x = 0; x < n; x++) {
            cin >> arr[y][x];
         }
      }

      cout << "#" << tc<<endl;
      for (int y = 0; y < n; y++) {
         rotate();
         for (int x = 0; x < n; x++) {
            cout << arr[y][x];
         }
         cout << " ";
         rotate();
         for (int x = 0; x < n; x++) {
            cout << arr[y][x];
         }
         cout << " ";
         rotate();
         for (int x = 0; x < n; x++) {
            cout << arr[y][x];
         }
         cout << endl;
         rotate();
      }
   }

   return 0;
}