#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N;
bool visit[11];
bool map[11][11] = { false };
int p[11];
int ans = 1000;

bool isPossible() {
   vector<int> A;
   vector<int> B;

   for (int i = 1; i <= N; i++) {
      if (visit[i] == true) {
         A.push_back(i);
      }
      else {
         B.push_back(i);
      }
   }
      
   //구역에 하나이상 있어야함
   if (A.size() == 0 || B.size() == 0) {
      return false;
   }
   
   //팀A : visit이 true인것끼리 인접해있는지
   bool check[11] = { false, };
   queue<int> q;
   
   q.push(A[0]);
   check[A[0]] = true;
   int num = 1;
   while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int i = 1; i <= N; i++) {
         if (map[cur][i] == true && visit[i] == true && !check[i]) {
            num++;
            check[i] = true;
            q.push(i);
         }
      }
   }
   if (num != A.size()) {
      return false;
   }

   //팀B : visit이 false인 것 끼리 인접해있는지
   memset(check, false, sizeof(check));
   q.push(B[0]);
   check[B[0]] = true;
   num = 1;
   while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int i = 1; i <= N; i++) {
         if (map[cur][i] == true && !visit[i] && !check[i]) {
            num++;
            check[i] = true;
            q.push(i);
         }
      }
   }
   if (num != B.size()) {
      return false;
   }

   return true;
}

void DFS(int cnt, int start, int end) {
   if (cnt == end) {
      if (isPossible()) {
         int a = 0, b = 0;
         for (int i = 1; i <= N; i++) {
            if (visit[i] == true) {
               a += p[i];
            }
            else {
               b += p[i];
            }
         }
         ans = min(ans, abs(a - b));
         return;
      }
   }
   else {
      for (int i = start; i <= N; i++) {
         if (!visit[i]) {
            visit[i] = true;
            DFS(cnt + 1, i, end);
            visit[i] = false;
         }
      }
   }
}


int main() {
   cin >> N;
   //사람수
   for (int i = 1; i <= N; i++) {
      cin >> p[i];
   }

   //인접한 노드
   for (int i = 1; i <= N; i++) {
      int t;
      cin >> t;z
      for (int j = 0; j < t; j++) {
         int k;
         cin >> k;
         map[i][k] = true;
         map[k][i] = true;
      }
   }

   //사람 조합 : bottom-up
   for (int i = 1; i <= N-1; i++) {
      DFS(0, 1, i); //cnt, start, end
   }
   if (ans == 1000) {
      cout << -1 << '\n';
   }
   else
      cout << ans << '\n';
   return 0;
}
