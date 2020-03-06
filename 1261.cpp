#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 987654321

int N, M;
int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int map[101][101] = { 0 };
int dijk[101][101];
bool visit[101][101];


bool isRange(int x, int y){
    if(x >= 0 && x < M && y >= 0 && y < N){
        return true;
    }
    return false;
}

int algoSpot(){
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    dijk[0][0] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(isRange(nx, ny)){
                if(map[nx][ny] == 0){
                    if(dijk[nx][ny] > dijk[x][y]){
                        dijk[nx][ny] = dijk[x][y];
                        q.push(make_pair(nx,ny));
                    }
                }

                else if(map[nx][ny] == 1){
                    if(dijk[nx][ny] > dijk[x][y] + 1){
                        dijk[nx][ny] = dijk[x][y] + 1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    return 0;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            dijk[i][j] = INF;
        }
    }
    algoSpot();
    printf("%d\n", dijk[M-1][N-1]);
    return 0;
}
