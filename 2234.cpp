#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int map[51][51];
bool visited[51][51] = { false };
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int wall[4] = {1, 2, 4, 8}; //서, 북, 동, 남
int cnt = 0, roomSize = 0, removeWall = 0;

bool isRange(int y, int x){
    if(y >= 0 && x >= 0 && y < M && x < N){
        return true;
    }
    return false;
}

int BFS(int y, int x){
    queue<pair<int, int>> q;
    int size = 1;
    q.push({y, x});
    visited[y][x] = true;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){ //dir
            if ((map[r][c] & wall[i]) > 0){
                continue;
            }
            else{
                int next_r = r + dir[i][0];
                int next_c = c + dir[i][1];
                if (isRange(next_r, next_c) && !visited[next_r][next_c])
                {
                    visited[next_r][next_c] = true;
                    q.push({next_r, next_c});
                    size++;
                }
            }
        }
    }
    return size;
}

void Solve(){
    //방 갯수 구하기
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                cnt++;
                int ans = BFS(i, j);
                roomSize = max(roomSize, ans);
            }
        }
    }
    
    //방 벽 하나 없애는 경우
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for(int k = 0; k < 4; k++){
                if((map[i][j] & wall[k]) > 0){
                    //초기화
                    memset(visited, false, sizeof(visited));
                    map[i][j] -= wall[k];
                    int ans = BFS(i, j);
                    removeWall = max(removeWall, ans);
                    map[i][j] += wall[k];
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    Solve();
    cout << cnt << '\n' << roomSize << '\n' << removeWall << '\n';
    return 0;
}