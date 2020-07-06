#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int M, N;
int map[501][501];
int dp[501][501];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int cnt = 0;

int Solve(int r, int c) {
   //종료 조건
   if (r == M - 1 && c == N - 1) {
      return 1;
   }
   
   //메모이제이션
   int& ret = dp[r][c];
   if (ret != -1) {
      return ret;
   }
   ret = 0;
   for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];
      if (nr >= 0 && nc >= 0 && nr < M && nc < N) {
         if (map[nr][nc] < map[r][c]) {
            //bottom up 
            ret += Solve(nr, nc);
         }
      }
   }
   return ret;
}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> M >> N;
   for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
         cin >> map[i][j];
      }
   }
   memset(dp, -1, sizeof(dp));
   cout << Solve(0, 0) << '\n';
   return 0;
}
