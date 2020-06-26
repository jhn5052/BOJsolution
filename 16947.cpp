#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N;
vector<int> v[3002];//노드 간선 저장 벡터
int map[3002] = { 0 };
bool visited[3002] = { false };
bool isCycle[3002] = { false }; //싸이클 확인 배열
int cycle = 0;

bool FindCycle(int prev, int cur) {
   visited[cur] = true;
   for (int i = 0; i < v[cur].size(); i++) {
      int next = v[cur][i];
      if (prev == next || cur == next)    continue;
      if (!visited[next]) {
         //DFS탐색 - node가 cycle일때 false로 바꾸기
         bool flag = FindCycle(cur, next);
         if (flag == true) {
            if (cycle == next) {
               isCycle[next] = true;
               return false;
            }
            else {
               isCycle[next] = true;
               return true;
            }
         }
      }
      else if (visited[next] == true) {
         //싸이클 발견
         cycle = next;
         isCycle[next] = true;
         return true;
      }
   }
   return false;
}

int BFS(int node) {
   queue<pair<int, int> > q;
   q.push({ node, 0 }); //start node, cnt
   visited[node] = true;
   while (!q.empty()) {
      int cur = q.front().first;
      int dist = q.front().second;
      q.pop();
      if (isCycle[cur] == true) {
         return dist;
      }
      for (int i = 0; i < v[cur].size(); i++) {
         int next = v[cur][i];
         if (!visited[next]) {
            q.push({ next, dist + 1 });
            visited[next] = true;
         }
      }
   }
   return 0;
}

int main() {
   cin >> N;
   int a, b;
   for (int i = 0; i < N; i++) {
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
   }

   //cycle 찾기 DFS
   FindCycle(0, 1);
   
   //싸이클 아닐때만 거리구하기 BFS
   for (int i = 1; i <= N; i++) {
      if (!isCycle[i]) {
         memset(visited, false, sizeof(visited));
         int ans = BFS(i);
         cout << ans << ' ';
      }
      else {
         cout << 0 << ' ';
      }
   }

   return 0;

}
