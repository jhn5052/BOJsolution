//10026 적록색약
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, cnt = 0;
char map[101][101];
bool visit[101][101] = { false };
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool isRange(int y, int x) {
   if (y < 0 || x < 0 || y >= N || x >= N) {
      return false;
   }
   return true;
}

void BFS(int y, int x, char color, bool flag){
   queue<pair<int, int> > q;
   q.push({ y,x });
   visit[y][x] = true;
   if (flag == false) {
      while (!q.empty()) {
         int y = q.front().first;
         int x = q.front().second;
         q.pop();
         for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if (!visit[ny][nx] && isRange(ny, nx) && map[ny][nx] == color) {//색이 같을 때만
                  q.push({ ny,nx });
                  visit[ny][nx] = true;
            }
         }
      }
   }
   else if(flag == true){
      while (!q.empty()) {
         int y = q.front().first;
         int x = q.front().second;
         q.pop();
         for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if (visit[ny][nx] || !isRange(ny, nx)) continue;
            if (color == 'G' || color == 'R'){
               if (map[ny][nx] == 'G' || map[ny][nx] == 'R') {
                  q.push({ ny, nx });
                  visit[ny][nx] = true;
               }
            }
            else if (color == 'B' && map[ny][nx] == 'B') {
               q.push({ ny, nx });
               visit[ny][nx] = true;
            }
         }
      }
   }
   
}

int main() {
   cin >> N;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cin >> map[i][j];
      }
   }

   //일반인
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         if (!visit[i][j]) {
            cnt++;
            BFS(i, j, map[i][j], false);
         }
      }
   }
   cout << cnt << ' ';
   memset(visit, false, sizeof(visit));
   cnt = 0;
   //적록색약
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         if (!visit[i][j]) {
            cnt++;
            BFS(i, j, map[i][j], true);
         }
      }
   }
   cout << cnt << ' ';
   return 0;
}
