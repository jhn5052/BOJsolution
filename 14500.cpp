#include<iostream>
#include<algorithm>
using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int map[500][500] ={ 0 };
int visit[500][500] = { false };
int N, M;

bool isRange(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= M){
        return false;
    }
    return true;
}

int DFS(int x, int y, int cnt){
    if(cnt >= 5){
        return 0;
    }
    int result = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dir[i][1];
        int ny = y + dir[i][0];
        if(isRange(nx, ny)){
            if(visit[nx][ny] == false){
                visit[nx][ny] = true;
                result = max(result, DFS(nx, ny, cnt+1) + map[x][y]);
                visit[nx][ny] = false;
            }
        }
    }
    return result;
}

int other_shape(int x, int y){
    int result = 0;
    if(x >= 1 && y >= 1 && x < N && y < M-1){
        //ㅗ
        result = max(result, map[x][y-1] + map[x-1][y] + map[x][y] + map[x][y+1]);
    }
    if(x >= 0 && x < N-1 && y >= 1 && y < M-1){
        //ㅜ
        result = max(result, map[x][y-1] + map[x][y] + map[x+1][y] + map[x][y+1]);
    }
    if(x >= 1 && x < N-1 && y >= 1 && y < M){
        //ㅓ
        result = max(result, map[x][y] + map[x][y-1] + map[x-1][y] + map[x+1][y]);
    }
    if(x >= 1 && x < N-1 && y >= 0 && y < M-1){
        //ㅏ
        result = max(result, map[x][y] + map[x-1][y] + map[x+1][y] + map[x][y+1]);
    }
    return result;
}

int main(){
    cin >> N;
    cin >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            visit[i][j] = false;
        }
    }
    int ans = 0;
    for(int n = 0; n < N; n++){
        for(int m = 0; m < M; m++){
            visit[n][m] = true;
            ans = max(ans, DFS(n, m, 1));
            ans = max(ans, other_shape(n, m));
            visit[n][m] = false;
        }
    }
    cout << ans;
    return 0;
}

