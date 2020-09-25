#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#include <limits.h>
using namespace std;
#define MAX 51

typedef struct info{
    int y,x,time;
}Info;

int N, M;
int map[MAX][MAX] = { 0 };
vector<pair<int, int> > v;
bool vir[11] = { false };
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans = INT_MAX;

int Solve(){
    queue<Info> q;
    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 10; i++){
        if(vir[i]){
            int r = v[i].first;
            int c = v[i].second;
            q.push({r, c, 0});
            visited[r][c] = true;
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int t = q.front().time;
        if(map[y][x] != 2 && cnt < t){
            cnt = t;
        }

        q.pop();

        for(int i = 0; i < 4; i++){
            int next_y = y + dir[i][0];
            int next_x = x + dir[i][1];

            //범위를 벗어난 경우, 이미 들린경우, 벽인 경우
            if(next_y < 0 || next_x < 0 || next_y >= N || next_x >= N)  continue;
            if (visited[next_y][next_x] || map[next_y][next_x] == 1)
                continue;

            //방문하지 않았으면서 (빈칸인경우, 비활성화 바이러스 인경우)
            if (!visited[next_y][next_x])
            {
                if(map[next_y][next_x] == 0 || map[next_y][next_x] == 2){
                    visited[next_y][next_x] = true;
                    q.push({next_y, next_x, t+1});
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j] && map[i][j] == 0){
                return -1;
            }
        }
    }
    return cnt;
}

//활성화 map[i][j] = -1
void Virus(int idx, int cnt){
    //M개 바이러스 선택 완료
    if(cnt == 0){
        int result = Solve();
        if(ans != INT_MAX && ans > 0){
            if(result != -1){
                ans = min(result, ans);
            }
        }
        else if(ans == INT_MAX){
            ans = result;
        }
        else if(ans == -1){
            ans = max(result, ans);
        }
        return;
    }

    else if(idx == v.size()){
        return;
    }
    else{
        vir[idx] = true;
        Virus(idx+1, cnt-1);
        vir[idx] = false;
        Virus(idx+1, cnt);
    }
}

int main(){
    //input
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                v.push_back({i,j});
            }

        }
    }

    Virus(0, M);
    cout << ans << '\n';
    return 0;
}