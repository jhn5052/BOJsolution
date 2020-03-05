#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int w, h;
int dir[8][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int map[50][50] = { 0 };
bool visit[50][50] = { false };
int cnt = 0;

bool isRange(int y, int x){
    if(y < 0 || y >= h || x < 0 || x >= w){
        return false;
    }
    return true;
}

int DFS(int y, int x){
    visit[y][x] = true;
    for(int i = 0; i < 8; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(map[ny][nx] == 1 && visit[ny][nx] == false && isRange(ny, nx)){
            DFS(ny, nx);
        }
    }
    return 0;
}

int main(){
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }
        
        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> map[i][j];
            }
        }
        cnt = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(visit[i][j] == false && map[i][j] == 1){
                    cnt += 1;
                    DFS(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
