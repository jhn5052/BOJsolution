#include<iostream>
using namespace std;

int N, M, y, x, K;
int map[21][21] = { 0 };
int dir[4][2] = {{0, 1}, {0 , -1}, {-1, 0}, {1, 0}}; //동서북남
int dice[7] = { 0 };

bool isRange(int x, int y){
    if(x < 0 || x > N-1 || y < 0 || y > M-1){
        return false;
    }
    return true;
}

int main(){
    cin >> N >> M >> x >> y >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    int order = 0;
    for(int i = 0; i < K; i++){
        cin >> order;
        int nx = x + dir[order-1][0];
        int ny = y + dir[order-1][1];
        if(!isRange(nx, ny)){
            continue;
        }
        int new_head;
        if(order == 1){
            new_head = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = new_head;
        }
        else if(order == 2){
            new_head = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = new_head;
        }
        else if(order == 3){
            new_head = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = new_head;
        }
        else if(order == 4){
            new_head = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = new_head;
        }
        cout << dice[1] << '\n';
        if(map[nx][ny] == 0){
            map[nx][ny] = dice[6];
        }
        else if(map[nx][ny] != 0){
            dice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }
        x = nx;
        y = ny;
    }
    return 0;
}
