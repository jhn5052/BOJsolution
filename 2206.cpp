#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char map[1001][1001];
int dist[1001][1001][2];

bool isRange(int y, int x){
    if(y < 0 || y >= N || x < 0 || x >= M){
        return false;
    }
    return true;
}

int BFS(){
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0, 0), 0));
    dist[0][0][0] = 1;
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int crash = q.front().second;
        q.pop();
        if(y == N-1 && x == M-1){
            return dist[y][x][crash];
        }
        for(int i = 0; i < 4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(isRange(ny, nx)){
                if(map[ny][nx] == '1' && crash == 0){
                    q.push(make_pair(make_pair(ny, nx), 1));
                    dist[ny][nx][1] = dist[y][x][crash] + 1;
                }
                else if(map[ny][nx] == '0' && dist[ny][nx][crash] == 0){
                    q.push(make_pair(make_pair(ny, nx), crash));
                    dist[ny][nx][crash] = dist[y][x][crash] + 1;
                }
            }
        }
    }
    return -1;
}




int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    memset(dist, 0, sizeof(dist));
    int ans = BFS();
    cout << ans << '\n';
    return 0;
}
