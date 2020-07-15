//9207
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 100

int N;
int dir[4][2] = { {1,0}, {-1, 0}, {0, 1}, {0,-1} };
char map[6][10];
int ans = MAX;
int Move = 0;

void DFS(int cnt, int m) {
   if (ans > cnt) {
      ans = cnt;
      Move = m;
      if (cnt == 1) {
         return;
      }
   }

   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 9; j++) {
         if (map[i][j] == 'o') {//pin 발견

            //인접한 곳 핀 있는지 탐색
            for (int k = 0; k < 4; k++) {
               int nr = i + dir[k][0];
               int nc = j + dir[k][1];
               if (nr < 0 || nc < 0 || nr >= 5 || nc >= 9)   continue;
               if (map[nr][nc] == 'o') {
                  //인접한 곳에 핀이 존재하면 다음칸이 빈칸인지 확인
                  if (map[nr + dir[k][0]][nc + dir[k][1]] == '.') {
                     map[i][j] = '.';
                     map[nr][nc] = '.';
                     map[nr + dir[k][0]][nc + dir[k][1]] = 'o';
                     DFS(cnt - 1, m + 1);
                     
                     //되돌려주기
                     map[i][j] = 'o';
                     map[nr][nc] = 'o';
                     map[nr + dir[k][0]][nc + dir[k][1]] = '.';
                  }
               }
            }
         }
      }
   }
   return;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> N;
   while (N--) {
      memset(map, 0, sizeof(map));
      ans = MAX;
      Move = MAX;

      int pin_cnt = 0;
      for (int i = 0; i < 5; i++) {
         for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'o') {
               pin_cnt++;
            }
         }
      }

      DFS(pin_cnt, 0);
      //output
      cout << ans << ' ' << Move << '\n';
   }
}
