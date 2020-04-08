#include<iostream>
using namespace std;

int N, M;
int r, c, d;
int cnt = 0;
int map[51][51];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int back[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

void find(int y, int x, int f){
    if(map[y][x] == 1){
        return;
    }
    else if(map[y][x] == 0){
        map[y][x] = -1;
        cnt++;
    }

    for(int i = 0; i < 4; i++){
        int nd = f-1 >= 0 ? f-1 : 3;
        int ny = y + dir[nd][0];
        int nx = x + dir[nd][1];
        
        //왼쪽 방향에 청소하지 않은 공간 존재
        if(map[ny][nx] == 0){
            find(ny, nx, nd);
            return;
        }
        else{
            f = nd;
        }
    }

    int ny = y + back[f][0];
    int nx = x + back[f][1];
    find(ny, nx, f);
}
    

int main(){
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    find(r, c, d);
    cout << cnt << '\n';
    return 0;
}
