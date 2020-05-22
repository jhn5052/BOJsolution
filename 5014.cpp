//스타트링크
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 987654321
int S, G, F, U, D;
bool visit[1000001];

int BFS(){
    queue<pair<int, int> > q;
    q.push(make_pair(S, 0));
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == G){
            return cnt;
        }
        if(cur + U <= F && !visit[cur+U]){ 
            visit[cur+U] = cnt + 1;
            q.push(make_pair(cur+U, cnt+1));
        }
        if (cur - D > 0 && !visit[cur-D])
        {
            visit[cur-D] = cnt + 1;
            q.push(make_pair(cur-D, cnt+1));
        }
    }
    return MAX;
}

int main(){
    cin >> F >> S >> G >> U >> D;
    memset(visit, false, sizeof(visit));
    int ans = BFS();
    if(ans == MAX){
        cout << "use the stairs" << '\n';
    }
    else{
        cout << ans << '\n';
    }
    return 0;
}
