#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int ans = 0;
int map[9][9];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isRange(int y, int x){
    if(y >= 0 && x >= 0 && y < N && x < M){
        return true;
    }
    return false;
}

void BFS(){
    int visit[9][9];
    queue<pair<int, int> > q;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visit[i][j] = map[i][j];
            if(map[i][j] == 2){
                q.push(make_pair(i, j));
            }
        }
    }

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(isRange(ny, nx) && !visit[ny][nx]){
                visit[ny][nx] = 2;
                q.push(make_pair(ny, nx));
            }
        }
    }
    int tmp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visit[i][j]){
                tmp++;
            }
        }
    }
    ans = max(ans, tmp);
    return;
}


void Wall(int cnt){
    if(cnt == 3){
        BFS();
        return;
    }
    
    else{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 0){
                    map[i][j] = 1;
                    Wall(cnt + 1);
                    map[i][j] = 0;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                Wall(1);
                map[i][j] = 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
